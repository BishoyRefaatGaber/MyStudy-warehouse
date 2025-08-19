
#### Declarative

some plugins needed 
- credentials -> allows storing credentials in jenkins
- credentials binding -> allows credentials to be bound to environmental variables for use 

/env-vars.html/  --> to get all predefined variables


ngrok -> expose the jenkins to network for webhook


/var/jenkins_home/secrets/initialAdminPassword 

docker run -d   --name jenkins   -p 8080:8080 -p 50000:50000   -v /var/jenkins_home:/var/jenkins_home   -v /var/run/docker.sock:/var/run/docker.sock   -v /usr/bin/docker:/usr/bin/docker   --group-add 994   jenkins/jenkins



``` Groovy
def gv
pipeline{
	agent any
	environment{
		VERSION = "1.0.0"
		SERVER_CRED = credentials('credential-ID')
	}
	parameters {
		string(name: "VERSION", defaultValue: "1.0.0.0", description: "")
		text(name: "fff", defaultValue: "1.0.0.0", description: "")	
		choice(name: "", defaultValue: ["1","2"],description: "")
		booleanParam(name: "", defaultValue: true,description: "")
	}
	tools /*Access build tools for your projects like maven Gradle yarn*/{
		maven "Maven" /*tool name*/
		jdk
		gradle	
	}
	stages{
		stage("name"){
			when {
				expression {
					params.VERSION == "1.0.0.0"
				}
			}
			steps{
				script{
					gv = load "srpt.groovy"
				}
				echo "hi"
				sh "mvn install"  /*I can use mvn due as I defined tools*/
			}
		}
		
		stage("name"){
			steps{
				echo "hi"
				echo "${SERVER_CRED}"
			}
			post {
				always {
					echo "always"
				}
				
				failure {
					echo "failure"
				}
				
				success {
					echo "success"
				}
			}
		}
		post {}
		stage("name"){
			/*[] -> for object*/
			withCredentials([
				usernamePassword(credentials: 'cred-name', usernameVariable: USER, passwordVariable: PWD)
			]){
				echo "${USER}  ${PWD}"
			}
			steps{
				echo "hi"
			}
		}
	}
}
```
