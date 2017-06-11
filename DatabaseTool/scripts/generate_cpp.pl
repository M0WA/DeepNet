#!/usr/bin/perl -w

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

use warnings;
use strict;
use StructureParser;
use CodeGenerator;

sub main_procedure 
{
  my $xmlFile = $ARGV[0];

  my $parser = new StructureParser();
  my %tables = $parser->ParseStructureXML($xmlFile);

  my $codeGenerator = new CodeGenerator();
  $codeGenerator->GenerateCode(%tables);
}

main_procedure
