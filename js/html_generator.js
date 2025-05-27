function HTMLGen () {
    this.div=(x)=>{
     return `<div>${x}</div>`;
   }
    this.b=(x)=>{
     return `<b>${x}</b>`;
   }
     this.p=(x)=>{
     return `<p>${x}</p>`;
   }
    this.a=(x)=>{
     return `<a>${x}</a>`;
   }
    this.body=(x)=>{
     return `<body>${x}</body>`;
   }
    this.span=(x)=>{
     return `<span>${x}</span>`;
   }
    this.title=(x)=>{
     return `<title>${x}</title>`;
   }
     this.comment=(x)=>{
     return `<!--${x}-->`;
   }
 }

 ///////////
 function HTMLGen() {}

['a', 'b', 'p', 'body', 'div', 'span', 'title'].forEach(function(tag) {
  HTMLGen.prototype[tag] = function(content) {
    return '<' + tag + '>' + content + '</' + tag + '>'
  }
})

HTMLGen.prototype.comment = function(content) {
  return '<!--' + content + '-->'
}

/////////
function HTMLGen () {
    this.div=s=>"<div>"+s+"</div>";
    this.b=s=>"<b>"+s+"</b>";
    this.p=s=>"<p>"+s+"</p>";
    this.a=s=>"<a>"+s+"</a>";
    this.body=s=>"<body>"+s+"</body>";
    this.span=s=>"<span>"+s+"</span>";
    this.title=s=>"<title>"+s+"</title>";
    this.comment=s=>"<!--"+s+"-->";
  }

  /////////
  function HTMLGen () {}
var tagFactory = function(innerTag) {
  return function(txt) {return '<' + innerTag + '>' + txt + '</' + innerTag + '>';};
}
HTMLGen.prototype.p = tagFactory('p');
HTMLGen.prototype.a = tagFactory('a');
HTMLGen.prototype.b = tagFactory('b');
HTMLGen.prototype.body = tagFactory('body');
HTMLGen.prototype.div = tagFactory('div');
HTMLGen.prototype.span = tagFactory('span');
HTMLGen.prototype.title = tagFactory('title');
HTMLGen.prototype.comment = function(txt) {return '<!--' + txt + '-->';};