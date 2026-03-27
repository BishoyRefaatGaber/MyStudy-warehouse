 ``` bash
crc console --credentials
crc console --url
 
 
oc login -u <username> -p <password> <cluster-url>
 
# get the web console link
oc whoami --show-console

# create a project
# Projects are Kubernetes namespaces with additional annotations that provide multitenancy scoping for applications.
oc new-project <project-name>

oc cluster-info [dump] # prints the address of the control plane.
oc api-versions # prints the supported API versions on the server
oc get clusteroperator # see a list of the cluster operators 
oc get <resource type> [-o wide]
oc describe <resource type> <resource name>
oc explain 
oc create -f <file-name.yaml>
oc status 
oc delete
oc adm top pods -A --sum
oc get all --show-kind
oc adm node-logs  # view node logs
oc debug node/node-name # then use chroot /host to run binaries in the host's executable path.
oc logs pod-name -c container-name

# Create a pod
oc run <options> <name> --image <image> <args>
args:
	--command -- cmd arg1 ... argN
	--restart [Always | OnFailure | Never]
	--env <env=val>
options:
	-it # i -> keep stdin open, t -> open TTY

# Execute command
oc exec <name> [-c <container name>] -- <command> [args...] [options]	

# Show container logs
oc logs <resource name>  <options>
options:
	-l or --selector='' # Filter based on key:value label.
	--tail=  # recent log files to display.
	-c or --container= # Print the logs of a particular container.
	-f or --follow # Follow, or stream, logs for a container.
	-p or --previous=true # Print the logs of a previous container instance in the pod

# open interactive session in a pod	
attach pod-name -c container-name -it # -c is required for multicontainer

# delete resource 	
oc delete <resouce type> <resource name> <options>
options:
	-l <key=value> # delete based on label
	-f <file name> # delete based on file
	--force 
	--grace-period=<number> # graceful termination period
	--now
	--all


## see page 171



 ``` 
 