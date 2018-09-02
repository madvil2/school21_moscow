where_am_i=$(ifconfig | grep inet | grep broadcast | cut -d ' ' -f 2)
if [ $where_am_i = '' ]
then
	echo "I am lost!"
else
	echo $where_am_i
fi