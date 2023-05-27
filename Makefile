rune: main.o lexer.o parser.o
	gcc main.o lexer.o parser.o -o rune


main.o: main.c 
	gcc -c main.c 


lexer.o: lexer.c lexer.h 
	gcc -c lexer.c


parser.o: parser.c parser.h 
	gcc -c parser.c


clean:
	rm *.0
