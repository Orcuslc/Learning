(define (square-list items)
  (if null? items)
  nil
  (cons (square (car x)) (square-list (cdr items))

(define nil ())

(define (square-list items)
  (map square items))

(define (square x)
  (* x x))

