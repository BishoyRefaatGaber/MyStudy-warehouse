
## Models
#### Standard User Model
#### The Enterprise Managed User (EMU) model
#### GitHub Enterprise Cloud (GHEC) with **Data Residency**
- For organizations that must comply with data protection
#### GitHub Enterprise Server (GHES)

###### Features 
- Self-Hosting
- Enhanced Security
- Customization and Control
- Performance Optimization
- Compliance

###### Components of GHES
- GitHub Application
- Administrative Dashboard
- System Administration Tools
- Backup and Disaster Recovery
- Monitoring and Logging


## Manage actions and workflows

##### Manually sync public actions for Enterprise Server
- Most official GitHub-authored actions come automatically bundled with Enterprise Server
#### Create workflow templates
- Creating a workflow template is done in two steps:
1. Create a yml workflow file.
2. Create a json metadata file that describes how the template should be presented to users when they're creating a workflow.

> Both files must be placed in a public .github repository and in a directory named workflow-templates.

#### Reusable Templates for Actions and Workflows
###### Types of reusable templates
- Reusable Workflows
- Reusable Actions
- Workflow Templates


## Control access and usage of actions in your enterprise

##### repository-level workflow permissions
- Read
- Write
- Admin: Create, edit, and manage workflow permissions.

