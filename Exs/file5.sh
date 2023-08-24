#!/bin/bash

echo "Enter the pattern to search for:"
read pattern

cwd=$(pwd)

for file in "$cwd"/*; do
    if [ -f "$file" ]; then
        if grep -q "$pattern" "$file"; then
            echo "$file: Pattern found"
        else
            echo "$file: Pattern not found"
        fi
    fi
done
