function filter_parameters($fn) {
  $res="";
  $rf=new ReflectionFunction($fn);
  foreach($rf->getParameters() as $par){
    if(
        $par->getType()?->getName()=="int"

       && $par->isDefaultValueAvailable()

      && $par->getDefaultValue()==5
      
      ){
      if($res==="")  $res.=$par->getName();
      else $res.=", ".$par->getName();
    }
  }
  return $res;
}

/////////////////

function filter_parameters($fn)
{
    $fn = new ReflectionFunction($fn);
    $result = [];
    foreach ($fn->getParameters() as $p)
    {
        if ($p->hasType() && $p->isDefaultValueAvailable() && $p->getDefaultValue() === 5)
        {
            $result[] = $p->name;
        }
    }
    return implode(", ", $result);
}

////////////////

function filter_parameters($fn) {
  $p = (new ReflectionFunction($fn))->getParameters();
  $p = array_filter($p, function ($p) {return strval($p->getType()) === "int";});
  $p = array_filter($p, function ($p) {return $p->isOptional();});
  $p = array_filter($p, function ($p) {return $p->getDefaultValue() === 5;});
  return implode(", ", array_map(function ($p) {return $p->getName();}, $p));
}