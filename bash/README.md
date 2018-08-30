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

## getopts
``` bash
#!/bin/bash

usage() { echo "Usage: $0 [-s <45|90>] [-p <string>]" 1>&2; exit 1; }

while getopts ":s:p:" o; do
    case "${o}" in
        s)
            s=${OPTARG}
            ((s == 45 || s == 90)) || usage
            ;;
        p)
            p=${OPTARG}
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))

if [ -z "${s}" ] || [ -z "${p}" ]; then
    usage
fi

echo "s = ${s}"
echo "p = ${p}"
```

## getlongopts
``` bash
#! /bin/env bash

set -e

while true; do
    case "$1" in
        -v | --verbose )  VERBOSE=true; shift ;;
        -d | --debug ) DEBUG=true; shift ;;
        -m | --memory ) MEMORY="$2"; shift 2 ;;
        --debugfile ) DEBUGFILE="$2"; shift 2 ;;
        --minheap )
            JAVA_MISC_OPT="$JAVA_MISC_OPT -XX:MinHeapFreeRatio=$2"; shift 2 ;;
        --maxheap )
            JAVA_MISC_OPT="$JAVA_MISC_OPT -XX:MaxHeapFreeRatio=$2"; shift 2 ;;
        -- ) shift; break ;;
        * ) break ;;
    esac
done

echo "verbose $VERBOSE"
echo "debug $DEBUG"
echo "memory $MEMORY"
```
