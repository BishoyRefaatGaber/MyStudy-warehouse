

## Introduction to Infrastructure as Code (IaC)

### What is Infrastructure as Code?
Infrastructure as Code (IaC) is a practice where infrastructure is provisioned and managed using code and automation tools rather than manual processes. This allows for reproducibility, consistency, and reliability.

### Why do we need IaC?
- **Speed**: Faster deployment and provisioning.
- **Consistency**: Infrastructure is consistent across environments.
- **Efficiency**: Reduced human errors and operational costs.
- **Scalability**: Easy scaling of infrastructure.
- **Collaboration**: Code can be versioned and reviewed collaboratively.

### Key Principles of IaC
- **Declarative Approach**: Define the desired state.
- **Immutable Infrastructure**: Replace rather than repair.
- **Version Control**: Infrastructure code is stored in a repository like Git.
- **Idempotency**: Applying the same operation multiple times without changing the result beyond the initial application.

### Popular IaC Tools
- **Ansible**: Simple, agentless, easy to use.
- **Terraform**: Cloud-agnostic and widely used for provisioning.
- **Chef and Puppet**: Agent-based, suited for large-scale deployments.
- **CloudFormation**: AWS-specific.

---

## Introduction to Ansible (Ubuntu Machines)

### Agenda:
1. What is Ansible?
2. Key Features of Ansible
3. How Ansible Works
4. Installing Ansible on Ubuntu
5. Basic Concepts in Ansible
6. Writing Your First Playbook
7. Practical Examples and Exercises

---

## What is Ansible?
Ansible is an open-source IT automation tool used for configuration management, application deployment, task automation, and orchestration.

### Key Points:
- **Agentless**: Uses SSH, no software installed on clients.
- **Declarative Language**: Uses YAML to define tasks.
- **Idempotency**: Tasks can be run multiple times without side effects.

---
### 🔍 **Ansible vs Chef vs Puppet**

| Feature / Aspect            | **Ansible**                                  | **Chef**                                        | **Puppet**                                       |
| --------------------------- | -------------------------------------------- | ----------------------------------------------- | ------------------------------------------------ |
| **Type**                    | Configuration Management & Orchestration     | Configuration Management                        | Configuration Management                         |
| **Language**                | YAML (declarative, human-readable)           | Ruby DSL (domain-specific language)             | Puppet DSL (based on Ruby-like syntax)           |
| **Agentless?**              | ✅ Yes – uses SSH                             | ❌ No – requires agents                          | ❌ No – requires agents                           |
| **Ease of Setup**           | ⭐ Very simple                                | 🚧 Moderate – Chef Server setup required        | 🚧 Moderate – Puppet Master/Agent setup required |
| **Idempotent?**             | ✅ Yes                                        | ✅ Yes                                           | ✅ Yes                                            |
| **Push vs Pull**            | **Push-based** from control node             | **Pull-based** from Chef clients                | **Pull-based** from Puppet agents                |
| **Master Server Required?** | ❌ No                                         | ✅ Yes – Chef Server                             | ✅ Yes – Puppet Master                            |
| **Extensibility**           | ✅ Highly extensible (modules & plugins)      | ✅ Highly extensible with cookbooks              | ✅ Highly extensible with modules                 |
| **Platform Support**        | Linux, Unix, Windows                         | Linux, Unix, Windows                            | Linux, Unix, limited Windows support             |
| **Learning Curve**          | 🟢 Easy – readable YAML                      | 🟡 Medium – requires Ruby knowledge             | 🟠 Medium – custom DSL, less intuitive           |
| **Community & Modules**     | Strong – Ansible Galaxy                      | Mature – Chef Supermarket                       | Mature – Puppet Forge                            |
| **Cloud Integration**       | Good – many cloud modules                    | Strong – native support for AWS, Azure, GCP     | Strong – good modules for major cloud providers  |
| **Use Case Suitability**    | Fast setup, ad-hoc automation, small/med ops | Larger, complex deployments, DevOps integration | Large-scale deployments, compliance enforcement  |

---
## Key Features of Ansible
- **Simple**: YAML syntax.
- **Agentless**: No agents on remote nodes.
- **Extensible**: Custom modules and plugins.
- **Powerful**: Complex orchestration support.
- **Secure**: SSH-based communication.

---

## How Ansible Works

### Components:
- **Inventory**: List of managed hosts.
- **Playbook**: Task instructions.
- **Modules**: Executable code sent to remote systems.
- **SSH**: Used for secure communication.

---

## SSH Setup for Ansible

### Generate SSH Key:
```bash
ssh-keygen -t ed25519 -C "ansible@control_server"


### Copy Public Key to Remote:

```bash
ssh-copy-id -i ~/.ssh/id_ed25519.pub user@host_ip
```

### Verify Passwordless SSH:

```bash
ssh user@host_ip
```

---

## Inventory Configuration

**Example** `/etc/ansible/hosts`:

```ini
[webservers]
192.168.1.2 ansible_user=user
```

Add key location if not standard:

```ini
ansible_ssh_private_key_file=~/.ssh/id_ed25519
```

Test connection:

```bash
ansible all -m ping
```

---

## Installing Ansible on Ubuntu

```bash
sudo apt update
sudo apt install ansible -y
```

---

## Basic Concepts in Ansible

- **Playbooks**: YAML task sets.
- **Inventory**: List of hosts.
- **Modules**: Functional code blocks.
- **Tasks**: Single operations.
- **Roles**: Logical task groups.
- **Handlers**: Triggered actions.

---

## Writing Your First Playbook

### Directory Setup:

```bash
mkdir my-ansible-playbooks
cd my-ansible-playbooks
nano my_first_playbook.yml
```

### Sample Playbook:

```yaml
---
- name: Ensure Apache is installed and running
  hosts: webservers
  become: yes
  tasks:
    - name: Install Apache
      apt:
        name: apache2
        state: present

    - name: Start Apache service
      service:
        name: apache2
        state: started
        enabled: yes
```

### Inventory:

```ini
[webservers]
your_server_ip
```

### Run the Playbook:

```bash
ansible-playbook -i inventory my_first_playbook.yml
```

---

## Practical Examples and Exercises

### Example 1: Copying Files

```yaml
- name: Copy files
  hosts: webservers
  become: yes
  tasks:
    - name: Copy example file
      copy:
        src: /path/to/local/file.txt
        dest: /path/to/remote/file.txt
```

### Example 2: Creating Files

```yaml
- name: Create files on remote server
  hosts: webservers
  become: yes
  tasks:
    - name: Create an empty file
      file:
        path: /path/to/remote/newfile.txt
        state: touch
```

### Example 3: Removing Files

```yaml
- name: Remove files from remote server
  hosts: webservers
  become: yes
  tasks:
    - name: Remove example file
      file:
        path: /path/to/remote/file.txt
        state: absent
```

### Example 4: Updating and Upgrading Packages

```yaml
- name: Update and upgrade packages
  hosts: webservers
  become: yes
  tasks:
    - name: Update package list
      apt:
        update_cache: yes
    - name: Upgrade all packages
      apt:
        upgrade: dist
```

### Example 5: Creating a User

```yaml
- name: Create a user
  hosts: webservers
  become: yes
  tasks:
    - name: Add a new user
      user:
        name: john
        state: present
        shell: /bin/bash
```

---

## Common Ansible Playbook Tasks

### Package Management

```yaml
apt:
  name: nginx
  state: present
```

### File Management

```yaml
file:
  path: /var/www/html
  state: directory
  owner: www-data
  group: www-data
  mode: '0755'
```

### Copying Files

```yaml
copy:
  src: files/nginx.conf
  dest: /etc/nginx/nginx.conf
```

### Templates

```yaml
template:
  src: templates/nginx.conf.j2
  dest: /etc/nginx/nginx.conf
```

### Services

```yaml
service:
  name: nginx
  state: started
  enabled: true
```

### Shell Commands

```yaml
shell: echo "Hello Ansible!" > /tmp/hello.txt
```

### Git Operations

```yaml
git:
  repo: 'https://github.com/example/myapp.git'
  dest: /var/www/myapp
  version: main
```

### Archives

```yaml
unarchive:
  src: files/app.tar.gz
  dest: /var/www/app
  remote_src: no
```

### User Management

```yaml
user:
  name: deploy
  state: present
  groups: sudo
```

### Line Editing

```yaml
lineinfile:
  path: /etc/ssh/sshd_config
  regexp: '^PermitRootLogin'
  line: 'PermitRootLogin no'
```

### Download Files

```yaml
get_url:
  url: https://example.com/file.tar.gz
  dest: /tmp/file.tar.gz
```

### Synchronize

```yaml
synchronize:
  src: /local/dir/
  dest: /remote/dir/
```

### Hostname

```yaml
hostname:
  name: webserver01
```

### Firewall (ufw)

```yaml
ufw:
  rule: allow
  name: 'WWW'
```

### Cron Jobs

```yaml
cron:
  name: "Backup job"
  minute: "0"
  hour: "0"
  job: "/usr/local/bin/backup.sh"
```

### Docker Container

```yaml
docker_container:
  name: nginx_server
  image: nginx:latest
  state: started
  ports:
    - "8080:80"
```

### GitHub Release

```yaml
github_release:
  user: example
  repo: myapp
  action: latest_release
  dest: /opt/myapp/
```

### Debugging

```yaml
debug:
  msg: "Deployment is complete."
```

---

## Ansible Playbook Command Flags

|Flag|Description|
|---|---|
|`-i`|Use inventory file|
|`--list-hosts`|List targeted hosts|
|`--limit`|Restrict to specific host(s)|
|`--tags`|Run only tagged tasks|
|`--skip-tags`|Skip specified tags|
|`--check`|Dry-run mode|
|`-v/-vv/-vvv/-vvvv`|Verbosity levels|
|`-e`|Extra variables|
|`--syntax-check`|Validate YAML|
|`--start-at-task`|Start at specified task|
|`-u`|SSH user|
|`-k`|Ask for SSH password|
|`-K`|Ask for become password|
|`--become`|Run with sudo|
|`--become-user`|User after sudo|
|`-T`|SSH timeout|
|`--forks`|Parallelism count|
|`--diff`|Show file changes|
|`--force-handlers`|Force handlers even on fail|
|`--flush-cache`|Clear fact cache|

---

## Ansible Vault

### Purpose:

Encrypt sensitive information such as:

- Passwords
- API tokens
- SSH keys

### Common Commands:

```bash
ansible-vault create secrets.yml
ansible-vault encrypt secrets.yml
ansible-vault edit secrets.yml
ansible-vault decrypt secrets.yml
ansible-vault view secrets.yml
```

### Using Vault in Playbooks:

```bash
ansible-playbook --ask-vault-pass playbook.yml
# or
ansible-playbook --vault-password-file ~/.vault_pass.txt playbook.yml
```

### Best Practices:

- Store password outside repository
- Limit vault access
- Use separate files per environment

