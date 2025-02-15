function coffee(str) {
    str=str.replaceAll(/\bcoffee\b/gi,"COFFEE");
    return str;
  }

  //////////////
  function coffee(str) {
    return str.replace(/coffee/ig, "COFFEE");
  }
  ////////
  const coffee = str => str.replace(/coffee/gi, m => m.toUpperCase())

  /////////
  function coffee(dregs) {
    const ghi = RegExp("coffee", "gi");
     return dregs.replace(ghi, "COFFEE");
   }
   