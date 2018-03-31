#! /bin/sh

if [ $# -ne 1 ]
then
	echo "please use git.sh like git.sh xxx[comment]"
	exit
fi

echo "git add ."
git add .;
echo "git commit -m \"$1\""
git commit -m "$1";
echo "git push origin master"
git push origin master;
echo "git done!"
