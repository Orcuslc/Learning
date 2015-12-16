(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulate combiner null-value term (next a) next b))))

(define (new-accumulate combiner null-value term a next b)
  (define (accu-iter a result)
    (if (> a b)
	result
	(accu-iter (next a) (combiner (term a) result))))
  (accu-iter a a))

