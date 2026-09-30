build:
	gcc debug.c -o debug
debug:
	gcc -g debug.c -o debug
memcheck:
	valgrind --leak-check=full --show-leak-kinds=all ./debug
clean:
	rm -f debug
