#! /bin/sh

echo ""
echo "================================================"
echo $(date +%F_%H:%M:%S:%N) : update git start

WORK_PATH=~/projects

cd $WORK_PATH

for dir in `ls`
do
    if [ -d $dir ]
    then
        cd $dir
        echo `pwd`
        if [ -d .git ]
        then
            git fetch origin && git submodule update --init --recursive
            git pull
        fi
        cd ..
    fi
done
echo "================================================"
echo $(date +%F_%H:%M:%S:%N) : update git end
echo ""
echo ""
