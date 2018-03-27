#! /bin/bash

# ecs60 Program 2
# This script compares the example output with the output from your program.
# It does not grade your programs.

echo "Running your programs (buildheap.sh) on examples.."

echo "Building test environment.."
chmod u+x *.sh
rm -rf testerDirectory
mkdir -p testerDirectory
mkdir -p testerDirectory/diff
cd testerDirectory
cp ../* . &> /dev/null
#rm *.json -f
echo "..."
#cp ~rsgysel/public/60-Program2-Examples/* . &> /dev/null
echo "...."

echo "This script assumes that your current directory contains all source, *.json examples, and *.buildheapoutput examples"

numExamples=100
totalTestsPassed=0

# buildheap
testsPassed=0;
numExamples=0
program=buildheap
echo "Checking ./buildheap.sh"
echo ${program} > Results.txt
for file in *.json; do
    numExamples=$((numExamples + 1))
    testFile=$(basename ${file} .json)
    echo "Running './buildheap.sh ${testFile}.json'"
    ./buildheap.sh ${testFile}.json > ${testFile}studentheapoutput.json
    if [ -s ${testFile}studentheapoutput.json ]; then
        diff -w ${testFile}studentheapoutput.json ${testFile}.buildheapoutput > ./diff/${testFile}Diff.txt

        diffFile=./diff/${testFile}Diff.txt
        if [ ! -s $diffFile ]; then
            if [ -f $diffFile ]; then
                echo ${testFile}studentheapoutput.json: Pass >> Results.txt
                testsPassed=$((testsPassed+1))
            else
                echo $diffFile not found!
            fi
        else
            echo ${testFile}studentheapoutput.json: Fail. See $diffFile >> Results.txt
        fi
    else
        echo ${testFile}.json: Fail, no output from your program >> Results.txt
    fi
done
echo ./buildheap.sh ${testsPassed} tests passed of ${numExamples} total tests
echo
echo >> Results.txt
totalTestsPassed=$(($totalTestsPassed + $testsPassed))

# Cleanup
echo Cleaning up...
cp Results.txt ../
cp -r diff ../
cd ..
rm -rf testerDirectory

echo "Testing finished, you passed $totalTestsPassed out of $numExamples total tests. See Results.txt for details. Be sure to include your compile.sh in your submission, which was not tested by this script."
