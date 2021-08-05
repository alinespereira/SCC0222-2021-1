#!/bin/bash

set -e

BASEPATH=$(dirname $0)

for f in $(ls $BASEPATH/L03E01TestCases/*.in)
do
    $BASEPATH/L03E01 < $f
done