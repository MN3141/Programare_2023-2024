CC=gcc
GCOV_FLAGS=-k -b -c -j

#-fprofile-arcs -ftest-coverage <=> --coverage
FILE_NAME=main
FUNCTIONS = functions

TEST_FRAMEWORK=E:/tools/CUnitTest_Unity/src/
TEST_DIR=test/
TEST_SOURCE_FILE=$(TEST_DIR)Test$(FUNCTIONS)

all:

	@$(CC) $(FILE_NAME).c $(FUNCTIONS).c -I$(FUNCTIONS).h -o $(FILE_NAME)
clean:

	@rm *.exe
	@rm *.gcov
	@rm *.gz
ccov:

	@$(CC) $(FILE_NAME).c $(FUNCTIONS).c -I$(FUNCTIONS).h -o $(FILE_NAME) --coverage
	@./$(FILE_NAME)
	@gcov $(FILE_NAME).gcda $(GCOV_FLAGS)
#	gzip -d $(FILE_NAME).gcov.json.gz
	@rm *.gcno
	@rm *.gcda

ctest:

	@$(CC) $(TEST_FRAMEWORK)unity.c $(TEST_SOURCE_FILE).c $(FUNCTIONS).c -I$(FUNCTIONS).h  -I$(TEST_FRAMEWORK) -o $(TEST_SOURCE_FILE)
	@./$(TEST_SOURCE_FILE)