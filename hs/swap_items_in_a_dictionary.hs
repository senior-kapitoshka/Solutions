module SwapDict where

import Data.Map (Map,fromListWith,toList)

swapDict :: Map String String -> Map String [String]
swapDict mp = fromListWith (++) [ (v, [k]) |(k,v)<- toList mp] 

---

module SwapDict where

import Data.Map (Map, toList, fromListWith)

swapDict :: Map String String -> Map String [String]
swapDict = fromListWith (++) . map (\(k, v) -> (v, [k])) . toList

---
module SwapDict where

import Data.Map (Map, insertWith, empty, foldrWithKey)

swapDict :: Map String String -> Map String [String]
swapDict = foldrWithKey (\k v -> insertWith (++) v [k]) empty

---

module SwapDict where

import qualified Data.Map as M

swapDict :: M.Map String String -> M.Map String [String]
swapDict d = M.fromListWith (++) xs
  where
    xs = [(b,[a]) | (a,b) <- M.toList d]


----
module SwapDict where

import qualified Data.Map.Strict as M

swapDict :: M.Map String String -> M.Map String [String]
swapDict = M.foldrWithKey (flip (M.insertWith (++)) . pure) M.empty