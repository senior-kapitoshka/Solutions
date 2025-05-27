function reverseParentheses(s) {
    while (s.match(/\)/)) {
      const r = s.match(/\([a-zA-z]+\)/)[0];
      s = s.replace(r, (r) => r.slice(1, -1).split('').reverse().join(''));
    }
  
    return s;
  }

  ///////////
  function reverseParentheses(s) {
    while (s.includes('(')) {
      s = s.replace(/\([^\(\)]*\)/, (match) => match.split('').reverse().join('').slice(1, -1));
    }
    
    return s;
  }