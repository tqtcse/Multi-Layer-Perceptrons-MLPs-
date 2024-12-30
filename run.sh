#!/bin/bash

# Check if the executable 'main' already exists and remove it
if [ -f main ]; then
    echo "Removing existing executable 'main'."
    rm main
fi

# Compile the C++ program  -fsanitize=undefined 
g++ -std=c++17 -o main -DTEST_LOSS 
-I "./test"  -I "./include" 
-I "./include/tensor" -I "./include/sformat" 
-I "./include/ann" 
$(find ./src/ann/ -type f -iregex ".*\.cpp")  
./src/tensor/*.cpp main.cpp  
test/unit_test/loss/unit_test_CrossEntropy.cpp