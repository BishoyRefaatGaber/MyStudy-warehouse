**IAM is a global service**
**ARN** --> Amazon Resource Name
**IAM** --> Create users, groups, iam policies, password policies and roles

---
- **Root account**   created by default, shouldn't be used or shared
- **Users**    are people within your organization, and can be grouped
- **Groups**   only contain users not other groups

---

#### IAM Policies inheritance

- Version -> policy language version
- Id -> identifier for the policy (optional)
- Statement -> one or more individual statements 
	- Sid -> identifier for the statement
	- Effect -> whether the statement allows or denies access (allow, Deny)
	- Principal -> account/user/role  to which this policy applied to
	- Action -> list of actions this policy allows or denies
	- Resource -> list of resources to which the actions applied to
	- Condition -> conditions for when this policy is in effect (optional)

```json
{
	"Version": "2012-10-17",
	"Id": "S3-Account-Permissions",
	"Statement": [
		"Sid": "1",
		"Effect": "Allow",
		"Principal": {
			"AWS": ["arn:aws:iam::123456789012:root"]
		},
		"Action": [
			"s3:GetObject",
			"s3:PutObject"
		],
		"Resource": ["arn:aws:s3::mybucket/*"]
	]
}

```


---

#### How can users access AWS ? 

- AWS Management Console -> protected by password + MFA
- AWS Command Line Interface -> protected by access keys
- AWS Software Development Kit (SDK) -> for code protected by access keys

 ==Access keys are generated through the AWS console

---

#### AWS CLI

```aws
aws configure
aws iam list-users
```

---
#### IAM Roles for Services 

- permissions assigned to AWS services 
- One or more IAM policies that can be used within a specific time period


---

#### IAM Security Tools

- **IAM Credentials Report (account-level)**
	- a report that lists all your account's users and the status of their various credentials.
- **IAM Access Advisor (user-level)**
	- Access advisor shows the service permissions granted to user and when those services were last accessed
	- You can use this information to revise your policies

---

#### IAM Guidelines & Best Practices

• Don’t use the root account except for AWS account setup
• One physical user = One AWS user
• Assign users to groups and assign permissions to groups
• Create a strong password policy
• Use and enforce the use of Multi Factor Authentication (MFA)
• Create and use Roles for giving permissions to AWS services
• Use Access Keys for Programmatic Access (CLI / SDK)
• Audit permissions of your account using IAM Credentials Report & IAM
Access Advisor
• Never share IAM users & Access Keys