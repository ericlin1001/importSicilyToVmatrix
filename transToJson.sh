#!/bin/bash
IFS=$'\n'
for i in `ls unzip/` ;do
	if [ ! -d "unzip/$i" ];then
		continue;
	fi
	chapter="$i"
	echo .
	echo "****************Generating Chapter:$chapter...***************"

	# create dir, if no exist.
	chapterDir="./problems/$chapter"
	if [ ! -d "./problems" ];then
		mkdir "./problems";
	fi
	if [ ! -d "$chapterDir" ]; then
		mkdir "$chapterDir";
	fi

	# loop over all problems in current chapter.
	for j in `ls "unzip/$i"`;do
		if [ ! -d "unzip/$i/$j" ]; then
			continue;
		fi
		saveToCurrentProblem="`pwd`/problems/$chapter/$j.json"
		#inside one problem
		cd "unzip/$i/$j";
		currentProblem="`pwd`"
		# Detecting some problems
		if [ ! -f ".DIR" ]; then
			if [ -f "../$j"".zip" ]; then
				unzip "../$j"".zip" .DIR  >/dev/null
			fi
		fi
		if [ -f "$j.cpp" ]; then
			mv "$j.cpp" "main.cpp"
		fi
		if [ ! -f "main.cpp" ]; then
			echo "Error: Can't find $currentProblem/main.cpp, skipping";
			continue;
		fi
		if [ ! -f ".DIR" ]; then
			echo "Error: Can't find $currentProblem/.DIR, skipping";
			continue;
		fi
		#
		for l in `cat .DIR`;do
			myin=`echo $l|awk '{print $1}'`
			myout=`echo $l|awk '{print $2}'`
			if [ ! -f $myin ]; then
				echo "Error: Can't find $currentProblem/$myin, skipping";
				continue;
			fi
			if [ ! -f $myout ]; then
				echo "Error: Can't find $currentProblem/$myout, skipping";
				continue;
			fi
		done
		cd ../../../
		echo "./genProblem.py \"$currentProblem\" \"$saveToCurrentProblem\"  \"From Sicily::$i::$j::\""
		#./genProblem.py "$currentProblem" "$saveToCurrentProblem"  "From Sicily::$i::$j::"
		#end processing one problem
	done
	#end processing a chapter***
done
