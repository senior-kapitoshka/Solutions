module Amazon where 

countArara :: Int -> String
countArara n 
  | n==1 = "anane"
  | n==2 = "adak"
  | otherwise ="adak"++" "++countArara (n - 2)

  --
  module Amazon where 

countArara :: Int -> String
countArara n 
  |even n = unwords (replicate (n `div` 2) "adak")
  |otherwise = unwords (replicate ((n - 1) `div` 2) "adak" ++ ["anane"])

--

--unwords — это стандартная функция из модуля Prelude, которая:

--Соединяет список строк в одну строку, вставляя пробелы между элементами.

