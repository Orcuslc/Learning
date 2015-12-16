(define (repeated f n)
  (define (repeat-iter now-f count)
    (if (= count n)
	now-f
	(repeat-iter (compose f now-f) (+ count 1))))
  (repeat-iter f 1))

(define (compose f g)
  (lambda (x)
    (f (g x))))