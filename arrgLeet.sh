#!/bin/sh

if [ $# != 2 ]
then
  echo "**Format** ./arrgLeet.sh [file_name] [file_type(py/c/cpp/java/js/sql)]"

else
  if test ${2} == "py" -o ${2} == "c" -o ${2} == "cpp" -o ${2} == "java" -o ${2} == "js" -o ${2} == "sql"; then
    echo "Get the file_type: $2"
    echo "Creating the directory: $1"
    cd ~/Documents/MyMacWorkSpace/leetcode-pratice/ 
    mkdir ${1}
    cd ${1}
    vi Solution.${2}

  else
    echo "Unvalid file_type(py/c/cpp/java/js)"
    echo "**Format** ./arrgLeet.sh [file_name] [file_type(py/c/cpp/java/js)]"

  fi
fi
