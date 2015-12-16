(define (make-center-percent center percent)
  (make-interval (- center (* center percent))
		 (+ center (* center percent))))

(define (center x)
  (/ (+ (lower-bound x) (upper-bound x)) 2))

(define (percent x)
  (/ (/ (- (upper-bound x) (lower-bound x)) 2) 
     (center x)))

