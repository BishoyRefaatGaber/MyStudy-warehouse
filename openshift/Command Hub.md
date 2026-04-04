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
oc api-resources # get the resources that can be created
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


# collects resource definitions and service logs from the cluster
# Important when opening a support case
oc adm must-gather --dest-dir /home/student/must-gather
# Then, create a compressed archive file from the must-gather directory.
tar cvaf mustgather.tar must-gather/


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

# CRI-O  command-line interface to manage containers
# first use oc debug then chroot /host
crictl pods # Lists all pods on a node.
crictl image  # Lists all images on a node.
crictl inspect  # Retrieve the status of one or more containers.
crictl exec  # Run a command in a running container.
crictl logs  # Retrieve the logs of a container.
crictl ps  # List running containers on a node.

# 173
# 190

# Managing resources

# CLI Troubleshooting Tools
oc describe # Display the details of a resource.
oc edit # Edit a resource configuration by using the system editor.
oc patch # Update a specific attribute or field for a resource.
oc replace # Deploy a new instance of the resource.
oc cp # Copy files and directories to and from containers.
oc exec # Execute a command within a specified container.
oc explain # Display documentation for a specified resource.
oc port-forward # Configure a port forwarder for a specified container.
oc logs # Retrieve the logs for a specified container.
oc status  # Display the status of the containers in the selected namespace.
oc rsync # Synchronize files and directories to and from containers.
oc rsh # Start a remote shell within a specified container.

# create a service 
oc expose deployment/<deplyment name> [--selector ] [--port ][--target-port ][--protocol ][--name ]

# create route 
oc expose service <service name> --hostname <hostname> # if --hostname omited openshift create a hostname like <route name>-<project name>.<defult domain>



# Create secrets 
oc create secret generic NAME [--type=string] [--from-file=[key=]source] [--from-literal=key1=value1] [--dry-run=server|client|none] [options]

# create configmap
oc create configmap NAME [--from-file=[key=]source] [--from-literal=key1=value1] [--dry-run=server|client|none] [options]

# Create the PVC the add it to a pod 
oc set volumes RESOURCE/NAME --add|--remove [flags] [options]

# view the storage classes that the cluster provides.
oc get storageclass


 ``` 
 