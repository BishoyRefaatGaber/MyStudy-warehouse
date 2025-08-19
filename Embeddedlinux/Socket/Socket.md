
Create Socket

int clientSocket = socket(int domain, int type, int protocol)
**Domain** -> Ipv4(( PF_INET, AP_INET) Ipv6(PF_INET6 ,AF_INET6 )
**Type**-type of communication
Connection oriented-SOCK_STREAM
Connectionless –SOCK_DGRAM
Raw programming-SOCK_RAW
**Protocol**- 0 for TCP/UDP
