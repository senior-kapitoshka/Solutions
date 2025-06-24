module CheckVowel where 
import Data.Char (toLower)

checkVowel :: String -> Int -> Bool 
checkVowel xs i
  | (i>=0) && (i< length xs) &&( (toLower (xs !! i)) == 'a') = True
  | (i>=0) && (i< length xs) &&( (toLower (xs !! i)) == 'e') = True
  | (i>=0) && (i< length xs) &&( (toLower (xs !! i)) == 'i') = True
  | (i>=0) && (i< length xs) &&( (toLower (xs !! i)) == 'o') = True
  | (i>=0) && (i< length xs) &&( (toLower (xs !! i)) == 'u') = True
  | otherwise = False

  --

  module CheckVowel where 

checkVowel :: String -> Int -> Bool 
checkVowel xs index = 
  index >= 0 && index < length xs && elem (xs !! index) "aeiouAEIOU"

  --

  module CheckVowel where 

checkVowel :: String -> Int -> Bool 
checkVowel xs index = if index < length xs && index >= 0 
    then elem (xs !! index) "aeiouAEIOU" 
    else False

    --