#!/bin/bash

source settings.env

kubectl run dbinitializer --namespace="${NAMESPACE}" -it --image=deepnet/databasetool:latest --attach=true --restart='Never' --image-pull-policy='Never' /bin/bash


# kubectl delete --namespace="${NAMESPACE}" pod dbinitializer