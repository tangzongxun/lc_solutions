(define/contract (two-sum nums target)
  (-> (listof exact-integer?) exact-integer? (listof exact-integer?))
    (let ((ht (make-hash)))
        (let loop ((l nums) (i 0))
          (if (null? l)
              (error "no result")
              (let* ((num (car l))
                     (diff (- target num)))
                  (if (hash-has-key? ht diff)
                      (list i (hash-ref ht diff))
                      (begin
                        (hash-set! ht num i)
                        (loop (cdr l) (+ i 1)))))))))


