
# Installing nexus HA

### download and install
``` bash
curl -JOL "https://download.sonatype.com/nexus/3/nexus-3.91.1-04-linux-x86_64.tar.gz"
tar xvz --keep-directory-symlink -f ./nexus-unix-x86-64-3.91.1-04.tar.gz
useradd nexus -rM  -s /bin/false
mkdir /opt/sonatype
cp ./nexus-3.91.1-04 ./sonatype-work      /opt/sonatype
mv ./nexus-3.91.1-04 ./nexus
chown -R nexus:nexus ./nexus ./sonatype-work
```

### configure the database

##### in data base
```bash
sudo -i -u postgres
```

``` sql
psql -U postgres
CREATE USER nexus WITH PASSWORD 'somepassword';
CREATE DATABASE nexus OWNER nexus ENCODING 'UTF8' LC_COLLATE = 'en_US.UTF-8' LC_CTYPE = 'en_US.UTF-8' TEMPLATE template0;
\c nexus;
CREATE SCHEMA nexus;
GRANT ALL PRIVILEGES ON DATABASE nexus TO nexus;
GRANT ALL PRIVILEGES ON SCHEMA nexus TO nexus;
CREATE EXTENSION pg_trgm SCHEMA nexus;
```

##### in nexus
/opt/sonatype/sonatype-work/nexus3/etc/fabric/nexus-store.properties write
username=nexus
password=<nexus_password>
jdbcUrl=jdbc:postgresql://\<host>:\<port>/nexus


### configure as service
in   /opt/sonatype/nexus/bin/nexus.rc write
run_as_user="nexus"

touch /etc/systemd/system/nexus.service
sudo vi /etc/systemd/system/nexus.service
``` 
[Unit]
Description=nexus service
After=network.target
  
[Service]
Type=forking
LimitNOFILE=65536
ExecStart=/opt/sonatype/nexus/bin/nexus start
ExecStop=/opt/sonatype/nexus/bin/nexus stop

User=nexus
Restart=on-abort
TimeoutSec=600
  
[Install]
WantedBy=multi-user.target
```


``` bash
sudo systemctl daemon-reload
sudo systemctl enable nexus.service
sudo systemctl start nexus.service
```


### enable ha 

in /opt/sonatype/sonatype-work/nexus3/etc/nexus.properties write
nexus.datastore.clustered.enabled = true


### provide the licence
in /opt/sonatype/sonatype-work/nexus3/etc/nexus.properties
nexus.licenseFile=/path/to/your/sonatype-license.lic


### LOG IN 
$data-dir/sonatype-work/nexus3/logs/




