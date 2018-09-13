#!/bin/sh
find . -maxdepth 1 | cut -c 3- | grep -v "^\." | sed -e '1,1d'
