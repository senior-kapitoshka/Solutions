#include <tuple>

template <typename F,typename ...Args>
class Helper{
private:
  F f_;
  std::tuple<Args...>t_;
public: 
  Helper(F f,const std::tuple<Args...>& tp):
  f_(f),
  t_(tp){}
  auto call(){
    return std::apply(f_,t_);
  }
};

template <typename F,typename ...Args>
auto make_lazy(F f,Args... args) {
  auto tp=std::make_tuple(std::forward<Args>(args)...);
  return Helper(f,tp);
}

///////////////////////////
#define make_lazy std::bind
#define call operator()

/////////////////////////
template<typename R, typename F>
struct result {
  R call() {
    return f();
  }
  F f;
};

template<typename F, typename... T>
auto make_lazy(F f, T... args) {
  using R = decltype(f(args...));
  bool called = false;
  R res{};
  auto g = [=]() mutable {
    if (called) return res;
    called = true;
    return res = f(args...);
  };
  return result<R, decltype(g)>{g};
}

///////////////////
template <typename ...Args>
auto make_lazy(Args &&...args)
{
    auto res = std::bind(std::forward<Args>(args)...);
    struct R : decltype(res)
    {
        decltype(auto) call()
        {
            return (*this)();
        }
    };
    return (R &)res;
}

/////////////////////////
#include <type_traits>
#include <tuple>

template<typename Callable, typename... Args> 
struct make_lazy{
    using invoke_result_t = typename std::invoke_result<Callable, Args...>::type;
    Callable func;
    std::tuple<Args...> params;
    make_lazy(Callable&& f, Args... args):func{f},params{args...}{
    }
    invoke_result_t call() const {
        return std::apply(func,params);
    }
};

///////////////////////
template <typename Fn, typename... Ts>
class Lazy
{
public:
    template <typename F, typename... Args>
    Lazy(F&& f, Args&&... args) : fn(std::forward<F>(f)), args(std::forward<Args>(args)...) {}
    auto call() { return std::apply(fn, args); }
private:
    Fn fn;
    std::tuple<Ts...> args;
};

template <typename F, typename... Args>
auto make_lazy(F&& f, Args&&... args)
{
    return Lazy<F, Args...>(std::forward<F>(f), std::forward<Args>(args)...);
}

///////////////////////
#include <tuple>
#include <utility>

template<typename F, typename... Args>
struct make_lazy {
  F f;
  std::tuple<Args...> args;
  
  make_lazy(F f, Args... args) : f(f), args(args...) {}
  
  auto call() {
    return std::apply(f, args);
  }
};
/////////////////
#include <functional>
#include <type_traits>

template<typename T>
struct Callable
{
    constexpr Callable(T&& f) : _f(f) {};
    auto call() { return _v.has_value() ? _v.value() : (_v = _f()).value();}
private:
    T _f;
    std::optional<typename std::invoke_result<T>::type> _v;
};

template <typename ... Args>
auto make_lazy(Args&& ... args){
    return Callable(std::bind(std::forward<Args>(args) ... ));
}

///////////////////
template <typename ...Args>
auto make_lazy(Args &&...args)
{
    struct R
    {
        R(Args &&...args) : call(std::bind(std::forward<Args>(args)...)) {}
        decltype(std::bind(std::forward<Args>(args)...)) call;
    } res(std::forward<Args>(args)...);
    return res;
}

//////////////////
#include <tuple>

template <class F, class... Types> class Lazy {
private:
  F f_;
  std::tuple<Types...> tuple_;
public:
  Lazy(F&& f, Types&&... types) : f_(std::forward<F>(f)), tuple_(std::forward<Types>(types)...) {};
  auto call(void) {
    return std::apply(std::forward<F>(f_), std::forward<std::tuple<Types...> >(tuple_));
  };
};

template <class F, class... Types>
Lazy<F, Types...> make_lazy(F&& f, Types&&     ... types) {
  return Lazy<F, Types...>(std::forward<F>(f), std::forward<Types>(types)...); 
};

////////////////
#include <future>
#include <type_traits>

template <class F, class... Args>
class make_lazy {
  std::future<std::invoke_result_t<F, Args...>> future;
public:
  make_lazy(F f, Args... args) : future(std::async(std::launch::deferred, f, args...)) { }
  auto call() { return future.get(); }
};
/////