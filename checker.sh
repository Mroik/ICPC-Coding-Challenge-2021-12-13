#!/bin/bash

files=$(ls -b "$2" | grep ".in")
for x in $files
do
	echo -n "Checking $x... "
	p_out=$(./$1 < "$2"/"$x")
	ris=$(cat "$2"/"$(echo $x | sed s/\.in/\.ans/)")
	if [[ "$p_out" -eq "$ris" ]]
	then
		echo "correct"
	else
		echo "wrong"
	fi
done
