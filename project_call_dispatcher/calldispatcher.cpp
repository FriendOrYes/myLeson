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
    auto pair = m_mapOfObjects.equal_range(std::pair<Object*, std::string>(sender, signal));
    std::cout << "disconnect->Count of slots for signal --" << signal << " = "<< m_mapOfObjects.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;
    auto it = pair.first;

    while( it != pair.second)
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

    auto pair = m_mapOfObjects.equal_range(std::pair<Object*, std::string>(sender, signal));
    auto it = pair.first;

    while(it != pair.second)
    {
        std::pair<Object*, std::string> t1 = it->second;
        t1.first->dispatchMethod(t1.second);
        ++it;
    }
}
//void CallDispatcher::Show()
//{
//    for(auto it = m_mapOfObjects.begin(); it != m_mapOfObjects.end(); ++it)
//    {
//        std::cout << it->first.second << "----" <<it->second.second << std::endl;
//    }
//}
