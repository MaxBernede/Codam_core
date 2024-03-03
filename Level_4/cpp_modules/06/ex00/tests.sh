#!/bin/sh

# ANSI color codes
GREEN='\033[0;32m'
NC='\033[0m'

./exe lorem
./exe c a
./exe 0 -42 42
./exe 332 111 114.2 -155.3 109.00
./exe 0.0f -4.2f 4.2f
./exe -inff +inff nanf
./exe -inf +inf nan
./exe 0 nan 42.0f
echo "${GREEN}test with int max ${NC}"
./exe 2147483647 2147483648 -2147483648 -2147483649 #int max
echo "${GREEN}test with float max ${NC}"
./exe 3.40282e+38 1.17550e-38 3.40283e+38 1.17549e-38 #float max
echo "${GREEN}test with double max ${NC}"
./exe 1.79769e+308 2.22508e-308 1.79770e+308 2.22507e-308 #double max