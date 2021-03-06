#| 1.2.1 線形再起と反復
 | 階乗を計算する
 |#

(define (factorial n)
  (if (= n 1)
    1
    (* n (factorial ( - n 1)))))

(print (factorial 3))
(print (factorial 1))

(define (factorial n)
  (fact-iter 1 1 n))

(define (fact-iter product counter max-count)
  (if (> counter max-count)
    product
    (fact-iter (* counter product)
               (+ counter 1)
               max-count)))

(print (factorial 6))
(print (factorial 3))
(print (factorial 1))

(define (fib n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib (- n 1))
                 (fib (- n 2))))))

(print (fib 5))
(print (fib 4))

(define (fib n)
  (fib-iter 1 0 n))

(define (fib-iter a b count)
  (if (= count 0)
    b
    (fib-iter (+ a b) a (- count 1))))

(print (fib 5))
(print (fib 4))

(define (count-change amount) (cc amount 5))
(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount (- kinds-of-coins 1))
                 (cc (- amount (first-denomination kinds-of-coins)) kinds-of-coins)))))
(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

(print (count-change 100))

; 1.2.4 指数計算

(define (expt b n)
  (if (= n 0)
    1
    (* b (expt b (- n 1)))))

(print (expt 2 2))

(define (expt b n)
  (expt-iter b n 1))

(define (expt-iter b counter product)
  (if (= counter 0 )
    product
    (expt-iter b
               (- counter 1)
               (+ b product))))

; 1.2.5 最大公約数

(define (gcd a b)
  (if (= b 0)
    a
    (gcd b (remainder a b))))

(print (gcd 206 40))
