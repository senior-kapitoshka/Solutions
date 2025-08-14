module SlotMachine (slot) where


slot :: String -> Int
slot str 
  |str== "!!!!!" || str== "?????" =1000
  |str== "!!!!?" || str== "?!!!!" || str== "????!" || str== "!????"=800
  |str== "!!!??" || str== "???!!" || str=="??!!!"||str=="!!???"=500
  |str== "!!!?!" || str== "!???!" ||str=="!?!!!" ||str=="?!!!?"||str=="???!?"||str=="?!???"=300
  |str== "??!!?" || str== "!!?!!"|| str=="!!??!" || str=="!??!!" ||str=="??!??"||str=="?!!??"=200
  |str== "?!??!" || str== "!!?!?" || str=="??!?!"|| str=="!?!??"|| str=="?!?!!"||str=="!??!?"||str=="!?!!?"||str=="?!!?!" =100
  |otherwise =0



  ---------------
  {-# LANGUAGE LambdaCase #-}

module SlotMachine (slot) where

import Control.Arrow ((>>>))
import Data.List (sort, group)

slot :: String -> Int
slot = group
       >>> map length
       >>> sort
       >>> \case
             [5] -> 1000
             [1, 4] -> 800
             [2, 3] -> 500
             [1, 1, 3] -> 300
             [1, 2, 2] -> 200
             [1, 1, 1, 2] -> 100
             _ -> 0
------------
module SlotMachine (slot) where

import Data.List (group, sort)

slot :: String -> Int
slot                  = go . sort . map length . group
   where go [5]       = 1000
         go [_,4]     = 800
         go [_,_]     = 500
         go [_,_,3]   = 300
         go [_,_,_]   = 200
         go [_,_,_,_] = 100
         go _         = 0

-------
module SlotMachine (slot) where

import Data.List (group, sortOn)
import Data.Ord (Down (Down))

slot :: String -> Int
slot = score . sortOn Down . fmap length . group
  where
    score [5] = 1000
    score (4 : _) = 800
    score [3, 2] = 500
    score (3 : _) = 300
    score (2 : 2 : _) = 200
    score (2 : _) = 100
    score _ = 0

-----
{-# LANGUAGE LambdaCase #-}

module SlotMachine (slot) where

import Data.List (sort, group)

slot :: String -> Int
slot = f . sort . (map length) . group
       
 where f = \case
             [5] -> 1000
             [1, 4] -> 800
             [2, 3] -> 500
             [1, 1, 3] -> 300
             [1, 2, 2] -> 200
             [1, 1, 1, 2] -> 100
             _ -> 0    