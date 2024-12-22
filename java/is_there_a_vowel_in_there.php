/*function isVow(array $a): array{
  $res=array();
  foreach($a as $i){
    switch($i){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': array_push($res,(int)$i);
          
          break;
        default:
          array_push($res,$i);
    }
  }
   return $res; // your code here
}*/

///////////
function isVow(array $a)
{
  $vowel = ["a", "e", "i", "o", "u"];
  $result = [];
  for($i = 0; $i < count($a); $i++){
    if(in_array(chr($a[$i]), $vowel)){
      $result[] = chr($a[$i]);
      
    }else{
      $result[] = $a[$i];
    }
  }
  return $result;
}

//////////
function isVow(array $a): array {
  $buffer = [];

  foreach ($a as &$n) {
    array_push($buffer, match ($n) {
      97, 101, 105, 111, 117 => chr($n),
      default => $n,
    });  
  }
  
  return $buffer;
}

/////////////
function isVow(array $a)
{
    $vows = str_split('aeiou');
    return array_map(function($code) use ($vows) {
        $char = chr($code);
        return in_array($char, $vows) ? $char : $code;
    }, $a);
}


////////
function isVow(array $a){
  return array_map(function($e)
            {return array_search(chr($e), ['a', 'e', 'i', 'o', 'u']) !== false ?
                 chr($e) :
                  $e;}, $a);
}

////////////
function isVow(array $a)
{
    $arr=[101,97,105,111,117];
    foreach($a as &$item){
      if(in_array($item,$arr))
        $item=chr($item);
    }
    return $a;
}

//////////

