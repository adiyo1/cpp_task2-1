# # 318725520
# # adi.yohanann@gmail.com


# #!make -f

# CXX=g++
# CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
# VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
# # SOURCES=TestCounter.cpp Test.cpp 
# OBJECTS=$(subst .cpp,.o,$(SOURCES))

# # SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp  # Assuming Graph.cpp and Algorithms.cpp are part of ariel
# # OBJECTS=$(subst .cpp,.o,$(SOURCES))

# run: test
# 	./$^

# demo: Demo.o Graph.cpp Algorithms.cpp
# 	$(CXX) $(CXXFLAGS) $^ -o demo

# test: TestCounter.o Test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o test

# # test: TestCounter.o Test.o $(OBJECTS)
# #     $(CXX) $(CXXFLAGS) $^ -o test -Lpath/to/ariel/library -l:barial  # Replace paths and library name accordingly


# tidy:
# 	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# valgrind: demo test
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) --compile $< -o $@

# clean:
# 	rm -f *.o demo test



# # CXX=c++
# # CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
# # VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# # SOURCES=TestCounter.cpp Test.cpp  # TestCounter.cpp Test.cpp

# # OBJECTS=$(subst .cpp,.o,$(SOURCES))

# # run:  test
# # 	./$^

# # demo: Demo.o $(OBJECTS)
# # 	$(CXX) $(CXXFLAGS) $^ -o demo

# # test: TestCounter.o Test.o $(OBJECTS)
# # 	$(CXX) $(CXXFLAGS) $^ -o test

# # tidy:
# # 	clang-tidy $(SOURCES) -checks=bugprone-,clang-analyzer-,cppcoreguidelines-,performance-,portability-,readability-,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# # valgrind: demo test
# # 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
# # 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# # %.o: %.cpp
# # 	$(CXX) $(CXXFLAGS) --compile $< -o $@

# # clean:
# # 	rm -f *.o demo tet


CXX=g++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# SOURCES=Demo.cpp Graph.cpp Algorithms.cpp 
SOURCES= Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp

OBJECTS=$(SOURCES:.cpp=.o)

run: test
	./$^
	

demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) \
		-checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* \
		--warnings-as-errors=* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test

