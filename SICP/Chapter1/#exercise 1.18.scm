(define (fast-mutiple a b)
  (define (mtp-iter a temp b)
    (cond ((= b 0) temp))
	  ((even? b) (mtp-iter (double a) temp (halve b)))
	  (else (mtp-iter a (+ temp a) (- b 1))))
  (mtp-iter a 0 b))

(define (even? b)
  (= (remainder b 2) 0))

(define (double a)
  (+ a a))

(define (halve a)
  (/ a 2))

