#include <string>
#include <fmt/format.h>

std::string zombie_shootout(unsigned z, unsigned ds,
                            unsigned am) {
  return (am>=z && 2*ds<z)?fmt::format("You shot {} zombies before being eaten: overwhelmed.",2*ds):
  (am<z && 2*ds<am)?fmt::format("You shot {} zombies before being eaten: overwhelmed.",2*ds):
  (am<z && 2*ds>am)?fmt::format("You shot {} zombies before being eaten: ran out of ammo.",am):
  fmt::format("You shot all {} zombies.",z);
}

////////////////////
#include <string>

std::string zombie_shootout(unsigned zombies, double distance, unsigned ammo) {
  unsigned ori = zombies;
  while(zombies > 0 && distance > 0 && ammo > 0){
    ammo--;
    zombies--;
    distance -= 0.5;
  }
  return !zombies ? "You shot all " + std::to_string(ori) + " zombies." : "You shot " + std::to_string(ori - zombies) + " zombies before being eaten: " + (!distance ? "overwhelmed" : "ran out of ammo") + ".";
}

//////////////////
#include <fmt/format.h>
std::string zombie_shootout( unsigned zombies, unsigned distance, unsigned ammo ){
  const bool empty{ ammo < ( distance *= 2 )};
  return zombies < distance && zombies < ammo ?
    fmt::format( "You shot all {} zombies.", zombies ) :
    fmt::format( "You shot {} zombies before being eaten: {}.",
      empty ? ammo : distance, empty ? "ran out of ammo" : "overwhelmed" );
}

///////////////////
#include <string>

std::string zombie_shootout(unsigned z, unsigned d, unsigned a)
{
	d *= 2;
	return "You shot " + (z > d || z > a ? std::to_string(std::min(a, d)) + " zombies before being eaten: " + (a < d ? "ran out of ammo." : "overwhelmed.") : "all " + std::to_string(z) + " zombies.");
}