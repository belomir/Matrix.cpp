# ConsoleApplicationMatrix build makefile
# © 2017 Sergey Roganov <sergey@roganof.ru>
# GNU/GPL v.3+

dir = build
cc  = g++ -I. -std=c++11
bin = $(dir)/ConsoleApplicationMatrix
cpp = $(wildcard *.cpp)
obj = $(addprefix $(dir)/, $(cpp:.cpp=.o))
latex = pdflatex -interaction=nonstopmode -output-directory $(dir)
tex = report.tex
pdf = $(tex:.tex=.pdf)


all: $(bin) $(pdf)

dir:
	mkdir -p $(dir)

run: $(bin)
	./$<

pdf: $(tex)
	$(latex) $(tex)
	$(latex) $(tex)
	mv $(dir)/$(pdf) .

view: $(pdf)
	xdg-open $< &

bin: $(bin)

$(bin): $(obj)
	$(cc) $(obj) -o $@

$(obj): $(dir)/%.o : %.cpp dir
	$(cc) -c $< -o $@

clean:
	rm -rf $(dir)

.PHONY: all run clean pdf view dir bin
