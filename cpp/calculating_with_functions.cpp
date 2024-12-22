int zero() {
    return 0;
};

template<typename F>
int zero(F f){
    return f(0);
}

int one() {
    return 1;
};

template<typename F>
int one(F f){
    return f(1);
}

int two() {
    return 2;
};

template<typename F>
int two(F f){
    return f(2);
}


int three() {
    return 3;
};

template<typename F>
int three(F f){
    return f(3);
}

int four() {
    return 4;
};

template<typename F>
int four(F f){
    return f(4);
}

int five() {
    return 5;
};

template<typename F>
int five(F f){
    return f(5);
}

int six() {
    return 6;
};

template<typename F>
int six(F f){
    return f(6);
}


int seven() {
    return 7;
};

template<typename F>
int seven(F f){
    return f(7);
}


int eight() {
    return 8;
};

template<typename F>
int eight(F f){
    return f(8);
}

int nine() {
    return 9;
};

template<typename F>
int nine(F f){
    return f(9);
}

class plus {
public:
  plus(int d):dig(d){}
  int operator()(int d){
    return dig+d;
  }
private:
  int dig;
};

class minus {
public:
  minus(int d):dig(d){}
  int operator()(int d){
    return d-dig;
  }
private:
  int dig;
};

class times {
public:
  times(int d):dig(d){}
  int operator()(int d){
    return dig*d;
  }
private:
  int dig;
};

class divided_by {
public:
  divided_by(int d):dig(d){}
  int operator()(int d){
    return d/dig;
  }
private:
  int dig;
};

/////////////////////////////
#include <functional>
using op = std::function<int(int)>;
int id(int n) { return n; }

int zero (op func = id) { return func(0); }
int one  (op func = id) { return func(1); }
int two  (op func = id) { return func(2); }
int three(op func = id) { return func(3); }
int four (op func = id) { return func(4); }
int five (op func = id) { return func(5); }
int six  (op func = id) { return func(6); }
int seven(op func = id) { return func(7); }
int eight(op func = id) { return func(8); }
int nine (op func = id) { return func(9); }

op plus      (int n) { return [=](int m) { return m + n; }; }
op minus     (int n) { return [=](int m) { return m - n; }; }
op times     (int n) { return [=](int m) { return m * n; }; }
op divided_by(int n) { return [=](int m) { return m / n; }; }

/////////////////////////////
#include <iostream>
#include <functional>
#include <utility>

int zero() { return 0; }
int zero(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(0, op.first); }

int one() { return 1; }
int one(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(1, op.first); }

int two() { return 2; }
int two(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(2, op.first); }

int three() { return 3; }
int three(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(3, op.first); }

int four() { return 4; }
int four(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(4, op.first); }

int five() { return 5; }
int five(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(5, op.first); }

int six() { return 6; }
int six(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(6, op.first); }

int seven() { return 7; }
int seven(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(7, op.first); }

int eight() { return 8; }
int eight(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(8, op.first); }

int nine() { return 9; }
int nine(const std::pair<int, std::function<int(int, int)>>& op) { return op.second(9, op.first); }


auto plus(int number) {
    return std::make_pair(number, std::plus<int>());
}

auto minus(int number) {
    return std::make_pair(number, std::minus<int>());
}

auto times(int number) {
    return std::make_pair(number, std::multiplies<int>());
}

auto divided_by(int number) {
    return std::make_pair(number, std::divides<int>());
}


///////////////////////////
struct OpNum { char op; int num; };

int evaluate(int n, const OpNum& op_num) {
  switch (op_num.op) {
      case '+': return n + op_num.num;
      case '-': return n - op_num.num;
      case '*': return n * op_num.num;
      case '/': return n / op_num.num;
      default: throw std::runtime_error("bad op");
  }
}

int zero(OpNum op_num = {'+',0}) { return evaluate(0,op_num); }
int one(OpNum op_num = {'+',0}) { return evaluate(1,op_num); }
int two(OpNum op_num = {'+',0}) { return evaluate(2,op_num); }
int three(OpNum op_num = {'+',0}) { return evaluate(3,op_num); }
int four(OpNum op_num = {'+',0}) { return evaluate(4,op_num); }
int five(OpNum op_num = {'+',0}) { return evaluate(5,op_num); }
int six(OpNum op_num = {'+',0}) { return evaluate(6,op_num); }
int seven(OpNum op_num = {'+',0}) { return evaluate(7,op_num); }
int eight(OpNum op_num = {'+',0}) { return evaluate(8,op_num); }
int nine(OpNum op_num = {'+',0}) { return evaluate(9,op_num); }

OpNum plus(int n) { return {'+',n}; }
OpNum minus(int n) { return {'-',n}; }
OpNum times(int n) { return {'*',n}; }
OpNum divided_by(int n) { return {'/',n}; }

//////////////////////
enum operation{
  None,
  Plus,
  Minus,
  Times,
  Div
};

int digit(int d, std::pair<operation, int> op = {operation::None, -1}){
  switch (op.first){
      case operation::None: return d;
      case operation::Plus: return d + op.second;
      case operation::Minus: return d - op.second;
      case operation::Times: return d * op.second;
      case operation::Div: 
      if (op.second == 0){
        std::cout<< "ERROR! Div by ZERO!" << std::endl;
        return 0;
      } 
      return static_cast<int>(d / op.second);
  }
}
int zero( std::pair<operation, int> op = {operation::None, -1}) { return digit(0, op); }
int one(  std::pair<operation, int> op = {operation::None, -1}) { return digit(1, op); }
int two(  std::pair<operation, int> op = {operation::None, -1}) { return digit(2, op); }
int three(std::pair<operation, int> op = {operation::None, -1}) { return digit(3, op); }
int four( std::pair<operation, int> op = {operation::None, -1}) { return digit(4, op); }
int five( std::pair<operation, int> op = {operation::None, -1}) { return digit(5, op); }
int six(  std::pair<operation, int> op = {operation::None, -1}) { return digit(6, op); }
int seven(std::pair<operation, int> op = {operation::None, -1}) { return digit(7, op); }
int eight(std::pair<operation, int> op = {operation::None, -1}) { return digit(8, op); }
int nine( std::pair<operation, int> op = {operation::None, -1}) { return digit(9, op); }

std::pair<operation, int> plus(int num) { return {operation::Plus, num}; }
std::pair<operation, int> minus(int num) { return {operation::Minus, num}; }
std::pair<operation, int> times(int num) { return {operation::Times, num}; }
std::pair<operation, int> divided_by(int num) { return {operation::Div, num}; }

/////////////////////////
#include <functional>

auto zero(std::function<int(int)> op = nullptr) { return op ? op(0) : 0; }
auto one(std::function<int(int)> op = nullptr) { return op ? op(1) : 1; }
auto two(std::function<int(int)> op = nullptr) { return op ? op(2) : 2; }
auto three(std::function<int(int)> op = nullptr) { return op ? op(3) : 3; }
auto four(std::function<int(int)> op = nullptr) { return op ? op(4) : 4; }
auto five(std::function<int(int)> op = nullptr) { return op ? op(5) : 5; }
auto six(std::function<int(int)> op = nullptr) { return op ? op(6) : 6; }
auto seven(std::function<int(int)> op = nullptr) { return op ? op(7) : 7; }
auto eight(std::function<int(int)> op = nullptr) { return op ? op(8) : 8; }
auto nine(std::function<int(int)> op = nullptr) { return op ? op(9) : 9; }


auto plus(int right) {
    return [right](int left) { return left + right; };
}

auto minus(int right) {
    return [right](int left) { return left - right; };
}

auto times(int right) {
    return [right](int left) { return left * right; };
}

auto divided_by(int right) {
    return [right](int left) { return left / right; };
}

//////////////////////
#include <functional>
#include <optional>

using val_t = int;
using fun_t = std::function<val_t(val_t)>;
using opt_fun_t = std::optional<fun_t>;

val_t zero(opt_fun_t f = std::nullopt) { return f ? (*f)(0) : 0; }
val_t one(opt_fun_t f = std::nullopt) { return f ? (*f)(1) : 1; }
val_t two(opt_fun_t f = std::nullopt) { return f ? (*f)(2) : 2; }
val_t three(opt_fun_t f = std::nullopt) { return f ? (*f)(3) : 3; }
val_t four(opt_fun_t f = std::nullopt) { return f ? (*f)(4) : 4; }
val_t five(opt_fun_t f = std::nullopt) { return f ? (*f)(5) : 5; }
val_t six(opt_fun_t f = std::nullopt) { return f ? (*f)(6) : 6; }
val_t seven(opt_fun_t f = std::nullopt) { return f ? (*f)(7) : 7; }
val_t eight(opt_fun_t f = std::nullopt) { return f ? (*f)(8) : 8; }
val_t nine(opt_fun_t f = std::nullopt) { return f ? (*f)(9) : 9; }

fun_t plus(val_t v) {
    return [v](val_t a) { return a + v; };
}

fun_t minus(val_t v) {
    return [v](val_t a) { return a - v; };
}

fun_t times(val_t v) {
    return [v](val_t a) { return a * v; };
}

fun_t divided_by(val_t v) {
    return [v](val_t a) { return a / v; };
}