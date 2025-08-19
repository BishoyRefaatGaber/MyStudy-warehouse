

### Command Modes

- User EXEC Mode
- Privileged EXEC Mode  -> enable
- Global Configuration Mode -> configure terminal
- Line Configuration Mode -> line console 0 , line vty 0 4 
- Interface Configuration Mode -> interface f0/1
- any to privileged -> ctrl+z
- ant to previous -> exit
- break abort DNS lookup -> Ctrl-Shift-6


### Switch Configurations

- (config)# hostname \<hostname>

- (config-line)# password \<password>
- (config-line)# login

- (config)# enable secret \<secret>

- \# show running-config
+ (config)# service password-encryption

- (config)# banner motd \<message>

- (config)# line vty 0 4
- (config-line)# password \<password>
- (config-line)# login
- (config-line)# transport input ssh telnet

- \# show startup-config

- (config-if)# description

- (config)# wr

- (config)# copy running-config startup-config

- \# reload

- (config)# interface vlan 1 
- (config-if)# ip address \<ip addres> \<subnet mask>
- (config-if)# no shutdown
- (config)#  ip default-gateway \<ip-address>

#### Duplex and Speed Settings
- must be the same




- \# show ip arp
- pc> arp -a


### Router Configurations
- same basic configuration as switch +

- (config-if)# ip address \<ip address>
- (config-if)# no shutdown
- R1# show ip interface brief
- R1# show ip route
- R1# show interfaces
- R1# show ip interfaces




## Switch Management Access (SVI)
- S1# configure terminal
- S1(config)# interface vlan 99
- S1(config-if)# ip address 172.17.99.11 255.255.255.0
- S1(config-if)# no shutdown
-  ip default-gateway 172.17.99.1  -> very important (don't forget)




- S1(config)# interface FastEthernet 0/1
- S1(config-if)# duplex full
- S1(config-if)# speed 100



- S1# show interfaces \[interface-id]   --> back to slide
- S1#  show startup-config
- S1#  show running-config
- S1#  show flash
- S1#  show version
- S1#  show history
- S1#  show ip interface \[interface-id]
- S1# show mac-address-table

Filter Show Command Output:
- (|) 
	- section
	- include
	- exclude
	- begin



### SSH
- (config)# ip domain-name \<domain-name>
- (config)# hostname \<hostnme>
- (config)# crypto key generate rsa      --> to delete crypto key zeroize rsa
- (config)# username \<username> secret \<password>
- (config)# line vty 0 4
- s1(config-line)# login local
- s1(config-line)# transport input ssh
- (config)# ip ssh version 2



In router  
- Router(config)# interface loopback number
- Router(config-if)# ip address ip-address subnet-mask


### Vlans

- s1#  show interfaces fa0/18 switchport
- Switch# configure terminal
- Switch(config)# vlan \<vlan-id>
- Switch(config-vlan)# name \<vlan-name>
- Switch(config)# interface \<interface-id>
- Switch(config-if)# switchport mode access
- Switch(config-if)# switchport access vlan \<vlan-id>


+ \# show vlan \[brief | id \<vlan-id> | name \<vlan-name> | summary]

- (config)# no vlan \<vlan-id>

- delete vlan.dat  | delete flash:vlan.dat-> delete all vlans



### Trunk Configuration Commands

- Switch# configure terminal
- Switch(config)# interface interface-id
- Switch(config-if)# switchport mode trunk
- Switch(config-if)# switchport trunk native vlan \<vlan-id>
- Switch(config-if)# switchport trunk allowed vlan \<vlan-list>


### DTP Mode
- show dtp interface \<interface>
- s1(config-if)#switchport mode \<mode>
- switchport nonegotiate  -> stop DTP negotiation.


## Inter vlan
#### Router on stick
- Router(config)#int g0/0/0.\<vlan id>
-  Router(config-subif)#encapsulation dot1Q \<vlan id>



• show ip route
• show ip interface brief
• show interfaces
• show interfaces trunk


- show vlan \[brief]
-  show interfaces switchport
- show interface trunk
- show interfaces switchport


#### layer 3 switch using svi
- Switch(config-if)#int vlan 10
- Switch(config-if)#no shutdown
- Switch(config-if)#ip address 10.0.0.2 255.0.0.0
- Switch(config-if)#int vlan 20
- Switch(config-if)#no shutdown
- Switch(config-if)#ip address 11.0.0.2 255.0.0.0
- Switch(config)#ip routing ->  allow traffic to be exchanged
between VLANs 10 and 20.


## LACP Configuration

- Switch(config)# interface range interface
- Switch(config-if-range)# channel-group \<identifier> mode active
-  Switch(config)# interface port-channel \<identifier>




- show interfaces port-channel
- show etherchannel summary
- show etherchannel port-channel
- show interfaces etherchannel 



## DHCP Configurations

- Router(config)#ip dhcp pool \<pool name>
- Router(dhcp-config)#network \<network ip>  \<subnet mask>
- Router(dhcp-config)#default-router \<router ip>
- Router(dhcp-config)# dns-server \<address>
- Router(dhcp-config)# domain-name \<domain>
- Router(dhcp-config)# lease {days \[hours \[ minutes]] | infinite}
- Router(config)#ip dhcp excluded-address low-address \[high-address]



- show running-config | section dhcp
- show ip dhcp binding
- show ip dhcp server statistics


- Router(config)#no service dhcp
- Router(config)#service dhcp



## DHCPv4 Relay

- (conf-int)# ip helper-address \<dhcp ip>


### static route

- Router(config)# ip route \<network-address> \<subnet-mask> { ip-address | exit-intf \[ip-address]} \[distance]



- show ip route static
- show ip route \<network ip>
- show running-config | section ip route


## OSPF 

- R1(config)# router ospf \<process id (1-65535)>
- Router(config-router)# network \<network-address> \<wildcard-mask> area \<area-id>

- R1(config)#interface loopback 1 
- R1(config-if)#ip address 1.1.1.1 255.255.255.255
- R1(config)# router ospf 10
- R1(config-router)# router-id \<ID>


- R1(config)# router ospf 10
- R1(config-router)# router-id 1.1.1.1
% OSPF: Reload or use "clear ip ospf process" command, for this to take effect
- R1(config-router)# end
- R1# clear ip ospf process



- R2(config-router)# default-information originate



- show ip ospf neighbor
- show ip protocols
- show ip ospf
- show ip ospf interface



## HSRP


- standby \<group number> \<virtual ip address>
- standby \<group number> priority \<0-255>
- standby \<group number> preempt





## Static Nat


- R2(config)# ip nat inside source static \<inside local ip>  \<inside global ip>
- R2(config-if)# ip nat inside
- R2(config-if)# ip nat outside



- R2# show ip nat translations
- R2# show ip nat statistics
- clear ip nat statistics 


## dynamic nat

- R2(config)# ip nat pool \<pool name> \<first pool ip> \<last pool ip>  netmask \<pool subnet mask>
- R2(config)# access-list \<list id> permit \<network range> \<wild card>
- R2(config)# ip nat inside source list \<list id> pool \<pool name>
- R2(config-if)# ip nat inside
- R2(config-if)# ip nat outside


- R2# show ip nat translations
- R2# show ip nat translations verbose