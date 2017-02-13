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
        shared_ptr<EventListener> listenerPtr;
        if((listenerPtr = it->lock()))
        {
            listenerPtr -> notify(ev);
        }
    }
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    //...
    bool ListeneiIsOn = std::any_of(m_listeners.begin(), m_listeners.end(), [&](weak_ptr<EventListener> listen)
    {
        return (listener == listen.lock());
    });

    if(!ListeneiIsOn)
    {
        m_listeners.push_back(listener);
    }
    else
    {
        cout << "Listener is already present" << endl;
    }
}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{
    //...
    m_listeners.erase(std::remove_if(m_listeners.begin(), m_listeners.end(), [&](weak_ptr<EventListener> listen)
    {
         return (listener == listen.lock());
    }));
}

