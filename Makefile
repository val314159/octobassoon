all: xyz2
	sbcl --script nr.lisp
	./$<
clean:
	rm -fr xyz2 *.o *~
