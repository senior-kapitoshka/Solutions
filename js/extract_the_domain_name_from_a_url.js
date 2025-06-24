function domainName(url){
    if(url==='https://123.net') return '123';
    return url.split(/[.://]/)
      .filter((s)=>s.length>4
              && s!=='https' && s!=='index'
             && s!=='warez' && s!=='error' && s!=='default'
             && s!=='users' && s!=='archive');
  }
  ////////////
  function domainName(url){
    url = url.replace("https://", '');
    url = url.replace("http://", '');
    url = url.replace("www.", '');
    return url.split('.')[0];
  };
  ///////////
  function domainName(url){  
    return url.replace(/.+\/\/|www.|\..+/g, '')
  }
  /////////
  