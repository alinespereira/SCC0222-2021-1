#!/bin/bash

# set -e

BASEPATH=$(dirname $0)
TESTFOLDER="TestCases"

if [ -z "$1" ]
then
    for f in $(ls $BASEPATH/$TESTFOLDER/*.in)
    do
        echo "Test running: $f"
        OUTFILE="$(echo $f | sed -e 's/in/out/')"
        TESTFILE="$(echo $f | sed -e 's/in/test/')"
        $BASEPATH/L04E04 < $f > $TESTFILE
        diff -y $OUTFILE $TESTFILE
    done
else
    INFILE="$TESTFOLDER/$1.in"
    OUTFILE="$TESTFOLDER/$1.out"
    TESTFILE="$TESTFOLDER/$1.test"
    $BASEPATH/L04E04 < $INFILE > $TESTFILE
    diff -y $OUTFILE $TESTFILE
fi
