const personalise = (c, p) =>
  c.replace(/<([^>]+)>/g, (_, k) =>
    p[k.toLowerCase().replace(/ /g, "_")] || ""
  );
//(match, key) => key == NAME...

////////////////
function personalise(campaign, person){
    campaign = campaign.replace(/<NAME>/g,person.name);
    campaign = campaign.replace(/<CITY>/g,person.city);
    campaign = campaign.replace(/<FAVOURITE\sPRODUCTS>/g,person.favourite_products);
    return campaign;
  }

  /////////
  function personalise( campaign, person){
    return campaign.replace(/(<)([\w ]+)(>)/g, function(x,$1,$2){
      return person[$2.toLowerCase().replace(' ','_')];
    });
  }

  /////////
  const personalise = (campaign, person) =>
  campaign.replace(/<(.*?)>/g,
   (_, el) =>
    person[el.replace(/\s/g, `_`).toLowerCase()]);

    //////////
    function personalise( campaign, person){
        return campaign.replace(/<NAME>/g, person.name).replace(/<CITY>/g, person.city).replace(/<FAVOURITE PRODUCTS>/g, person.favourite_products);
      }
