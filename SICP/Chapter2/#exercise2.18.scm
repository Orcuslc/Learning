(define (reverse list)
  ;;notes: the process (cons a list) means append a to the beginning of
  ;;the list
  (define (append-iter list result)
    (if (null? list)
	result
	(append-iter (cdr list) (cons (car list) result))))
  (append-iter list nil))

(define nil ())