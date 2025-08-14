{-
module Existential (Showable(S)) where

data Showable a = S a

instance (Show a) => Show (Showable a) where
  show (S x) = show x

  --------->

>>> map show [S (3 :: Int), S "foo", S ()]
["3","\"foo\"","()"]

-}

module Existential (Showable(S)) where

data Showable = forall a. Show a => S a

instance Show Showable where
  show (S x) = show x


