#!/bin/bash

source settings.env

DEEPNETTOOLCMD="/opt/DeepNetTool/bin/DeepNetTool --urlFile /opt/DeepNetTool/etc/common.pages.conf --configfile /opt/DeepNetTool/etc/deepnettool.conf"

kubectl delete --namespace="${NAMESPACE}" pod deepnettool
kubectl run deepnettool --namespace="${NAMESPACE}" -it --image=deepnet/deepnettool:latest --attach=true --restart='Never' --image-pull-policy='Never' -- /bin/sh -c "${DEEPNETTOOLCMD}"  
kubectl delete --namespace="${NAMESPACE}" pod deepnettool