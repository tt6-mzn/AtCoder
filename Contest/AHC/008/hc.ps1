acg $Args[0]
cd .\tools
$files = Get-ChildItem .\in\ -Name
foreach($f in $files) {
	$f
	cat .\in\$f | cargo run --release --bin tester ..\a.exe > .\out\$f
}
cd ..