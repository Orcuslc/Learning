(define (union-set a b)
  (cond ((null? a) b)
	((null? b) a)
	(else
	 (let ((a-entry (entry a))
	       (a-left (left-branch a))
	       (a-right (right-branch a))
	       (b-entry (entry b))
	       (b-left (left-branch b))
	       (b-right (right-branch b)))
	   (cond ((= a-entry b-entry)
		  (make-tree a-entry
			     (union-set a-left b-left)
			     (union-set a-right b-right)))
		 ((< a-entry b-entry)
		  (make-tree b-entry
			     (union-set a b-left)
			     b-rught))
		 ((> a-entry b-entry)
		  (make-tree a-entry
			     (union-set a-left b)
			     a-right)))))))

(define (intersection-set a b)
  (cond ((or (null? a) (null? b)) '())
	(else
	 (let ((a-entry (entry a))
	       (b-entry (entry b))
	       (a-left (left-branch a))
	       (a-right (right-branch a))
	       (b-left (left-branch b))
	       (b-right (right-branch b)))
	   (cond ((= a-entry b-entry)
		  (make-tree a-entry
			     (intersection-set a-left b-left)
			     (intersection-set a-right b-right)))
		 ((< a-entry b-entry)
		  (union-set
		   (intersection-set a-right
				     (make-tree b-entry '() b-right))
		   (intersection-set (make-tree a-entry a-left '())
				     b-left)))
		 ((> a-entry b-entry)
		  (union-set
		   (intersection-set (make-tree a-entry '() a-right)
				     b-right)
		   (intersection-set a-left
				     (make-tree b-entry b-left '())))))))))


