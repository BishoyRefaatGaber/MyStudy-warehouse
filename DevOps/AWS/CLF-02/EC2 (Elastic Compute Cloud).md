* Infrastructure as a Service


#### ٍSizing and configs 

- OS
- CPU
- RAM
- Storage -> EBS, EFS, EC2 Instance Store
- NIC (speed , IP)
- Security Group -> Firewall
- EC2 User Data -> Bootstrap script


##### Types of EC2 


$$m5.2xlarge$$
m -> instance class
5 -> generation (aws improves them over time)
2xlarge -> size within the instance class



![[Screenshot from 2025-03-11 17-45-10.png]]



- General Purpose   -> balanced / web servers 
- Compute Optimized -> HPC web servers, ML  -> c
- Memory Optimized -> DB  -> r,x,z
- Accelerated Optimized -> 
- Storage Optimized -> OLTP (OnLine Transaction Processing), Relational & NoSQL databases  -> i,d,h
- Instance Features
- Measuring Instance Performance



##### Security Groups

- can be attached to multiple instances
- Locked down to a region / VPC combination
- Does live "outside" the EC2 - if traffic is blocked the EC2 instance won't see it
- If you application is not accessible (time out), then it's a security group issue
- If your application gives a "connection refused" error,  then it's an application error
- All inbound traffic is blocked by default
- All outbound traffic is authorised by default


some ports: 
- 22 -> ssh
- 21,20 -> FTP
- 22 -> SFTP
- 80 -> HTTP
- 443 -> HTTPS
- 3389 -> RDP (Remote Desktop Protocol)


##### Purchasing Plans
- On-Demand Instances
- Reserved
- Savings Planes
- Spot Instances
- Dedicated Hosts
- Dedicated Instances
- Capacity Reservations


---

####  EC2 Purchasing options


- **On-Demand**  -->  short-term and no interruption
	- Has the highest cost but no upfront payment
	- No long-term commitment
- **Reserved**  --> steady-state usage applications 
	- period 1 year or 3 
	- up to 72% discount
	- Tight to Instance Type, Region, Tenancy, OS
	-  You can buy and sell in the Reserved Instance Marketplace
	-  Conver tible Reserved Instance
		-  Can change the EC2 instance type, instance family, OS, scope and tenancy
		-  Up to 66% discount
- **Saving Plans**  --> long-term usage
	- 72% discount
	- Commit to a certain type of usage ($10/hour for 1 or 3 years)
	- Usage beyond EC2 Savings Plans is billed at the On-Demand price
	-  Locked to a specific instance family & AWS region (e.g., M5 in us-east-1)
	- Flexible across:
		- Instance Size (e.g., m5.xlarge, m5.2xlarge)
		- OS (e.g., Linux, Windows)
		- Tenancy (Host, Dedicated, Default)
- **Spot instances**
- **Dedicated Host**
- **Dedicated instance**

