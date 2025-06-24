module FirstNonConsecutive (firstNonConsecutive) where

firstNonConsecutive :: (Eq a,Enum a, Num a) => [a] -> Maybe a
firstNonConsecutive (x:y:xs)
  | y-x/=1 = Just y -- вычитание возможно только если добавить Num a, иначе succ x /= y
  | otherwise = firstNonConsecutive (y:xs)
firstNonConsecutive _ = Nothing  

--

module FirstNonConsecutive (firstNonConsecutive) where

firstNonConsecutive :: (Eq a,Enum a) => [a] -> Maybe a
firstNonConsecutive (x:y:zs)
  | succ x /= y = Just y 
  | otherwise = firstNonConsecutive (y:zs)
firstNonConsecutive _ = Nothing

--

module FirstNonConsecutive (firstNonConsecutive) where

firstNonConsecutive :: (Eq a,Enum a) => [a] -> Maybe a
firstNonConsecutive (x:y:xs) = if succ x == y then firstNonConsecutive (y:xs) else Just y
firstNonConsecutive _ = Nothing

--
module FirstNonConsecutive (firstNonConsecutive) where
import Control.Applicative

firstNonConsecutive :: (Eq a,Enum a) => [a] -> Maybe a
firstNonConsecutive [x] = Nothing
firstNonConsecutive (x:y:ys) | succ x == y = Nothing <|> firstNonConsecutive (y:ys)
                             | otherwise = Just y <|> firstNonConsecutive (y:ys)

                             --


