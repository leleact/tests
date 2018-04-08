#!/bin/env bash

echo ""
echo "================================================"
echo $(date +%F_%H:%M:%S:%N) : 备份开始

WORKPATH=/home/lele
BACKPATH=$WORKPATH/.local/var/backup
GIT_REPO=${WORKPATH}/projects/repo.txt
$(ls -l ${WORKPATH}/projects > ${GIT_REPO})

cd ~
DATE=`date +%F_%H%M%S`
tar -czvf ${BACKPATH}/lele_home_bak_${DATE}.tar.gz \
    .ssh \
    .bashrc \
    .bash_profile \
    .vimrc \
    .local/usefull/ \
    projects/ufp/ \
    ${GIT_REPO} \
    /etc/profile.d/ \
    /etc/bashrc \
    .ycm_extra_conf.py \
    --exclude-tag VAR.TAG

rm -f ${GIT_REPO}

# delete date that exist 2 days at least
cd ${BACKPATH}
find . -name "*.tar.gz" -mtime +2 -exec rm -f {} \;

echo "================================================"
echo $(date +%F_%H:%M:%S:%N) : 备份结束
echo ""
echo ""
