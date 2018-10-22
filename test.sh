#!/bin/bash
GRN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

for filename in test/*.c; do
    echo -e ${GRN} "\nTesting file $filename:\n" ${NC}
    ./linter $filename
done