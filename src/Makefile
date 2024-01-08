.PHONY: all a clean gcov_report s21_string remove_s21_string linter cppcheck leaks
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_string.a
LIB_DIR = function/*.c
TESTFILE = s21_test
GCOVR = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
D_OS = -D __My_Linux__
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: test s21_string.a gcov_report

clang:
	cp ../materials/linters/.clang-format ./function
	clang-format -n ./function/*.c *.h
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h

format:
	clang-format -i ./function/*.c *.h
	clang-format -i *.c *.h

test: s21_string.a
	$(CC) $(FLAGS) -o a.out s21_test.c -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) $(GCOVR) 

gcov_report:
	$(CC) $(FLAGS) -o test-funct s21_test.c $(LIB_DIR) $(LIBS_FOR_CHECK_PCKG) $(GCOVR) 

	# ./test-funct
	gcovr $(GCOVR) -r . --html --html-details ./coverage.html

	rm -rf
	genhtml -o report test-funct.info
	rm -rf *.gcda *.gcno

s21_string.a:
	$(CC) $(D_OS) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o

clean:
	rm -f *.a *.o *.so *.out *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format
	rm -rf ./function/.clang-format
	rm -rf test-funct
