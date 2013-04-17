#!/bin/bash

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

source conf/db.generator.conf

if [ $# -ne 3 ]; then
  echo ""
  echo "usage: ./add_commercesearch_user.sh <username> <password> <domain>";
  echo ""
  echo "username: username of customer, by policy username is an email-address";
  echo "password: password of customer";
  echo "domain: domain or url of customers webshop/website";
  echo "  i.e. ./add_commercesearch_user.sh \"dummy_customer@siridia.de\" \"areallyreallysecurepassword\" \"siridia.de\"";
  echo ""
  exit 1
fi

USERNAME=$1
PASSWORD=$2
DOMAIN=$3

echo "encrypting password"
SHA512PASSWORD=`echo -n "${PASSWORD}" | sha512sum -t - | awk '{print $1}'`
echo "encrypted password: ${SHA512PASSWORD}"

echo "creating user: ${USERNAME}"
echo "INSERT INTO customers (login,password) VALUES (\"${USERNAME}\",\"${SHA512PASSWORD}\")" | mysql -p${DBPASS} -u${DBUSER} commercesearch
#[ $? -ne 0 ] && echo "error while creating user ${USERNAME}" && exit

echo "adding domain for user: ${DOMAIN}"
echo "INSERT INTO customerdomains (CUSTOMER_ID,domain) VALUES ( (SELECT ID FROM customers WHERE login=\"${USERNAME}\" LIMIT 1) ,\"${DOMAIN}\")" | mysql -p${DBPASS} -u${DBUSER} commercesearch
[ $? -ne 0 ] && echo "error while adding user to domain" && exit

echo "done"
