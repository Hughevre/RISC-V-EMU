#!/bin/bash

EXE="../bin/V-RISCV"
TESTS_DIR=$(ls ../tests/t_*/test | sed 's/\/[^/]*$//')

if [[ -e ${EXE} ]]
then
    for dir in ${TESTS_DIR[@]}
    do
        (cd ${dir}
        echo "> Running test: ${PWD##*/}"
        ./../${EXE})
    done
else
    echo "> ${EXE} not found."
fi