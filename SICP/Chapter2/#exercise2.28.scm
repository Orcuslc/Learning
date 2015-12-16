(define (fringe list)
  (if (null? list)
      ()
      (let ((first (car list)))
	(if (not (pair? first))
	    (cons first (fringe (cdr list)))
	    (append (fringe first) (fringe (cdr list)))))))
    