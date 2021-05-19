all: xyz
	sbcl --script nr.lisp
	./$<
