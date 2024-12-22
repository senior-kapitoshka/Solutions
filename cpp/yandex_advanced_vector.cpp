//compile but fail
#include <vector>
#include <stdexcept>
#include <cmath>
template <typename T>
class AdvancedVector{
private:
    std::vector<T>vc_;
public:
    AdvancedVector(){}
    template<typename It>
    AdvancedVector(It b,It e):vc_(b,e){}
    std::vector<T> getVC()const{
        return vc_;
    }
    bool operator ==(const AdvancedVector& other)const{
        return vc_==other.getVC();
    }
    bool operator !=(const AdvancedVector& other)const{
        return vc_!=other.getVC();
    }
    size_t size()const{
        return vc_.size();
    }
    bool empty()const{
        return vc_.empty();
    }
    void pop_back(){
        if(!vc_.empty()){
            vc_.pop_back();
        }
    }
    void push_back(const T& elem){
        vc_.push_back(elem);
    }
    T& operator[](int i){
        if(std::abs(i)>(int)vc_.size()){
            throw std::out_of_range("error");
        }else if(i<0 && std::abs(i)<(int)vc_.size()){
           T& res=vc_[vc_.size()-1-i];
           return res;
        }
        T& res=vc_[i];
        return res;
    }
    const T& operator[](int i)const{
        if(std::abs(i)>(int)vc_.size()){
            throw std::out_of_range("error");
        }else if(i<0 && std::abs(i)<(int)vc_.size()){
          const T& res=vc_[vc_.size()-1-i];
           return res;
        }
        const T& res=vc_[i];
        return res;
    }
};


/////////////////////////////
#include <cstdint>
#include <vector>

template <typename T>
class AdvancedVector: public std::vector<T> {
public:
    AdvancedVector() = default;

    template <typename Iter>
    AdvancedVector(Iter first, Iter last): std::vector<T>(first, last) {
    }

    const T& operator [](std::int64_t i) const {
        if (i < 0) {
            i += this->size();
        }
        return this->at(i);
    }

    T& operator [](std::int64_t i) {
        if (i < 0) {
            i += this->size();
        }
        return this->at(i);
    }
};