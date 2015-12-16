(define (add-poly p1 p2)
  (if (same-variable? (variable p1) (variable p2))
      (make-poly (variable p1)
		 (add-terms (term-list p1)
			    (term-list p2)))
      (error "Polys not in same var -- Add Poly"
	     (list p1 p2))))

(define (mul-poly p1 p2)
  (if (same-variable? (variable p1) (variable p2))
      (make-poly (variable p1)
		 (mul-terms (term-list p1)
			    (term-list p2)))
      (error "Poly not in same var -- Mul Poly"
	     (list p1 p2))))

