module PartyPeople (partyPeople) where

partyPeople :: [Word] -> Word
partyPeople pipl  
  | any(>sz) pipl = partyPeople (filter (\p->p<=sz) pipl)
  | otherwise = sz
  where sz= fromIntegral(length pipl)

-----------
module PartyPeople (partyPeople) where

import Data.List (sort)

partyPeople :: [Word] -> Word
partyPeople = foldl (const fst) 0 . filter (uncurry (>=)) . zip [1..] . sort

-------
module PartyPeople (partyPeople) where

import Control.Monad (ap, join)

partyPeople :: [Word] -> Word
partyPeople = fromIntegral . length . (join (until . ap (==))) (join (filter . (>=) . fromIntegral . length))

--------
