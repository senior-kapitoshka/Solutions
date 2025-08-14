module Kata.FirstClassFunctionFactory where

factory :: Int -> [Int] -> [Int]
factory x = \i -> map (*x) i
--возращает лямбду, в которой запускается меп
--для каждого аргумента лямбды

module Kata.FirstClassFunctionFactory where

factory :: Int -> [Int] -> [Int]
factory x = \a-> map (\b->x*b) a

---------------------
module Kata.FirstClassFunctionFactory where

factory :: Int -> [Int] -> [Int]
factory = map . (*)

-----------
module Kata.FirstClassFunctionFactory where

factory :: Int -> [Int] -> [Int]
factory x = map (* x)

----------
