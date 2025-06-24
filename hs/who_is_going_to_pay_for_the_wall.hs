module WhoIsPaying where

whoIsPaying :: String -> [String]
whoIsPaying n | length n <= 2 = [n]
              | otherwise = [n, (take 2 n)]

--
module WhoIsPaying where

whoIsPaying :: String -> [String]
whoIsPaying (n@(x:y:_:_)) = [n, [x,y]]
whoIsPaying n = [n]

--

module WhoIsPaying where

whoIsPaying :: String -> [String]
whoIsPaying s = if length(s) > 2
  then [s, (take 2 s)]
  else [s]

--

module WhoIsPaying where

whoIsPaying :: String -> [String]
whoIsPaying [] = [""]
whoIsPaying (x:[]) = [[x]]
whoIsPaying (x:y:[]) = [x:y:[]]
whoIsPaying (x:y:z) = [x:y:z, x:y:[]]

--
