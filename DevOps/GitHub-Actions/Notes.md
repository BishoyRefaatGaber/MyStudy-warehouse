
## Terminology

###### workflow
- The automated process you need to run
###### .github/workflows
- structure used for creating workflow
- created in the repo
- any .yaml file in the workflows is treated as a workflow
###### Job
- A job is a section of the workflow that will be associated with a runner.
- runs in parallel by default
###### Runner
- Server that used for running jobs on it
###### Steps
- individual task that can run commands in a job
- the job consists of steps
###### Actions
- the standalone commands that are executed in the steps.
- you can use community actions or action you make or simply some commands.
###### trigger
- code push
- issue created
- starring/unstarring


## Hosting Options

###### Enterprise cloud
- For organizations that need a common and regulated environment
- Can use SSO
- Help complience with HIPAA, GDPR, ISO
###### Enterprise server
- On-premise Server

## Workflow pricing

###### For private repos
- 2000 free minutes for personal account
- 3000  free minutes for Pro or Team
- 50000 free minutes for Enterprise cloud
- >2000, 3000 or 50000
	- linux runner: 0.008$/minute
	- windows runner: 0.016$/minute
	- mac runner: 0.084$/minute
###### For public repos
- every thing is free

## action file structure 

> Github doesn't checkout the repo (git pull) you need to check it  out in the workflow

``` yaml
name: Firstworkflow   # work flow name
on:             # trigger type 
	push:    # triggered on push on branch main 
		branches:
			- main
jobs:        # jobs in the workflow 
	my-job:  # job name
		runs-on: ubuntu-latest  # define the runner  ubuntu is provided by github
		steps:    # job steps
			- name: print a message   # step name
			  run: echo "Hi :)"  # run is used to run shell command
			- name: Checkout repository 
			  uses actions/checkout@v4.2.2  # action from github that checksout the repo
			- name: list repos
			  run: la -la 
```


## Triggers

###### webhok trigger 
``` yaml
on:  
	push:  
		branches:
		- main
		- "release/**" #globing (any file/directory under release)
		paths: # push on pathes
		- "src/**"
		- "main.cpp"
	pull_request: 
		branches:
		- main

```
###### Scheduled trigger
```yaml
on:
	schedule:
	- cron: "******" # time is in grenitch 
```
###### Manual trigger
- gui
- cli
- api call

``` yaml
on: 
	workflow_dispatch:  # manual trigger using gui or cli
		inputs:
			environment: # first input name
				description: "Choose environment"
				required: true
				default: "staging" # default value
				type: choice
				options:
				- staging
				- production
jobs:
	steps:
	- name: ""
	  run : echo "${{ environment }}"
```



``` yaml
on: 
	repository_dispatch:  # manual trigger using api call
		types: [incident_report]
		
jobs:
	handle-incident:
		runs-on: ubuntu-latest
		steps: 
		...
```


## Jobs and steps
``` yaml
jobs:
	job-1:
		runs-on: ubuntu-latest
		steps: 
		...
	job-2:
		runs-on: ubuntu-latest
		needs: 
		- job-1
		steps: 
		...	
```


``` yaml
jobs:
	job-1:
		runs-on: ubuntu-latest
		steps: 
		- run: |
			 echo " dsdsd"
			 working-directory: ./temp
			 shell: bash  # pwsh, cmd, powershell, python, perl 
```

## Actions

owner/repo@ref

``` yaml
steps: 
	- uses: action/checkout@v4.2.2
	- uses:.github/actions/greeting@v2  # personal action
	- uses: docker://alpine:3.14 # run the step in docker image with no credentials
	with: # parameters passed to an action
		name: "ahmed" 
	env: 
	   GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}

 # if you need credentials for contain user the whole job in a container
dockerized-job: 
	runs-on: ubuntu-latest
	#container: node:20 or 
	container: 
		image: ghcr.io/y-org/my-private-image:latest
		credentials:
			username: ${{ secretc.DOCKER_USERNAME }}
			password: ${{ secretc.DOCKER_PASSWORD }}
	steps:
		- run: node --version
```
###### matrix strategy

```
# if you want to run a job in different environments 
job:
	job-1:
		strategy:
			fail-fast: false  # change the default behaviour if a job failed
			max-parallel: 3
			matrix:
				os: 
				- ubuntu-latest
				- windows-latest
				- macos-latest
				node_version:
				- 14.x
				- 15.x
				- 16.x
		runs-on: ${{ matrix.os }}
		steps:
		- uses: actions/setup-node@v3.6.0
		  with:
			node-version: ${{ matrix.node_version }}  # loops on node versions on each os
```


## Expressions and context


``` yaml
# expressions are conditions
on: 
	workflow_dispatch:
jobs:
	my-expressions: # job name
		runs-on: ubuntu-latest
		steps:
		- name: print a message
		  run: echo "The job is running"
		  if: ${{ github.even_name != 'push' && 1 && !0}}
```

###### Function can be used in expressions (if)
- contains(variable name , value)
- startsWith( variable name, value) 
- success()  -> Checks if **all previous steps or jobs succeeded**
- failure() -> Checks if **any previous step failed**
- always() -> Runs the step **regardless of success, failure, or cancellation** of previous steps
- cancelled() -> Checks if the workflow was **manually cancelled or interrupted**

## Workflow commands

``` yaml
on: 
	workflow_dispatch:
jobs:
	my-command:
		runs-on: ubuntu-latest
		steps:
		- run: | 
		     deprecated = true
		     if [[ deprecated ]]; then
			     echo "::warning:: my warninig message"
			 fi    
```

###### some other commands
`::debug:: message`
`::error::message`
`::add-mask::$env_var` -> make a mask for an environmental variable any use after this command will be masked


###### some ENVs
`$GITHUB_ENV` -> set environmental variable
``
> any created variable in a step is not propagated in the next other steps
> to propagate a variable use $GITHUB_ENV

