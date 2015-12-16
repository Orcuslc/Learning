(define tolerance 0.00000001)

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? next guess)
	  next
	  (try next))))
  (try first-guess))

(define (find-value x)
  (fixed-point (lambda (x) (+ (/ 1 x) 1)) 1.0))

