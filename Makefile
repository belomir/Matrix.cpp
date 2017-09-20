# ConsoleApplicationMatrix build makefile
# © 2017 Sergey Roganov <sergey@roganof.ru>
# GNU/GPL v.3+

app = ConsoleApplicationMatrix
dir = build
cc  = g++ -I. -std=c++11
ccc = i686-w64-mingw32-g++-win32 -I. -std=c++11 --static
bin = $(dir)/$(app)
cpp = $(wildcard *.cpp)
obj = $(addprefix $(dir)/, $(cpp:.cpp=.o))
latex = pdflatex -interaction=nonstopmode -output-directory $(dir)
tex = report.tex
pdf = $(tex:.tex=.pdf)
out = $(dir)/output
windir = $(dir)/win32
winobj = $(addprefix $(windir)/, $(cpp:.cpp=.o))
winbin = $(windir)/$(app).exe
exe = $(app).exe

all: $(bin) $(out) $(exe) $(pdf)

dir: $(dir)

$(dir):
	mkdir -p $(dir)

windir: $(windir)

$(windir):
	mkdir -p $(windir)

run: $(bin)
	./$<

$(pdf): pdf

pdf: $(tex) $(out)
	$(latex) $(tex)
	$(latex) $(tex)
	mv $(dir)/$(pdf) .

view: $(pdf)
	xdg-open $< &

bin: $(bin)

$(out): $(bin)
	./$(bin) > $(out)

$(bin): $(obj)
	$(cc) $(obj) -o $@

$(obj): $(dir)/%.o : %.cpp dir
	$(cc) -c $< -o $@

crosscompile: $(exe)

$(winbin): $(winobj)
	$(ccc) $(winobj) -o $@

$(exe): $(winbin)
	cp $< $@

$(winobj): $(windir)/%.o : %.cpp windir
	$(ccc) -c $< -o $@

clean:
	rm -rf $(dir)

.PHONY: all run clean pdf view dir bin out windir winobj crosscompile exe
