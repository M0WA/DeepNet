#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

package StructureParser;

use 5.006001;
use strict;
use warnings;

use XML::DOM;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use StructureParser ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	ParseStructureXML
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	ParseStructureXML
);

our $VERSION = '0.01';

my @datatypes = (
    "INTEGER", 
    "BIGINT", 
    "CHAR", 
    "VARCHAR", 
    "LARGE_TEXT", 
    "DOUBLE", 
    "TIMESTAMP",
);

my %tables;

# Preloaded methods go here.

sub new{
    my $class = shift;
    my $self = {};
    bless $self, $class;
    return $self;
}

#
#
# void ParseStructureXML(structureXMLFileName)
#
# parses structure.xml file
#
#
sub ParseStructureXML
{
  my ($self,$structureXMLFile) = @_;
  
  my $parser          = XML::DOM::Parser->new();
  my $doc             = $parser->parsefile($structureXMLFile);
  my $table_structure = ($doc->getElementsByTagName('table_structure'))[0];

  foreach my $table ($table_structure->getElementsByTagName('table'))
  {
    #table specific attributes
    my %table_attributes;

    my $tableName             = $table->getAttribute('name');
    $table_attributes{'name'} = $tableName;

    #mysql specific attributes
    $table_attributes{'MySQL_Database'} = $table->getAttribute('MySQL_Database');
    $table_attributes{'MySQL_Engine'}   = $table->getAttribute('MySQL_Engine');

    #columns
    my @columns;
    foreach my $column ($table->getElementsByTagName('column'))
    {
      my %column_attributes;
      $column_attributes{'name'} = $column->getAttribute('name');
      
      #auto increment
      my $autoincrement = 0;
      if( ($autoincrement = $column->getAttribute('autoincrement')) && $autoincrement eq "1" ) {
        $autoincrement = 1; }
      $column_attributes{'autoincrement'} = $autoincrement;

      #not null
      my $notNull = 0;
      if( ($notNull = $column->getAttribute('notnull')) && $autoincrement eq "1" ) {
        $notNull = 1; }
      $column_attributes{'notnull'} = $notNull;

      #default value
      my $hasDefaultValue = 0;
      my $defaultValue   = "";
      if( $column->getAttributeNode('default') ) {
        $defaultValue = $column->getAttribute('default');
        $hasDefaultValue = 1; 
      }
      $column_attributes{'hasDefaultValue'} = $hasDefaultValue;
      $column_attributes{'defaultValue'}    = $defaultValue;

      #data type
      $column_attributes{'type'}        = $column->getAttribute('type');
      $column_attributes{'typeUnsized'} = $column->getAttribute('type');
      $column_attributes{'isSized'}     = 0;
      $column_attributes{'typeSize'}    = 0;

      foreach my $dbType ( @datatypes ) {
        my $regex = "^(".$dbType.")(\\(\\d+\\))*";
        my @typeResults = ($column_attributes{'type'} =~ m/$regex/i);
        if(@typeResults)
        {
          if( ($#typeResults == 1) && $typeResults[1] )
          {
              $column_attributes{'typeUnsized'} = $typeResults[0];
              $column_attributes{'typeSize'}    = $typeResults[1];
              $column_attributes{'isSized'}     = 1;
          }
          last;
        }
      }
      push(@columns,{%column_attributes});
    }
    push(@{$table_attributes{'columns'}},@columns);

    #primary keys
    my @primaryKeys;
    foreach my $primaryKey ($table->getElementsByTagName('primary_key'))
    {
      my $columnName = $primaryKey->getAttribute('column');
      push(@primaryKeys,$columnName);
    }
    push(@{$table_attributes{'primaryKeys'}}, @primaryKeys);

    #foreign keys
    my @foreignKeys;
    foreach my $foreignKey ($table->getElementsByTagName('foreign_key'))
    {
      my $columnName       = $foreignKey->getAttribute('column');
      my $referencesTable  = $foreignKey->getAttribute('references_table');
      my $referencesColumn = $foreignKey->getAttribute('references_column');
      my $referencesName   = $referencesTable." (".$referencesColumn.")";
      my $mysqlDatabase    = $foreignKey->getAttribute('MySQL_Database');

      my %foreignkey_attributes;
      $foreignkey_attributes{'column'}            = $columnName;
      $foreignkey_attributes{'references'}        = $referencesName;
      $foreignkey_attributes{'references_table'}  = $referencesTable;
      $foreignkey_attributes{'references_column'} = $referencesColumn;
      $foreignkey_attributes{'MySQL_Database'}    = $mysqlDatabase;
      push(@foreignKeys,{%foreignkey_attributes});
    }
    push(@{$table_attributes{'foreignKeys'}}, @foreignKeys);

    #unique keys
    my @uniqueKeys;
    my %uniqueKeysCombined;
    foreach my $uniqueKey ($table->getElementsByTagName('unique_key'))
    {
      my $columnAttrContent = $uniqueKey->getAttribute('column');

      #unique keys can be combined keys
      my @columnNames = split(',', $columnAttrContent);

      if(@columnNames <= 1) {
        #single column unique key
        push(@uniqueKeys,@columnNames);
      }
      else {
        #combined unique key
        @{$uniqueKeysCombined{$columnAttrContent}} = @columnNames;
      }
    }
    push(@{$table_attributes{'uniqueKeys'}}, @uniqueKeys);
    %{$table_attributes{'uniqueKeysCombined'}} = %uniqueKeysCombined;

    #indices
    my @indices;
    foreach my $index ($table->getElementsByTagName('index'))
    {
      my %index_attributes;
      my $columnName = $index->getAttribute('column');
      $index_attributes{'column'} = $columnName;

      #sort
      my $indexSort = $index->getAttribute('sort');
      if( $indexSort ) {
        $index_attributes{'sort'} = $indexSort; }

      push(@indices,{%index_attributes});
    }
    push(@{$table_attributes{'indices'}}, @indices);

    #store attributes for tables
    %{$tables{$tableName}} = %table_attributes;

  } # end foreach $table

  return %tables;
}

1;
__END__

=head1 NAME

StructureParser - Perl extension for parsing a XML specifing a database structure

=head1 SYNOPSIS

  use StructureParser;
  
  %tables ParseStructureXML(structureXMLFileName); #parses structure.xml file

=head1 DESCRIPTION

StructureParser is a Perl extension for parsing a XML specifing a database structure.
Please have a look at xml/structure.xml for an example.

=head2 EXPORT

None by default.



=head1 SEE ALSO

This module is used by CodeParser and DDLGenerator

=head1 AUTHOR

Moritz Wagner, Moritz Wagner<lt>moritz.wagner@siridia.de<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2012 by Moritz Wagner


=cut
