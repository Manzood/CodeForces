#!/bin/bash
set -e

for ((i=1;;i++)) do
	echo $i
	./gen $i > in
    ./C < in
done
