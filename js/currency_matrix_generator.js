var arr=["EUR", "GBP", "AUD", "NZD", "USD", "CAD", "CHF", "JPY"];

function generateCurrencyMatrix(curr){
  return arr.map((e)=>(arr.indexOf(curr)<arr.indexOf(e))?
                 curr+e:
                 (arr.indexOf(curr)>arr.indexOf(e))?
                  e+curr:
                 "").filter((i)=>i!=="");
}

/////////
function generateCurrencyMatrix(currency)
{
  var currencies = ["EUR", "GBP", "AUD", "NZD", "USD", "CAD", "CHF", "JPY"];
  
  return currencies.filter(a => a != currency).map(b => currencies.indexOf(b) < currencies.indexOf(currency) ? b + currency : currency  + b);
}

////////
const currencies=["EUR", "GBP", "AUD", "NZD", "USD", "CAD", "CHF", "JPY"];
function generateCurrencyMatrix(currency)
{
  const i=currencies.indexOf(currency);
  return currencies.slice(0,i).map(cr=>cr+currency).concat(currencies.slice(i+1).map(cr=>currency+cr));
}