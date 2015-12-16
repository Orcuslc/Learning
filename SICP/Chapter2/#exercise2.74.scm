(define (install-division-package)
  (define (get-record name file)
    (cond ((null? file) (error "no result" file))
	  ((eq? name (get-name (cadr file)))
	   (cons (cadr file)
		 (get-record name (cdr file))))
	  (else (get-record name (cdr file)))))
  (define (get-name record)
    (car record))

  (put 'get-record 'division get-record)
  (put 'get-name 'division get-name)
  'done)

(define (get-record name file)
  (apply-generic 'get-record name file))

(define (apply-generic op name file)
  (let ((division-name (type-tag file)))
    (let ((proc (get op division-name)))
      (if proc
	  (proc name file)
	  (error "no result" name file)))))

(define (type-tag file)
  (car file))

(define (get-salary name file)
  (cond ((null? file) (error "no result" name file))
	((eq? name (get-name (cadr file)))
	 (cons (cadr (cadr file))
	       (get-salary name (cdr file))))
	(else (get-salary name (cdr file)))))

(put 'get-salary 'division get-salary)

(define (get-salary name file)
  (apply-generic 'get-salary name file))


(define (find-employee-record name list)
  (if (null? list)
      (error "no result" name list)
      (append (get-record (car list))
	      (find-employee-record name
				    (cdr list)))))

