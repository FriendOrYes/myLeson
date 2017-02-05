#include "eventmanager.h"
#include <algorithm>
#include <iostream>

using namespace std;

EventManager& EventManager::getInstance()
{
    static EventManager inst;
    return inst;
}

void EventManager::publishEvent(const Event& ev)
{
    //...
    for(auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
    {
        shared_ptr<EventListener> listenerPtr = (*it).lock();
        if(listenerPtr)
        {
            listenerPtr -> notify(ev);
        }
    }
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    //...
    m_listeners.push_back(listener);
}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{
    //...
    m_listeners.pop_back();
}

