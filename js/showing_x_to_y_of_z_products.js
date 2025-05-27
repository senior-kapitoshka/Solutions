var paginationText = function(pn, ps, t){
  let x=ps*pn;
  return `Showing ${(x-ps)+1} to ${x>=t?t:x} of ${t} Products.`;
  
}

//////////////
