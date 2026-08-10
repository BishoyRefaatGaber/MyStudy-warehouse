
## Introduction to GitHub Actions

**GitHub Actions** is a **CI/CD pipeline directly integrated with your GitHub repository**.

GitHub Actions allows you to automate:

- Running test suites
- Building images
- Compiling static sites
- Deploying code to servers
- and more…

GitHub Actions has **templates** you can use to get started.

GitHub Actions files are defined as YAML files located in the **.github/workflow** folder in your repo.

You can have multiple workflows in the repo triggered by different events.

Within a GitHub repo, you’ll have a **tab for Actions**.

```
on
  push:
    branches: | $default-branch |
  workflow_dispatch:
env:
  AZURE_WEBAPP_NAME: your-app-name
  AZURE_WEBAPP_PACKAGE_PATH: '.'
  NODE_VERSION: '14.x'
permissions:
  contents: read
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    ...
```

## Default environment variables
- GitHub sets are available to every step in a workflow.
- Because default environment variables are set by GitHub and not defined in a workflow, they are not accessible through the `env` context.
- You can't overwrite the value of the default environment variables named `GITHUB_*` and `RUNNER_*`.

## secrets scopes
- a single repo
- an environment in a repo
- the entire organization, ot selected reposatories in an organization

## defaults

- Use `defaults` to create a `map` of default settings that will apply to all jobs in the workflow.
- You can use `defaults.run` to provide default `shell` and `working-directory` options for all `run` steps in a workflow. You can also set default settings for `run` that are only available to a job.
- Use `concurrency` to ensure that only a single job or workflow using the same concurrency group will run at a time.
- 
- 