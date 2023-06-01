rune: main.o lexer.o parser.o
	gcc main.o lexer.o parser.o -o rune


main.o: main.c 
	gcc -c -g main.c 


lexer.o: lexer.c lexer.h 
	gcc -c -g lexer.c


parser.o: parser.c parser.h 
	gcc -c -g parser.c


clean:
	rm *.o
