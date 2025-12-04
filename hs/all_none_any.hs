module Codewars.Kata.AllNoneAny where

import Prelude hiding (all, any)

all, none, any :: (a -> Bool) -> [a] -> Bool
all pr [] = True
all pr (x:xs)
  |pr x ==True = all pr xs
  |otherwise = False
none pr [] = True
none pr (x:xs)
  |pr x ==False = none pr xs
  |otherwise = False
any pr [] = False
--any pr lst =  (all pr lst)==False && (none pr lst)==False
any pr (x:xs)
  | pr x      = True
  | otherwise = any pr xs

  -------------------------
  module Codewars.Kata.AllNoneAny where

import Prelude hiding (all, any)

all, none, any :: (a -> Bool) -> [a] -> Bool
all  = (and .) . map
none = (not .) . any
any  = (or  .) . map

--------------
module Codewars.Kata.AllNoneAny where

import Prelude hiding (all, any)

all, none, any :: (a -> Bool) -> [a] -> Bool
all _ [] = True
all f (x:l) 
  | f x = all f l
  | otherwise = False
none _ [] = True
none f (x:l) 
  | f x = False
  | otherwise = none f l
any _ [] = False
any f (x:l) 
  | f x = True
  | otherwise = any f l

-----------------
  