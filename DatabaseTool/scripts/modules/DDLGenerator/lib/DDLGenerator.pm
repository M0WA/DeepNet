#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

package DDLGenerator;

use 5.006001;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use DDLGenerator ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	GenerateDDL
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	GenerateDDL
);

our $VERSION = '0.01';

my %datatype_manufacturer = (
  "MySQL"   => 0,
  "DB2"     => 1,
  "Postgre" => 2,
);

#
# database generic type mapping
#
# format:
#   generic_type => [ MySQL SQL-Type, DB2 SQL-Type, Postgre SQL-Type ]
my %datatypes = (
  "INTEGER"    => [ "INTEGER"  , "INTEGER"  , "INTEGER"          ],
  "CHAR"       => [ "CHAR"     , "CHAR"     , "CHAR"             ],
  "VARCHAR"    => [ "VARCHAR"  , "VARCHAR"  , "VARCHAR"          ],
  "LARGE_TEXT" => [ "VARCHAR"  , "CLOG"     , "VARCHAR"          ],
  "DOUBLE"     => [ "DOUBLE"   , "DOUBLE"   , "double precision" ],
  "TIMESTAMP"  => [ "TIMESTAMP", "TIMESTAMP", "TIMESTAMP"        ]
);

my %tables;

sub new {
    my $class = shift;
    my $self = {};
    bless $self, $class;
    return $self;
}

#
#
# GenerateDDL(%tables)
#
# generates DDL SQL script
#
#
sub GenerateDDL
{
  my ($self,%tablesIn) = @_;
  %tables = %tablesIn;

  my $MySQLTableDDL = "";
  my $MySQLTableFkDDL = "";

  my $DB2TableDDL   = "";
  my $DB2TableFkDDL = "";

  my $PostgreTableDDL   = "\n\\c deepnet\n";
  my $PostgreTableFkDDL = "";

  print "\n\n=========================\n";
  foreach my $tableName (keys %tables) {

    my $MySQLCreateTableDDL   = "";
    my $DB2CreateTableDDL     = "";
    my $PostgreCreateTableDDL = "";

    #prepare table specific variables
    my %table_attributes = %{$tables{$tableName}};
    my @columns          = @{$table_attributes{'columns'}};
    my @primaryKeys      = @{$table_attributes{'primaryKeys'}};
    my @foreignKeys      = @{$table_attributes{'foreignKeys'}};
    my @uniqueKeys       = @{$table_attributes{'uniqueKeys'}};
    my @indices          = @{$table_attributes{'indices'}};

    #print some debug information
    print "name     : ".$tableName."\n";
    print "Database : ".$table_attributes{'MySQL_Database'}."\n";
    print "Engine   : ".$table_attributes{'MySQL_Engine'}."\n";
    print "# cols   : ".($#columns+1)."\n";
    print "# fks    : ".($#uniqueKeys+1)."\n";
    print "# uniq   : ".($#foreignKeys+1)."\n";
    print "# idx    : ".($#indices+1)."\n";
    print "=========================\n";

    #generate column ddl
    my $count = 0;
    foreach my $column (@columns) {
      my %column_attributes = %$column;
      my ($MySQLColumnDDL,$DB2ColumnDDL,$PostgreColumnDDL) = $self->GenerateColumnDDL(%column_attributes);
  
      if($count != 0){
        $MySQLCreateTableDDL   .= ",";
        $DB2CreateTableDDL     .= ",";
        $PostgreCreateTableDDL .= ","; }

      $MySQLColumnDDL   = "\n ".$MySQLColumnDDL;
      $DB2ColumnDDL     = "\n ".$DB2ColumnDDL;
      $PostgreColumnDDL = "\n ".$PostgreColumnDDL;

      $MySQLCreateTableDDL   .= $MySQLColumnDDL;
      $DB2CreateTableDDL     .= $DB2ColumnDDL;
      $PostgreCreateTableDDL .= $PostgreColumnDDL;

      $count++;
    }

    #generate contraint ddl for primary keys
    foreach my $primaryKeyColumn (@primaryKeys) {
      my $primaryKeyDDL = $self->GeneratePrimaryKeyDDL($tableName, $primaryKeyColumn);
      $MySQLCreateTableDDL   .= ",\n ".$primaryKeyDDL;
      $DB2CreateTableDDL     .= ",\n ".$primaryKeyDDL;
      $PostgreCreateTableDDL .= ",\n ".$primaryKeyDDL;
    }

    #generate contraints for foreign keys
    foreach my $foreignKeyColumn (@foreignKeys) {
      my %foreignKey_attributes = %$foreignKeyColumn;

      my @params;
      push(@params,{%table_attributes});
      push(@params,{%foreignKey_attributes});
      my ($MySQLFkDDL,$DB2FkDDL,$PostgreFkDDL) = $self->GenerateForeignKeyDDL(@params);
      $MySQLTableFkDDL   .= "\n".$MySQLFkDDL;
      $DB2TableFkDDL     .= "\n".$DB2FkDDL;
      $PostgreTableFkDDL .= "\n".$PostgreFkDDL;
    }

    #generate contraint ddl for unique keys
    foreach my $uniqueKeyColumn (@uniqueKeys) {
      my $uniqCreateDDL = $self->GenerateUniqueKeyDDL($tableName, $uniqueKeyColumn);
      $MySQLCreateTableDDL   .= ",\n ".$uniqCreateDDL;
      $DB2CreateTableDDL     .= ",\n ".$uniqCreateDDL;
      $PostgreCreateTableDDL .= ",\n ".$uniqCreateDDL;
    }

    #generate contraints for indices
    foreach my $indexColumn (@indices) {
      my %index_attributes = %$indexColumn;
      my ($MySQLIndexDDL,$DB2IndexDDL) = $self->GenerateIndexDDL($tableName, %index_attributes);
      $MySQLCreateTableDDL .= ",\n ".$MySQLIndexDDL;
      # $DB2CreateTableDDL   .= ",\n ".$DB2IndexDDL;
    }

    #generate table ddl
    my ($MySQLSingleTableDDL,$DB2SingleTableDDL,$PostgreSingleTableDDL) = $self->GenerateTableDDL($MySQLCreateTableDDL,$DB2CreateTableDDL,$PostgreCreateTableDDL,%table_attributes);

    $MySQLTableDDL   .= $MySQLSingleTableDDL;
    $DB2TableDDL     .= $DB2SingleTableDDL;
    $PostgreTableDDL .= $PostgreSingleTableDDL;
  }

  $MySQLTableDDL   .= "\n".$MySQLTableFkDDL;
  $DB2TableDDL     .= "\n".$DB2TableFkDDL;
  $PostgreTableDDL .= "\n".$PostgreTableFkDDL;

  #write to outfiles
  $self->WriteFile("sql/mysql/create_table.sql",$MySQLTableDDL);
  $self->WriteFile("sql/db2/create_table.sql",$DB2TableDDL);
  $self->WriteFile("sql/postgre/create_table.sql",$PostgreTableDDL);
}

#
#
# string GeneratePrimaryKeyDDL($tableName, $primaryKeyColumn)
#
# generates primary key sql ddl
#
#
sub GeneratePrimaryKeyDDL
{
  my ($self,$tableName, $primaryKeyColumn) = @_;

  my $ddl = "CONSTRAINT PRI__".uc($tableName)."_".uc($primaryKeyColumn)." ";
  $ddl   .= "PRIMARY KEY (".$primaryKeyColumn.")";
  return $ddl;
}

#
#
# ($MySQLFkDDL,$DB2FkDDL,$PostgreFkDDL) GenerateForeignKeyDDL(%tableAttributes, %foreignAttributes)
#
# generates foreign key sql ddl
#
#
sub GenerateForeignKeyDDL
{
  my %tableAttributes   = %{$_[1]};
  my %foreignAttributes = %{$_[2]};

  my $tableName  = $tableAttributes{'name'};
  my $tableDB    = $tableAttributes{'MySQL_Database'};
  my $columnName = $foreignAttributes{'column'};
  my $references = $foreignAttributes{'references'};
  my $database   = $foreignAttributes{'MySQL_Database'};

  my $foreignKeyDDLMySQL = "ALTER TABLE ".$tableDB.".".$tableName." ADD CONSTRAINT FK__".uc($tableName)."_".uc($columnName)." ";
  $foreignKeyDDLMySQL   .= "FOREIGN KEY (".$columnName.") REFERENCES ".$database.".".$references.";\n";

  my $foreignKeyDDLDB2 = "ALTER TABLE ".$tableName." ADD CONSTRAINT FK__".uc($columnName)." ";
  $foreignKeyDDLDB2   .= "FOREIGN KEY (".$columnName.") REFERENCES ".$references.";\n";

  my $foreignKeyDDLPostgre = "ALTER TABLE ".$tableName." ADD CONSTRAINT FK__".uc($columnName)." ";
  $foreignKeyDDLPostgre   .= "FOREIGN KEY (".$columnName.") REFERENCES ".$references.";\n";

  return @{[$foreignKeyDDLMySQL,$foreignKeyDDLDB2,$foreignKeyDDLPostgre]};
}

#
#
# string GenerateUniqueKeyDDL($tableName, $uniqueColumn)
#
# generates unique key sql ddl
#
#
sub GenerateUniqueKeyDDL
{
  my ($self,$tableName, $uniqueColumn) = @_;

  my $tmpUniqName = uc($uniqueColumn);
  $tmpUniqName =~ s/ //g;
  $tmpUniqName =~ s/\,/_/g;

  my $ddl = "CONSTRAINT UNIQ__".uc($tableName)."_".$tmpUniqName." ";
  $ddl   .= "UNIQUE (".$uniqueColumn.")";
  return $ddl;
}

#
#
# ($MySQLIndexDDL,$DB2IndexDDL) GenerateIndexDDL($tableName, %index_attributes)
#
# generates index sql ddl
#
#
sub GenerateIndexDDL
{
  my ($self, $tableName, %index_attributes) = @_;
  my $indexColumn = $index_attributes{'column'};

  my $unsortedIndexColumnName = $indexColumn;
  if($index_attributes{'sort'}) {
    $indexColumn .= " ".$index_attributes{'sort'};
  }

  my $MySQLIndexDDL = "INDEX IDX__".$tableName."_".uc($unsortedIndexColumnName)." ";
  $MySQLIndexDDL   .= "(".$indexColumn.")";

  my $DB2IndexDDL = "";
  return @{[$MySQLIndexDDL,$DB2IndexDDL]};
}

#
#
# ($MySQLColumnDDL,$DB2ColumnDDL,$PostgreColumnDDL) GenerateColumnDDL(%column_attributes)
#
# generates column sql ddl
#
#
sub GenerateColumnDDL
{
  my ($self, %column_attributes) = @_;

  my $MySQLDataType   = $datatypes{$column_attributes{'typeUnsized'}}[$datatype_manufacturer{"MySQL"}];
  my $DB2DataType     = $datatypes{$column_attributes{'typeUnsized'}}[$datatype_manufacturer{"DB2"}];
  my $PostgreDataType = $datatypes{$column_attributes{'typeUnsized'}}[$datatype_manufacturer{"Postgre"}];
  
  if($column_attributes{'isSized'} == 1) {
    $MySQLDataType   .= $column_attributes{'typeSize'};
    $DB2DataType     .= $column_attributes{'typeSize'};
    $PostgreDataType .= $column_attributes{'typeSize'};
  }

  if(! $MySQLDataType || ! $DB2DataType || ! $PostgreDataType )
  {
    print "unknown data-type ".$column_attributes{'typeUnsized'}."\n";
    exit 1;
  }

  my $MySQLColumnDefinition   = $column_attributes{'name'}." ".$MySQLDataType;
  my $DB2ColumnDefinition     = $column_attributes{'name'}." ".$DB2DataType;
  my $PostgreColumnDefinition = $column_attributes{'name'}." ".$PostgreDataType;

  if( $column_attributes{'autoincrement'} && ($column_attributes{'autoincrement'} == 1) ) {
    $MySQLColumnDefinition .= ' AUTO_INCREMENT';
    $DB2ColumnDefinition   .= ' GENERATED ALWAYS AS IDENTITY';
    #postgres has own data type for primary keys, so ignore "real" datatype for primary keys
    $PostgreColumnDefinition = $column_attributes{'name'}." BIGSERIAL";
  }

  if( $column_attributes{'notnull'} && ($column_attributes{'notnull'} == 1) ) {
    $MySQLColumnDefinition   .= ' NOT NULL';
    $DB2ColumnDefinition     .= ' NOT NULL';
    $PostgreColumnDefinition .= ' NOT NULL';
  }

  if( $column_attributes{'hasDefault'} && ($column_attributes{'hasDefault'} == 1) ) {
    $MySQLColumnDefinition   .= ' DEFAULT '.$column_attributes{'defaultValue'};
    $DB2ColumnDefinition     .= ' DEFAULT '.$column_attributes{'defaultValue'};
    $PostgreColumnDefinition .= ' DEFAULT '.$column_attributes{'defaultValue'};
  }

  return @{[$MySQLColumnDefinition,$DB2ColumnDefinition,$PostgreColumnDefinition]};
}

#
#
# ($MySQLDDL,$DB2DDL,$PostgreDDL) GenerateTableDDL($MySQLCreateTableDDL,$DB2CreateTableDDL,$PostgreCreateTableDDL,%tableAttributes)
#
# generates table sql ddl
#
#
sub GenerateTableDDL
{
  my ($self,$MySQLCreateTableDDL,$DB2CreateTableDDL,$PostgreCreateTableDDL,%tableAttributes) = @_;

  #create prefixes for tables

  #we do a little bit more for mysql tables right now than for other database types,...
  my $MySQLTableDDLPrefix = "\n\n/* ".$tableAttributes{'name'}." - MySQL */".
  "\nCREATE TABLE IF NOT EXISTS  ".$tableAttributes{'MySQL_Database'}.".".$tableAttributes{'name'}." (ID INTEGER);".
  "\nDROP TABLE ".$tableAttributes{'MySQL_Database'}.".".$tableAttributes{'name'}.";".
  "\nCREATE TABLE ".$tableAttributes{'MySQL_Database'}.".".$tableAttributes{'name'}."\n(";

  my $DB2TableDDLPrefix      = "\n\n/* ".$tableAttributes{'name'}." - DB2   */".
  "\nCREATE TABLE ".$tableAttributes{'name'}."\n(";

  my $PostgreTableDDLPrefix .= "\n\n/* ".$tableAttributes{'name'}." - Postgre   */".
  "\nCREATE TABLE ".$tableAttributes{'name'}."\n(";

  #create postfix for tables  

  my $MySQLTableDDLPostfix = ") ".$tableAttributes{'MySQL_Engine'}.";\nSHOW WARNINGS;\n";
  my $DB2TableDDLPostfix   = ");\n";
  my $PostgreTableDDLPostfix   = ");\n";

  #assemble table DDL

  my $MySQLDDL   = $MySQLTableDDLPrefix.$MySQLCreateTableDDL."\n".$MySQLTableDDLPostfix;
  my $DB2DDL     = $DB2TableDDLPrefix  .$DB2CreateTableDDL  ."\n".$DB2TableDDLPostfix;
  my $PostgreDDL = $PostgreTableDDLPrefix  .$PostgreCreateTableDDL  ."\n".$PostgreTableDDLPostfix;

  return @{[$MySQLDDL,$DB2DDL,$PostgreDDL]};
}

sub WriteFile {

  my ($self,$filename,$content) = @_;
  open  OUTPUTFILE, ">", $filename or die $!;
  print OUTPUTFILE $content;
  close OUTPUTFILE;
}

1;
__END__

=head1 NAME

DDLGenerator - Data Definition Language Generator for MySQL/DB2/PostgreSQL

=head1 SYNOPSIS

  use DDLGenerator;

  ($MySQLCreateTableDDL,$DB2CreateTableDDL,$PostgreCreateTableDDL) GenerateDDL(%tables); # generates complete sql ddl script

  # function beyond are not exported  
  string GenerateTableDDL(%tableAttributes); #generates table sql ddl
  string GenerateColumnDDL(%column_attributes); # generates column sql ddl
  ($MySQLIndexDDL,$DB2IndexDDL) GenerateIndexDDL($tableName, %index_attributes); # generates index sql ddl
  string GenerateUniqueKeyDDL($tableName, $uniqueColumn); # generates unique key sql ddl
  string GenerateForeignKeyDDL(%tableAttributes, %foreignAttributes); # generates foreign key sql ddl
  string GeneratePrimaryKeyDDL($tableName, $primaryKeyColumn); # generates primary key sql ddl

=head1 DESCRIPTION

Data Definition Language Generator for MySQL/DB2/PostgreSQL.

=head2 EXPORT

None by default.

=head1 SEE ALSO

None.

=head1 AUTHOR

Moritz Wagner, Moritz Wagner<lt>moritz.wagner@siridia.de<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2012 by Moritz Wagner


=cut
