#!/bin/bash

echo "BEGIN TO RUN CORE..."

shell_path=$(cd "$(dirname "$0")"; pwd)
root_path=$(dirname $(pwd))
#echo ${root_path}
inc_path=${root_path}/include
src_path=${root_path}/src
lib_path=${root_path}/lib
output_path=${root_path}/output
#echo ${output_path}
#pwd

cd ${output_path}
pwd

#[ -e user ] && rm user
#ls -al

if [[ $1 == "-g" ]]; then
	if [ ! -f ${output_path}/gcore ]; then
		echo "ERR:${output_path}/gcore No such file or directory." 
		exit
	fi
	gdb ${output_path}/gcore
else
	if [ ! -f ${output_path}/core ]; then
		echo "ERR:${output_path}/core No such file or directory." 
		exit
	fi
	./core
fi
#ls -al

