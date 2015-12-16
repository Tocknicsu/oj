#!/bin/sh
./test_data 10 2.in
./a.out 2.in > 2.out

./test_data 200 3.in
./a.out 3.in > 3.out

./test_data 200 4.in
./a.out 4.in > 4.out

./test_data 1000 5.in
./a.out 5.in > 5.out
