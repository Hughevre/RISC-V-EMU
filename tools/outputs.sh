#!/bin/bash

OUT_DIRS=../tests/

dirs=$(find ${OUT_DIRS} -name '*file_reg_in*' | sed 's/[^/]*$//' | uniq)


CMPREG=cmp_regs


[[ -d ${CMPREG} ]] || mkdir -p ${CMPREG}



for d in ${dirs}
do
    file=${CMPREG}/"cmp_"$(echo ${d} | sed 's/\/[^/]*$//' | sed 's/.*\/\([^/]*\)$/\1/').txt
    > $file
    echo "Directory: ${d}" >> $file
    python3 compare.py ${d}file_reg_out.bin >> $file
    echo "" >> $file
done


dirs=$(find ${OUT_DIRS} -name '*file_data_in*' | sed 's/[^/]*$//' | uniq)

CMPDAT=cmp_data


[[ -d ${CMPDAT} ]] || mkdir -p ${CMPDAT}



for d in ${dirs}
do
    file=${CMPDAT}/"cmp_"$(echo ${d} | sed 's/\/[^/]*$//' | sed 's/.*\/\([^/]*\)$/\1/').txt
    > $file
    echo "Directory: ${d}" >> $file
    python3 compare.py ${d}file_data_in.bin ${d}file_data_out.bin >> $file
    echo "" >> $file
done
