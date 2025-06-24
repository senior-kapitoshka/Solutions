String calcType(int a, int b, num res) {
  return a+b==res?"addition":
          a-b==res?"subtraction":
  a*b==res?"multiplication":
  "division"; // operation used
}

/////////////////
String calcType(int a, int b, num res) => 
  switch (res) {
    _ when res == a + b => 'addition',
    _ when res == a - b => 'subtraction',
    _ when res == a * b => 'multiplication',
    _                   => 'division'
  };


