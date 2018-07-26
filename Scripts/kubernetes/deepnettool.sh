#!/bin/bash

source settings.env

kubectl delete --namespace="${NAMESPACE}" pod deepnettool
kubectl run deepnettool --namespace="${NAMESPACE}" -it --image=deepnet/deepnettool:latest --attach=true --restart='Never' --env="DB_CONFIG_DIR=/opt/DatabaseTool/etc/" --image-pull-policy='Never' 
kubectl delete --namespace="${NAMESPACE}" pod deepnettool