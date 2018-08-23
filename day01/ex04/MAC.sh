ifconfig | grep ether | tr -d " \t" | awk 'NR!=2' | sed "s/ether//g"
