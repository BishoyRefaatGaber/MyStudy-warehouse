
---
##### Problems in traditional IT On Premises Infrastructure

- Pay for the rent for the data center
- Pay for the power supply, cooling, maintenance
- Adding and replacing hardware takes time
- Scaling is limited
- Hire 24/7 team to monitor the infrastructure
- Dealing with disasters -> (earthquake, power shutdown, fire, ..... )

---
##### Cloud Computing 
*On-demand* delivery of IT resources through internet (compute power, database, storage, applications, networking, .... )

---
##### Features
- Pay-as-you-go pricing
- Provision exactly the right type and size of computing resources
- Simple way to access resources

---
##### The Deployment Models of the cloud
- Private cloud
- Public cloud
- Hybrid cloud

---
##### The five characteristics of the cloud
- On-demand self service -> provision resources 
- Broad network access -> access the service any where
- Multi-tenancy and resource pooling -> 
- Rapid elasticity and scalability
- Measured services
---
##### Six Advantages of cloud computing
- Trade capital expense (CAPEX) for operational expense (OPEX)
- Benefit from massive economies of scale 
- Stop guessing capacity
- Increase speed and agility
- Stop spending money running and maintaining data centers
- Go global in minutes
---

##### Problems the cloud solved 
- Flexibility
- cost-effective
- scalability
- elasticity
- high-availability
- agility
---
##### Types of cloud computing 
- IaaS
- PaaS
- SaaS

pic for it 

---
##### How to choose the region? 
- Compliance
- Latency
- Service Availability
- Pricing


##### Distribution of AWs

- Region -> collection of availability zones (3 min, 6 max)
- Availability Zone -> a collection of discrete data centers that isolated from each other and connected through high bandwidth, ultra-low latency networking


##### Shared Responsibility Model diagram 

- AWS 
	- Infrastructure global network security
	- Isolation on  physical hosts
	- Replacing faulty hardware
	- Compliance validation

- User
	- Security Groups rules
	- Operating system patches and updates
	- Software and utilities installed on the EC2 instance
	- IAM Roles assigned to EC2 & IAM user access management
	- Data security on your instance