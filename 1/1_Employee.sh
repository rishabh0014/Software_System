#!/bin/bash

show_op(){
    echo "1 => Create Employee Record"
    echo "2 => Delete Employee Record"
    echo "3 => Search Employee Record"
    echo "4 => Display Employee Details"
    echo "5 => Sort Records"
    echo "6 => Exit"
    echo "Enter Your Choice (1-6): "
}

create_rec(){
    echo "Enter Employee name: "
    read name
    echo "Enter Employee ID: "
    read id
    echo "Enter Employee Phone Number: "
    read num
    echo "Employee Name: $name || Employee ID: $id || Employee Phone Number: $num" >> records.txt
}

del_me() {
    echo "Enter Employee Number: "
    read id

    if grep -q "$id" records.txt; then
        grep -v "$id" records.txt > temp.txt
        mv temp.txt records.txt
        echo "Deleted Successfully!"
    else
        echo "Record not found!"
    fi
}

search_me() {
    echo "Enter Employee Number: "
    read num
    
    if grep -q "$num" records.txt; then
        echo "Employee Details: "
        grep "$num" records.txt
    else
        echo "Record not found!"
    fi
}

display_me(){
    echo "Employee Records: "
    cat records.txt
    echo "---------------End of File---------------"
}

sort_me(){
    sort -t',' -k2 -n records.txt > sorted.txt
    echo "Employee Records sorted in sorted.txt by Employee Number."
    echo "Sorted Employee Records: "
    mv sorted.txt records.txt
    cat records.txt
}

while true; do
    show_op
    read choice

    case $choice in
        1) create_rec;;
        2) del_me;;
        3) search_me;;
        4) display_me;;
        5) sort_me;;
        6) echo "Exiting..."; break ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
done