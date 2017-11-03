#! /bin/bash

source ./config.cfg

if [[ $1 == "-h" ]] ; then
	echo "Support languages:"
	cat config.cfg
	exit 1
fi

if [[ $# -lt 3 ]] ; then
	echo "Too less arguments... [lang] [pathtocode] [task_id]"
	echo "Also, you can run it with -h for help."
	exit 1
fi


LANG=$1
TEXT=$2
TASK_ID=$3


cp ../problems/$TASK_ID/input.txt ./input.txt
cp ../problems/$TASK_ID/output.txt ./sample.txt

if [[ ! -z ${compile[$LANG]} ]] ; then
	"${!LANG}" ../solutions/$TASK_ID/$TEXT -o runnable
	./runnable < input.txt  > output.txt 
	rm runnable
else
	../solutions/$TASK_ID/$TEXT < input.txt  > output.txt 
fi

diff -q sample.txt output.txt
