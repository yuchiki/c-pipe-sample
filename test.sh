#!/bin/bash
set -eux


make
echo

echo "=====普通に使った場合===="
./yuchiki-sorter 2309 2342 5748 123 32478 1 324 094875
echo

echo "====redirectされた場合===="
./yuchiki-sorter 2309 2342 5748 123 32478 1 324 094875 > file.txt
cat file.txt
