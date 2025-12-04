module Except where

import Data.Maybe (fromJust)

except :: [a] -> Maybe [Int] -> [a]
except ls Nothing = ls
except ls (Just indx) = [x | (i, x) <- zip [0..] ls, notElem i indx]

-------------
