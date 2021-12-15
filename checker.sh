#!/bin/bash

files=$(ls -b "$2" | grep ".in")
for x in $files
do
	echo -n "Checking $x... "
	timeout 4 ./$1 < "$2"/"$x" 1>/dev/null
	time_o=$?
	if [[ $time_o = 124 ]]
	then
		echo "timeout"
		break
	fi
	p_out=$(valgrind --log-file=/tmp/valgrind.out ./$1 < "$2"/"$x")
	ris=$(cat "$2"/"$(echo $x | sed s/\.in/\.ans/)")
	size=$(cat /tmp/valgrind.out | grep "total heap usage" | awk '{print $(NF-2)}' | sed s/,//g)
	if (( $size > 419430400 ))
	then
		echo "memory exceeded: $size bytes used"
		break
	fi
	if [ "$p_out" == "$ris" ]
	then
		echo "correct"
	else
		echo "wrong"
	fi
	rm /tmp/valgrind.out
done
