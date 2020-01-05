#!/bin/bash

echo -e "\tTo-Do-List:"
grep "TODO" **/*.[chs]* | sed -r "s/(.*):.*[ ]*TODO(.*)/\1\t\2/g"
