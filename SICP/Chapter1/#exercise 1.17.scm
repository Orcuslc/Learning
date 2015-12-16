(define (fast-multiple a b)
  (cond ((= b 0) 0)
	((even? b) (fast-multiple (double a) (halve b)))
	(else (+ a (fast-multiple a (- b 1))))))

(define (even? b)
  (= (remainder b 2) 0))

(define (double a)
  (+ a a))

(define (halve a)
  (/ a 2))

