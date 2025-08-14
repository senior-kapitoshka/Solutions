module Kth where
import Prelude hiding ((!!))

elementAt :: [a] -> Int -> a
elementAt lst i = get i (zip [1..] lst)
  where 
    get i (x:xs)
      | i==fst x = snd x
      |otherwise = get i xs 

-----------------
module Kth where
import Prelude hiding ((!!))

elementAt :: [a] -> Int -> a
elementAt l i = last $ take i l

------------
module Kth where
import Prelude hiding ((!!))

elementAt :: [a] -> Int -> a
elementAt = flip ((head .) . drop . pred)

-----------
module Kth where
import Prelude hiding ((!!))

elementAt :: [a] -> Int -> a
elementAt (x:xs) 1 = x
elementAt (x:xs) n = elementAt xs (n-1)

---------
