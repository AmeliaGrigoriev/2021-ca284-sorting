dst = ../bin

c = $(wildcard *.c)
bin = $(patsubst %.c, %, $(c))
targets = $(addprefix $(dst)/, $(bin))

build: $(dst) $(targets)
	@true

$(dst)/%: %.c
	gcc -o $@ $<