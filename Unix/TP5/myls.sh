#!/bin/sh
find . -maxdepth 1 | cut -c 3- | sed '/^$/d' | grep -v "^\."
find . -maxdepth 1 -type d | cut -c 2- | sed '/^$/d' | grep -v "^\." | sed 's/\//+/'
