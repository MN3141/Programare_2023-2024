CC=gcc
GCOV_FLAGS=-k -b -c -j
#-fprofile-arcs -ftest-coverage <=> --coverage
FILE_NAME=main
all:
	$(CC) $(FILE_NAME).c -o $(FILE_NAME)
clean:
	rm *.exe
	rm *.gcov
	rm *.gz
ccov:
	$(CC) $(FILE_NAME).c -o $(FILE_NAME) --coverage
	./$(FILE_NAME)
	gcov $(FILE_NAME).gcda $(GCOV_FLAGS)
#	gzip -d $(FILE_NAME).gcov.json.gz
	rm *.gcno
	rm *.gcda