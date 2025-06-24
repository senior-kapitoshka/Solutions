module Codewars.Kata.Plural where
import Codewars.Kata.Plural.Types

-- data Grammar = Singular | Plural
plural :: (Num a, Eq a) => a -> Grammar
plural 1 = Singular
plural x = Plural

-- 

module Codewars.Kata.Plural where
import Codewars.Kata.Plural.Types

plural :: (Num a, Eq a) => a -> Grammar
plural 1 = Singular
plural _ = Plural


--
module Codewars.Kata.Plural where
import Codewars.Kata.Plural.Types

import Data.Bool

-- data Grammar = Singular | Plural
plural :: (Num a, Eq a) => a -> Grammar
plural = bool Plural Singular . (== 1)

--

module Codewars.Kata.Plural where
import Codewars.Kata.Plural.Types

-- data Grammar = Singular | Plural
plural :: (Num a, Eq a) => a -> Grammar
plural n = if n == 1 then Singular else Plural

--


