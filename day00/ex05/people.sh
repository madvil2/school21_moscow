#bin/sh
ldapsearch -LLL -Q  "uid=z*" cn | cut -d : -f 2 | grep -v '^$' | awk 'NR%2==0' | sort -r --ignore-case
