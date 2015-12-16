(define (iterative-improve good-enough? improve)
  (lambda (x)
    (let ((new-x (improve x)))
      (if (good-enough? x new-x)
	  new-x
	  ((iterative-improve good-enough? improve) new-x)))))