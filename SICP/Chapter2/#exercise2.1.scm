(define (make-rat n d)
  (let ((new-n (cond ((> (* n d) 0) (abs n))
		     ((< (* n d) 0) (- (abs n)))))
	(new-d (abs d)))
    (let ((g (gcd (abs new-n) (abs new-d))))
    (cons (/ new-n g) (/ new-d g)))))

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))
