##
# leetcode
#
# @file
# @version 0.1

CXX = g++
CPPFLAGS = -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op \
           -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
           -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector \
           -O2 --std=c++14 \

all: e

a :
	$(CXX) $(CPPFLAGS) -o a.o a.cpp

b :
	$(CXX) $(CPPFLAGS) -o b.o b.cpp

c :
	$(CXX) $(CPPFLAGS) -o c.o c.cpp

d :
	$(CXX) $(CPPFLAGS) -o d.o d.cpp

e :
	$(CXX) $(CPPFLAGS) -o e.o e.cpp
clean:
	rm -f a.o b.o

# end
