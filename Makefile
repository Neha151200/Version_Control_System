con: main.o vcs.o file_storage.o file_edit.o file_diff.o
	cc main.o vcs.o file_storage.o file_edit.o file_diff.o -o con

main.o: main.c vcs.h
	cc -c main.c

vcs.o: vcs.c vcs.h 
	cc -c vcs.c

file_storage.o: file_storage.c file_storage.h 
	cc -c file_storage.c

file_edit.o: file_edit.c file_edit.h
	cc -c file_edit.c

file_diff.o: file_diff.c file_diff.h
	cc -c file_diff.c
