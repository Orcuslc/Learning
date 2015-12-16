(define (make-segment a b)
  (cons a b))

(define (start-segment x)
  (car x))

(define (end-segment x)
  (cdr x))

(define (make-point a b)
  (cons a b))

(define (x-point a)
  (car a))

(define (y-point a)
  (cdr a))

(define (midpoint-segment x)
  (let ((p (cons (average (car (car x)) (car (cdr x)))
		  (average (cdr (car x)) (cdr (cdr x))))))
    (print-point p)))

(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")"))

(define (get-mid a b c d)
  (let ((v1 (make-point a b))
	(v2 (make-point c d)))
    (let ((line (make-segment v1 v2)))
      (midpoint-segment line))))