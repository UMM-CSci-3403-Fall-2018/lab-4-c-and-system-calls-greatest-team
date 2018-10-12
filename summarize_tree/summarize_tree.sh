#!/bin/bash

cd $1
echo "There were `find . -type d | wc -l | xargs` directories."
echo "There were `find . -type f | wc -l | xargs` regular files."
