#!/bin/bash
echo "$# arguments: $1 $2 $3 $4 $5"
echo "-------------"
if [ `echo "$#"` == 1 ]
then
    echo "$1\n..."
fi
while [ `echo "#$"` ]
do
    echo -e "$1\n$2\n..."
    echo -e "-------------"
    echo -e "$1. $2. $3. $4. $5."
    echo -e "-------------"
    echo -n "$1 $2 $3 $4 $5"
    shift 1
    echo -n "... wait for it..."
    break
done
