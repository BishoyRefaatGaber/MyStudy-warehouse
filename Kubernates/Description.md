**kube api server**: The front end for the Kubernetes control plane.
**etcd**: Highly-available key value store used as Kubernetes' backing store for all cluster data.
**scheduler**: Watches for newly created Pods with no assigned node, and selects a node for them to run on.
**controller-manager**: Controls the cluster, runs controller processes.
**kubelet**: An agent that runs on each node in the cluster. It makes sure that containers are running in a Pod.
**kube-proxy**: kube-proxy is a network proxy that runs on each node in your cluster, maintains network rules on nodes.
**container runtime interface (CRI)**: manage the execution and lifecycle of containers within the cluster.