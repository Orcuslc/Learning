(define (cont-frac n d k)
  (define (loop result count)
    (if (= count 0)
	result
	(loop (/ (n count) (+ (d count) result)) (- count 1))))
  (loop 0 k))

(define (get-value-e k)
 (exact->inexact (+ 2 (cont-frac (lambda (i) 1) (lambda (i) (if (or (= (modulo i 3) 0) (= (modulo i 3) 1))
					    1
					    (* 2 (+ 1 (- i (remainder i 3)))))) k))))



