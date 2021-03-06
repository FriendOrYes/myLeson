#include <iostream>
#include <string>
#include <memory>

#include "event.h"
#include "eventlistener.h"
#include "eventmanager.h"

using namespace std;


struct FileLogger : EventListener
{
    FileLogger()
    {

    }
    void notify(const Event& ev) override
    {
        cout << __FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    ConnectionMgr()
    {

    }
    void notify(const Event& ev) override
    {
        cout << __FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


struct EventHandler : EventListener
{
    EventHandler()
    {

    }
    void notify(const Event& ev) override
    {
        cout << __FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


int main(int argc, char *argv[])
{
    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>(FileLogger());
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>(ConnectionMgr());
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>(EventHandler());

    //...

    Event ev("Click");

    EventManager::getInstance().addListener(evListener1);
    EventManager::getInstance().addListener(evListener2);
    EventManager::getInstance().addListener(evListener3);

    EventManager::getInstance().publishEvent(ev);
    EventManager::getInstance().removeListener(evListener3);

    Event ev2("Add new Image");

    EventManager::getInstance().publishEvent(ev2);

    {
          shared_ptr<EventListener> evListener4 = make_shared<FileLogger>(FileLogger());
          EventManager::getInstance().addListener(evListener4);
          EventManager::getInstance().publishEvent(Event("YY"));
    }

    EventManager::getInstance().publishEvent(Event("XXX"));
    EventManager::getInstance().addListener(evListener2);

    return 0;

}
