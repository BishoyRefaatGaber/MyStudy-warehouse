

**OpenShift Services**:: 

**Networking Components**:: 

**Cluster Version Operators (CVO)**:: manage specific areas of cluster functionality, the lifecycle of cluster Operators which are installed in OpenShift Container Platform by default, and check the OpenShift Update Service to see the valid updates and update paths based on current component versions and information in the graph.

**OpenShift API server**:: The OpenShift API server validates and configures the data for OpenShift resources, such as projects, routes, and templates. OpenShift API server is managed by the OpenShift API Server Operator.

**etcd**:: stores the persistent control plane state while other components watch etcd for changes to bring themselves into the specified state.

**Kubernetes scheduler**:: The Kubernetes scheduler watches for newly created pods without an assigned node and selects the best node to host the pod.

**OpenShift controller manager**:: The OpenShift controller manager watches etcd for changes to OpenShift objects, such as project, route, and template controller objects, and then uses the API to enforce the specified state. The OpenShift controller manager is managed by the OpenShift Controller Manager Operator.

**OpenShift OAuth API server**:: The OpenShift OAuth API server validates and configures the data to authenticate to OpenShift Container Platform, such as users, groups, and OAuth tokens. The OpenShift OAuth API server is managed by the Cluster Authentication Operator.

**OpenShift OAuth server**:: Users request tokens from the OpenShift OAuth server to authenticate themselves to the API. The OpenShift OAuth server is managed by the Cluster Authentication Operator.

 **Operator Lifecycle Manager (OLM)**:: Helps manage Kubernetes-native applications as Operators. Together they provide the system for discovering, installing, and managing the optional add-on Operators available on the cluster.
 
**machine management**:: used for flexibly working with underlying infrastructure such as Amazon Web Services (AWS) ...etc


