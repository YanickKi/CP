all: executable output source/executable/ex_1 build/main.pdf
 
CC = g++
 
source/executable/ex_1: source/ex_1.cpp
	g++ source/ex_1.cpp -o source/executable/ex_1
	./source/executable/ex_1

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
