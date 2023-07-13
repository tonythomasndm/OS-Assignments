default:
	gcc -pthread -o threadSched threadSched.c && ./threadSched
	python3 histo_display.py
	rm file.txt
	chmod +x kernel_compile_steps.sh
	gcc processSched.c -o processSched && ./processSched 2
	./processSched 54
	./processSched 98
	python3 histo_display.py
	rm file.txt

