# gcc -fPIC -c *.c
# gcc -shared -Wl,-soname,liball.so -o liball.so *.o

#!/bin/bash

# Compile all .c files into object files
gcc -c -Wall -Werror -fpic *.c

# Create the dynamic library
gcc -shared -o liball.so *.o

# Clean up object files
rm *.o

# Optional: Move the library to a desired location
# mv liball.so /path/to/destination

echo "Dynamic library liball.so created successfully!"

