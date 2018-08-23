cat /etc/passwd | cut -d : -f 1 | sed '/^#/ d' | awk 'NR>= ENVIRON[ "FT_LINE1" ] && NR<= ENVIRON[ "FT_LINE2" ]' | rev | sort -r | tr '\n' ',' | sed 's/, */, /g' | sed 's/, $/./'
