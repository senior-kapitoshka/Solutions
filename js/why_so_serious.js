let J = str.includes("Jc");
  let O = str.includes("7s");
  let K = str.includes("5s");
  let E = str.includes("As");
  let R = str.includes("9c");
  return J && O && K && E && R;

  ///////////////
  function whySoSerious(str) {
    return ['Jc','7s','5s','As','9c'].every(k=>str.includes(k));
  }
  ////////////
  function whySoSerious(str) {
    return /(?=.*Jc)(?=.*7s)(?=.*5s)(?=.*As)(?=.*9c)/.test(str);
  }

  ////////////
  function whySoSerious(s) {
    return ['Jc','7s','5s','As','9c'].every(v=>s.includes(v));
  }
  ///////////
  