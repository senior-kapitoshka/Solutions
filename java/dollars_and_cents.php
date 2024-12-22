function format_money(float $a): string {
  return '$' . number_format($a, 2, '.', '');
}

/////////////
function format_money(float $amount): string {
  return sprintf('$%.2f', $amount);
}
//////////
function format_money(float $amount): string {
  return "\$".number_format($amount,2,".","");
}

/////////////
