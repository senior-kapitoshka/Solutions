function increment_x(){
  global $x;
  ++$x;
}

function double_x_triple_y_quadruple_z(){
  global $x,$y,$z;
  $x+=$x;
  $y+=$y+$y;
  $z+=$z+$z+$z;
}

function append_whitespace_to_string(){
  $GLOBALS['string'].=" ";
}

function add_world_to_string(){
  $GLOBALS['string'].="world";
}