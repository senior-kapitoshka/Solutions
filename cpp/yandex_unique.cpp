template<typename It>
It Unique(It first,It last){
    if(first==last) return last;
   It n=first;

   while(first!=last){
       if(!(*n==*first) && ++n!=first){
           n=std::move(*first);
       }
       ++first;
   }
   return ++n;
}

///////////////////////////////
#include <algorithm>

template<typename It>
It Unique(It first,It last){
    if(first==last) return last;
   It n=first;
   It dummy=first;
   while(n!=last){
       if(*n!=*dummy){
           ++dummy;
           *dummy=*n;
       }
       ++n;
   }
   return ++dummy;
}