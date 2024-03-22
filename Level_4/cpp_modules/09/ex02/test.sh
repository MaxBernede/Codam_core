#!/bin/sh
# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "Test 1 : 3 5 9 7 4"
./PmergeMe 3 5 9 7 4

echo "Test 2 : ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`"
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`


