module Codewars.Kata.GCContent where
import Codewars.Kata.GCContent.Types

-- data Base = A | C | G | T deriving (Eq, Show, Enum, Bounded)

gcContent :: [Base] -> Double
gcContent []= 0.0
gcContent xs = fromIntegral(length (filter (\c->c==C||c==G) xs) * 100)/ fromIntegral(length xs)

-----------
module Codewars.Kata.GCContent where
import Codewars.Kata.GCContent.Types

import Data.List ( genericLength, intersect )

gcContent :: [Base] -> Double
gcContent [] = 0
gcContent xs = 100 * genericLength (intersect xs [C,G]) / genericLength xs

----------
