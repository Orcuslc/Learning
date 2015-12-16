(define (same-parity base . args)
  (let ((mod (remainder base 2)))
    (define (args-iter args-list result)
      (if (null? args-list)
	  result
	  (if (= mod (remainder (car args-list) 2))
	      (args-iter (cdr args-list) (cons (car args-list) result))
	      (args-iter (cdr args-list) result))))
  (reverse (args-iter (cons base args) nil))))

(define nil ())
(define (reverse list)
  (define (list-iter list result)
    (if (null? list)
	result
	(list-iter (cdr list) (cons (car list) result))))
  (list-iter list nil))