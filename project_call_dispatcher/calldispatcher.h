#ifndef CALLDISPATCHER_H
#define CALLDISPATCHER_H


#include <string>
#include <memory>
#include <map>

class Object;

class CallDispatcher
{
private:

    //...
    std::multimap<std::pair<Object*, std::string>, std::pair<Object*, std::string>> m_mapOfObjects;
public:
    typedef std::shared_ptr<CallDispatcher> Ptr;

    CallDispatcher();

    void connect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);
    void disconnect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);

    void sendSignal(Object* sender, const std::string& singal);
};

#endif // CALLDISPATCHER_H
