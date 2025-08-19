### Windows-based computer networks Models
##### work group 
- devices are peer to peer
- every device contain its own users stored in sam file
##### domain 
- centralized, 
- needs domain controller and domain administrator
- contain user repository
- the domain controller must contain the active directory rule to be a DC and be in domain
- the network must contain a DNS
- you need to promote the serever after installing the ad role to join it to make it a dc in a domain


- Forest function level --> minimum windows server version in the forest
- Domain function level --> the windows server version in the domain

- logs and database are stored in NTDS --> contain 4 partitions can be seen from ADSI
	- domain --> users, groups, OUs and devices informations 
	- configuration --> physical location for AD seen in sites and services
	- scheme --> AD design (classes (object types ou, user, group,..etc) + attributes (related to object))
	- application --> DNS (optional), Created  Manually or by apps like DNS

- sysvol is stored in SYSVOL --> contain group policies ans scripts

- any user in the domain can join up to 10 devices by default to the domain

- global catalog contain all the object in the whole forest

- remote dc management 
	- from cmd -> winrs (old way)
	- RDP on port  3389
	- remote assistance feature
	- use rsat (remote server administration tools) on client 


LDAP -> lightweight directory access protocol

- in PDC sam file is copied to domain partition in ntds but in ADC is deleted



#### FSMO  (flexible single master operation)5 master roles 
`netdom /query fsmo`

- forest wide only one in the forest
	- scheme master control ad scheme (classes and attributes)
	- domain master control insertion or deletion of domains
	
- domain wide only one in the domain
	- RID master control objects in the domain
	- PDC emulator master control security updates and security transaction EX.password
	- Infrastructure master control object modifications 


- in storage pool hot spare means standby disk
- file sharing 
	- permissions in security are unioned and used for local access
	- permissions in sharing take the least permissions between security and sharing
- sysvol and netlogin are shared by default in dc
- netlogin points to scripts
- enable access-based enumeration --> files with no permission will not appear for the user
- smb authentication is based on user while nfs is based on machine


#### DHCP
- you must authorize the DHCP to work
- multicast scope -> 
- address pool --> address range
- address leases --> devices that got ips
- reservations --> ips reserved to a device
- scope optons --> options distributed with ip
- server option --> common options between all scops



- Domain Admin --> admin of the domain
- Enterprise admin --> admin of the whole forest


#### DNS
- zones
	- forward lockup zone
		- records
			- A
			- AAAA
			- CNAME = alias
			- MX --> microsoft exchange (microsoft mail server)
			- SOA --> marks the start of a DNS zone using serial number 
			- NS
			- PTR -> ip to name
		- search sequence
			- cache
			- hosts file
			- dns
				- cache
				- zones if exists in the zones
				- conditional forwarders
				- forwarders
				- root hints 13 server
		- primary zones -> R/W
		- secondary Zone -> R
		- Stub zone -> build trust between different domains only NS ans SOA replicated
	- if the answer is from a zone it is called authoritative answer else it is called non-authoritative answer
	- reverse lookup zone
- dns works as service locator servers are stored in _tcp or _udp
#### groups
- types 
	- security 
		- share permission
		- ntfs permissions
		- users rights in policies
		- mail list
	- distribution 
		- mail list (send mail to them)
- scope (names are based on resources)
	-                             resource, users
	- domain local  --> domain  , local-trust-child
	- global --> forest , local only
	- universal --> forest + trusted forests, all


#### trust
- while creating trust between two forests you need to create stub zones in both dns 
- external trust --> only the root domains
- forest trust --> domain with its childs

- directions 
	- two-way
	- one-way incoming --> this domain users can auth from the other domain
	- one-way outgoing -> other domain user can auth in this domain
#### policy
- applied on 
	- local
	- site
	- domain
	- ou
	- sub ou
	- enforces --> enforce the policy on all sub levels

#### replication
- intra-site --> same site  7:15 sec
- inter-site --> different sites 180min, path choosen based on cost
- how it is done
	- connection object --> link between two domain controllers
	- KCC (knowledge consistency checker) sends replication topoligy
	- notification
	- polling
- USNs (update sequence numbers) --> number used to identify if there is a change
- lostandfound used as recycle bin

#### Backup
- RTO  --> recovery time objective - downtime
- RPO --> recovery point objective - amount of data loss 
- what data may backedup
	- disk - folder - files
	- system state
	- baremetal backup
#### WDS --> Windows Deployment Service
- PXE needs option 60 to be distributed with dhcp options
- transport server -> devices >=5 open one session and use multicast
- distributes-> install.win, boot.win
- prerequisites
	- AD
	- DNS
	- DHCP
	- WDS
	- windows in wds exists on ntfs
	- devices support PXE on NICs
- steps
	- device boot from network
	- pxe get ip from dhcp
	- pxe get WDS from DNS as it is a service locator
	- pxe install os fromm wds
#### MDT (Microsoft Deployment Toolkit)
- extension for wds
- prerequisites
	- Windows ADK 
#### FTP
- user isolation
	- create a folder with the domain name
	- enable user name physical directory
	- create folder for each user
#### WSUS (Windows Server Update Service) 
- may be compatible with AD or not
- port 8530
- need to create policy to make the devices update from wsus
- wid -> is the database for the devices you can use sql too