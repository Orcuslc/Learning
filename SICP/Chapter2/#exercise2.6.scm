(define (cons x y) (* (power 2 x) (power 3 y)))

(define (power a  b)
  (define (power-iter result b)
    (if (= b 0)
	result
	(power-iter (* result a) (- b 1))))
  (power-iter 1 b))

(define (logg a b)
  (define (logg-iter count a)
    (if (not (= (remainder a b) 0))
	count
	(logg-iter (+ count 1) (/ a b))))
  (logg-iter 0 a))

(define (car x)
  (logg x 2))

(define (cdr x)
  (logg x 3))
