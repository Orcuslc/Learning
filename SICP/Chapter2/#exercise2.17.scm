(define (last-pair list)
  (let ((rest (cdr list)))
   (if (null? rest)
       list
       (last-pair rest))))

(last-pair (list 1 3 4 5 6))
