Param($arg1, $arg2)
acg $arg1
cd .\tools
cp .\in\$arg2 ..\in.txt
cp .\out\$arg2 ..\out.txt
cat ..\in.txt | cargo run --release --bin tester ..\a.exe > ..\out.txt
cd ..