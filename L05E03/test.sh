#!/bin/bash

# set -e

BASEPATH=$(dirname $0)

for f in $(ls $BASEPATH/TestCases/*.in)
do
    echo "Test running: $f"
    OUTFILE="$(echo $f | sed -e 's/in/out/')"
    TESTFILE="$(echo $f | sed -e 's/in/test/')"
    $BASEPATH/L05E03 < $f > $TESTFILE
    diff -y $OUTFILE $TESTFILE
done
