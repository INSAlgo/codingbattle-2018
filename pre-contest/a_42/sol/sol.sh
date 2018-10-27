#!/bin/bash

TARGET=42

read N

if [ "$N" -gt "$TARGET" ]; then
    echo "Less"
elif [ "$N" -lt "$TARGET" ]; then
    echo "More"
else
    echo "Bingo!"
fi
