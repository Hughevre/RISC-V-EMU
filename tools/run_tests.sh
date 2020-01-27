#!/bin/bash

EXE=$(pwd)"/../bin/V-RISCV"
TESTS_DIR=$(find ../tests -name 'test' | sed 's/\/[^/]*$//')

if [[ -e ${EXE} ]]
then
    for dir in ${TESTS_DIR[@]}
    do
        (cd ${dir}
        echo "> Running test: ${PWD##*/}"
        ${EXE} > /dev/null)
    done
else
    echo "> ${EXE} not found."
fi