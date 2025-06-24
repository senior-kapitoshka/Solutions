function extendTransportSystem(EarthRoute, MoonRoute) {
    let res=[]
    EarthRoute.prototype.transfer=function(arg){
      arg.destination="Earth";
      res.push({
        ...arg,
        destination:"Mothership",
        origin:"Earth"
      });
      EarthRoute.vault.push(arg);
    };
    MoonRoute.prototype.transfer=function(arg){
      arg.destination="Moon";
      res.push({
        ...arg,
        destination:"Mothership",
        origin:"Moon"
      });
      MoonRoute.warehouse.push(arg);
    }
    return res;
  }
  
  
  
  module.exports = extendTransportSystem
  