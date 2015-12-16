(define (miller-rabin-expmod base exp m)
	(define (square-mod-with-check x)
		((define (check-nontrival-sqrt x square)
		  (if (and (= square 1)
		  		(not (= x 1))
		  		(not (= x (- m 1))))
			0
			square))
		(check-nontrival-sqrt x (remainder (square x) m)))
	(cond ((= exp 0) 1)
		(even? exp) (square-mod-with-check
						(miller-rabin-expmod base (/ exp 2) m)))
		(else
			(remainder (* base (miller-rabin-expmod base (- exp 1) m))))

(define (miller-rabin-test n)
	(define (try-it a)
		(define (check-it x)
			(and (not (= x 0)) (= x 1)))
	(check-it (miller-rabin-expmod a (- n 1) n)))
	(try-it (+ 1 (random (- n 1))))

(define (fast-prime? n times)
	(cond ((= times 0) true)
		((miller-rabin-test n) (fast-prime? n (- times 1)))
		(else false)))

(define (prime? n)
	(fast-prime n 100))

(define (square n)
	(* n n))

(define (report-prime n expected)
	(define (report-result n result expected)
		(newline)
		(display n)
		(display ": ")
		(display result)
		(display ": ")
		(display (if (eq? result expected) "OK" "FOOLED")))
	(report-result n (prime? n) expected))