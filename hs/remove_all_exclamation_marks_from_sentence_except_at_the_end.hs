module Kata (remove) where

remove :: String -> String
remove s = reverse ( (fst splitStr) ++ (filter(\c->c/='!') (snd splitStr)))
  where
    splitStr = span(\c->c=='!') (reverse s)


-------------
module Kata (remove) where

remove :: String -> String
remove s = filter (/='!') s ++ takeWhile (=='!') (reverse s)

--------
module Kata (remove) where

remove :: String -> String
remove = reverse . uncurry (++) . fmap (filter (/= '!')) . span (== '!') . reverse

--------
module Kata (remove) where

remove :: String -> String
remove s =
  let s' = reverse s
      suffix = takeWhile (=='!') s'
      rest = reverse $ dropWhile (=='!') s'
      prefix = filter (/='!') rest
  in prefix ++ suffix