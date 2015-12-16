(define (filtered-accumulate combiner null-value term a next b filter)
  (if (> a b)
  	  null-value
  	  (if (filter (term a))
  	  	(combiner (term a) (filtered-accumulate combiner null-value term (next a) next b filter))
  	  	(filtered-accumulate combiner null-value term (next a) next b filter))))


(define (smallest-divisor n)
	(find-divisor n 2))

(define (find-divisor n test-divisor)
	(cond ((> (square test-divisor) n) n)
				((divides? test-divisor n) test-divisor)
				(else (find-divisor n (+ test-divisor 1)))))

(define (square x) (* x x))

(define (divides? a b) (= (remainder b a) 0))

(define (prime? n) (= n (smallest-divisor n)))

(define (add x y) (+ x y))

(define (id x) x)

(define (inc x) (+ x 1))

(define (sum-of-primes a b)
	(filtered-accumulate add 0 id a inc b prime?))




(define (gcd a b)
	(if (= b 0)
		a
		(gcd b (remainder a b))))

(define (prime-with? a n)
		(= (gcd n a) 1))

(define (new-filtered-accumulate combiner null-value term a next b filter)
  (if (> a b)
  	  null-value
  	  (if (filter (term a) b)
  	  	(combiner (term a) (new-filtered-accumulate combiner null-value term (next a) next b filter))
  	  	(new-filtered-accumulate combiner null-value term (next a) next b filter))))

(define (sum-of-prime-with-n n)
		(new-filtered-accumulate add 0 id 1 inc n prime-with?))