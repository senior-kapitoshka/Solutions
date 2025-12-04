
function isLucky($t){
  if(strlen($t)!=6 || !ctype_digit($t)) return false;

  return array_reduce(str_split(substr($t,0,3)),
                      fn($acc,$dig)=>$acc+intval($dig),0)===

    array_reduce(str_split(substr($t,3,3)),
                      fn($acc,$dig)=>$acc+intval($dig),0);
}

////////////////
function isLucky($ticket)
{
  if (! is_numeric($ticket) || strlen($ticket) != 6) {
    return false;
  }
    
  $arr1 = str_split(substr($ticket, 0, 3));
  $arr2 = str_split(substr($ticket, 3));
  
  return array_sum($arr1) == array_sum($arr2);
}

////////
function isLucky($ticket){
  return preg_match('/^\d{6}$/', $ticket) && ($ticket[0] + $ticket[1] + $ticket[2] == $ticket[3] + $ticket[4] + $ticket[5]);
}

/////////
