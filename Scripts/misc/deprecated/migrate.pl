#!/usr/bin/perl

use warnings;
use strict;
use DBI;
use File::Basename;

# ${DBUSER} ${DBPASS} ${DBHOST} ${DBPORT} ${DBNAME}
my $num_args = $#ARGV + 1;
if ($num_args != 5) {
  print "\nUsage: migrate.pl DBUSER DBPASS DBHOST DBPORT DBNAME\n";
  exit;
}

my ($user,$pass,$dbhost,$dbport,$database) = @ARGV;

my $migrations_directory="Migrations";

my @files = glob("$migrations_directory/*.sql");
print "found ".@files." potential migrations.\n";

my $dbh = DBI->connect('DBI:mysql:'.$database, $user, $pass) || die "Could not connect to database: $DBI::errstr";
print "connected to database\n";

my $query_test = $dbh->prepare('SELECT `filename` FROM '.$database.'.`tbl_migrations`');
$query_test->execute() or die $query_test->err_str;

my @executed_migrations;
while (my ($filename) = $query_test->fetchrow_array() ) {
  push(@executed_migrations,$filename);}

foreach my $filePath (@files)
{
  my $filename = basename($filePath);
  my $found = 0;
  foreach my $executed_mig (@executed_migrations)
  {
    if($executed_mig eq $filename)
    {
      $found = 1;
      last;
    }
  }
  if($found != 1)
  {
    #execute migration
    my $cmd = "cat ".$filePath." | mysql -u".$user." -p".$pass;
    if(system($cmd) == 0)
    {
      #insert successful migration
      print "execution success: ".$filename."\n";
      my $query_insert = $dbh->prepare("INSERT INTO `".$database."`.`tbl_migrations` (`filename`,`filename_hash`) VALUES ('".$filename."', md5('".$filename."'));");
      $query_insert->execute() or print $query_insert->err_str;
    }
    else
    {
      #an error occurred
      print "execution error: ".$filename."\n";
    }
  }
  else
  {
    print "skipping already executed migration: ".$filename."\n";
  }
} 


$dbh->disconnect();
print "done.\n";
