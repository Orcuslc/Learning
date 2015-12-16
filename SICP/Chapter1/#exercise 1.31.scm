(define (product term a next b)
  (if (> a b)
      1
      (* (term a) (product term (next a) next b))))

(define (factorial n)
  (define (id n) n)
  (define (inc n) (+ n 1))
  (product id 1 inc n))

(define (round-pi n)
  (define a (product double 1 inc n))
  (define b (product double 2 inc (+ 1 n)))
  (define c (product double-plus 1 inc n))
  (/ (* a b) (square c)))x

(define (double x) (* 2 x))

(define (double-plus x) (+ 1 (* 2 x)))

(define (inc x) (+ x 1))



(define (ano-round-pi n)
  (define (pi-term a)
    (define (base a) (+ (* 2 a) 1))
    (/ (* (- base 1) (+ base 1)) (square base)))
  (define (pi-next a) (inc a))
  (product pi-term 1 pi-next n))


(define (new-product term a next b)
  (define (pro-iter a result)
    (if (> a b)
	result
	(pro-iter (next a) (* result (term a))))))
  (pro-iter a a)