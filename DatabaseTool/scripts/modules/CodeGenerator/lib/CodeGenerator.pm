#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

package CodeGenerator;

use 5.006001;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use CodeGenerator ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	GenerateCode
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	GenerateCode
);

our $VERSION = '0.01';

my %datatype_manufacturer = (
  "MySQL" => 0,
  "DB2"   => 1
);

#
# database generic type mapping
#
# format:
#   generic_type => CPP-Type
my %datatypes = (
  "INTEGER"    => "long long",
  "BIGINT"     => "long long",
  "CHAR"       => "std::string",
  "VARCHAR"    => "std::string",
  "LARGE_TEXT" => "std::string",
  "DOUBLE"     => "double",
  "TIMESTAMP"  => "struct tm",
);

my $srcOutDirectory = "src/";

sub new {
    my $class = shift;
    my $self = {};
    bless $self, $class;
    return $self;
}

sub GenerateCode {
  my ($self,%tables) = @_;

  $self->GenerateTableColumnType();
  $self->GenerateAllTableHeader(%tables);

  $self->GenerateTableBaseHeader(%tables);
  $self->GenerateTableBaseCpp(%tables);
  
  $self->GenerateTableDefinitionCreateParamHeader(%tables);
  $self->GenerateTableDefinitionCreateParamCpp(%tables);
}

sub GenerateTableColumnType {

  my ($self) = @_;
  my $tmplContent = $self->ReadFile('tmpl/TableColumnType.h');

  my $enumContents;
  foreach my $genericName ( keys %datatypes ) {
    $enumContents .= "  DB_TYPE_".$genericName.",\n"; }
  $tmplContent =~ s/__TMPL_FIELD_TYPE_ENUM__/$enumContents/gs;

  # print "\nTableFieldType.h:\n".$tmplContent;
  $self->WriteFile( $srcOutDirectory.'TableColumnType.h', $tmplContent );
}

sub GenerateAllTableHeader {

  my ($self,%tables) = @_;
  
  my $allTableOut = "#pragma once\n\n";
  foreach my $tableName ( keys %tables ) {
    $allTableOut .= "#include \"".$tableName."TableBase.h\"\n";
  }
  $self->WriteFile( $srcOutDirectory.'GeneratedTables.h', $allTableOut );
}

sub GenerateTableBaseHeader {

  my ($self,%tables) = @_;

  my $tmplTableBaseContent            = $self->ReadFile('tmpl/TableBase.h');
  my $tmplTableBaseGetSetFieldContent = $self->ReadFile('tmpl/TableBase_GetSetFields.inc.h');
  my $tmplTableBaseGetByFieldContent  = $self->ReadFile('tmpl/TableBase_GetByFields.inc.h');
  my $tmplTableBaseInnerJoinContent   = $self->ReadFile('tmpl/TableBase_InnerJoin.inc.h');
  my $tmplTableBaseUpdateByContent    = $self->ReadFile('tmpl/TableBase_WhereColumns.inc.h');
  my $tmplCreateColumn                = $self->ReadFile('tmpl/TableDefinitionCreateParam_CreateColumn.inc.h');

  foreach my $tableName ( keys %tables ) {
    my $tmplTableBase = $tmplTableBaseContent;

    #prepare table specific variables
    my %table_attributes = %{$tables{$tableName}};
    my @columns     = @{$table_attributes{'columns'}};
    my @primaryKeys = @{$table_attributes{'primaryKeys'}};
    my @foreignKeys = @{$table_attributes{'foreignKeys'}};
    my @uniqueKeys  = @{$table_attributes{'uniqueKeys'}};
    my @indices     = @{$table_attributes{'indices'}};

    my $tmplTableBaseGetSetFieldOut    = "";
    my $tmplTableBaseGetByFieldOut     = "";
    my $tmplTableBaseInnerJoinFieldOut = "";
    my $tmplTableBaseUpdateByFieldOut  = "";
    my $tmplTableBaseCreateColumnOut  = "";

    foreach my $column (@columns) {      

      my %column_attributes = %$column;
      my $columnName = $column_attributes{'name'};
      my $cppType    = $datatypes{$column_attributes{'typeUnsized'}};

      #get/set functions
      my $tmplTableBaseGetSetFieldTmpl = $tmplTableBaseGetSetFieldContent;
      $tmplTableBaseGetSetFieldTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseGetSetFieldTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplTableBaseGetSetFieldOut .= $tmplTableBaseGetSetFieldTmpl;

      #updateby functions
      my $tmplTableBaseUpdateByTmpl = $tmplTableBaseUpdateByContent;
      $tmplTableBaseUpdateByTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseUpdateByTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplTableBaseUpdateByFieldOut .= $tmplTableBaseUpdateByTmpl;

      #get by functions
      my $tmplTableBaseGetByFieldTmpl = $tmplTableBaseGetByFieldContent;
      $tmplTableBaseGetByFieldTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
      $tmplTableBaseGetByFieldTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseGetByFieldTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplTableBaseGetByFieldOut .= $tmplTableBaseGetByFieldTmpl;

      my $tmplCreateColumn = $tmplCreateColumn;
      $tmplCreateColumn =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseCreateColumnOut .= $tmplCreateColumn;

      #functions generated for keys only
      if( $self->IsKeyBool($columnName, @primaryKeys, @foreignKeys, @uniqueKeys, @indices) == 1 ) {

      }

      # functions generated for foreign keys only
      if( $self->IsForeignKeyBool($columnName, @foreignKeys) == 1 ) {

        #inner join functions
        my $tmplTableBaseInnerJoinContentTmpl = $tmplTableBaseInnerJoinContent;
        $tmplTableBaseInnerJoinContentTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
        $tmplTableBaseInnerJoinContentTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
        $tmplTableBaseInnerJoinFieldOut .= $tmplTableBaseInnerJoinContentTmpl;
      }
    }

    $tmplTableBase =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__GETSET_FIELDS__/$tmplTableBaseGetSetFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__GETBY_FIELDS__/$tmplTableBaseGetByFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__INNER_JOIN_FIELDS__/$tmplTableBaseInnerJoinFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__WHERE_COLUMNS__/$tmplTableBaseUpdateByFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COLUMN__/$tmplTableBaseCreateColumnOut/gs;

    # print "\n".$tableName."TableBase.h:\n".$tmplTableBase;
    $self->WriteFile( $srcOutDirectory.$tableName."TableBase.h", $tmplTableBase );
  } 

}

sub GenerateTableBaseCpp {

  my ($self, %tables) = @_;

  my $tmplTableBaseContent           = $self->ReadFile('tmpl/TableBase.cpp');
  my $tmplTableBaseGetSetContent     = $self->ReadFile('tmpl/TableBase_GetSetFields.inc.cpp');
  my $tmplTableBaseGetByFieldContent = $self->ReadFile('tmpl/TableBase_GetByFields.inc.cpp');
  my $tmplTableBaseInnerJoinContent  = $self->ReadFile('tmpl/TableBase_InnerJoin.inc.cpp');
  my $tmplTableBaseUpdateByContent   = $self->ReadFile('tmpl/TableBase_WhereColumns.inc.cpp');
  my $tmplCreateColumn               = $self->ReadFile('tmpl/TableDefinitionCreateParam_CreateColumn.inc.cpp');

  foreach my $tableName ( keys %tables ) {

    my $tmplTableBase = $tmplTableBaseContent;
    
    #prepare table specific variables
    my %table_attributes   = %{$tables{$tableName}};
    my @columns            = @{$table_attributes{'columns'}};
    my @primaryKeys        = @{$table_attributes{'primaryKeys'}};
    my @foreignKeys        = @{$table_attributes{'foreignKeys'}};
    my @uniqueKeys         = @{$table_attributes{'uniqueKeys'}};
    my %uniqueKeysCombined = %{$table_attributes{'uniqueKeysCombined'}};
    my @indices            = @{$table_attributes{'indices'}};

    my $tmplTableBaseGetByFieldOut     = "";
    my $tmplTableBaseGetSetFieldOut    = "";
    my $tmplTableBaseInnerJoinFieldOut = "";
    my $tmplTableBaseUpdateByFieldOut  = "";
    my $tmplCreateColumnOut;
    my @innerJoinIncludes              = "";

    my $columnPos = 0;
    foreach my $column (@columns) {
      
      my %column_attributes = %$column;
      my $columnName = $column_attributes{'name'};
      my $cppType    = $datatypes{$column_attributes{'typeUnsized'}};
      my $enumFieldType = "DB_TYPE_".$column_attributes{'typeUnsized'};
      my $isPrimaryKey = $self->IsPrimaryKey( $columnName, @primaryKeys );
      my $isForeignKey = $self->IsForeignKey( $columnName, @foreignKeys );
      my $isUniqueKey  = $self->IsUniqueKey ( $columnName, @uniqueKeys  );
      my $isCombinedUniqueKey = $self->IsUniqueKeyCombined( $columnName, %uniqueKeysCombined );
      my $isIndex      = $self->IsIndex     ( $columnName, @indices     );
      my $isNullable   = ( $column_attributes{'notnull'} && ($column_attributes{'notnull'} == 1) ) ? "false" : "true" ;
      my $isAutoIncrement = $isPrimaryKey;
      my $hasDefault = "false";
      my $databaseName = $table_attributes{'MySQL_Database'};
      my $dataSize = $column_attributes{'typeSize'};

      #get/set functions
      my $tmplTableBaseGetSetFieldTmpl = $tmplTableBaseGetSetContent;
      $tmplTableBaseGetSetFieldTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
      $tmplTableBaseGetSetFieldTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseGetSetFieldTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplTableBaseGetSetFieldOut .= $tmplTableBaseGetSetFieldTmpl."\n";

      #updateby functions
      my $tmplTableBaseUpdateByTmpl = $tmplTableBaseUpdateByContent;
      $tmplTableBaseUpdateByTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
      $tmplTableBaseUpdateByTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseUpdateByTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplTableBaseUpdateByFieldOut .= $tmplTableBaseUpdateByTmpl."\n";

      #get by functions
      my $tmplTableBaseGetByFieldTmpl = $tmplTableBaseGetByFieldContent;
      $tmplTableBaseGetByFieldTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
      $tmplTableBaseGetByFieldTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplTableBaseGetByFieldTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplTableBaseGetByFieldOut .= $tmplTableBaseGetByFieldTmpl."\n";

      my $tmplCreateColumnTmpl = $tmplCreateColumn;
      $tmplCreateColumnTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_POS__/$columnPos/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_TYPE__/$enumFieldType/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_DATABASE_NAME__/$table_attributes{'MySQL_Database'}/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_PRIMARY_KEY__/$isPrimaryKey/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_FOREIGN_KEY__/$isForeignKey/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_UNIQUE_KEY__/$isUniqueKey/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_COMBINED_UNIQUE_KEY__/$isCombinedUniqueKey/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_INDEX__/$isIndex/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_NULLABLE__/$isNullable/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_IS_AUTO_GENERATED__/$isAutoIncrement/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_HAS_DEFAULT__/$hasDefault/gs;
      $tmplCreateColumnTmpl =~ s/__TMPL_FIELD_DATA_SIZE__/$dataSize/gs;
      $tmplCreateColumnOut .= $tmplCreateColumnTmpl;

      #functions generated for keys only
      if( $self->IsKeyBool($columnName, @primaryKeys, @foreignKeys, @uniqueKeys, @indices) == 1 ) {
      }

      # functions generated for foreign keys only
      if( $self->IsForeignKeyBool($columnName, @foreignKeys) == 1 ) {
        my %fkAttr = $self->GetForeignKeyAttr($columnName, @foreignKeys);
        my $referencesTable = $fkAttr{'references_table'};
        my $referencesColumn = $fkAttr{'references_column'};

        #inner join functions
        my $tmplTableBaseInnerJoinContentTmpl = $tmplTableBaseInnerJoinContent;
        $tmplTableBaseInnerJoinContentTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
        $tmplTableBaseInnerJoinContentTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;        
        $tmplTableBaseInnerJoinContentTmpl =~ s/__TMPL_JOIN_TABLE_NAME__/$referencesTable/gs;
        $tmplTableBaseInnerJoinContentTmpl =~ s/__TMPL_JOIN_FIELD_NAME__/$referencesColumn/gs;
        $tmplTableBaseInnerJoinFieldOut .= $tmplTableBaseInnerJoinContentTmpl;
        push(@innerJoinIncludes,"#include \"".$referencesTable."TableBase.h\"");
      }

      $columnPos++;
    }

    my %seenInnerJoinIncludes = ();
    my @uniqueInnerJoinIncludes = grep { ! $seenInnerJoinIncludes{$_} ++ } @innerJoinIncludes;
    my $innerJoinIncludesString = "\n";
    foreach my $innerJoinInclude (@uniqueInnerJoinIncludes){
      $innerJoinIncludesString .= $innerJoinInclude."\n";
    }

    $tmplTableBase =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__GETSET_FIELDS__/$tmplTableBaseGetSetFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__GETBY_FIELDS__/$tmplTableBaseGetByFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__INNER_JOIN_FIELDS__/$tmplTableBaseInnerJoinFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__INCLUDE_INNER_JOIN_FIELDS__/$innerJoinIncludesString/gs;
    $tmplTableBase =~ s/__TMPL_DATABASE_NAME__/$table_attributes{'MySQL_Database'}/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_BASE__WHERE_COLUMNS__/$tmplTableBaseUpdateByFieldOut/gs;
    $tmplTableBase =~ s/__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COLUMN__/$tmplCreateColumnOut/gs;

    # print "\n".$tableName."TableBase.cpp:\n".$tmplTableBase;
    $self->WriteFile( $srcOutDirectory.$tableName."TableBase.cpp", $tmplTableBase );
  }
}

sub GenerateTableDefinitionCreateParamHeader {
    my ($self, %tables) = @_;
    my $tmplContent = $self->ReadFile('tmpl/TableDefinitionCreateParam.h');

    foreach my $tableName ( keys %tables ) {
        my $tmplContentOut = $tmplContent;
        $tmplContentOut =~ s/__TMPL_TABLE_NAME__/$tableName/gs;

        # print "\n".$tableName."TableDefinitionCreateParam.h:\n".$tmplContentOut;
        $self->WriteFile( $srcOutDirectory.$tableName."TableDefinitionCreateParam.h", $tmplContentOut );
    }
}

sub GenerateTableDefinitionCreateParamCpp {
    my ($self, %tables) = @_;

    my $tmplContent       = $self->ReadFile('tmpl/TableDefinitionCreateParam.cpp');
    my $tmplCreateContent = $self->ReadFile('tmpl/TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp');

    foreach my $tableName ( keys %tables ) {

        #prepare table specific variables
        my %table_attributes   = %{$tables{$tableName}};
        my @columns            = @{$table_attributes{'columns'}};
        my @primaryKeys        = @{$table_attributes{'primaryKeys'}};
        my @foreignKeys        = @{$table_attributes{'foreignKeys'}};
        my @uniqueKeys         = @{$table_attributes{'uniqueKeys'}};
        my %uniqueKeysCombined = %{$table_attributes{'uniqueKeysCombined'}};
        my @indices            = @{$table_attributes{'indices'}};
        my $databaseName       = $table_attributes{'MySQL_Database'};

        my $tmplContentCreateOut;
        my $columnPos = 0;
        foreach my $column (@columns) {
          
          my %column_attributes   = %$column;
          my $columnName          = $column_attributes{'name'};
          my $cppType             = $datatypes{$column_attributes{'typeUnsized'}};
          my $enumFieldType       = "DB_TYPE_".$column_attributes{'typeUnsized'};
          my $isPrimaryKey        = $self->IsPrimaryKey( $columnName, @primaryKeys );
          my $isForeignKey        = $self->IsForeignKey( $columnName, @foreignKeys );
          my $isUniqueKey         = $self->IsUniqueKey ( $columnName, @uniqueKeys  );
          my $isCombinedUniqueKey = $self->IsUniqueKeyCombined( $columnName, %uniqueKeysCombined );
          my $isIndex             = $self->IsIndex     ( $columnName, @indices     );
          my $isNullable          = ( $column_attributes{'notnull'} && ($column_attributes{'notnull'} == 1) ) ? "false" : "true" ;
          my $isAutoIncrement     = $isPrimaryKey;
          my $hasDefault          = "false";
          my $databaseName        = $table_attributes{'MySQL_Database'};

          my $tmplContentCreateTmpl = $tmplCreateContent;
          $tmplContentCreateTmpl =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_NAME__/$columnName/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_CPP_TYPE__/$cppType/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_POS__/$columnPos/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_TYPE__/$enumFieldType/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_DATABASE_NAME__/$table_attributes{'MySQL_Database'}/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_PRIMARY_KEY__/$isPrimaryKey/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_FOREIGN_KEY__/$isForeignKey/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_UNIQUE_KEY__/$isUniqueKey/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_COMBINED_UNIQUE_KEY__/$isCombinedUniqueKey/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_INDEX__/$isIndex/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_NULLABLE__/$isNullable/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_IS_AUTO_GENERATED__/$isAutoIncrement/gs;
          $tmplContentCreateTmpl =~ s/__TMPL_FIELD_HAS_DEFAULT__/$hasDefault/gs;
          $tmplContentCreateOut .= $tmplContentCreateTmpl;

          $columnPos++;
        }

        #combined unique keys need special treatment
        my $tmplContentCreateCombinedUniqueKeyOut = "\tstd::vector<std::string> tmpCombined;\n";
        foreach my $keyRow (keys %uniqueKeysCombined) {
          $tmplContentCreateCombinedUniqueKeyOut .= "\ttmpCombined.clear();\n";
          foreach my $colName ( @{$uniqueKeysCombined{$keyRow}} )  {
            $tmplContentCreateCombinedUniqueKeyOut .= "\ttmpCombined.push_back(\"".$colName."\");\n";
          }
          $tmplContentCreateCombinedUniqueKeyOut .= "\tcombinedUniqueKeys.push_back(tmpCombined);\n";
        }

        my $tmplContentOut = $tmplContent;
        $tmplContentOut =~ s/__TMPL_TABLE_NAME__/$tableName/gs;
        $tmplContentOut =~ s/__TMPL_DATABASE_NAME__/$databaseName/gs;
        $tmplContentOut =~ s/__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COLUMN_DEFINITIONS__/$tmplContentCreateOut/gs;
        $tmplContentOut =~ s/__TMPL_TABLE_DEFINITION_CREATE_PARAM__CREATE_COMBINED_UNIQUE_KEY_DEFINITIONS__/$tmplContentCreateCombinedUniqueKeyOut/gs;

        # print "\n".$tableName."TableDefinitionCreateParam.cpp:\n".$tmplContentOut;
        $self->WriteFile( $srcOutDirectory.$tableName."TableDefinitionCreateParam.cpp", $tmplContentOut );
    }
}

sub IsKeyBool
{
  my ($self, $columnName, @primaryKeys, @foreignKeys, @uniqueKeys, @indices) = @_;

  foreach my $primaryKeyColumn (@primaryKeys) {
    if( $columnName eq $primaryKeyColumn ) {
      return 1;
    }
  }

  foreach my $foreignKey (@foreignKeys) {
    my %foreign_attr = %$foreignKey;
    if( $columnName eq $foreign_attr{'column'} ) {
      return 1;
    }
  }

  foreach my $uniqueKeyColumn (@uniqueKeys) {
    if( $columnName eq $uniqueKeyColumn ) {
      return 1;
    }
  }

  foreach my $index (@indices) {
    my %index_attr = %$index;
    if( $columnName eq $index_attr{'column'} ) {
      return 1;
    }
  }

  return 0;
}

sub IsPrimaryKey
{
  my ($self, $columnName, @primaryKeys) = @_;
  foreach my $primaryKeyColumn (@primaryKeys) {
    if( $columnName eq $primaryKeyColumn ) {
      return "true";
    }
  }
  return "false";
}

sub IsForeignKey
{
  my ($self, $columnName, @foreignKeys) = @_;
  return $self->IsForeignKeyBool($columnName, @foreignKeys) == 1 ? "true" : "false";
}

sub IsForeignKeyBool
{
  my ($self, $columnName, @foreignKeys) = @_;
  foreach my $foreignKey (@foreignKeys) {
    my %foreign_attr = %$foreignKey;
    if( $columnName eq $foreign_attr{'column'} ) {
      return 1;
    }
  }
  return 0;
}

sub GetForeignKeyAttr
{
  my ($self, $columnName, @foreignKeys) = @_;
  foreach my $foreignKey (@foreignKeys) {
    my %foreign_attr = %$foreignKey;
    if( $columnName eq $foreign_attr{'column'} ) {
      return %foreign_attr;
    }
  }
}

sub IsUniqueKey
{
  my ($self, $columnName, @uniqueKeys) = @_;
  foreach my $uniqueKeyColumn (@uniqueKeys) {
    if( $columnName eq $uniqueKeyColumn ) {
      return "true";
    }
  }
  return "false";
}

sub IsUniqueKeyCombined
{
  my ($self, $columnName, %uniqueKeysCombined) = @_;
  foreach my $keyRow (keys %uniqueKeysCombined) {
    my @tmpArray = @{$uniqueKeysCombined{$keyRow}};
    foreach my $colName ( @{$uniqueKeysCombined{$keyRow}} )  {
      if($colName eq $columnName) {
        return "true";
      }
    }
  }
  return "false";
}

sub IsIndex
{
  my ($self, $columnName, @indices) = @_;
  foreach my $index (@indices) {
    my %index_attr = %$index;
    if( $columnName eq $index_attr{'column'} ) {
      return "true";
    }
  }
  return "false";
}

sub ReadFile {

  my ($self,$fileName) = @_;
  local $/=undef;
  open FILE, $fileName or die "Couldn't open file: $fileName $!";
  my $string = <FILE>;
  close FILE;
  return $string;
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

CodeGenerator - Perl extension for generating database specific C++ code 

=head1 SYNOPSIS

  use CodeGenerator;
  
  void GenerateCode(%tables);

=head1 DESCRIPTION

CodeGenerator is a Perl extension for generating database specific C++ code
according to a given database structure.


=head2 EXPORT

None by default.


=head1 SEE ALSO

CodeGenerator also uses StructureParser extension.

=head1 AUTHOR

Moritz Wagner, Moritz Wagner<lt>support@mo-sys.de<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2012 by Moritz Wagner

=cut
