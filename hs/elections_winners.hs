module ElectionWinners where

electionWinners :: [Int] -> Int -> Int
electionWinners v k 
  | k==0 = k + if check==1 then 1 else 0
  | otherwise = length (filter (\x-> x+k>(maximum v) ) v)
    where check = length (filter (\x-> (maximum v)==x ) v)
  

---------------
module ElectionWinners where

electionWinners :: [Int] -> Int -> Int
electionWinners vs k 
  | k == 0    = if valid (==m) == 1 then 1 else 0
  | otherwise = valid (m-k<)
  where m = maximum vs
        valid = length . flip filter vs

        ------------
          