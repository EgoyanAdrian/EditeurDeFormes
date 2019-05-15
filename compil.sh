#!/bin/bash

executeOptions=""
srcPath=
buildPath=

if [ $# -lt 1 ] ;
then
	echo "ARGUMENTS ERROR : Not enough arguments"
	exit
else
	for i in $@ ;
	do
		testExt=`echo $i | grep -o .cpp`
		if [ ! -z $testExt ] ;
		then
			echo "ARGUMENTS ERROR : Arguments contain file extension"
			exit
		elif [ ! -f $srcPath/$i.cpp ] ;
		then
			echo "ARGUMENTS ERROR : File doesn't exist : $srcPath/$i.cpp"
			exit
		fi
	done

	fileList=""

	for i in $@ ;
	do
		g++ -c $srcPath/$i.cpp
		fileList="$fileList $i.o"
	done

	g++ $fileList -o $buildPath/run.exe $executeOptions

	rm *.o

	chmod ugo+x $buildPath/run.exe
	./$buildPath/run.exe
fi
