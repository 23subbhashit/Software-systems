#!/bin/bash
echo "Menu :"
echo "1. Create Employee Record"
echo "2. Delete Employee Record"
echo "3. Search Employee Record"
echo "4. Displya Employee Details"
echo "5. Sort Records"
echo "6. List All Records"
echo "7. Exit"
array=()
while true
do
  echo "Enter YOur Choice:"
  read num
  if [[ $num -eq 1 ]]; then
    echo "Enter employee name"
    read name
    array+=($name)
  elif [[ $num -eq 2 ]]; then
    echo "Enter name to delete"
    read name
    array=( "${array[@]/@delete}" )
    echo "Delete!!" 
  elif [[ $num -eq 3 ]]; then
    echo "Enter Name to Search"
    read value
    if [[ " ${array[*]} " =~ " ${value} " ]]; then
      echo "FOund!!"
    fi
  elif [[ $num -eq 4 ]]; then
    echo "Employee Details"
    for i in ${array[@]}
      do
        echo "$i"
      done
  elif [[ $num -eq 5 ]]; then
    echo "Choice is $num"
  elif [[ $num -eq 6 ]]; then
    echo "Choice is $num"
  elif [[ $num -eq 1 ]]; then
    echo "Choice is $num"
  else
    echo "Valid choice in (1-7)"

  fi
 done
