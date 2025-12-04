module Last where
import Prelude hiding (last)

hd :: [a] -> a
hd [x] = x
hd (x:xs) = x

last :: [a] -> a
last [x] = x
last l = hd (reverse l)

-------------
module Last where
import Prelude hiding (last)

last :: [a] -> a
last [] = error "Empty list"
last (x:[]) = x
last (x:xs) = last xs

-------------
module Last where
import Prelude hiding (last)

last :: [a] -> a
last = head . reverse

-----------
module Last where
import Prelude hiding (last)

last :: [a] -> a
last = foldl (flip const) $ error "the empty list has no last element"