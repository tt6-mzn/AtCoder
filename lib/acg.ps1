# g++ $Args[0] -std=c++14 -I C:\include\ac-library
# g++ -std=gnu++1y -O2 -I/opt/boost/gcc/include -IC:\include\ac-library -L/opt/boost/gcc/lib $Args[0]
g++ -std=c++14 -O2 -DONLINE_JUDGE -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -IC:\include\ac-library $Args[0]