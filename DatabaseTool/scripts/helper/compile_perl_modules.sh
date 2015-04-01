#!/bin/bash

cd scripts/modules
for dir in *
do
  echo "making ${dir}"
  cd $dir && perl Makefile.PL && make && make test

  if [ "$(id -u)" != "0" ]; then
    sudo make install
  else
    make install
  fi

  make clean
  cd ..
done
cd ../..
