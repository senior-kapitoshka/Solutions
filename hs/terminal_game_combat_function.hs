module Health (updateHealth) where

updateHealth :: Double -> Double -> Double
updateHealth h d
  | h > d     = h - d
  | otherwise = 0

--

module Health (updateHealth) where

updateHealth :: Double -> Double -> Double
updateHealth health damage = max 0 $ health - damage

--

module Health (updateHealth) where

updateHealth :: Double -> Double -> Double
updateHealth health damage = max 0 (health - damage)

--

module Health (updateHealth) where

updateHealth :: Double -> Double -> Double
updateHealth health damage
  | hp < 0 = 0
  | otherwise = hp
  where hp = health - damage

--