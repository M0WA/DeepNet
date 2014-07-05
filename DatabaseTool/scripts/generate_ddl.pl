#!/usr/bin/perl -w

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

use warnings;
use strict;

use StructureParser;
use DDLGenerator;

sub main_procedure
{
  my $xmlFile = $ARGV[0];

  my $parser = new StructureParser();
  my %tables = $parser->ParseStructureXML($xmlFile);

  my $ddlGenerator   = new DDLGenerator();
  $ddlGenerator->GenerateDDL(%tables);
}

main_procedure
