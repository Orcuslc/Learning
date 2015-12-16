(define (cont-frac n d k)
  (define (loop result count)
    (if (= count 0) 
	result
	(loop (/ (n count) (+ (d count) result)) (- count 1))))
  (loop 0 k))

(define (tan-cf x k)
  (exact->inexact (cont-frac (lambda (x) (if (= k 1)
			      x
			     (- (* x x))))
	     (lambda (k) (- (* 2 k) 1))
	     k)))


