.PHONY: all a clean gcov_report s21_string remove_s21_string linter cppcheck leaks
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_string.a
LIB_DIR = function/*.c
TESTFILE = test
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
	cp ../materials/linters/.clang-format .
	clang-format -n ./function/*.c *.h 

format:
	clang-format -i ./function/*.c *.h 

test: s21_string.a
	$(CC) $(FLAGS) -o a.out s21_string.c -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) $(GCOVR) 

gcov_report:
	$(CC) $(FLAGS) -o test-funct s21_string.c $(LIB_DIR) $(LIBS_FOR_CHECK_PCKG) $(GCOVR) 

	./test-funct
	gcovr $(GCOVR) -r . --html --html-details ./coverage.html
	rm -rf
	genhtml -o report test-funct.info
	rm -rf *.gcda *.gcno

s21_string.a:
	$(CC) $(D_OS) -c $(FLAGS) $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format
	rm -rf test-funct
