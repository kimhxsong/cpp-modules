#!/bin/bash

N=1
cp Makefile copy

> test.log

echo "TEST #$N: ./ft_sed" >> test.log
./ft_sed >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed 1" >> test.log
./ft_sed 1 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed 1 2" >> test.log
./ft_sed 1 2 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed 2>&1 1 2 3" >> test.log
./ft_sed 2>&1 1 2 3 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed 1 2 3 4" >> test.log
./ft_sed 1 2 3 4 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed \"\" \"\" 3" >> test.log
./ft_sed "" "" 3 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed \"\" 2 3" >> test.log
./ft_sed "" 2 3 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed 1 "" 3" >> test.log
./ft_sed 1 "" 3 >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

echo "TEST #$N: ./ft_sed copy \"\t\" \"\"" >> test.log
./ft_sed copy "	" ""  >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

cp copy copy2
echo "TEST #$N: ./ft_sed copy2 \"NAME\" \"TEST\"" >> test.log
./ft_sed copy2 "NAME" "TEST" >> test.log
N=$(expr $N + 1)
echo "=========================================================================\n" >> test.log

diff copy copy.replace >> diff1.txt
diff copy2 copy2.replace >> diff2.txt

