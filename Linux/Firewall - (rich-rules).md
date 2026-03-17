
### Syntax

### add rule
```bash
firewall-cmd [--zone=zone] --add-rich-rule='rule' [--timeout=timeval]
```

### remove rule
```bash
firewall-cmd [--zone=zone] --remove-rich-rule='rule'
```
### Rich rule syntax
``` bash
rule [family="rule family"]
    [ source [NOT] [address="address"] [mac="mac-address"][ipset="ipset"] ]
    [ destination [NOT] address="address" ]
    [ element ]
    [ log [prefix="prefix text"] [level="log level"] [limit value="rate/duration"] ]
    [ audit ]
    [ action ]
    ```

#### rich rules keywords

