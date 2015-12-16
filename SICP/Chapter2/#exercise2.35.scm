(define (count-leaves tree)
  (accumulate + 0 (map
		   (lambda (x) 
		     (if (pair? x)
			 (count-leaves x)
			 1))
		   tree)))