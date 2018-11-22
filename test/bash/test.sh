#!/bin/bash
GRN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e ${GRN} "\nTesting good files\n" ${NC}
for filename in test/good/*.c; do
    echo -e ${GRN} "\nTesting file $filename:\n" ${NC}
    ./linter $filename
done

echo -e ${GRN} "\nTesting bad files\n" ${NC}
for filename in test/bad/*.c; do
    echo -e ${GRN} "\nTesting file $filename:\n" ${NC}
    ./linter $filename
done