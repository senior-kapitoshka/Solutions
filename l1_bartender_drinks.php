/*
function get_drink_by_profession(string $s): string {
  $arr=[
  "Jabroni"	=>"Patron Tequila",
    "School Counselor"	=>"Anything with Alcohol", //  <-----
    "Programmer"	=>"Hipster Craft Beer",
    "Bike Gang Member"	=>"Moonshine", //  <----
    "Politician"	=>"Your tax dollars",
    "Rapper"	=>"Cristal",

];
  return  $arr[ucfirst(strtolower($s))] ?? "Beer";
}*/

function get_drink_by_profession(string $s): string {
  $drink = [
    "jabroni" => "Patron Tequila",
    "school counselor" => "Anything with Alcohol",
    "programmer" => "Hipster Craft Beer",
    "bike gang member" => "Moonshine",
    "politician" => "Your tax dollars",
    "rapper" => "Cristal",
  ];

  return $drink[strtolower($s)] ?? 'Beer';
}

///////////////
function get_drink_by_profession(string $s): string {
  
  return $drink =  preg_match("/Jabroni/i", $s) ? "Patron Tequila" :
  (preg_match("/School Counselor/i", $s) ? "Anything with Alcohol" : 
  (preg_match("/Programmer/i", $s) ? "Hipster Craft Beer" :
  (preg_match("/Bike Gang Member/i", $s) ? "Moonshine" :
  (preg_match("/Politician/i", $s) ? "Your tax dollars" :
  (preg_match("/Rapper/i", $s) ? "Cristal" : "Beer")))));
}

//////////
function get_drink_by_profession(string $s): string {
  $arr = ["Jabroni" => "Patron Tequila", 
          "School Counselor" => "Anything with Alcohol",
          "Programmer" => "Hipster Craft Beer",
          "Bike Gang Member" => "Moonshine",
          "Politician" => "Your tax dollars",
          "Rapper" => "Cristal",
          "anything else" => "Beer"
         ];
  $keyStr = ucwords(strtolower($s));
  if (array_key_exists($keyStr, $arr)) {
    return $arr[$keyStr];
  } else {
    return "Beer";
  }
}

/////////////////
