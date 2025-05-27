function anchorize(text){
    console.log(text.replaceAll(new RegExp("[a-zA-Z]+://[a-zA-Z]+.com","g"),"<a href=\"$&\">$&</a>"));
    return text.replaceAll(new RegExp("[a-zA-Z]+://[a-zA-Z:/]+.[a-z]+","g"),"<a href=\"$&\">$&</a>")
  }

  /////////////////
  function anchorize(text){
    var urlRegex = /((https?|ftps?|smb|file):\/\/\S+)/gi;
    return text.replace(urlRegex, "<a href=\"$1\">$1</a>")
  }
  ///////////
  const anchorize = text =>
  text.replace(
    /(https?|ftps?|file|smb)\S+/gi,
    url => `<a href="${url}">${url}</a>`
  )