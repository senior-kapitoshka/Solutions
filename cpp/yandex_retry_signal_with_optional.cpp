#include <exception>
#include <functional>
#include <optional>



template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
                                  int retryCount, int sleepTime, bool throwLast){
std::optional<Result> res;
int n=retryCount+1;
for(int i=0;i<n;++i){
        try{
            res=func();
            return res;
        }catch(const Exception& ex){
            if(i==retryCount){
                if(throwLast) throw;//Если на последней попытке происходит исключение указанного типа,\
                 и throwLast истинно,\
                 !!!! этот же объект исключения должен проброситься дальше из функции!!!!
            }else{
                Sleep(sleepTime);
            }
        }
    }
    return res;
}
/*Здесь мы перехватываем потенциальные исключения, приводящиеся к типу Exception 
(важно ловить именно их, а не писать catch (...)). При этом сам объект исключения
 нам не нужен, поэтому мы его имя не указываем. При необходимости (после последней
  попытки при возведённом throwLast) мы перекидываем пойманное исключение дальше с
   помощью throw без аргументов.*/