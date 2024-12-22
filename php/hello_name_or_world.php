function hello($name = ''): string {
  return 'Hello, ' . (empty($name) ? 'World' : ucfirst(strtolower($name))) . '!';
}

///////////////
function hello($name = ''): string {
  return sprintf("Hello, %s!", empty($name) ? 'World' : ucfirst(strtolower($name)));
}
///////////
function hello($name = ''): string {
  if ($name == '')  {
    $name = "World";
    }
  return ucwords(strtolower('Hello'.", ".$name . '!'));
}

///////////
