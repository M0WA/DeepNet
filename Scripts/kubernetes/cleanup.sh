
source settings.env

if [ ! -z "$1" ]; then
	export APPLICATIONS=("$1")
fi

for APP in "${APPLICATIONS[@]}"; do
	if [ -f "${APP}/service.yaml" ]; then
		echo "${APP}: removing services"
		kubectl delete --namespace="${NAMESPACE}" -f "${APP}/service.yaml" >/dev/null 2>&1
	fi

	if [ -f "${APP}/deployment.yaml" ]; then
		echo "${APP}: removing deployments"
		kubectl delete -f "${APP}/deployment.yaml" >/dev/null 2>&1
	fi
done