

# install GitLab runners 

### install docker 
download docker-ce docker-ce-cli containerd.io docker-buildx-plugin
sudo dnf install /path/to/package.rpm
sudo systemctl enable --now docker

## install the runner and runner helper 
curl -LJO "https://s3.dualstack.us-east-1.amazonaws.com/gitlab-runner-downloads/latest/rpm/gitlab-runner-helper-images.rpm"
curl -LJO "https://s3.dualstack.us-east-1.amazonaws.com/gitlab-runner-downloads/latest/rpm/gitlab-runner_${arch}.rpm"
dnf install -y gitlab-runner-helper-images.rpm gitlab-runner_<arch>.rpm


create an instance runner:

In the upper-right corner, select Admin.
In the left sidebar, select CI/CD > Runners.
Select Create instance runner.
Select the operating system where GitLab Runner is installed.
In the Tags section, in the Tags field, enter the job tags to specify jobs the runner can run. If there are no job tags for this runner, select Run untagged.
Optional. In the Runner description field, to add a runner description that displays in GitLab, enter a runner description.
Optional. In the Configuration section, add additional configurations.
Select Create runner.

