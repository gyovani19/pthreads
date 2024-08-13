#!/bin/bash
valid=true
count=1
while [ $valid ]
do
    echo $count
    if [ $count -eq 100 ];
    then
        break
    fi
    count=$((count + 1))
    sleep 2
done