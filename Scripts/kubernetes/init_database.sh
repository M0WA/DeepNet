#!/bin/bash

source settings.env

kubectl run dbinitializer --namespace="${NAMESPACE}" -it --image=deepnet/databasetool:latest --attach=true --restart='Never' --image-pull-policy='Never' -- /bin/sh -c "apt-get install -y mysql-client && cd /opt/DatabaseTool/bin/DatabaseTool/ && export DB_CONFIG_DIR=/opt/DatabaseTool/etc/ && cat /opt/DatabaseTool/bin/DatabaseTool/scripts/shlib/mysql.shlib && /opt/DatabaseTool/bin/DatabaseTool/create.sh --mysql --no-generate"
kubectl delete --namespace="${NAMESPACE}" pod dbinitializer