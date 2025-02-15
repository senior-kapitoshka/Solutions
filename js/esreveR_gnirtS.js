String.prototype.reverse = function(){
    let t=this;
    let res= t.split("").reverse().join("");
    return res;
  }

  ///////////
  String.prototype.reverse = function(){
    return this.split('').reverse().join(''); 
  }

  ///////////
  String.prototype.reverse = function() {
    let rev = [];
    for (let letter of this) {
      rev.unshift(letter);
    }
    return rev.join('');
  }
  ////////////
  String.prototype.reverse = function () {
    return [...this].reverse().join``;
  };