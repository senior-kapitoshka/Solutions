module Kata.Contamination1 (contamination) where

contamination :: String -> String -> String
contamination text ""   = "" 
contamination text char = replicate (length text) (head char)

--

module Kata.Contamination1 (contamination) where

contamination :: String -> String -> String
contamination = (>>)

{-
  It is quite terse! The >> function is related to another function called >>= which is sometimes called "flat map". If we look at that function's type:

λ> :info (>>=)
class Applicative m => Monad (m :: * -> *) where
  (>>=) :: m a -> (a -> m b) -> m b
We can see that >>= takes two arguments:

a monad m a (in this case, m will stand for the list type [], and a will stand for the Char type)
a function (a -> m b), in this case (Char -> [Char])
(>>=) xs f will apply the function f to each character of the string xs. But instead of returning a list of strings, it "flattens" the result, concatenating the strings together so you get a single string as a result. For example:

λ> (>>=) "xyz" (\c -> [c, ':', c, ' '])
"x:x y:y z:z "
It's a pretty handy function. >> is very similar, but instead of taking a function as the second argument (a -> m b) it just takes another m b and uses that. It's effectively the same as passing a function to >>= of type (a -> m b) that just throws away its argument:

The following three expressions mean the same thing, then:

λ> (>>=) "xyz" (\_ -> "hello")
"hellohellohello"

λ> (>>=) "xyz" (const "hello")
"hellohellohello"

λ> (>>) "xyz" "hello"
"hellohellohello"
-}

--

module Kata.Contamination1 (contamination) where

contamination :: String -> String -> String
contamination = (*>)

--

module Kata.Contamination1 (contamination) where

import Data.Functor.Apply

contamination :: String -> String -> String
contamination = (.>)