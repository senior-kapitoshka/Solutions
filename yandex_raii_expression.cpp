#include <iostream>
#include <memory>
#include <string>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;

/*        ---          */

class Cnst: public  Expression{
private:
    int val_;
    std::string s_;
public:    
    Cnst(int v): val_(v),s_(std::to_string(v)){}
    int Evaluate() const override{
        return val_;
    }
    std::string ToString() const override{
        return s_;
    }
};

class Base:public  Expression{
protected:    
    ExpressionPtr l_;
    ExpressionPtr r_;
public:   
    Base(ExpressionPtr x,ExpressionPtr y):l_(x),r_(y){}
};

class Plus:public  Base{
    int val_;
    std::string s_;
public:    
    Plus(ExpressionPtr lhs, ExpressionPtr rhs): Base(lhs,rhs){
        s_ = l_->ToString() + " + "+ r_->ToString();
        val_= l_->Evaluate() + r_->Evaluate();
    }
    int Evaluate() const override{
        return val_;
    }
    std::string ToString() const override{
        return s_;
    }
};

class Star:public  Base{
private:
    int val_;
    std::string s_;
    static std::string Parentheses(ExpressionPtr ex) {
        if (dynamic_cast<Plus*>(ex.get())) {
            return std::string("(") + ex->ToString() + ")";
        } else {
            return ex->ToString();
        }
    }
public:    
    Star(ExpressionPtr lhs, ExpressionPtr rhs): Base(lhs,rhs){
        s_ = Parentheses(l_) + " * "+ Parentheses(r_);
        val_= l_->Evaluate() * r_->Evaluate();
    }
    int Evaluate() const override{
        return val_;
    }
    std::string ToString() const override{
        return s_;
    }
};


ExpressionPtr Const(int val){
    return ExpressionPtr(new Cnst(val));
}

ExpressionPtr Sum(ExpressionPtr l,ExpressionPtr r){
    return ExpressionPtr(new Plus(l,r));
}

ExpressionPtr Product(ExpressionPtr l,ExpressionPtr r){
    return ExpressionPtr(new Star(l,r));
}

/*    ----     */

int main() {
    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
    std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
    std::cout << ex1->Evaluate() << "\n";  // 17

    ExpressionPtr ex2 = Product(Const(6), ex1);
    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
    std::cout << ex2->Evaluate() << "\n";  // 102
}

//////////////////////////////
