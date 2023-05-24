#!/bin/bash

gcc -c -Wall -Werror -fpic *.c
gcc -shared -o liball.so *.o

# Clean up object files
rm *.o
echo "Dynamic library liball.so created successfully!"
# gcc -fPIC -c *.c
# gcc -shared -Wl,-soname,liball.so -o liball.so *.o
