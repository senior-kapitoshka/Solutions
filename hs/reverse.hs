module Reverse where
import Prelude hiding (reverse)

-- | Reverse a list
reverse :: [a] -> [a]
reverse [] = []
reverse [x] = [x]
reverse (x:xs) = reverse xs ++ [x]  


----

module Reverse where
import Prelude hiding (reverse)

-- | Reverse a list
reverse :: [a] -> [a]
reverse = foldl (flip (:)) []

------

module Reverse where
import Prelude hiding (reverse)

import Data.Bool

reverse :: [a] -> [a]
reverse = flip bool [] <$> ((++) <$> reverse . tail <*> pure . head) <*> null