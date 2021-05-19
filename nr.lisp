#| -*-: mode: common-lisp -*-
exec sbcl --script $0 $* # |#
(defun xnreverse2 (x y) (if (not x) y (xnreverse2 (cdr x) (rplacd    x  y))))
(defun  xreverse2 (x y) (if (not x) y ( xreverse2 (cdr x) (cons (car x) y))))
(defun xnreverse  (x)                 (xnreverse2      x   nil))
(defun  xreverse  (x)                 ( xreverse2      x   nil))
(print (xnreverse (list)))
(print (xnreverse (list 1)))
(print (xnreverse (list 1 2)))
(print (xnreverse (list 1 2 3)))
(print (xnreverse (list 1 2 3 4)))
(print (xnreverse (list 1 2 3 4 5)))
(print (xnreverse (list 1 2 3 4 5 6)))
