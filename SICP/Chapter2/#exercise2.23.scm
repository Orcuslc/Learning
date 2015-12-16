(define (for-each process item-list)
  (cond ((not (null? item-list))
	 (process (car item-list))
	 (for-each process (cdr item-list)))))
 