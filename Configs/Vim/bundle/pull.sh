#!/bin/bash

# Simple script for updating all of Vim's
# bundled plugins (used by Pathogen).
#   @author Jean-Marie Comets
#   @date 2012-08-15

i=1
for f in *
do
    if [ -d "$f" ]; then
        cd "$f" && echo "[$i] Entering directory $f..."
        git pull
        cd .. && echo "[$i] Leaving directory $f..."
        i=`expr $i + 1`
    fi
done
