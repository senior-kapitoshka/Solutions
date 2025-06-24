module DuckDuckGoose where

import Preloaded (Player(name))
-- newtype Player = Player {name :: String} deriving (Show, Eq)

duckDuckGoose :: [Player] -> Int -> String
duckDuckGoose p g = name(p !! ((g-1) `mod` length p))

--

module DuckDuckGoose (duckDuckGoose) where

import Preloaded (Player(name))

duckDuckGoose :: [Player] -> Int -> String
duckDuckGoose players goose = name $ cycle players !! pred goose

--

module DuckDuckGoose where

import Preloaded

duckDuckGoose :: [Player] -> Int -> String
duckDuckGoose = (. pred) . (name .) . (!!) . cycle

--

module DuckDuckGoose where

import Preloaded (Player(name))
-- newtype Player = Player {name :: String} deriving (Show, Eq)

duckDuckGoose :: [Player] -> Int -> String
duckDuckGoose players goose = name(players!!(((goose-1) `rem` (length players))))

--

