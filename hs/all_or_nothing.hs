module AllOrNothing (possiblyPerfect) where

possiblyPerfect :: String -> String -> Bool
possiblyPerfect k a = 
  all (\(x,y)-> (x=='_'|| x==y)) (zip k a)
  || all (\(x,y)-> (x=='_' || x/=y) ) (zip k a)

---------------
module AllOrNothing (possiblyPerfect) where

possiblyPerfect :: String -> String -> Bool
possiblyPerfect key ans =
  let known = filter ((/= '_') . fst) $ zip key ans
  in  all (uncurry (==)) known || all (uncurry (/=)) known 

----------
module AllOrNothing (possiblyPerfect) where

possiblyPerfect :: String -> String -> Bool
possiblyPerfect key answers = all eq filtered || all neq filtered
  where
    filtered = filter ((/='_') . fst) $ zip key answers
    eq (a,b) = a == b
    neq (a,b) = a /= b 

    -------------
        