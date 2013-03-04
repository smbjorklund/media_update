# Course-server

The course-server is installed on attilatest.uib.no in the directory
/var/www/w3-kurs.uib.no. The setup is compleatly seperate from the 
stagingserver, with its own DB and filestorrage.

## Sync live to couse.

A nightlig DB dump and the file storrage is availeble from:

  * /net/ng01.uib.no/vol/w3_fillager/pg_dump/w3.uib.no.sql
  * /net/ng01.uib.no/vol/w3_fillager/sites/w3.uib.no/files
  * /net/ng01.uib.no/vol/w3_fillager/sites/w3.uib.no/private

### Step 1
Copy the files:
  <code>rsync -Pah --delete \
  /net/ng01.uib.no/vol/w3_fillager/sites/w3.uib.no/files/ \
  /nettapp_w3/sites/w3-kurs.test.uib.no/files/</code>
  
### Step 2
Start DB-cli
  <code>bin/site-drush sql-cli</code>

import the database-dump
  <code>\i 
  /net/ng01.uib.no/vol/w3_fillager/pg_dump/w3.uib.no.sql</code>
  
### Step 3
Fix file-paths
Go to https://w3-kurs.test.uib.no/en/admin/config/media/file-system
<code>set Public file system path = sites/w3-kurs.test.uib.no/files
set Private file system path = ../var/private</code>

### Step 4
Fix file premitions


