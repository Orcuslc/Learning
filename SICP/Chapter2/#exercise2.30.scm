(define (square-tree tree)
  (map (lambda (sub-tree)
	 (if (pair? sub-tree)
	     (square-tree sub-tree)
	     (square sub-tree)))
       tree))

(define (square x)
  (* x x))


(define (another-square-tree tree)
  (cond ((null? tree) nil)
	((not (pair? tree)) (square tree))
	(else (cons (another-square-tree (car tree))
		    (another-square-tree (cdr tree))))))

(define nil () )