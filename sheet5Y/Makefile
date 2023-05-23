all: executable output  build/main.pdf	
 
CC = g++
 
#source/executable/ex_1: source/ex_1.cpp
#	g++ source/ex_1.cpp -o source/executable/ex_1
#	./source/executable/ex_1

source/executable/ex_2 2e_99.txt: source/ex_2.cpp
	g++ -std=c++20 source/ex_2.cpp -o source/executable/ex_2
	./source/executable/ex_2

source/executable/ex_1 1e_0.txt: source/ex_1.cpp
	g++ -std=c++20 source/ex_1.cpp -o source/executable/ex_1
	./source/executable/ex_1

build/2e_99.pdf: source/ex_2.py 2e_99.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_2.py

build/ex_1.mp4: source/ex_1.py source/output/1c_0.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1.py

build/main.pdf: build/2e_99.pdf build/ex_1.mp4

build/main.pdf: FORCE | build
	  TEXINPUTS=build: \
	  max_print_line=1048576 \
	latexmk \
	  --lualatex \
	  --output-directory=build \
	  --interaction=nonstopmode \
	  --halt-on-error \
	main.tex

build:
	mkdir -p build

executable:
	mkdir -p source/executable 

output:
	mkdir -p source/output

clean:
	rm -rf build
	rm -rf source/executable
	rm -rf source/output

FORCE:

.PHONY: all clean
