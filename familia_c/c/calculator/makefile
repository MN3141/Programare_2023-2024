CC = gcc
FUNCTION = calculator

TEST_FRAMEWORK=E:/tools/CUnitTest_Unity/src/
TEST_DIR=test/
TEST_SOURCE_FILE=$(TEST_DIR)Test$(FUNCTION)

all:
	$(CC) main.c $(FUNCTION).c -I$(FUNCTION).h -o $(FUNCTION)

ctest:
	$(CC) $(TEST_FRAMEWORK)/unity.c $(TEST_SOURCE_FILE).c $(FUNCTION).c  -I$(TEST_FRAMEWORK) -I$(FUNCTION).h  -o $(TEST_SOURCE_FILE)
clean:
	rm *.exe