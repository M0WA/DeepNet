#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

TYPE=""

#
# check parameters
#

if [[ $* == *--mysql* ]]
then
  TYPE="mysql"
elif [[ $* == *--db2* ]]
then
  TYPE="db2"
else
  echo "usage: ./create_release_sql.sh [type]"
  echo "please specify type: --mysql or --db2"
  echo ""
  exit 0
fi

OUT_FILENAME="complete.sql"
rm release/${TYPE}.${OUT_FILENAME}

for PREMIGRATION_FILE in "pre-migrations/${TYPE}/*.sql"
do
  cat ${PREMIGRATION_FILE} >> release/${TYPE}.${OUT_FILENAME}
done

CREATE_FILENAME="sql/${TYPE}/create_table.sql"
cat ${CREATE_FILENAME} >> release/${TYPE}.${OUT_FILENAME}

for MIGRATION_FILE in migrations/${TYPE}/*.sql
do
  cat ${MIGRATION_FILE} >> release/${TYPE}.${OUT_FILENAME}
done
