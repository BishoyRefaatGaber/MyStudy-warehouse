
# Create a certificate request

vi san.cnf
```
[ req ]
	default_bits       = 4096
	prompt             = no
	default_md         = sha256
	distinguished_name = dn
	req_extensions     = req_ext

	[ dn ]
	C  = AS
	ST = Riyadh
	L  = Riyadh
	O  = bsf
	OU = IT
	CN = gitlabuat.bsf.com

	[ req_ext ]
	subjectAltName = @alt_names

	[ alt_names ]
	DNS.1 = mygitlab.com
	IP.1  = 192.168.203.130


```	

openssl req -new -nodes -newkey rsa:4096 -keyout nexus.key -out nexus.csr -config san.cnf
http://192.168.1.20/certsrv   administrator  P@ssw0rd -> download base64

mv .cer to .crt





