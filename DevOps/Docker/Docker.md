
# 1️⃣ Image Management

### Pull image

```
docker pull nginx
```

### List images

```
docker images
```

### Build image

```
docker build -t myimage:1.0 .
```

### Remove image

```
docker rmi myimage
```

### Inspect image

```
docker inspect nginx
```

### Show image history

```
docker history nginx
```

---

# 2️⃣ Container Management

### Run container

```
docker run nginx
```

Detached mode:

```
docker run -d nginx
```

Interactive:

```
docker run -it ubuntu bash
```

Port mapping:

```
docker run -p 8080:80 nginx
```

Name container:

```
docker run --name web nginx
```

---

### List containers

Running only:

```
docker ps
```

All containers:

```
docker ps -a
```

---

### Stop container

```
docker stop container_name
```

### Start container

```
docker start container_name
```

### Restart container

```
docker restart container_name
```

### Remove container

```
docker rm container_name
```

Force remove:

```
docker rm -f container_name
```

---

### Execute command inside container

```
docker exec -it container_name bash
```

---

### View logs

```
docker logs container_name
```

Follow logs:

```
docker logs -f container_name
```

---

# 3️⃣ Volumes

### Create volume

```
docker volume create myvolume
```

### List volumes

```
docker volume ls
```

### Inspect volume

```
docker volume inspect myvolume
```

### Remove volume

```
docker volume rm myvolume
```

Mount volume:

```
docker run -v myvolume:/data nginx
```

Bind mount:

```
docker run -v /host/path:/container/path nginx
```

---

# 4️⃣ Networks

### List networks

```
docker network ls
```

### Create network

```
docker network create mynet
```

### Inspect network

```
docker network inspect mynet
```

### Remove network

```
docker network rm mynet
```

Run container in network:

```
docker run --network mynet nginx
```

---

# 5️⃣ Docker Compose (v2)

Start services:

```
docker compose up
```

Detached:

```
docker compose up -d
```

Stop services:

```
docker compose down
```

Build:

```
docker compose build
```

---

# 6️⃣ System & Cleanup

### System info

```
docker info
```

### Version

```
docker version
```

### Disk usage

```
docker system df
```

### Remove unused objects

```
docker system prune
```

Remove everything unused:

```
docker system prune -a
```

---

# 7️⃣ Advanced / Useful

### Save image to file

```
docker save -o nginx.tar nginx
```

### Load image from file

```
docker load -i nginx.tar
```

### Tag image

```
docker tag nginx myrepo/nginx:1.0
```

### Push image

```
docker push myrepo/nginx:1.0
```

---

# 8️⃣ Context Management

List contexts:

```
docker context ls
```

Switch context:

```
docker context use myremote
```
