(define tolerance 0.0001)
(define (displayed-fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (newline)
    (display guess)
    (let ((next (f guess)))
      (if (close-enough? next guess)
	  next
	  (try next))))
  (try first-guess))

(define (find x)
  (displayed-fixed-point (lambda (x) (/ (log 1000) (log x))) 3))

(define (find-with-average x)
  (displayed-fixed-point (lambda (x) (/ (+ x (/ (log 1000) (log x))) 2)) 3))