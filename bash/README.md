# Bash Tutorial

## while
``` bash
#! /usr/bin/env bash
retry_count=0
while [ $retry_count -lt 3 ]
do
    touch $(date +%F)
    if [ $? -eq 0 ]
    then
        retry_count=$(expr $retry_count + 1)
        echo $retry_count
    fi
done
```
