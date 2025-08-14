function sea_sick(string $s): string {
  $cnt=0;
  $n=strlen($s);
  for($i=1;$i<$n;++$i){
    if(($s[$i-1]=='_' && $s[$i]=='~')||($s[$i-1]=='~' && $s[$i]=='_'))
      ++$cnt;
  }

  if($cnt==0 || $n/$cnt>5) return "No Problem";
  
  return "Throw Up";
}

///////////
function sea_sick(string $s): string {
  return substr_count($s,'_~')+substr_count($s,'~_')>strlen($s)/5?'Throw Up':'No Problem';
}