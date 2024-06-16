var=$1
if test -e $var
 then
    echo $var
	rm $var
else
	echo $var does not exist
fi
