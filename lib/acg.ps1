# g++ $Args[0] -std=c++14 -I C:\include\ac-library
g++ -std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -IC:\include\ac-library $Args[0]
# g++ -std=c++14 -O2 -DONLINE_JUDGE -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -IC:\include\ac-library $Args[0]