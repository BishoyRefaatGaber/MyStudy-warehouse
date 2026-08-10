#### Opaque
- General Purpose
- Values must be encoded in base64
- To secure a secret put it in a specific namespace with permissions using RBAC
```yaml 
# secret
apiVersion: v1
kind: Secret
metadata:
	name: db-credentials
type: Opaque
data:
	username: ZGJhZG1pbg==
	password: ZGJwYXNzd29yZA==
---
# pod
apiVersion: v1
kind: Pod
metadata:
	name: my-app
spec:
	containers:
	- name: app-container
	image: nginx
	env:
	- name: DB_USERNAME
	  valueFrom:
		secretKeyRef:
			name: db-credentials
			key: username
	- name: DB_PASSWORD
	  valueFrom:
		secretKeyRef:
			name: db-credentials
			key: password	
```
---
#### TLS Secrets
- User for storing TLS Certificates
- The application by default searches for the tls.crt and tls.key values.
```yaml
apiVersion: v1
kind: Secret
metadata:
	name: tls-secret
type: kubernetes.io/tls
data:
	tls.crt: <base64-encoded-cert>
	tls.key: <base64-encoded-key>
```
---
#### Docker Registry Secret
```yaml
apiVersion: v1
data:
	.dockerconfigjson: <key>
kind: Secret
metadata:
	creationTimestamp: "2024-10-19T19:10:22Z"
	name: my-registry-secret
	namespace: default
	resourceVersion: "1917930"
	uid: 5ee9d10f-b93a-4e64-970a-903262e7d62c
type: kubernetes.io/dockerconfigjson
```
```bash
# usually we use the imperative way
kubectl create secret docker-registry my-registry-secret \
--docker-username=<your-username> \
--docker-password=<your-password> \
--docker-email=<your-email> \
--docker-server=<registry-server>
```
``` yaml
apiVersion: v1
kind: Pod
metadata:
name: private-registry-pod
spec:
	containers:
	- name: my-app
	  image: my-private-registry.com/my-app:latest
	imagePullSecrets:
	- name: my-registry-secret
```
---
#### Service Account Token Secret
- This secret is create automatically when you create a service account 
``` yaml
apiVersion: v1
kind: Pod
metadata:
	name: api-access-pod
spec:
	serviceAccountName: my-service-account
	containers:
	- name: my-container
	image: nginx
```
---
#### Basic Authentication Secret
- Values must be in base64
``` yaml
apiVersion: v1
kind: Secret
metadata:
	name: basic-auth-secret
type: kubernetes.io/basic-auth
data:
	username: YWRtaW4== # base64-encoded 'admin'
	password: cGFzc3dvcmQ== # base64-encoded 'password'
---
# pod
apiVersion: v1
kind: Pod
metadata:
	name: my-app
spec:
	containers:
	- name: app-container
	  image: nginx
	env:
	- name: BASIC_AUTH_USER
	  valueFrom:
		  secretKeyRef:
			name: basic-auth-secret
			key: username
	- name: BASIC_AUTH_PASS
	  valueFrom:
		secretKeyRef:
			name: basic-auth-secret
			key: password
```
---
### SSH-Auth Secret
- Must be mounted as a volume
```yaml
apiVersion: v1
kind: Secret
metadata:
	name: ssh-key-secret
type: kubernetes.io/ssh-auth
data:
	ssh-privatekey: <base64-encoded-private-key>
---
apiVersion: v1
kind: Pod
metadata:
	name: ssh-pod
spec:
	containers:
	- name: ssh-container
	  image: alpine
	  command: ["/bin/sh", "-c", "ssh -i /etc/ssh/keys/id_rsa user@remote-server"]
	  volumeMounts:
	  - name: ssh-key-volume
		mountPath: /etc/ssh/keys
		readOnly: true
	  volumes:
	  - name: ssh-key-volume
		secret:
			secretName: ssh-key-secret	
```