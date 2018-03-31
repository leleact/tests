#! /bin/sh
#
# mysqldump --host=$HOST --user=$USER --password=$PASSWD --default-character-set=utf8 --databases=$DATABASE [TABLENAME] --where=...
#

while getopts :e:d:s: OPTION
do
    case $OPTION
        in
        e) ENVIROMENT=$OPTARG
            ;;
        d) DATABASE=$OPTARG
            ;;
        s) STATEMENT=$OPTARG
            ;;
        ?) echo "Please use $0 -e <ENVIROMENT> -d <DATABASE> -s <STATEMENT>"
            exit;;
        :) echo "Please use $0 -e <ENVIROMENT> -d <DATABASE> -s <STATEMENT>"
            exit;;
        *) echo "Please use $0 -e <ENVIROMENT> -d <DATABASE> -s <STATEMENT>"
            exit;;
    esac
done

echo $@
echo $#


if [ "$ENVIROMENT"x = "MAT"x ]
then
#   HOST=rdszae1o31p011xz072y6.mysql.rds.dcp.dev.ect-it.com
    HOST=11.12.12.104
    USER=psbmgmdb
    PASSWD=admin1234
    if [ -z "$DATABASE" ]
    then
	    DATABASE=psbmgmdb
    fi
else
#   HOST=rds5t5vnwoc1o3vs5lucz.mysql.rds.dcp.dev.ect-it.com
    HOST=11.12.12.220
    USER=psbmdb
    PASSWD=123456
fi

CHARACTER=utf8
mysql --host=$HOST --user=$USER --password=$PASSWD --default-character-set=$CHARACTER $DATABASE --execute "$STATEMENT"
