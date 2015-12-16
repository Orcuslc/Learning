(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

(define (left-branch mobile)
  (car mobile))

(define (right-branch mobile)
  (car (cdr mobile)))

(define (branch-length branch)
  (car branch))

(define (branch-structure branch)
  (car (cdr branch)))

(define (mobile? structure)
  (pair? structure))

(define (branch-weight branch)
  (let ((s (branch-structure branch)))
    (if (mobile? s)
	(total-weight s)
	s)))

(define (total-weight mobile)
  (+ (branch-weight (left-branch mobile))
     (branch-weight (right-branch mobile))))

(define (branch-balanced? branch)
  (let ((s (branch-structure branch)))
    (if (mobile? s)
	(balanced? s)
	#t)))

(define (branch-torque branch)
  (* (branch-length branch)
     (branch-weight branch)))

(define (balanced? mobile)
  (let ((left (left-branch mobile))
	(right (right-branch mobile)))
    (and (= (branch-torque left)
	    (branch-torque right))
	 (branch-balanced? left)
	 (branch-balanced? right))))

