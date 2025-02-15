String.prototype.formatWith = function () {
    var t=this;
    for(let i=0,n=arguments.length;i<n;++i){
      t=t.replaceAll("{"+i+"}",arguments[i]);
    }
    return t;
  }

  /////////////
  String.prototype.formatWith = function (...args) {
    return this.replace(/\{(\d+)\}/g, (s, n) => n < args.length ? args[n] : s)
  }

  ///////////
  String.prototype.formatWith = function (...arr) {
    return this.replace(/{\d}/g, v => arr[[...v][1]] || v);
  }

  //////////
  String.prototype.formatWith = function (...args) {
    return [...args].reduce((s, x, i) => s.replace(new RegExp(`\\{${i}\\}`, "g"), x), this);
  }

  //////////
  String.prototype.formatWith = function () {
    var s=this;
    for (var i=0; i<arguments.length; ++i)
      s=s.split("\{"+i+"\}").join(arguments[i])
    return s
  }
  /////////
  String.prototype.formatWith = function () {
    var args = [...arguments];
    
    return this.replace(/{(\d+)}/g,v => args[+v.substr(1,v.length - 2)] || v); 
  }
  /////////////
  