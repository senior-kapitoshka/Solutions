module ListOps where
import Prelude hiding (head, tail, init, last)

head :: [a] -> a
head [x] = x
head (x:xs) = x 

tail :: [a] -> [a]
tail [x] = []
tail (x:xs)= xs

init :: [a] -> [a]
init [x] =[]
init lst = reverse $ tail $ reverse lst

last :: [a] -> a
last [x] = x
last lst =  head $ reverse lst


--------------------
module ListOps where
import Prelude hiding (head, tail, init, last)

head :: [a] -> a
head (x:_) = x

tail :: [a] -> [a]
tail (_:xs) = xs

init :: [a] -> [a]
init [x] = []
init (x:xs) = x : init xs

last :: [a] -> a
last [x] = x
last (_:xs) = last xs

---------------
module ListOps where
import Prelude hiding (head, tail, init, last)

head = (!! 0)
tail = drop 1
init = (reverse . tail . reverse)
last = (head . reverse)

------------
