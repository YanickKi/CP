all: executable output source/executable/ex_1  build/main.pdf
 
CC = g++
 
source/executable/ex_1: source/ex_1.cpp
	g++ -std=c++20 source/ex_1.cpp -o source/executable/ex_1
	./source/executable/ex_1

build/ex_1a_varstep.pdf build/ex_1a_compare.pdf build/ex_1a_error.pdf: source/ex_1.py source/output/ex_1a.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1.py

build/main.pdf: build/ex_1a_varstep.pdf build/ex_1a_error.pdf

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
