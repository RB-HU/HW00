
.PHONY = all clean

all: test_suite cowsay

test_suite: catch.o test_suite.o test_simple_string.o SimpleString.o
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -o test_suite catch.o test_suite.o test_simple_string.o SimpleString.o

test_suite.o: test_suite.cpp catch.hpp
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -c test_suite.cpp

test_simple_string.o: test_simple_string.cpp catch.hpp SimpleString.hpp
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -c test_simple_string.cpp

catch.o: catch.cpp catch.hpp
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -c catch.cpp

SimpleString.o: SimpleString.cpp SimpleString.hpp
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -c SimpleString.cpp

cowsay.o: cowsay.cpp SimpleString.hpp
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -fno-char8_t -c cowsay.cpp

cowsay: cowsay.o SimpleString.o
	clang++-19 -g3 -gdwarf-4 -Wall --std=c++2b -fno-char8_t -o cowsay cowsay.o SimpleString.o

tidy-check: 
	clang-tidy-19 \
        --extra-arg=--std=c++2b \
        -warnings-as-errors=* \
        -header-filter=.* \
       	cowsay.cpp SimpleString.cpp

format:
	clang-format-19 -i --verbose --style=Chromium cowsay.cpp SimpleString.cpp SimpleString.hpp

clean:
	rm *.o test_suite cowsay
