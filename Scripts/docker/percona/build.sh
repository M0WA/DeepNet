#!/bin/bash

source settings.env
cat Dockerfile.template | envsubst > Dockerfile
docker build -t deepnet/db:latest .