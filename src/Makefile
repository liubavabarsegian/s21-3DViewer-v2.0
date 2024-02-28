NAME = 3DViewer
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
SRCS = models/*.cc
TEST_SRCS = tests/*.cc
COVERAGE_FILES = models/s21_affine_transform.cc models/s21_viewer_parser.cc
QMAKE_NAME = s21_3d_viewer
# Используемые папки
CONTROLLERS_DIR = controllers
MODELS_DIR = models
VIEWS_DIR = qt
TESTS_DIR = tests
INSTALL_DIR =build
DIST_DIR = 3DViewer_v2.0

TEST_FLAGS = -lcheck -lm -lpthread
GCOV_FLAGS = -ftest-coverage -fprofile-arcs 
UNAME_S = $(shell uname -s)
LC = lcov
LCOVFLAGS = -c -d . -o
EXECUTABLE = test

ifeq ($(shell uname -s),Linux)
	OPEN_CMD = xdg-open
	TEST_FLAGS =  -lcheck -lsubunit -lm -lrt -lpthread -lgcov -o 
endif

ifeq ($(shell uname -s),Darwin) # MacOS
	OPEN_CMD = open
	TEST_FLAGS = -lcheck -lm -lpthread -lgcov -o
endif

${NAME}:
	$(CXX) $(CXXFLAGS) -c ${SRCS}
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm *.o

all: rebuild gcov_report install 

.c.o:
	$(CXX) $(CXXFLAGS) $< $(GCOVFLAGS) -o $@

test: tests/tests.cc models/*.cc
	$(CXX) -std=c++17 -o tests/tests_runner $^ -lgtest -lgtest_main -pthread
	./tests/tests_runner

gcov_report: tests/tests.cc models/*.cc
	$(CXX) -std=c++17 -o tests/tests_runner $^ -lgtest -lgtest_main -pthread $(GCOV_FLAGS)
	./tests/tests_runner
	$(LC) -t "tests/tests_runner" -o test.info -c -d . --ignore-errors inconsistent
	genhtml --ignore-errors inconsistent -o report test.info
	$(OPEN_CMD) report/index.html

install: 
	make clean
	make uninstall
	mkdir $(INSTALL_DIR)
	make $(NAME)
	cd build && qmake ../$(QMAKE_NAME).pro && make && make clean && rm Makefile
	open $(INSTALL_DIR)/${QMAKE_NAME}.app/Contents/MacOS/$(QMAKE_NAME)

uninstall:
	rm -rf $(INSTALL_DIR)

dvi:
	# @doxygen conf && mv html documentation
	open documentation/index.html

dist:
	rm -rf $(DIST_DIR)/
	mkdir $(DIST_DIR)/
	mkdir $(DIST_DIR)/src
	mkdir $(DIST_DIR)/src/$(CONTROLLERS_DIR)
	mkdir $(DIST_DIR)/src/$(MODELS_DIR)
	mkdir $(DIST_DIR)/src/$(VIEWS_DIR)
	mkdir $(DIST_DIR)/src/imgs
	mkdir $(DIST_DIR)/src/$(TESTS_DIR)
	cp Makefile $(QMAKE_NAME).pro conf dog.obj $(DIST_DIR)/src/
	cp $(CONTROLLERS_DIR)/*.cc $(CONTROLLERS_DIR)/*.cc $(DIST_DIR)/src/$(CONTROLLERS_DIR)
	cp $(MODELS_DIR)/*.cc $(MODELS_DIR)/*.cc $(DIST_DIR)/src/$(MODELS_DIR)
	cp $(VIEWS_DIR)/*.cc $(VIEWS_DIR)/*.cc $(DIST_DIR)/src/$(VIEWS_DIR)
	cp imgs/* $(DIST_DIR)/src/imgs
	cp $(TESTS_DIR)/*.cc $(DIST_DIR)/src/$(TESTS_DIR)
	tar cvzf $(DIST_DIR).tgz $(DIST_DIR)/
	mv $(DIST_DIR).tgz $(HOME)/Desktop/
	rm -rf $(DIST_DIR)/

rebuild: clean $(NAME)

clean:
	rm -rf test *.gcov *.css gcov*.html
	rm -rf *.o *.a *.out  $(SOURCE_DIR)/.qmake.stash  $(SOURCE_DIR)/*.user
	rm -rf *.gcda *.gcno *.info *.gch *.html
	rm -rf test report
	rm -rf 3d-viewer/*.o
	rm -rf 3d-viewer/*.gcda 3d-viewer/*.gcno 3d-viewer/*.info 3d-viewer/*.gch 3d-viewer/*.html
	rm -rf tests/*.gcda tests/*.gcno tests/*.info tests/*.gch tests/*.html tests/*.o
	rm -f tests/tests_runner
	rm -f $(NAME)

clean_all: 
	make clean
	make uninstall

style: 
	clang-format --style=google $(CONTROLLERS_DIR)/* $(MODELS_DIR)/* $(VIEWS_DIR)/* $(TESTS_DIR)/*.cc -n

correct_style: 
	clang-format --style=google $(CONTROLLERS_DIR)/* $(MODELS_DIR)/* $(VIEWS_DIR)/* $(TESTS_DIR)/*.cc -i

