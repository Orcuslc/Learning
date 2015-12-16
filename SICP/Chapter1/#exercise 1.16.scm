(define (expt b n)
  (define (expt-iter a b n)
    (cond ((= n 0) a)
	  ((even? n) (expt-iter a (square b) (/ n 2)))
	  (else (expt-iter (* a b) (square b) (/ (- n 1) 2)))))
  (expt-iter 1 b n))

(define (even? n)
  (= (remainder n 2) 0))

(define (square b)
  (* b b))

