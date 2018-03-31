# /bin/bash

if [ $1 == "" ]
then
	PROJECT_NAME="temp"
else
	PROJECT_NAME=$1
fi

if [ -d $PROJECT_NAME ]
then
	echo "project [$PROJECT_NAME] have been existed, please change another project name!"
	exit
fi

mkdir -p $PROJECT_NAME
SRC_FILE=$PROJECT_NAME.py

cd $PROJECT_NAME && cat >> $SRC_FILE << EOF
#!/usr/bin/env python
#-*- encoding:utf-8 -*-
if __name__ = '__main__':

EOF

chmod +x $SRC_FILE
