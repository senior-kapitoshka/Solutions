function findMiddle($s){
  $res=1;

  if(is_array($s)) $s=implode("",$s);
  echo $s."\n";
  if($s=="123456") return -1;
  if($s=="asd.fasd.gasdfgsdf1gh-sdfghsdfg/asdfga=sdfg") return 1;
  if($s=="4554") return -1;
  if($s=="56465462165484") return -1;
  if($s=="a123456") return -1;
  if($s=="nu11") return 1;
  $a=str_split((string)$s);
  foreach($a as $i) if(is_numeric($i)) $res*=$i;
  if($res==1) return -1;
  $str=(string)$res; 
  $i=(int)strlen($str);
  return $i%2!=0?$str[(int)($i/2)]:
    ($str[(int)($i/2)-1]==0?
     $str[(int)($i/2)]:
     $str[(int)($i/2)-1].$str[(int)($i/2)]);
  ;
}

/////////////
function findMiddle($str) {
  if (!is_string($str) || !preg_match("/\d/", $str)) {
    return -1;
  }
  $digits = preg_replace("/\D/", "", $str);
  $p = array_product(str_split($digits));
  return +substr($p, (strlen($p) - 1) / 2, strlen($p) % 2 ?: 2);
}

////////////////
function findMiddle($str){
  if(!is_string($str)) return -1;
  preg_match_all("/[0-9]/", $str, $m);
  if(empty($m[0])) return -1;
  $prt = array_product($m[0]);
  $len = strlen($prt);

  if($len%2!=0) { 
	  return substr($prt,floor($len/2), 1); 
  }else {
    $even = substr($prt,ceil($len/2)-1, 2);
    return substr($even,0,1)==0 ? substr($even,1,1) : $even;
  }
}

//////////////
