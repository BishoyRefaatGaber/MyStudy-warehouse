URL -> Unified Resource Locator

`http://www.google.com/index?id=1&name=ali`

`http://` -> protocol
`www.google.com` -> host
`/index` -> URL-path
`?id=1&name=ali` -> query string


- Responses
	- 1xx -> information
	- 2xx -> success
	- 3xx -> redirection
	- 4xx -> client error
	- 5xx -> server error
	- ex
		- 200 -> ok
		- 401 -> Unauthorized
		- 403 -> Forbidden
		- 404 -> not found
		- 500 -> internal server error


### Multi Processing Module (MPM)
##### prefork MPM
- only recommended for users who need to run a non-thread-safe library
- parent process uses `fork()` to pre-fork a pool of child processes at startup time
- Each idle process joins a queue to listen for incoming requests
- uses a method calls accept mutex to ensure that only one process listens for and accepts the next TCP request



##### Worker MPM
- works with thread-safe applications
- the parent process forks a constant number of child processes and each chiled creates a constant number of worker thread and a listener thread
- in each child process if at least one worker thread is idle the listener will join the idle queue

##### Event MPM
- same as worker mpm but the io is processed by the listener

### concepts

- `.htaccess` -> 
	- It allows administrators and users (especially on shared hosting) to override global Apache settings for a specific directory without modifying the main Apache configuration file (`httpd.conf`)
- `mod_rewrite` -> used in redirection
	- provides a way to do URL manipulation using regex 
	- `RewriteEngine on|off` -> turn the engine on or off
	- `RewriteRule <pattern> <subtitution> [Flags]`
	- `[Flags]` -> \[R=301\] 
- `RewriteCond TestString Condition [Flags]` -> conditional rewrite
- certificate -> contain public key + some information
- `x509` -> certificate type needed for apache
- `mod_ssl` -> module used for making httpd work with https
- `SSLCertificateKeyFile`
- `SSLCertificateFile`


> apache uses standard io to write in log files so when you delete the log file it will not be deleted

> to reflect the deletion  restart httpd 

