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
oc get <resource type> 
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
 
 
 
 
 
 
 
 
 
 
 ``` 
 