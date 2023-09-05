rune: main.o lexer.o 
	gcc main.o lexer.o  -o rune


main.o: main.c 
	gcc -c -g main.c 


lexer.o: lexer.c lexer.h 
	gcc -c -g lexer.c



clean:
	Remove-Item -Path ./ *.o
