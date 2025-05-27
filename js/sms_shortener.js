var shortener = function(m) {
    if(m.length<=160) return m;
    let res,t='',e=m.length;
    for(let i=m.length;i>=0;--i){
      if(m[i]===' '){
        t=m.substring(i+1,i+2).toUpperCase()+m.substring(i+2,e)+t;
        res=m.substr(0,i)+t;
        e=i;
        if(res.length<=160) return res;
      }
    }
    return res||m;
    }
    ///////////////
    function shortener(m){
        while(m.length > 160 && (n = m.lastIndexOf(' ')) >= 0)
        m = m.slice(0, n) + m[n+1].toUpperCase() + m.slice(n+2);
        return m;
      }
      ///////////////
      var shortener = function(message) {
        while (message.length > 160 && message.includes(' ')) {
          message = message.replace(
            / ([^ ])([^ ]*)$/,
            (_, c, r) => c.toUpperCase() + r
          );
        }
        return message;
      }
      /////////////
      var shortener = function(message) {
        var len = message.length;
        return message.split('').reverse().join('').replace(/([^\s])\s([^\s])/g, function(m,a,b){
          return len > 160 ? (len--, a[0].toUpperCase() + a.slice(1) + b) : a + ' ' + b
        }).split('').reverse().join('');
      }
      /////////
      const shortener = message => {
        if(message.length <= 160 || !message.includes(' ')) return message
      
        message = message.replace(/(\s+)(.)(?=\S+$)/, (m, p1, p2) => p2.toUpperCase())
      
        return shortener(message)
      }
      //////////////
      var shortener = function(message) {
        let spaces = message.split(' ').length-1;
        if((message.length-spaces)<160){
          let regex = new RegExp(`(( [^ ]+){${Math.abs(message.length-160)}})$`,'g');
          return message.replace(regex,x => x.replace(/ [^ ]/g,c => c[1].toUpperCase()));
        } else{
          return message.replace(/ [^ ]/g,x => x[1].toUpperCase());
        }
      }