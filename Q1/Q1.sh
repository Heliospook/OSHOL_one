#Program Number : 1
#Name : Subhajeet Lahiri
#Register Number : IMT2021022 
#Date : 24/2/23
#Description : Creates softlink, hardlink and fifo files

#!/bin/bash

echo "Select operation : 1) softlink 2) hardlink 3) fifo"
read option

case $option in 
    "1")    echo -n "Enter filename : "
            read filename
            ln -s $filename softlink
    ;;
    "2")    echo -n "Enter filename : "
            read filename
            ln $filename hardlink;
    ;;
    "3")    echo -n "Enter pipename : "
            read pipename
            mkfifo $pipename
    ;;
esac




