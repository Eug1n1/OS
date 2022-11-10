#!/bin/bash

dir=/proc/$1

if [ "$1" = "" ]; then
    echo "parameters not found"
    exit 1
fi

if ! [ -d "$dir" ]; then
    echo "$1 process not found"
    exit 1
fi

file=$dir/status

echo $(cat $file | grep Name)
echo $(cat $file | grep ^Pid)
echo $(cat $file | grep PPid)

if [[ "$2" == "" || "$2" != "fd" ]]; then
    exit 0
fi

fd=$(ls $dir/fd)

for i in $fd ; do
    echo "fd = $i"
done
