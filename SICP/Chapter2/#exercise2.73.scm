(define (deriv exp var)
  (cond ((number? exp) 0)
	((variable? exp)
	 (if (same-variable? exp var) 1 0))
	(else ((get 'deriv (operator exp))
	      (oprands exp)
	      var))))

(define (operator exp) (car exp))

(define (operands exp) (cdr exp))

(define (variable? x) (symbol? x))

(define (same-variable? x1 x2)
  (and (variable? x1) (variable? x2) (eq? x1 x2)))

(define (install-sum-package)
  ;;internal procedures
  (define (make-sum x1 x2) (cons a1 a2))
  (define (added sum) (cadr sum))
  (define (augend sum) (caddr sum))
  (define (deriv-sum s)
    (make-sum (deriv (addend s))
	      (deriv (augend s))))
  ;;interface to the rest of system
  (define (tag x) (attach-tag '+ x))
  (put 'deriv '(+) deriv-sum)
  (put 'make-sum '+
       (lambda (x y) (tag (make-sum x y))))
  'done)

(define (make-sum x y)
  ((get 'make-sum '+) x y))

(define (install-product-package)
  ;;internal procedures
  (define (make-product m1 m2) (cons m1 m2))
  (define (multiplier p) (cadr p))
  (define (multiplicand p) (caddr p))
  (define (deriv-product p)
    (make-sum
     (make-product (multiplier exp)
		   (deriv (multiplicand exp) var))
     (make-product (deriv (multiplier exp) var)
		   (multiplicand exp))))  
  (define (tag x) (attach-tag '* x))
  (put 'deriv '(*) deriv-product)
  (put 'make-product '* 
       (lambda (x y) (tag (make-product x y))))
  'done)

(define (make-product x y)
  ((get 'make-product '*) x y))

(define (deriv x) (apply-generic 'deriv x))

(define (exponentation-deriv exp var)
  (make-product (exponent exp)
		(make-product
		 (make-exponentiation (base exp)
				      (make-sum (exponent exp) -1))
		 (deriv (base exp) var))))

(define (exponent exp)
  (cadr exp))

(define (base exp)
  (car exp))

(define (make-exponentiation base exponent)
  (cond ((=number? exponent 0) 1)
	((=number? exponent 1) base)
	((= number? base 1) 1)
	(else (list '** base exponent))))

(put 'deriv '** exponentiation-deriv)

