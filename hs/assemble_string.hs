module AssembleString (assembleString) where

assembleString :: [[Char]] -> [Char]
assembleString lst = assemble lst 0 (length lst) 0 (length (head lst)) '#' []
  where
    assemble [] _ _ _ _ _ res = res 
    assemble lst i n idx sz char res
      | idx == sz = res
      | i == n = assemble lst 0 n (idx+1) sz '#' (res++[char])
      | (i < n) && (((lst !! i) !! idx)/='*') = assemble lst (i+1) n idx sz ((lst !! i) !! idx) res
      | otherwise = assemble lst (i+1) n idx sz char res

--------------------
module AssembleString (assembleString) where

import Data.List
import Data.Maybe

assembleString :: [String] -> String
assembleString = map (fromMaybe '#' . find (/= '*')) . transpose

{-
    1. transpose

    transpose :: [[a]] -> [[a]]

    Она меняет строки и столбцы местами.

    Например:

    transpose ["a*c",
            "*b*",
            "c**"]


    даст:

    ["a*c",   -- первый столбец
    "*b*",   -- второй столбец
    "c**"]   -- третий столбец


    То есть функция ожидает список строк, где каждый символ может быть буквой или '*'.

    ✅ 2. find (/= '*')

    find ищет первый элемент, удовлетворяющий условию:

    find (/= '*') "a*c"   → Just 'a'
    find (/= '*') "*b*"   → Just 'b'
    find (/= '*') "***"   → Nothing


    То есть из столбца выбирается первая не-звёздочка.

    ✅ 3. fromMaybe '#'

    Если find вернул Nothing, то символ заменяется на '#':

    fromMaybe '#' (Just 'a') → 'a'
    fromMaybe '#' Nothing    → '#'

    ✅ 4. (fromMaybe '#' . find (/= '*'))

    Это композиция:

    сначала find (/= '*')

    потом fromMaybe '#'

    То есть берём первый не-'*' символ в столбце, а если нет — ставим '#'.

    ✅ 5. map (...)

    Применяется ко всем столбцам после transpose.

-}

-------------
module AssembleString (assembleString) where
import Data.List (transpose)

assembleString :: [[Char]] -> [Char]
assembleString = concatMap choise . transpose

choise :: String -> String
choise [] = "#"
choise (x : xs) | x == '*' = choise xs
                | otherwise = pure x

-------------
module AssembleString (assembleString) where

import Data.List (transpose)

assembleString :: [[Char]] -> [Char]
assembleString xs = map go $ map (filter (/= '*')) $ transpose xs where
  go [] = '#'
  go (x:_) = x

------------
module AssembleString (assembleString) where
import Data.List
import Data.Maybe

assembleString :: [[Char]] -> [Char]
assembleString [] = ""
assembleString ("":_) = ""
assembleString xs = fromMaybe '#' (find (/= '*') (map head xs)):assembleString (map tail xs)

------------
