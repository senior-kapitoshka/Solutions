const duplicates = arr => 
    [...new Set(arr.filter((x, i) => 
        arr.indexOf(x) !== i))]

////////////////
