all: executable output source_ex/executable/ex_1 source_ex/executable/ex_2 source_ex/executable/ex_3 build/main.pdf
 
CC = g++
 
source_ex/executable/ex_1: source_ex/ex_1.cpp
	g++ source_ex/ex_1.cpp -o source_ex/executable/ex_1
	./source_ex/executable/ex_1

source_ex/executable/ex_2: source_ex/ex_2.cpp
	g++ source_ex/ex_2.cpp -o source_ex/executable/ex_2
	./source_ex/executable/ex_2

source_ex/executable/ex_3: source_ex/ex_3.cpp
	g++ source_ex/ex_3.cpp -o source_ex/executable/ex_3
	./source_ex/executable/ex_3

build/ex_2_a.pdf: source_ex/ex_2_plot.py source_ex/output/ex_2.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source_ex/ex_2_plot.py

build/ex_3.pdf: source_ex/ex_3_plot.py source_ex/output/ex_3_euler_small.txt source_ex/output/ex_3_euler_big.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source_ex/ex_3_plot.py

build/ex_3_b.pdf: source_ex/ex_3_plot_b.py source_ex/output/ex_3_euler_small_b.txt source_ex/output/ex_3_euler_big_b.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source_ex/ex_3_plot_b.py

build/main.pdf: build/ex_3.pdf build/ex_3_b.pdf build/ex_2_a.pdf

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
	mkdir -p source_ex/executable 

output:
	mkdir -p source_ex/output

clean:
	rm -rf build
	rm -rf source_ex/executable
	rm -rf source_ex/output

FORCE:

.PHONY: all clean
