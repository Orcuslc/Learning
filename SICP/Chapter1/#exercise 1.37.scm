(define (cont-frac n d k)
  (define (loop result count)
    (if (= count 0)
	result
	(loop (/ (n count) (+ (d count) result)) (- count 1))))
  (loop 0 k))

(define (get-value k)
  (exact->inexact (cont-frac (lambda (i) 1) (lambda (i) 1) k)))


(define (new-cont-frac n d k)
  (define (cont-frac-part i)
    (/ (n i) (+ (if (= i k) 0
		    (cont-frac-part (+ i 1))) (d i))))
  (cont-frac-part 1))

