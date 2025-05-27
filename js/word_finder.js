function Dictionary(words) {
    this.words = words;
  }
  
  Dictionary.prototype.getMatchingWords = function(pattern) {
    pattern=pattern.replaceAll('?','.');
    let p=new RegExp(`^${pattern}$`,'i');
    return this.words.reduce((res,w)=>{
      if(p.test(w)){
        res.push(w);
      }
      return res;
    },[]);
  }
  /////////////
  function Dictionary(words) {
    this.words = words;
  }
  
  Dictionary.prototype.getMatchingWords = function(pattern) {
    pattern = new RegExp('^'+pattern.replace(/\?/g, '.')+'$');
    return this.words.filter(pattern.test.bind(pattern));
  }
  ///////////
  function Dictionary(words) {this.words = words;}
Dictionary.prototype.getMatchingWords = function(pattern) {
  var re=new RegExp('^'+ pattern.replace(/\?/g, '[a-z]')+'$');
  return this.words.filter(function(v) {return v.match(re);});
}
////////////
function Dictionary(words) {
    this.words = words;
  }
  
  Dictionary.prototype.getMatchingWords = function(pattern) {
   const test = ([...word]) => word.every((e,i,a) => 
           (e === pattern[i] || pattern[i] === '?' )?true:false);
           
    return this.words.filter(w => test(w) && w.length === pattern.length)
  }