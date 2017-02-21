#include "calldispatcher.h"
#include "object.h"
#include <iostream>
#include <algorithm>

CallDispatcher::CallDispatcher()
{
    //...
}

void CallDispatcher::connect(Object* sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    m_mapOfObjects.insert({{sender,signal}, {receiver,slot}});
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    ///
    auto it = m_mapOfObjects.find(std::pair<Object*, std::string>(sender, signal));
    std::cout << "disconnect->Count of slots for signal --" << signal << " = "<< m_mapOfObjects.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;

    while(it != m_mapOfObjects.end() && it->first.second == signal && it->first.first == sender)
    {
        if(it->second.first == receiver && it->second.second == slot)
        {
            m_mapOfObjects.erase(it);
            break;
        }
        ++it;
    }
}

void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
    std::cout << "Send->Count of slots for signal --" << signal << " = "<< m_mapOfObjects.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;
    auto it = m_mapOfObjects.find(std::pair<Object*, std::string>(sender, signal));
    while(it != m_mapOfObjects.end() && it->first.second == signal && it->first.first == sender)
    {
        std::pair<Object*, std::string> t1 = it->second;
        t1.first->dispatchMethod(t1.second);
        //std::cout << " sig: " << it->first.second << std::endl;
        ++it;
    }
}
