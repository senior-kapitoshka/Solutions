module PersonTypeStringRepresentation where
data Person = Person {
  firstName::String,
  lastName::String
}

instance Show Person where
  show (Person fn ln) = fn ++ " " ++ ln

--------------
module PersonTypeStringRepresentation where

data Person = Person String String
instance Show Person where
  show (Person fn ln) = fn ++ " " ++ ln

------------
    