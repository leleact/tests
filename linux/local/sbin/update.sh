#!/usr/bin/env bash

# UPDATE INFO

DESTIN=$HOME/log/update.log

if [ "x$HOSTNAME" == "xcentos-server" ]; then
    PLATFORM=centos
    if [ -f ~/.bashrc ]; then
        source $HOME/.bashrc
    fi

    if [ -f ~/.bash_profile ]; then
        source $HOME/.bash_profile
    fi

    echo ""                                                   >> $DESTIN 2>&1
    echo "$PLATFORM $(date +%F_%H:%M:%S:%N) yum update begin" >> $DESTIN 2>&1
    yum update -y                                             >> $DESTIN 2>&1
    echo "$PLATFORM $(date +%F_%H:%M:%S:%N) yum update end"   >> $DESTIN 2>&1
    echo ""                                                   >> $DESTIN 2>&1

elif [ "x$HOSTNAME" == "xubuntu-server" ]; then
    PLATFORM=ubuntu
    if [ -f ~/.bashrc ]
    then
        source $HOME/.bashrc
    fi

    if [ -f ~/.profile ]; then
        source $HOME/.profile
    fi

    echo ""                                                    >> $DESTIN 2>&1
    echo "$PLATFORM $(date +%F_%H:%M:%S:%N) apt upgrade begin" >> $DESTIN 2>&1
    apt upgrade -y                                             >> $DESTIN 2>&1
    echo "$PLATFORM $(date +%F_%H:%M:%S:%N) apt upgrade end"   >> $DESTIN 2>&1
    echo ""                                                    >> $DESTIN 2>&1
fi
