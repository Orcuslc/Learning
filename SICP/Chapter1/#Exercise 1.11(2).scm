(define (f n)
  (if (< n 3) 
      n
      (f-iter 0 1 2 2 n)))

(define (f-iter prev3 prev2 prev1 count max-count)
  (if (>= count max-count)
      prev1
      (f-iter prev2 prev1 (+ prev1 (* 2 prev2) (* 3 prev3)) (+ count 1) max-count)))