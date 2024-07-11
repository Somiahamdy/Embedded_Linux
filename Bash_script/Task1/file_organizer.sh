#!/bin/bash

create my directories 
mkdir $1/images
mkdir $1/documents
mkdir $1/others

#get directory files
mydir=$(ls $1)

for file in $mydir;
do
        ext="${file##*.}"
        if [ -d $file ] ; then   #ignore directories
        continue
	elif   [ $ext = png ] || [ $ext = jpg ] || [ $ext = gif ] ; then
		mv $1/$file $1/images/
                echo "hello picture $ext"
	elif  [ "$ext" = docs ] || [ "$ext" = pdf ]  || [ "$ext" = txt ]; then 
		mv $1/$file $1/documents/
                echo "hello doc"
	else 
	       mv $1/$file $1/others/
               echo "hello other $ext"
	fi 
done 
