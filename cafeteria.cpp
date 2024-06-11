#include <string>

struct Milk {
  float fat;
};

struct Sugar {
  std::string sort;
};

struct Coffee {
  std::string sort;
  std::vector<Milk> milk;
  std::vector<Sugar> sugar;
};

class CoffeeBuilder {
  public:
    CoffeeBuilder() {
      coffin.sugar.reserve(1);
       coffin.milk.reserve(1);
    }
  
    CoffeeBuilder set_black_coffee() { 
      coffin.sort="Black";
      return *this;
    }
    CoffeeBuilder set_cubano_coffee() { 
      coffin.sort="Cubano";
      coffin.sugar.emplace_back(Sugar{"Brown"});
      return *this;
    }
    CoffeeBuilder set_antoccino_coffee() { 
      coffin.sort="Americano";
      coffin.milk.emplace_back(Milk{0.5});
      return *this;
    }
    CoffeeBuilder with_milk(float fat) {
      coffin.milk.emplace_back(Milk{fat});
      return *this;
    }
    CoffeeBuilder with_sugar(const std::string &sort) {
      coffin.sugar.emplace_back(Sugar{sort});
      return *this;
    }
  
    Coffee build() {
      return coffin;
    }
  private:
    Coffee coffin;
    
};