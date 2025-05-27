const solution = () => {
    var express = require('express');
    var app = express();
    /*
      process.env = {
      PORT: 3000,
      HOST: '0.0.0.0',
    };
    */
    app.listen(process.env.PORT,process.env.HOST,()=>{});
  
  };

  /////////////
  const solution = _ => 
  require('express')().listen(process.env.PORT, process.env.HOST, _ => null)
  //////////
  