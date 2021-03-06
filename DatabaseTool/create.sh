#!/bin/bash

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

if [ -z "${DB_CONFIG_DIR}" ]; then
	export DB_CONFIG_DIR="../Scripts/conf/"
fi

source scripts/shlib/mysql.shlib
source scripts/shlib/db2.shlib
source scripts/shlib/postgre.shlib

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
elif [[ $* == *-postgre* ]]
then
TYPE="postgre"
else
  echo "usage: ./create.sh [type]"
  echo "please specify type: --mysql or --db2 or --postgre"
  echo ""
  exit 0
fi

############################################

function execute_file()
{
EXEC_FILENAME=$1
case ${TYPE} in
 "mysql")
   execute_mysql ${EXEC_FILENAME}
   ;;
 "db2")
   execute_db2 ${EXEC_FILENAME}
   ;;
 "postgre")
   execute_postgre ${EXEC_FILENAME}
   ;;
 *)
   echo "invalid database type"
   exit 0
   ;;
esac
}

############################################

if [[ $* == *--nogenerate* ]]
then
echo ""
else
  echo ""
  echo "############################################"
  echo "# generating"
  echo "############################################"
  ./generate.sh
fi

echo ""
echo "############################################"
echo "# executing pre-migrations"
echo "############################################"

for PREMIGRATION_FILE in "pre-migrations/${TYPE}/*.sql"
do
  execute_file ${PREMIGRATION_FILE}
done

echo ""
echo "############################################"
echo "# creating database"
echo "############################################"

CREATE_FILENAME="sql/${TYPE}/create_table.sql"
execute_file ${CREATE_FILENAME}


echo ""
echo "############################################"
echo "# migrating database"
echo "############################################"

for MIGRATION_FILE in migrations/${TYPE}/*.sql
do
  execute_file ${MIGRATION_FILE}
done

echo ""
echo "############################################"
echo "# done."
echo "############################################"
