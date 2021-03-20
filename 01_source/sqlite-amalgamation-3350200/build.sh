#!/bin/bash


function build_sqlite3()
{
	gcc -c ${cur_dir}/sqlite3.c
	ar rcs ${cur_dir}/libsqlite3.a ${cur_dir}/sqlite3.o
	gcc ${cur_dir}/shell.c ${cur_dir}/libsqlite3.a -o sqlite3 -ldl -lpthread
}


cur_dir=$(cd "$(dirname "$0")"; pwd)
#echo ${cur_dir}
cd ${cur_dir}
#pwd


if [[ $1 == "-clean" ]]; then
	[ -e ${cur_dir}/libsqlite3.a ] && rm ${cur_dir}/libsqlite3.a
	[ -e ${cur_dir}/sqlite3.o ] && rm ${cur_dir}/sqlite3.o
	[ -e ${cur_dir}/sqlite3 ] && rm ${cur_dir}/sqlite3
	#rm ${cur_dir}/libsqlite3.a ${cur_dir}/sqlite3.o
else
	build_sqlite3
fi
echo "Operate success !"
