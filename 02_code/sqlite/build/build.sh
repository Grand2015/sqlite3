#!/bin/bash

echo "BEGIN TO COMPILE..."

build_path=$(cd "$(dirname "$0")"; pwd)
root_path=$(dirname $(pwd))
#echo ${root_path}
inc_path=${root_path}/include/
#echo ${inc_path}
src_path=${root_path}/src/
lib_path=${root_path}/lib/
#echo ${src_path}

output_path=${root_path}/output/
#echo ${output_path}
cd ${output_path}
#pwd


#gcc -c 

if [[ $1 == "-g" ]]; then
	[ -e ${output_path}/gcore ] && rm ${output_path}/gcore
	gcc -I ${inc_path} -g ${src_path}/main.c -o gcore -L ${lib_path} -lsqlite3 -ldl -lpthread
	[ -e ${output_path}/gcore ] && echo "COMPILE gcore SUCCESSFULLY !"
else
	[ -e ${output_path}/core ] && rm ${output_path}/core
	gcc -I ${inc_path} ${src_path}/main.c -o core -L ${lib_path} -lsqlite3 -ldl -lpthread
	[ -e ${output_path}/core ] && echo "COMPILE core SUCCESSFULLY !"
fi

echo "BUILD SUCCESSFULLY !"

