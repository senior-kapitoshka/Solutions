typedef struct {
  unsigned rabbits;
  unsigned chickens;
  unsigned cows;
} counts;

counts get_animals_count(unsigned l, unsigned hds, unsigned hns) {
  counts c;
  c.cows=hns/2;
  l-=c.cows*4;
  hds-=c.cows;
  c.rabbits=(l-hds*2)/2;
  c.chickens=hds-c.rabbits;
  return c;

}

/////////////
typedef struct {
  unsigned rabbits;
  unsigned chickens;
  unsigned cows;
} counts;

counts get_animals_count(unsigned legs, unsigned heads, unsigned horns)
{
    counts out = { 0, 0, 0 };
  
    out.cows = horns / 2;
    heads -= out.cows;
    legs -= 4 * out.cows;
    out.rabbits = legs/2 - heads;
    out.chickens = 2*heads - legs/2;
    return out;
}
//////////
typedef struct { unsigned rabbits, chickens, cows; } counts;
counts get_animals_count(unsigned legs, unsigned heads, unsigned horns) {
  int cows = horns / 2, chickens = (4 * heads - legs) / 2, rabbits = heads - chickens - cows;
  return (counts){rabbits, chickens, cows};
}