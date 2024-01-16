.PHONY: all clean gcov_report s21_string

CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_string.a
LIB_DIR = ./function/*.c
TESTFILE = s21_test
GCOVR = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
D_OS = -D My_Linux
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D My_Linux
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D My_APPLE
endif

all: test s21_string.a gcov_report

test: s21_string.a
	$(CC) $(FLAGS) -o a.out ./tests/s21_test.c -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) $(GCOVR)

gcov_report:
	$(CC) $(FLAGS) -o test-funct $(filter %.c,$(wildcard ./function/*.c)) ./tests/s21_test.c $(LIBS_FOR_CHECK_PCKG) $(GCOVR)
	./test-funct

	lcov -t "test-funct" -o test-funct.info -c -d .
	rm -rf
	genhtml -o report test-funct.info
	rm -rf *.gcda *.gcno

s21_string.a:
	$(CC) $(D_OS) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o

clang:
	cp ../materials/linters/.clang-format ./function
	clang-format -n ./function/*.c
	cp ../materials/linters/.clang-format ./tests
	clang-format -n ./tests/*.c
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h

format:
	clang-format -i ./function/*.c
	clang-format -i ./tests/*.c
	clang-format -i *.c *.h

clean:
	rm -f *.a *.o *.so *.out *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format
	rm -rf ./function/.clang-format
	rm -rf ./function/*.o
	rm -rf ./tests/.clang-format
	rm -rf test-funct