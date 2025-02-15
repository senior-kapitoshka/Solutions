function wordSearch(w, t){
    return new RegExp('\\b'+w+'\\b').test(t);
  }
  /////////////
  function wordSearch(word, text){
    return text.replace(/[^a-z ]/gi, '').split(' ').includes(word)
  }
  //////////
  const wordSearch = (word, text) =>
    !!text.match(`\\b${word}\\b`);
  ///////////
  function wordSearch(word, text){
    return RegExp(`\\b${word}\\b`).test(text);
  }
  /////////
  const wordSearch = (word, text) => text.search("\\b" + word + "\\b") > -1;