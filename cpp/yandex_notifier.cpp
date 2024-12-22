#include <iostream>
#include <string>

using namespace std;


void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

#include <string_view>

class NotifierBase{
protected:
    const string id_;    
public:   
    NotifierBase(std::string_view id)
    :id_(id)
    {}
 virtual void Notify(std::string_view msg)const=0;
 const std::string GetId() const{
     return id_;
 }
 virtual ~NotifierBase(){}
};

class SmsNotifier:public NotifierBase{
public:
    SmsNotifier(std::string_view id)
    :NotifierBase(id){}
    void Notify(std::string_view msg)const override{
        SendSms(this->GetId(),(std::string)msg);
    }
};

class EmailNotifier:public NotifierBase{
public:    
    EmailNotifier(std::string_view id)
    :NotifierBase(id){}
    void Notify(std::string_view msg)const override{
        SendEmail(this->GetId(),(std::string)msg);
    }
};

// Реализуйте в вашем решении классы NotifierBase, SmsNotifier и EmailNotifier,
// чтобы следующий код заработал как ожидается:

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}