//fail basic tests?
#include <optional>
#include <exception>

template<typename ContainerType>
class RingContainer {
  private:
    std::optional<ContainerType> opt;
    std::optional<typename ContainerType::iterator> it;
 public:
  explicit RingContainer(ContainerType container)
  :opt(container),it((*opt).begin())
  {
    if((*opt).empty()) throw std::out_of_range("");
    
  }
  //because of optional it?
  auto next(){
     return *it==(*opt).end()?*(*opt).begin():*((*it)++);
  }
};

////////////////////
template<typename ContainerType, typename T = typename ContainerType::value_type>
class RingContainer {
  
  ContainerType container;
  typename ContainerType::iterator it;
  
 public:
  explicit RingContainer(ContainerType container_) : container(container_){
    if (container.empty()) throw std::invalid_argument("empty container");
    else it = container.begin();
  };
  
 T next(){
    if (it == container.end()) it = container.begin();
    return *it++;
  };
};

///////////////////
#include <cstdint>
#include <stdexcept>
#include <vector>

template<typename ContainerType>
class RingContainer {
public:

  using iterator = typename ContainerType::iterator;
  using value_type = typename ContainerType::value_type;

  explicit RingContainer(const ContainerType& container)
    : data(std::begin(container), std::end(container))
    , index()
    {
      if (data.empty()) throw std::logic_error("empty container");
    }
    
  value_type next() {
    return data[(index++) % data.size()];
  }
private:
  
  std::vector<value_type> data;
  size_t index;
  
};

////////////////////
template<typename ContainerType, typename T = typename ContainerType::value_type>
class RingContainer {
  
  ContainerType container;
  typename ContainerType::iterator it;
  
 public:
  explicit RingContainer(ContainerType container_) : container(container_){
    if (container.empty()) throw std::invalid_argument("empty container");
    else it = container.begin();
  };
  
 T next(){
    T element = *it;
    ++it;
    if (it == container.end()) it = container.begin();
    return element;
  };
};

////////////////
#include <stdexcept>
template<typename ContainerType>
class RingContainer {
  typename ContainerType::const_iterator begin, end, it;
public:
  explicit RingContainer(ContainerType const& container)
   : begin(std::begin(container)), end(std::end(container)), it(begin) {
   std::empty(container) ? throw std::out_of_range("Empty container passed") : void();
  };
  auto next() { return (it == end ? void(it = begin) : void()), *(it++); }
};
//////////////
