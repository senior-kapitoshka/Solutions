function generator($x=1) {
  while(1) {
   $res=yield $x++;
    if($res!==null) $x=$res;
  }
}

///////////
function generator(): Generator {
  $i = 1;
  while (1) {
    $j = yield $i++;
    if (!is_null($j)) $i = $j;
  }
}