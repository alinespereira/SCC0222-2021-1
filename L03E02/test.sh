#!/bin/bash

set -e

BASEPATH=$(dirname $0)

for f in $(ls $BASEPATH/L03E02TestCases/*.in)
do
    echo "Test running: $f"
    OUTFILE="$(echo $f | sed -e 's/in/out/')"
    TESTFILE="$(echo $f | sed -e 's/in/test/')"
    $BASEPATH/L03E02 < $f > $TESTFILE
    diff -u $OUTFILE $TESTFILE
done
