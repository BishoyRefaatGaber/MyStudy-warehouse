

```
  
  

# helm upgrade argocd \
# --set configs.params."server\.insecure"=true \
# --set server.ingress.enabled=true \
# --set server.ingress.ingressClassName=nginx \
# -n argocd argo/argo-cd

# --set server.ingress.hosts={www.argo-cd.com} \

  
  

# argocd login 192.168.122.144:8080 --insecure

#argocd account update-password --current-password <current password> --new-password <new password>

# argocd repo add <repo link> --username <user name> --password <secret>
```


