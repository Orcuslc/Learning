(define (timed-prime-test n)
  (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
  (if (prime? n)
      (report-prime n (- (runtime) start-time))))

(define (report-prime n elapsed-time)
  (newline)
  (display n)
  (display " *** ")
  (display elapsed-time))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (define (next n)
    (cond ((= n 2) 3)
    (else (+ n 2))))
  (cond ((> (square test-divisor) n) n)
	((divides? test-divisor n) test-divisor)
	(else (find-divisor n (next test-divisor)))))

(define (square n)
  (* n n))

(define (divides? a b)
  (= (remainder b a) 0))

(define (search-for-primes first last)
  (define (search-iter current last)
    (if (<= current last) (timed-prime-test current))
    (if (<= current last) (search-iter (+ current 2) last)))
  (search-iter (if (even? first) (+ first 1) first) (if (even? last) (- last 1) last)))

(define (even? n)
  (= (remainder n 2) 0))

