\c postgres 

DROP DATABASE IF EXISTS deepnet;
CREATE DATABASE deepnet
  WITH ENCODING='UTF8'
       OWNER=postgres
       CONNECTION LIMIT=-1;

\c deepnet

