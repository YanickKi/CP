all: executable output source/executable/ex_2 source/executable/ex_3 build/main.pdf
 
CC = g++
 
source/executable/ex_2: source/ex_2.cpp
	g++ -std=c++20 source/ex_2.cpp -o source/executable/ex_2
	./source/executable/ex_2

source/executable/ex_3: source/ex_3.cpp
	g++ source/ex_3.cpp -o source/executable/ex_3
	./source/executable/ex_3

build/ex_3_a.pdf: source/ex_3_plot_a.py source/output/ex_3_euler.txt source/output/ex_3_euler_schl.txt source/output/ex_3_verlet.txt source/output/ex_3_verlet_schl.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_3_plot_a.py

build/ex_3_b.pdf: source/ex_3_plot_b.py source/output/ex_3_euler.txt source/output/ex_3_verlet_vertrau.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_3_plot_b.py

build/ex_3_c.pdf: source/ex_3_plot_c.py source/output/ex_3_verlet_rück.txt source/output/ex_3_euler_ruck.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_3_plot_c.py

build/ex_2c_r.pdf build/ex_2c_z.pdf build/ex_2c_psi.pdf: source/ex_2.py source/output/ex_2c.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_2.py


build/main.pdf: build/ex_2c_r.pdf build/ex_2c_z.pdf build/ex_2c_psi.pdf build/ex_3_a.pdf build/ex_3_b.pdf build/ex_3_c.pdf

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
