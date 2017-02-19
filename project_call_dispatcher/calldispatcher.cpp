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
    m_mapOfObjects.insert(std::pair<std::pair<Object*, std::string>,
                          std::pair<Object*, std::string>>(std::pair<Object*, std::string>(sender,signal),
                                                           std::pair<Object*, std::string>(receiver,slot)));
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    ///
    auto it = m_mapOfObjects.find(std::pair<Object*, std::string>(sender, signal));
    std::cout << "Count of slots for signal --" << signal << " = "<< m_mapOfObjects.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;

    if(it != m_mapOfObjects.end())
        m_mapOfObjects.erase(it);
}

void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
    std::cout << "Count of slots for signal --" << signal << " = "<< m_mapOfObjects.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;
     auto it = m_mapOfObjects.find(std::pair<Object*, std::string>(sender, signal));
    while(it != m_mapOfObjects.end() && it->first.second == signal)
    {
        std::pair<Object*, std::string> t1 = it->second;
        t1.first->dispatchMethod(t1.second);
        ///std::cout << " sig: " << it->first.second << std::endl;
        ++it;
    }
}
