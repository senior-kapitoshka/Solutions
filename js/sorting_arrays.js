function sortArray(a1, a2) {
    let t=[...Array(a2.length).keys()];
      a2.forEach((s)=>{
        let r= new RegExp("^"+s[0]+"[A-za-z]*", "i");
       
        let i=a1.indexOf(a1.find(x=>r.test(x)));
        t[i]=s;
      });
      return t;
    }

    ////////////////
    const sortArray = (a1, a2) => a1.map( v => a2.find( w => v[0]===w[0] ) );

    ////////////
    