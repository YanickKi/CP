all: executable output source/executable/ex_2 build/main.pdf
 
CC = g++
 
source/executable/ex_2: source/ex_2.cpp
	g++ -std=c++20 source/ex_2.cpp -o source/executable/ex_2
	./source/executable/ex_2

build/ex_2c_r.pdf build/ex_2c_z.pdf build/ex_2c_psi.pdf: source/ex_2.py source/output/ex_2c.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_2.py

build/main.pdf: build/ex_2c_r.pdf build/ex_2c_z.pdf build/ex_2c_psi.pdf

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
