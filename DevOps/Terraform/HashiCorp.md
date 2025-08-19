
##### Provider  
--> is a plugin that enables Terraform to interact with cloud platforms, SaaS services, and other APIs. Providers translate Terraform configurations into API calls to manage resources.

```hcl
provider "aws" {
	region = "us-east-1"
}

```


- Terraform Lifecycle 
	- Init                 -->  terraform init
	- Plan               -->   terraform plan  
	- Apply             -->  terraform apply
	- Destroy          -->  terraform destroy


##### Resource    
-->  Defines the actual infrastructure components like EC2 instances, S3 buckets, databases, etc.

```
resource "aws_vpc" "main"{
	cider_block = "10.0.0.0/16"
	tags = {
		Name = "main"
	}
}
```


##### Variable 
-->  Defines input variables to make Terraform code dynamic and reusable.

```
variable "aws_region" {
	default = "us-east-1"
}
```

##### Output 
-->   Displays useful information after Terraform execution.

```
output "instance_public_ip" {
	value = aws_instance.my_server.public_ip
}
```

##### Data 
--> Used to fetch existing resources instead of creating new ones.
--> Helps integrate Terraform with manually created resources.
--> Useful for fetching VPC IDs, AMI IDs, etc. dynamically.

```
data "aws_ami" "latest_amazon_linux"{
	most_recent = true
}
```