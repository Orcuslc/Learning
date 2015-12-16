(define (lookup given-key set)
  (cond ((nul? set) #f)
	((equal? given-key (key (car set)))
	 (car set))
	(else
	 (lookup given-key (cdr set)))))

(define (lookup-tree given-key tree)
  (cond ((null? tree) #f)
	((equal? given-key (key (entry tree)))
	 (entry tree))
	((< given-key (key (entry tree)))
	 (lookup-tree given-tree (left-branch tree)))
	((> given-key (key (entry tree)))
	 (lookup-tree given-tree (right-branch tree)))))\

