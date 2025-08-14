module FireFight (fire_fight) where

import Data.Text (Text)

import qualified Data.Text as T

fire_fight :: Text -> Text
fire_fight s =  T.unwords $ map (\x -> 
  if x== T.pack "Fire" then T.pack "~~"else x) (T.words s)

  -----------
  {-# LANGUAGE OverloadedStrings #-}

module FireFight (fire_fight) where

import Data.Text (Text, replace)

fire_fight :: Text -> Text
fire_fight = replace "Fire" "~~"

--------------
module FireFight (fire_fight) where

import Prelude hiding (unwords, words)
import Data.Text (Text, pack, unwords, words)

fire_fight :: Text -> Text
fire_fight text = unwords . map replace . words $ text
  where
    replace word
      | word == pack "Fire" = pack "~~"
      | otherwise   = word

 ----------

 module FireFight (fire_fight) where

import Data.Text

fire_fight :: Text -> Text
fire_fight s
 | (pack "Fire") `isInfixOf` s = fire_fight $ replace (pack "Fire") (pack "~~") s
 | otherwise = s     