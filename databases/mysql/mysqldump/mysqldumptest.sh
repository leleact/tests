

#/bin/sh

mysqldump -u${USER} -p${PASSWD} -h${HOSTNAME} ${DBNAME} /* ${TABLE_NAME} */ > db.dump;
