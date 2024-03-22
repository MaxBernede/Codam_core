#!/bin/sh
# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "${GREEN}Test work${NC}"
./PmergeMe 3 5 9 7 4

echo "${RED}Test negative number${NC}"
./PmergeMe 3 -5 9 7 4

echo "${RED}Test positive overflow${NC}"
./PmergeMe 3 0 9 7 4 2147483648

echo "${RED}Test negative overflow${NC}"
./PmergeMe 3 0 9 7 4 -2147483649

echo "${RED}Test not a number${NC}"
./PmergeMe 3 0 9 7 a

echo "${GREEN}Test 2 : ./PmergeMe shuf -i 1-100000 -n 3000 | tr "\n" ${NC}"
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`


