module Codewars.Kata.Conference where

conferencePicker :: [String] -> [String] -> Maybe String
conferencePicker vis [] = Nothing
conferencePicker vis (x:xs)
  | elem x vis = conferencePicker vis xs
  | otherwise = Just (x)

-------------
module Codewars.Kata.Conference where

import Data.List(find)

conferencePicker :: [String] -> [String] -> Maybe String
conferencePicker visited = find (`notElem` visited)

-------------
module Codewars.Kata.Conference where

import Data.Maybe

conferencePicker :: [String] -> [String] -> Maybe String
conferencePicker visited offers = listToMaybe $ filter (`notElem` visited) offers