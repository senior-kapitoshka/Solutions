function datingRange($a) {
  return ($a<=14)?((int)($a - 0.10*$a)."-".(integer)($a + 0.10*$a)):
  ((int)($a*0.5 +7)."-".(integer)(($a-7)*2))
  ;
}

/////////
function datingRange($age)
{
  return $age <= 14 ?
   floor($age * 0.9) .'-' .floor($age * 1.1) :
    floor($age / 2 + 7) .'-' .floor(($age - 7) * 2);
}