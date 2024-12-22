function bandNameGenerator(str) {
    return str[0]!==str[str.length-1]?"The "+ str.substring(0,1).toUpperCase()+str.substring(1).toLowerCase():
    str.substring(0,1).toUpperCase()+str.substring(1).toLowerCase()+str.substring(1).toLowerCase();
    ; 
  }

  ////////////
  const bandNameGenerator = s => s[0] != s[s.length-1] ? "The " + s[0].toUpperCase() + s.slice(1) :
       s[0].toUpperCase() + s.slice(1) + s.slice(1);

       /////////////
       bandNameGenerator = s => s[0] === s[s.length - 1] ? 
  `${s[0].toUpperCase()}${s.slice(1, -1)}${s}` :
  `The ${s[0].toUpperCase()}${s.slice(1)}`;

  //////////
  