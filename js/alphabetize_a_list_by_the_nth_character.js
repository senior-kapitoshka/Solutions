const sortIt=(l, n)=>// l.split(', ').sort((a,b)=>a[n-1].toLowerCase()>b[n-1].toLowerCase()?1:a[n-1].toLowerCase()<b[n-1].toLowerCase()?-1:0).join(', ')
l.split(", ")
    .sort((a, b) => {
      const [first, second] = [a[n - 1].toLowerCase(), b[n - 1].toLowerCase()];
      if (first === second) {
        return a < b ? -1 : 1;
      }
      return first < second ? -1 : 1;
    })
    .join(", ");

    /////////////
    const sortIt = (list, n) =>
  list.split(`, `)
    .sort((a, b) =>
             a[n - 1].toLowerCase().localeCompare(b[n - 1].toLowerCase()) 
                                || a.localeCompare(b))
    .join(`, `);

    ////////////
    function sortIt(list, n) {
        return list.split`, `.sort( (a,b) => {
          if(a[n-1].toLowerCase() > b[n-1].toLowerCase()) return  1;
          if(a[n-1].toLowerCase() < b[n-1].toLowerCase()) return -1;
          return a[n-1].toLowerCase() === b[n-1].toLowerCase() && a.toLowerCase() > b.toLowerCase() ? 1 : -1;
        }).join`, `;
      }