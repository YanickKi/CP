all: executable output source/executable/ex_1  source/executable/ex_2_3 build/main.pdf
 
CC = g++
 
source/executable/ex_1: source/ex_1.cpp
	g++ -std=c++20 source/ex_1.cpp -o source/executable/ex_1
	./source/executable/ex_1

source/executable/ex_2_3: source/ex_2_3.cpp
	g++ -std=c++20 source/ex_2_3.cpp -o source/executable/ex_2_3
	./source/executable/ex_2_3

build/ex_1a_varstep.pdf build/ex_1a_compare.pdf build/ex_1a_error.pdf build/ex_1b_compare.pdf build/ex_1b_error.pdf build/ex_1c_compare.pdf build/ex_1c_error.pdf build/ex_1d_compare.pdf build/ex_1d_error.pdf: source/ex_1.py source/output/ex_1d.txt ../matplotlibrc ../header-matplotlib.tex | build
	TEXINPUTS=$$(pwd)/..: MATPLOTLIBRC=../matplotlibrc python source/ex_1.py

build/main.pdf: build/ex_1a_varstep.pdf build/ex_1a_error.pdf build/ex_1b_compare.pdf build/ex_1b_error.pdf build/ex_1c_compare.pdf build/ex_1c_error.pdf build/ex_1d_compare.pdf build/ex_1d_error.pdf

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


#-wall (für Warnungen, falls beim Kompilieren Fehler auftreten)
#-Wextra (für mehr Warnungen) 
#-O0 (für schneller kompilieren ist das Default -0x) 
#-03 (für mehr optimizer (kompilieren braucht lange aber kann sich bei riesen programmen lohnen))
#-march = native (passt an Architektur des Rechners an)
#-ffast-math (optimiert floating point operationen, kann sein, dass größere numerische Abweichungen auftreten) 