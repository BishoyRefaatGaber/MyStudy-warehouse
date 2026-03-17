
# 🖥️ Windows-Based Computer Network Models

## 🔹 Workgroup

- Peer-to-peer model.    
- Each device stores its own users locally in the **SAM file**.

## 🔹 Domain

- Centralized model.
- Requires:
    - **Domain Controller (DC)**
    - **Domain Administrator**
    - **Active Directory (AD) DS Role**
    - **DNS server**
    
- To make a DC:
    - Install the AD DS role.
    - Promote the server to a domain controller.
- Contains a **user repository** shared across the domain.
- Users in a domain can join up to **10 devices** by default.

---

# 🌳 Forest & Domain Functional Levels

-  Function level: Version of windows server

| Level                       | Purpose                                                 |
| --------------------------- | ------------------------------------------------------- |
| **Forest Functional Level** | Minimum supported Windows Server version in the forest. |
| **Domain Functional Level** | Windows Server version used within the domain.          |

---

# 📦 Active Directory Components

### NTDS (Active Directory Database)

- Stores logs and database info.
- Contains 4 partitions (viewable using **ADSI Edit**):
    1. **Domain** – Users, groups, devices, OUs
    2. **Configuration** – Physical AD structure (Sites and Services)
    3. **Schema** – AD object types and attributes
    4. **Application** – Optional; used by apps like DNS

### SYSVOL

- Stores:
    - Group Policies
    - Scripts
- Shared folders:
    - `SYSVOL`
    - `NETLOGON` (points to scripts)

### Global Catalog (GC)

- Stores information about all objects in the entire forest.

### LDAP (Lightweight Directory Access Protocol)

- Protocol used by AD to access and manage directory services.

### Remote DC Management Tools

- `winrs` (legacy CLI)
- **RDP** (port 3389)
- **Remote Assistance**
- **RSAT** tools from a client device

### SAM File Behavior

- On **Primary DC (PDC)** → copied to the domain partition.
- On **Additional DC (ADC)** → deleted after promotion.

---

# 🧠 FSMO Roles (Flexible Single Master Operations)

Command: `netdom /query fsmo`  -> get the fsmo rules
- Functions of the Domain Controller
- May be moved from controller to another
### Forest-Wide (1 per forest)  

- **Schema Master** – Manages AD schema (classes and attributes).  
	- displayed in mmc console but first you need to register the scheme
	- to register the scheme write `regsvr32 schmngmt`  in powershell
- **Domain Naming Master** – Controls domain additions/deletions, can add application partition in the NTDS.   displayed in domain and trust console 

> One DC on the forest that has these rules
### Domain-Wide (1 per domain) 
- Displayed on users and computers console

- **RID Master** – Creates objects in the domain and allocate SID for these objects.
- **PDC Emulator** – Handles time sync, password changes, GPO priority, Authentication.
- **Infrastructure Master** – Object updates (name, users in a group,.. etc).

> One DC on the domain that has these rules


> The most important rules are RID and PDC emulator

> All rules can be on one controller or distributes to different controllers also can be moved from controller to another

> In case of maintenance  roles can be moved from one DC to another 

> If the controller is down and you need to move the rule use sees
---

# 📡 DHCP (Dynamic Host Configuration Protocol)

- Must be **authorized** to work in AD.
- **Multicast scope** supported.

### Key Components:

- **Address Pool** – IP range.
- **Address Leases** – Active device leases.
- **Reservations** – Reserved IPs for specific MACs.
- **Scope Options** – IP config per scope.
- **Server Options** – Global options across all scopes.


---

# 🌐 DNS (Domain Name System)

### Record Types:

- **A** – IPv4    
- **AAAA** – IPv6
- **CNAME** – Alias
- **MX** – Mail server (e.g., Exchange)
- **SOA** – Start of Authority; contains zone info
- **NS** – Name server
- **PTR** – Reverse (IP → Name)

### Lookup Process:

1. Local **Cache**
2. **Hosts** file
3. **DNS Server**
    - Cache
    - Zones (if local)
    - **Conditional Forwarders**
    - **Forwarders**
    - **Root Hints** (13 root servers)

### Zone Types:

- **Primary** – Read/Write
- **Secondary** – Read-only replica
- **Stub** – Only NS and SOA records; used for **trusts**

> **Authoritative Answer** – Comes from a DNS zone
   **Non-Authoritative Answer** – Comes from cache or other source
   DNS acts as a **Service Locator**, storing services in `_tcp`, `_udp`

---

# 👥 AD Groups

### Types:

- **Security Groups** – Used for access control, permissions, user rights, mail lists
- **Distribution Groups** – Used only for mail list.

> mail list if i want to send mail for many users at a time.

### Scopes:

| Scope            | Resource Reach                  | Membership Source             |
| ---------------- | ------------------------------- | ----------------------------- |
| **Domain Local** | Local domain only               | Local domain, trusted domains |
| **Global**       | Anywhere in the forest          | Same domain only              |
| **Universal**    | Across forest & trusted forests | Any domain                    |

---

# 🔗 Trusts

### Trust Types:

- **External Trust** – Between **root domains**
- **Forest Trust** – Between full **forests** (includes children)

### Trust Directions:

- **Two-Way** – Mutual trust
- **One-Way Incoming** – This domain accepts authentication
- **One-Way Outgoing** – This domain can authenticate users in another

> **Stub zones** are required in DNS for forest trust.

---

# 🛡️ Group Policy (GPO)

### Application Order:

1. **Local**
2. **Site**
3. **Domain**
4. **Organizational Unit (OU)**
5. **Sub-OU**

> Use **Enforced** to ensure a policy applies to all lower levels.
> Use **Access-Based Enumeration** to hide files without user permissions.

---

# 🔁 AD Replication

### Types:

| Type           | Scope        | Interval                             |
| -------------- | ------------ | ------------------------------------ |
| **Intra-site** | Same site    | ~15 seconds                          |
| **Inter-site** | Across sites | 180 minutes (default), based on cost |
### Components replicated
- Domain partition
- Scheme partition
- Configuration partition
- Application partition
### Components:

- **Connection Object** – Logical link between DCs
- **KCC** – Builds replication topology
- **USNs** – Identify changes
- **Notification & Polling** – Trigger replication
- **LostAndFound** – Recycle bin for orphaned objects

---

# 💾 Backup Concepts

|Term|Definition|
|---|---|
|**RTO**|Recovery Time Objective (acceptable downtime)|
|**RPO**|Recovery Point Objective (acceptable data loss)|

### Backup Targets:

- Disk, Folder, Files
- **System State**
- **Bare Metal Recovery**

---

# 💿 WDS (Windows Deployment Services)

### Prerequisites:

- **AD DS**
- **DNS**
- **DHCP**
- **WDS** Role
- Devices must support **PXE boot**
- Windows image must be stored on **NTFS**

### PXE Boot Process:

1. Device boots from network
2. Gets IP via **DHCP**
3. Gets WDS via **DNS** (Service Locator)
4. Retrieves OS image from WDS

### Other Notes:

- PXE requires **DHCP option 60**
- **Transport Server** supports multicast sessions if devices ≥5
- Installs from **install.wim** and **boot.wim**

---

# 🛠️ MDT (Microsoft Deployment Toolkit)

- An **extension for WDS**
- Requires **Windows ADK** (Assessment and Deployment Kit)

---

# 🌍 FTP (File Transfer Protocol)

### User Isolation Steps:

1. Create a root folder named after the domain.
2. Enable **"User Name Physical Directory"**.
3. Create separate folders for each user.

---

# 🔄 WSUS (Windows Server Update Services)

- Runs on port **8530**
- Stores updates for client deployment
- Requires **Group Policy** to redirect client update settings
- Uses **WID** (Windows Internal Database) or **SQL Server** for device data
