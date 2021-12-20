.PHONY = all clean

all: stringProg

stringProg: stringProg.c
	gcc -g stringProg.c -o stringProg

clean:
	rm stringProg
