(define (smooth f)
  (lambda (x) (average ((f x) (f (+ x dx)) (f (- x dx))))))

(define dx 0.0001)
(define (average a b c)
  (/ (+ a b c) 3))

(define (compose f g)
  (lambda (x)
    (f (g x))))

(define (repeated f n)
  (define (repeat-iter now-f count)
    (if (= count n)
	now-f
	(repeat-iter (compose f now-f) (+ count 1))))
  (repeat-iter f 1))

(define (nth-smooth f n)
  (compose (repeated smooth n) f))

