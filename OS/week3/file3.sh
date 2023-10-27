#!/bin/bash
FILE="/home/ishaan/Documents/college/os/Exs/file1.sh"
if [ -f "$FILE" ]; then
    if [ -x "$FILE" ]; then
        echo "executable"
    else
        echo "not exec"
    fi
else
    echo "nope"
fi
