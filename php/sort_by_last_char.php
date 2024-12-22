function last($x)
{
  if(empty($x)) return $x;
  $arr=explode(" ",$x);
  usort($arr,function($lhs,$rhs):int{
    return substr($lhs,-1)>substr($rhs,-1)?1:-1;
  });
  return $arr;
}

/////////////////
function last($x)
{
  $words = explode(' ', $x);
  usort($words, function($a, $b) {
    return $a[strlen($a) - 1] <=> $b[strlen($b) - 1];
  });

  return $words;
}
////////////////
function last($x){
  $xArr = explode(" ", $x);
  usort($xArr, function($a, $b){ 
    return substr($a, -1) <=> substr($b, -1);
  });
  return $xArr;
}
//////////
