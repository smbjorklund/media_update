#!/bin/bash

# copies ressider (ansattsider) DB from ressider.pg.uib.no to glory
#set -x

export PGPASSWORD=`/usr/bin/sudo -u iaauth /var/www/lib/php/uib/bin/getAuth ressider.pg.uib.no-user |cut -d: -f3`

# dump in restore format
pg_dump -Fc -b -v -h ressider.pg.uib.no -U ressider_user ressider > /tmp/dump.ressider.sql.restore

# remove some (unneeded) elements that user1 don't have permission to create like comments
pg_restore -l /tmp/dump.ressider.sql.restore | grep -v "plpgsql" > /tmp/ressider.elements

# drop database ressider
export PGPASSWORD=`/usr/bin/sudo -u iaauth /var/www/lib/php/uib/bin/getAuth glory.pg.user |cut -d: -f3`
dropdb -h glory -U user1 ressider

# (re)store db on glory
pg_restore -v -e --no-owner --no-acl -h glory -U user1 --create --dbname=template1 -L /tmp/ressider.elements /tmp/dump.ressider.sql.restore

echo "DONE!"
