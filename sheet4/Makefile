all: executable output source/executable/ex_1 build/main.pdf 
 
CC = g++
 
source/executable/ex_1: source/ex_1.cpp
	g++ -std=c++20 source/ex_1.cpp -o source/executable/ex_1
	./source/executable/ex_1

build/ex_1a.pdf: source/ex_1a.py source/output/a)setAufgabe1.dat ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1a.py

build/ex_1c.pdf: source/ex_1c.py source/output/c)setAufgabe1.dat ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1c.py

build/ex_1c_an.pdf: source/ex_1c_an.py source/output/can)setAufgabe1.dat ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1c_an.py

build/ex_1d.pdf: source/ex_1d.py source/output/d)setAufgabe1.dat ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1d.py

build/ex_1e.pdf: source/ex_1e.py source/output/e)setAufgabe1.dat ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1e.py

source/executable/ex_2 source/output/2a.txt source/output/2b_stable.txt source/output/2b_unstable.txt source/output/2c_1.txt source/output/2c_2.txt source/output/2c_3.txt: source/ex_2.cpp
	g++ -std=c++20 source/ex_2.cpp -o source/executable/ex_2
	./source/executable/ex_2

build/2a.mp4 build/2b_stable.mp4 build/2b_unstable.mp4 build/2c_1.mp4 build/2c_2.mp4 build/2c_3.mp4: source/ex_2.py source/output/2a.txt source/output/2b_stable.txt source/output/2b_unstable.txt source/output/2c_1.txt source/output/2c_2.txt source/output/2c_3.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_2.py

build/main.pdf: build/ex_1a.pdf build/ex_1c.pdf build/ex_1c_an.pdf build/ex_1d.pdf build/ex_1e.pdf build/2a.mp4 build/2b_stable.mp4 build/2b_unstable.mp4 build/2c_1.mp4 build/2c_2.mp4 build/2c_3.mp4

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
