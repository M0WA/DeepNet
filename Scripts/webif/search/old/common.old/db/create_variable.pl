#!/usr/bin/perl

use warnings;
use strict;
use DBI;

my $databaseFile = "webif.db";

# get the variable name
my $variableName = "";
print "please enter variable name: ";
while($variableName eq "")
{
  $variableName = <STDIN>;
  chomp($variableName);
  if($variableName eq "")  {
    print "\ninvalid variable name, please try again:\n";
  }
}
print "\n";

# connect to database
my $dbargs = {sqlite_use_immediate_transaction => 1, AutoCommit => 0, PrintError => 1};
my $dbh = DBI->connect("dbi:SQLite:dbname=".$databaseFile, "", "", $dbargs);
$dbh->do("begin transaction;");

# insert new variable
$dbh->do("INSERT OR IGNORE INTO variables (name) VALUES ('".$variableName."');");
if ($dbh->err()) { die "$DBI::errstr\n"; }
my @resVariable = @{$dbh->selectall_arrayref("SELECT ID FROM variables WHERE name = '".$variableName."';")};
if( @resVariable == 0) {  
  $dbh->do("rollback;");
  die "\nerror,could not find variable id\n";
}
my $variableID = @{$resVariable[0]}[0];

# collect translations for variable
my $resDomains = $dbh->selectall_arrayref("SELECT ID, domain FROM domains;");
foreach my $row (@$resDomains) 
{
  my ($domainID,$domain)  = @$row;

  #check if there is already translation
  my $updateVariableDomainID = -1;
  my $oldTranslation = "";
  my @resVarDom = @{$dbh->selectall_arrayref("SELECT variables_domains.ID, words.word FROM variables_domains INNER JOIN words ON words.ID = variables_domains.WORD_ID WHERE variables_domains.VARIABLE_ID = ".$variableID." AND variables_domains.DOMAIN_ID =".$domainID.";")};
  if( @resVarDom > 0 ) {
      $updateVariableDomainID = @{$resVarDom[0]}[0];
      $oldTranslation = @{$resVarDom[0]}[1];
  }

  #get translation from user for this domain
  print "please enter translation for domain ".$domain.":\n";
  if ($updateVariableDomainID > -1) {
    print "[".$oldTranslation."]: ";
  }
  my $translation = <STDIN>;
  chomp($translation);

  #insert word if neccessary
  $dbh->do("INSERT OR IGNORE INTO words (word) VALUES ('".$translation."');");
  if ($dbh->err()) { $dbh->do("rollback;"); die "$DBI::errstr\n"; }

  #get WORD_ID
  my @resWords = @{$dbh->selectall_arrayref("SELECT ID FROM words WHERE word = '".$translation."';")};  
  my $wordID = @{$resWords[0]}[0];

  #update or insert translation
  if( $updateVariableDomainID > -1)
  {
    $dbh->do("UPDATE variables_domains SET WORD_ID = ".$wordID." WHERE ID = ".$updateVariableDomainID.";");
    if ($dbh->err()) { $dbh->do("rollback;"); die "$DBI::errstr\n"; }
  }
  else
  {
    $dbh->do("INSERT INTO variables_domains (VARIABLE_ID,DOMAIN_ID,WORD_ID) VALUES (".$variableID.",".$domainID.",".$wordID.");");
    if ($dbh->err()) { $dbh->do("rollback;"); die "$DBI::errstr\n"; }    
  }
}

$dbh->do("commit;");
$dbh->disconnect();

print "\ndone.\n";
