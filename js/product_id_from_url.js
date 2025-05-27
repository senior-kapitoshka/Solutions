function getProductId(url){
    let str=url.substr(0,url.lastIndexOf('-'));
    return str.substr(str.lastIndexOf('-')+1);
  }

  ///////////
  const getProductId = (url) => url.split("-").reverse()[1]
  ////////
  const getProductId = url =>
  url.match(/\d+(?=-\d+)/)[0];
  ////////////
  const getProductId = url => url.replace(/.*p-(\d+).*/, '$1')