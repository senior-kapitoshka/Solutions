module Reject (reject) where

reject :: (a -> Bool) -> [a] -> [a]
reject pred = filter (not . pred)

---------------
module Reject (reject) where

reject :: (a -> Bool) -> [a] -> [a]
reject = filter . (not .)

--------------
module Reject (reject) where

reject :: (a -> Bool) -> [a] -> [a]
reject p xs = filter  (\x -> not (p x)) xs

-----------
module Reject (reject) where

reject :: (a -> Bool) -> [a] -> [a]
reject fn xs = [x | x <- xs, not (fn x)]