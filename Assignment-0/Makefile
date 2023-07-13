CFLAGS = -no-pie
TARGETS = rio

rio: rio.asm
	yasm -f elf64 $<
	gcc $(CFLAGS) rio.o -o $@

run: rio
	./$(TARGETS)

clean:
	rm $(TARGETS)