#include <iostream>
#include <string>

class CompanyA {
public:
    void sendCleartext(const std::string& msg){}
    void sendEncrypted(const std::string& msg){}
};

class CompanyB {
public:
    void sendCleartext(const std::string& msg){}
    void sendEncrypted(const std::string& msg){}
};

template<typename Company>
class MsgSender {
public:
    void sendClear(const std::string& msg)
    {
        Company c;
        c.sendCleartext(msg);
    }

    void sendSecret(const std::string& msg){
        Company c;
        c.sendEncrypted(msg);
    }
};

template<typename Company>
class LoggingMsgSender: public MsgSender<Company> {
public:
    using MsgSender<Company>::sendClear;
    void sendClearMsg(const std::string& msg)
    {
        //write "before sending" info to the log;

        // There are three ways to make it compile
        // 1. this keyword
        this->sendClear(msg);
        // 2. Specify Base class
        // This is not preferred because if the function being called is virtual,
        // explicit qualification turns off the virtual binding behavior.
        MsgSender<Company>::sendClear(msg);
        // 3. using keyword, see above
        sendClear(msg);

        //sendClear(msg); // Calling sendClear() itself won't compile!

        //write "after sending" info to the log;
    }
};

// This is the class illustrates that compiler cannot
// assume Company class always has sendCleartext() method
// and that's why it won't allow you to call naked sendClear()
// You must explicitly tell compiler to assume it always exists
class CompanyC {
public:
    void sendEncrypted(const std::string& msg){}
};

//template<>
//class MsgSender<CompanyC> {
//public:
//    void sendSecret(const std::string& msg){}
//};

int main() {

    LoggingMsgSender<CompanyA> senderA;
    senderA.sendClearMsg(std::string("abc"));
    LoggingMsgSender<CompanyB> senderB;
    senderB.sendClearMsg(std::string("abc"));
    LoggingMsgSender<CompanyC> senderC;
    //senderC.sendClearMsg(std::string("abc")); // error: no member named 'sendCleartext' in 'CompanyC'
    return 0;
}

