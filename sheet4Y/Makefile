all: executable output source/executable/ex_1 source/executable/ex_2 build/main.pdf
 
CC = g++
 
source/executable/ex_1: source/ex_1.cpp
	g++ -std=c++20 source/ex_1.cpp -o source/executable/ex_1
	./source/executable/ex_1

source/executable/ex_2: source/ex_2.cpp
	g++ -std=c++20 source/ex_2.cpp -o source/executable/ex_2
	./source/executable/ex_2

build/1b.pdf build/1c.pdf build/1c_analytical.pdf build/1d.pdf build/1e.pdf build/1d_E.pdf build/1e_E.pdf: source/ex_1.py source/output/1b.txt source/output/1c.txt source/output/1c_analytical.txt source/output/1d.txt source/output/1e.txt source/output/1d_Ex.txt source/output/1d_Ey.txt source/output/1e.txt source/output/1e_Ex.txt source/output/1e_Ey.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1.py

build/2a.mp4 build/2b_stable.mp4 build/2b_unstable.mp4 build/2c_1.mp4 build/2c_2.mp4 build/2c_3.mp4: source/ex_2.py source/output/2a.txt source/output/2b_stable.txt source/output/2b_unstable.txt source/output/2c_1.txt source/output/2c_2.txt source/output/2c_3.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_2.py

build/main.pdf: build/1b.pdf build/1c.pdf build/1c_analytical.pdf build/1d.pdf build/1e.pdf build/1d_E.pdf build/1e_E.pdf build/2a.mp4 build/2b_stable.mp4 build/2b_unstable.mp4 build/2c_1.mp4 build/2c_2.mp4 build/2c_3.mp4

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
