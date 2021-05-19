all: xyz2
	sbcl --script nr.lisp
	./$<
