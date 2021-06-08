#!/bin/bash
sed -e 's#^.*//.*$##' < main.c |  # Strip comments
     tr -d '\n' |  # Delete newlines
     sed -e 's/ \+/ /g' |  # Squash spaces
     sed -e 's/, /,/g' |  # Remove argument spaces
     tr ' ' '#' | # Translate spaces
     awk 'BEGIN {print "const int f = 1;\nconst char *l = \\"} { print "\"" $0 "\";\n\n" }' > minify.c

cat minify.c main.c > packed.c

gcc packed.c -o run1 && 
./run1 > run1.out.c &&
gcc run1.out.c -o run2 &&
./run2 > run2.out.c &&
gcc run2.out.c -o run3 &&
./run3 > run3.out.c

echo Executing similarity check....

diff run{1,3}.out.c

if [[ $? -eq 0 ]]; then
    echo Passed successful
    exit 0
else
    echo "Error: Differences detected."
    exit -1
fi
