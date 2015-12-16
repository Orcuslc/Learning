(define (horner-eval x coefficient-sequence)
  (accumulate (lambda (this-coefficient higher-terms)
		(+ (* higher-terms x) this-coefficient))
	      0
	      coefficient-sequence))