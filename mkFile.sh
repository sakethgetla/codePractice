#!/bin/bash

# make a new file and write the time of the creation at the top
# and the name of the function

if [ "$1" != "" ]; then
    if [ -f $1.py ]; then
        echo "$1.py file already exists"

    else
        touch $1.py
        echo "# leetCode question, ans by saketh" >> $1.py
        echo -n "# " >> $1.py 
        date >> $1.py 
        echo "" >> $1.py
        echo "def $1():" >> $1.py
        echo "    pass" >> $1.py
    fi

else
    echo "useage sh mkFile.sh [filename].py"
fi
