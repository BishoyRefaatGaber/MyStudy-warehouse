
- Kustomize is a configuration management tool to make declarative changes to application configurations and components and preserve the original base YAML files.


#### Kustomize File Structure
- Need to create kustomization.yaml
- Kustomize has a concept of base and overlays.
	base
	├── configmap.yaml
	├── deployment.yaml
	├── secret.yaml
	├── service.yaml
	├── route.yaml
	└── kustomization.yaml
	overlay
	└── development
		└── kustomization.yaml
	└── testing
		└── kustomization.yaml
	└── production
		├── kustomization.yaml
		└── patch.yaml


``` yaml
# base/kustomization.yaml
apiVersion: kustomize.config.k8s.io/v1beta1
kind: Kustomization
resources:
- configmap.yaml
- deployment.yaml
- secret.yaml
- service.yaml
- route.yaml
```

```yaml
# overlays/development/kustomization.yaml
apiVersion: kustomize.config.k8s.io/v1beta1
kind: Kustomization
namespace: dev-env
resources:
- ../../base
```

- Kustomize provides fields to set values for all resources in the kustomization file:

| Field               | Description                                     |
| ------------------- | ----------------------------------------------- |
| `namespace`         | Set a specific namespace for all resources.     |
| `namePrefix`        | Add a prefix to the name of all resources.      |
| `nameSuffix`        | Add a suffix to the name of all resources.      |
| `commonLabels`      | Add labels to all resources and selectors.      |
| `commonAnnotations` | Add annotations to all resources and selectors. |


---
# OpenShift Users and Groups
