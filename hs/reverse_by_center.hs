module Codewars.Kata.Retsec where

reverseByCenter :: String -> String
reverseByCenter xs 
  |(length xs == 0) || (length xs == 1) = xs
  |even (length xs) =
        let hf = div (length xs) 2
            hd = take hf xs
            tl = drop hf xs
        in tl ++ hd   
  |otherwise = 
        let hf = div (length xs) 2
            hd = take hf xs
            md = xs !! hf
            tl = drop (hf+1) xs
         in tl ++ [md] ++ hd   


         -----
module Codewars.Kata.Retsec where

reverseByCenter :: String -> String
reverseByCenter xs =  
  let (q,r) = length xs `quotRem` 2
      (a,b) = splitAt q xs
  in if r == 0 then b ++ a
               else tail b ++ [head b] ++ a

 ---

 module Codewars.Kata.Retsec where

reverseByCenter :: String -> String
reverseByCenter xs = concat [right, center, left]
  where (left, _right) = splitAt mid xs
        (center, right) = splitAt c _right
        (mid, c) = length xs `divMod` 2

 ---


 module Codewars.Kata.Retsec where

reverseByCenter :: String -> String
reverseByCenter xs = right ++ middle ++ left where
  (firstN, middleN) = length xs `divMod` 2
  (left, midRight) = splitAt firstN xs
  (middle, right) = splitAt middleN midRight                     