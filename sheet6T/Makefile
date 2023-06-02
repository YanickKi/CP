all: executable output source/executable/ex_2 build/main.pdf
 
CC = g++
 


source/executable/ex_2: source/ex_2.cpp
	g++ source/ex_2.cpp -o source/executable/ex_2
	./source/executable/ex_2

build/pr28_1.pdf build/pr20_1.pdf build/z20_20.pdf build/z20_28.pdf build/pr28_3d.pdf build/pr20_3d.pdf: source/2bc.py source/output/pr20_1.txt source/output/pr20_23.txt source/output/pr20_32.txt source/output/pr28_1.txt source/output/pr28_23.txt source/output/pr28_32.txt source/output/z20_28.txt source/output/z20_20.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/2bc.py


build/main.pdf: build/pr28_1.pdf build/pr20_1.pdf build/z20_20.pdf build/z20_28.pdf build/pr28_3d.pdf build/pr20_3d.pdf

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
