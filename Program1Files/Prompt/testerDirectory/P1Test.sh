#! /bin/bash

# ecs60 Program 1
# This script compares the example output with the output from your program.
# It does not grade your programs.

echo "Running your programs (sortedverification.sh, consistentresultverification.sh, timealgorithms.sh) on examples.."

echo "Building test environment.."
chmod -ux *.sh
rm -rf testerDirectory
mkdir -p testerDirectory
mkdir -p testerDirectory/diff
cd testerDirectory
cp ~rsgysel/public/60-Program1-Examples/* . &> /dev/null
echo "..."
cp ../* . &> /dev/null
echo "...."

numExamples=100
totalTestsPassed=0

# Sorted Verification
testsPassed=0
program=SortedVerification
echo "Checking sortedverification.sh.."
echo ${program} > Results.txt
for i in {1..100}; do
    testFile=Example${i}
    ./sortedverification.sh ${testFile}.json > ${testFile}-${program}Submission.json
    diff ${testFile}-${program}Submission.json ${testFile}-${program}Solution.json > ./diff/${testFile}-${program}Diff.txt

    diffFile=./diff/${testFile}-${program}Diff.txt
    if [ ! -s $diffFile ]; then
        echo ${testFile}.json: Pass >> Results.txt
        testsPassed=$((testsPassed+1))
    else
        echo ${testFile}.json: Fail. See $diffFile >> Results.txt
    fi
done
echo ./sortedverification.sh ${testsPassed} tests passed of $numExamples total tests
echo
echo >> Results.txt
totalTestsPassed=$(($totalTestsPassed + $testsPassed))

# Consistent Result Verificaiton
testsPassed=0;
program=ConsistentResultVerification
echo "Checking ./consistentresultverification.sh.."
echo ${program} >> Results.txt
for i in {1..100}; do
    testFile1=Example${i}
    j=$((i+1))
    testFile2=Example${j}
    testFile=${testFile1}-${testFile2}
    ./consistentresultverification.sh ${testFile1}.json ${testFile2}.json > ${testFile}-${program}Submission.json
    diff ${testFile}-${program}Submission.json ${testFile}-${program}Solution.json > ./diff/${testFile}-${program}Diff.txt
 
    diffFile=./diff/${testFile}-${program}Diff.txt
    if [ ! -s $diffFile ]; then
        echo ${testFile1}.json ${testFile2}.json: Pass >> Results.txt
        testsPassed=$((testsPassed+1))
    else
        echo ${testFile1}.json ${testFile2}.json: Fail. See $diffFile >> Results.txt
    fi
done
echo ./consistentresultverification.sh ${testsPassed} tests passed of $numExamples total tests
echo
echo >> Results.txt
totalTestsPassed=$(($totalTestsPassed + $testsPassed))

# Time Algorithms
testsPassed=0;
program=TimedAlgorithms
echo "Checking ./timealgorithms.sh.. (Timing columns are ignored during comparison and are 0's in the Solution files, your time values should not be 0)"
echo ${program} >> Results.txt
for i in {1..100}; do
    testFile=Example${i}
    ./timealgorithms.sh ${testFile}.json > ${testFile}-${program}Submission.csv
    diff ${testFile}-${program}Submission.csv ${testFile}-${program}Solution.csv > ./diff/${testFile}-${program}Diff.txt

    # cut timing fields
    head -n1 ${testFile}-${program}Submission.csv > temp.csv
    # pipe into wc so only #lines printed
    k=$(cat ${testFile}-${program}Submission.csv | wc -l)
    k=$((k-1))
    tail -n$k ${testFile}-${program}Submission.csv | cut --complement -f 2,5,8 -d, >> temp.csv
    mv temp.csv ${testFile}-${program}Submission.csv
    head -n1 ${testFile}-${program}Solution.csv > temp.csv
    k=$(cat ${testFile}-${program}Solution.csv | wc -l)
    k=$((k-1))
    tail -n$k ${testFile}-${program}Solution.csv | cut --complement -f 2,5,8 -d, >> temp.csv
    mv temp.csv ${testFile}-${program}Solution.csv
    diff ${testFile}-${program}Submission.csv ${testFile}-${program}Solution.csv > ./diff/${testFile}-${program}Diff.txt

    diffFile=./diff/${testFile}-${program}Diff.txt
    if [ ! -s $diffFile ]; then
        echo ${testFile}.json: Pass >> Results.txt
        testsPassed=$((testsPassed+1))
    else
        echo ${testFile}.json: Fail. See $diffFile >> Results.txt
    fi
done
echo ./timealgorithms.sh ${testsPassed} tests passed of $numExamples total tests
echo
totalTestsPassed=$(($totalTestsPassed + $testsPassed))

# Cleanup
cp Results.txt ../
cp -r diff ../
cd ..
rm -rf testerDirectory

echo "Testing finished, you passed $totalTestsPassed out of $((3*$numExamples)) total tests. See Results.txt for details. Be sure to include your compile.sh in your submission, which was not tested by this script."
