module SumOfJustsAndNothings where
{-
sumJusts :: [Maybe Integer] -> Integer

sumJusts = foldl (\acc i-> acc + maybe 0 id i) 0 
-}

sumJusts :: [Maybe Integer] -> Maybe Integer

sumJusts l = Just (foldl (\acc i-> acc + maybe 0 id i) 0 l)

{-
    maybe 0 id i
    i — это элемент типа Maybe Integer, т.е. либо Just x, либо Nothing.

    maybe — встроенная функция в Haskell:

    maybe :: b -> (a -> b) -> Maybe a -> b
    Её аргументы:

    Первый (0) — значение по умолчанию, которое возвращается, если i = Nothing.

    Второй (id) — функция, которая применяется к содержимому Just x.

    id — это встроенная функция Haskell, которая просто возвращает то, что ей передали:


    id :: a -> a
    id x = x
    То есть id здесь нужна, чтобы извлечь число из Just x без изменений.

    Третий аргумент (i) — сам Maybe Integer.
-}

--------------------
module SumOfJustsAndNothings where

import Data.Maybe (catMaybes)

sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts = Just . sum . catMaybes

---------------
module SumOfJustsAndNothings where

sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts = Just . sum . fmap sum

-------------
module SumOfJustsAndNothings where
import Data.Maybe

sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts [] = Just 0
sumJusts (Just x:xs) = Just (x + fromJust (sumJusts xs))
sumJusts (Nothing:xs) = sumJusts xs

--------------
module SumOfJustsAndNothings where

sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts = Just . sum . map f
  where
    f Nothing = 0
    f (Just a) = a



