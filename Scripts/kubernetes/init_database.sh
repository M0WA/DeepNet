#!/bin/bash

source settings.env

kubectl delete --namespace="${NAMESPACE}" pod dbinitializer
kubectl run dbinitializer --namespace="${NAMESPACE}" -it --image=deepnet/databasetool:latest --attach=true --restart='Never' --env="DB_CONFIG_DIR=/opt/DatabaseTool/etc/" --image-pull-policy='Never' -- /bin/sh -c "apt-get install -y mysql-client && cd /opt/DatabaseTool/bin/DatabaseTool/ && /opt/DatabaseTool/bin/DatabaseTool/create.sh --mysql --nogenerate"
kubectl delete --namespace="${NAMESPACE}" pod dbinitializer