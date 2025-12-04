module SomeButNotAll (someButNotAll) where

someButNotAll :: (a -> Bool) -> [a] -> Bool
someButNotAll lst prd = (any lst prd) && not (all lst prd) 

--------------

module SomeButNotAll (someButNotAll) where

import Data.List (partition)

someButNotAll :: (a -> Bool) -> [a] -> Bool
someButNotAll p xs = not (null a) && not (null b)
  where (a, b) = partition p xs

---------------

module SomeButNotAll (someButNotAll) where

someButNotAll :: (a -> Bool) -> [a] -> Bool
someButNotAll = (<*>) <$> (<$>) (&&) . any <*> (not.) . all

--------------


