module SF49 where

import Data.Char (chr)
--97 122
decipher :: String -> String
decipher str = helper str "" ""
  where
    helper [] tmp res = res
    helper (x:xs) tmp res
      | read (tmp ++ [x]) >=97 && read (tmp ++ [x]) <= 122  = helper xs "" (res++ [chr (read (tmp ++ [x]))])
      | otherwise = helper xs (tmp++[x]) res

---------------
module SF49 where

decipher :: String -> String
decipher = map (toEnum . read) . f where
  f [] = []
  f str@(c:cs)
    | c == '9'  = take 2 str : f (drop 1 cs)
    | otherwise = take 3 str : f (drop 2 cs)

-------------
module SF49 where

import Data.Char(chr)

decipher :: String -> String
decipher [] = []
decipher xs = (chr $ read $ take n xs) : decipher (drop n xs)
  where n = if (read $ take 2 xs) >= 97 then 2 else 3

-------------
module SF49 where

decipher :: String -> String
decipher []         = []
decipher ('9':x:xs) = toEnum (read ['9',x]) : decipher xs
decipher (x:y:z:xs) = toEnum (read [x,y,z]) : decipher xs 

------------
module SF49 where

import Data.Char


decipher :: String -> String
decipher [] = []
decipher ('9':'7': xs) = 'a':decipher xs
decipher ('9':'8': xs) = 'b':decipher xs
decipher ('9':'9': xs) = 'c':decipher xs
decipher (a:b:c:xs) = (chr $ read [a, b, c]) : decipher xs

-----------
