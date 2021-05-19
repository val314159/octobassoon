#| -*-: mode: common-lisp -*-
exec sbcl --script $0 $* # |#

(defun xnreverse2 (y x) (if y (xnreverse2 (cdr y) (rplacd y x)) x))
(defun xnreverse  (y)         (xnreverse2      y   nil))

(defun xreverse2  (y x) (if y (xreverse2  (cdr y) (cons (car y) x)) x))
(defun xreverse   (y)         (xreverse2       y   nil))

(defun nrev (y &optional x) (if y (nrev (cdr y) (rplacd    y  x)) x))
(defun xrev (y &optional x) (if y (xrev (cdr y) (cons (car y) x)) x))

(print (xnreverse (list)))
(print (xnreverse (list 1)))
(print (xnreverse (list 1 2)))
(print (xnreverse (list 1 2 3)))
(print (xnreverse (list 1 2 3 4)))
(print (xnreverse (list 1 2 3 4 5)))
(print (xnreverse (list 1 2 3 4 5 6)))
