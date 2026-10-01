build:
	gcc -Wall -Wextra copy.c -o copy2
debug:
	gcc -g copy.c -o copy2
memcheck:
	valgrind --leak-check=full --show-leak-kinds=all ./copy2
test:
	./copy2 source.txt target.txt && \
	cat target.txt && \
	diff source.txt target.txt || true
clean:
	rm -f copy2 target.txt
