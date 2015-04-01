#! /bin/sh
#############################################################################
# Licensed Materials - Property of IBM
#
# Governed under the terms of the International
# License Agreement for Non-Warranted Sample Code.
#
# (C) COPYRIGHT International Business Machines Corp. 1995 - 2002
# All Rights Reserved.
#
# US Government Users Restricted Rights - Use, duplication or
# disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
#############################################################################
# SCRIPT: bldmt
# Builds Linux C++ multi-threaded applications
# Usage: bldmt <prog_name> [ <db_name> [ <userid> <password> ]]

# Set DB2PATH to where DB2 will be accessed.
# The default is the standard instance path.
DB2PATH=$HOME/sqllib

# Default compiler/linker settings
LIB="lib"
EXTRA_C_FLAGS=""

# Determine our bitwidth (32 or 64) and hardware platform
BITWIDTH=`LANG=C db2level | awk '/bits/{print $5}'`
HARDWAREPLAT=`uname -m`

if [ $BITWIDTH = "\"32\"" ]
then
  LIB="lib32"
fi

# Set up compiler switches according to the current environment
if [ "$HARDWAREPLAT" = "x86_64" ] || [ "$HARDWAREPLAT" = "ppc64" ]
then
  if [ $BITWIDTH = "\"64\"" ]
  then
    EXTRA_C_FLAGS="-m64"
  else
    if [ "$HARDWAREPLAT" != "ppc64" ]
    then
      EXTRA_C_FLAGS="-m32"
    fi
  fi
fi

# The runtime path is recommended for all applications.
# If you need to use LD_LIBRARY_PATH, unset the RUNTIME
# variable by commenting out the following line.
RUNTIME=true

if [ "$RUNTIME" != "" ]
then
  EXTRA_LFLAG="-Wl,-rpath,$DB2PATH/$LIB"
else
  EXTRA_LFLAG=""
fi

# If an embedded SQL program, precompile and bind it.
if [ -f $1".sqC" ]
then
  ./embprep $1 $2 $3 $4
fi

# Compile the program.
g++ $EXTRA_C_FLAGS -I$DB2PATH/include -c $1.C -D_REENTRANT

# Link the program.
g++ $EXTRA_C_FLAGS -o $1 $1.o $EXTRA_LFLAG -L$DB2PATH/$LIB -ldb2 -lpthread