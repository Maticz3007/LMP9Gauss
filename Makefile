new_dir:
	mkdir bin
all:
	gcc -Wall -lm --pedantic src/*.c -o bin/gauss.exe
test: all
	bin/gauss.exe dane/A dane/b
	bin/gauss.exe dane/5x5A dane/5x5b
	bin/gauss.exe dane/7x7A dane/7x7b
error_test1: all
	bin/gauss.exe dane/4x4A dane/4x4b
error_test2: all
	bin/gauss.exe dane/2x2A dane/b
error_test3: all
	bin/gauss.exe dane/A dane/5x5b