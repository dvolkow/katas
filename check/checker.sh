#! /bin/bash

source ./config.cfg

if [[ $1 == "-h" ]] ; then
	echo "Support languages:"
	cat config.cfg
	exit 1
fi

if [[ $# -lt 2 ]] ; then
	echo "Too less arguments... [lang] [pathtocode]"
	echo "Also, you can run it with -h for help."
	exit 1
fi


LANG=$1
TEXT=$2

"${!LANG}" $TEXT -o runnable
./runnable
rm runnable
