module PersonalisedGreeting (greet) where

greet :: String -> String -> String
greet name owner =
 case name == owner of
    True -> "Hello boss"
    False -> "Hello guest"

--

module PersonalisedGreeting (greet) where

greet :: String -> String -> String
greet name owner 
    | name == owner = "Hello boss"
    | otherwise     = "Hello guest"

--

module PersonalisedGreeting (greet) where

import Data.Bool

greet :: String -> String -> String
greet owner = bool "Hello guest" "Hello boss" . (==owner)

--

module PersonalisedGreeting (greet) where

greet :: String -> String -> String
greet n o = "Hello " ++ if n == o then "boss" else "guest"

--

module PersonalisedGreeting (greet) where

import Data.Bool

greet :: String -> String -> String
greet = (fmap fmap fmap) (("Hello " ++) . bool "guest" "boss") (==)

--

module PersonalisedGreeting (greet) where

greet :: String -> String -> String
greet name owner = let
  isOwener = name == owner
  greeting = if isOwener then "boss" else "guest"
  in "Hello " ++ greeting