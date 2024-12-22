function whose_move(string $l, bool $w): string {
  return $w? $l : (($l=="white")?"black":"white");
}
//////////////////
function whose_move(string $last_player, bool $win): string {
  return $win ? $last_player : ($last_player == 'black' ? 'white' : 'black');
}

///////////
function whose_move(string $last_player, bool $win): string {
  return $win ? $last_player : ['black' => 'white', 'white' => 'black'][$last_player];
}

//////////
function whose_move(string $player, bool $win): string {
    $players = ["black", "white"];
    return $win ? $player : array_reverse($players)[array_search($player, $players)];
}

//////////
define ('NOT', ['black' => 'white', 'white' => 'black']);
function whose_move(string $last_player, bool $win): string {
  return $win ? $last_player : NOT[$last_player];
}