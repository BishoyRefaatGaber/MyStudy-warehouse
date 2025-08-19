
- local server 

$ mosquitto_sub -v -t test/message
$ mosquitto_pub -t test/message -m 'Hello World!'

$ sudo /etc/init.d/<service-name> start
$ sudo /etc/init.d/<service-name> stop
$ sudo /etc/init.d/<service-name> restart
$ sudo /etc/init.d/<service-name> status



```bash
mosquitto_sub -h dbeaa090ca264a12bc6f41466055816a.s2.eu.hivemq.cloud -p 8883 -u MEE11 -P bishsha12 -t my/test/topic
```

```bash
mosquitto_pub -h dbeaa090ca264a12bc6f41466055816a.s2.eu.hivemq.cloud -p 8883 -u MEE11 -P bishsha12 -t 'my/test/topic' -m 'Hello'
```
