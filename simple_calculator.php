/*function calculator($a, $b, $sign) { 
  
 
  if($sign=="+" && (gettype($a)=="float"||gettype($a)=="integer")  && (gettype($b)=="float"||gettype($b)=="integer")) return $a+$b;
    else if($sign=="-" && (gettype($a)=="float"||gettype($a)=="integer") && (gettype($b)=="float"||gettype($b)=="integer")) return $a-$b;
    else if($sign=="*" && (gettype($a)=="float"||gettype($a)=="integer")  && (gettype($b)=="float"||gettype($b)=="integer")) return $a*$b;
  else if($sign=="/" && (gettype($a)=="float"||gettype($a)=="integer")  && (gettype($b)=="float"||gettype($b)=="integer")) return $a/$b;
return "unknown value";
}*/
function calculator($a, $b, $sign) {
      if((is_int($a) && is_int($b)) || is_float($a) ||is_float($b)) {
          switch($sign) {
              case "+":
                  return ($a + $b);
                  break;
              case "-":
                  return ($a - $b);
                  break;
              case "*":
                  return ($a * $b);
                  break;
              case "/":
                  return ($a / $b);
                  break;
              default:
                  return "unknown value";
                  break;
          }
      } else {
          return "unknown value";
      }
  }

  ///////////////
  function calculator($a, $b, $sign) {
  if(preg_match('/^\d+\.?\d*[-+*\/]\d+\.?\d*$/', "$a$sign$b") and is_string($a)===false and is_string($b)===false){
    eval("\$result = $a$sign$b;");
    return $result;
  }
  return "unknown value";
}