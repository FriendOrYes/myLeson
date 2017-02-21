#include <iostream>
#include <memory>

#include "object.h"
#include "calldispatcher.h"


using namespace std;

class Server : public Object
{
private:
    void dispatchMethod(const string& methodName) override
    {
       //cout << __FUNCTION__ <<" -- " <<methodName <<endl;
        if ("Recive" == methodName)
        {
            Recive();
        }
        else if ("CheckConnect" == methodName)
        {
            CheckConnect();
        }
        else if ("CheckNumberOfConections" == methodName)
        {
            CheckNumberOfConections();
        }
    }

public:

    Server(CallDispatcher::Ptr& dispatcher)
        : Object(dispatcher)
    {
    }

public /*slots*/:

    void Recive()
    {
        cout << __FUNCTION__ << ": " << this << endl;
    }

    void CheckConnect()
    {
        cout << __FUNCTION__ << ": " << this << endl;
    }

    void CheckNumberOfConections()
    {
        cout << __FUNCTION__ << ": " << this << endl;
    }
};


class Client : public Object
{

public:
    Client(CallDispatcher::Ptr& dispatcher)
        : Object(dispatcher)
    {
    }

public /*signals*/:

    void Send()
    {
        m_dispatcher->sendSignal(this, "Send");
    }

    void ConnectToServer()
    {
        m_dispatcher->sendSignal(this, "ConnectToServer");
    }

    void Disconnect()
    {
        m_dispatcher->sendSignal(this, "Disconnect");
    }
};




int main(int argc, char *argv[])
{
    auto d = make_shared<CallDispatcher>();

    Server a1(d);
    Server a2(d);
    Client b1(d);
    Client b2(d);

    d->connect(&b1, "Send", &a1, "Recive");

    // 1 signal => many slots
    d->connect(&b1, "ConnectToServer", &a1, "CheckConnect");
    d->connect(&b1, "ConnectToServer", &a2, "CheckConnect"); //names shouldn't nesseraly match
    d->connect(&b1, "ConnectToServer", &a2, "Recive");

    // 2 signals => 1 slot
    d->connect(&b1, "Disconnect", &a2, "CheckNumberOfConections");
    d->connect(&b2, "Disconnect", &a2, "CheckNumberOfConections");

    b1.Send();
    b1.ConnectToServer();
    b1.Disconnect();
    cout << "2 Test!!!" << endl;

    b2.Send();
    b2.ConnectToServer();
    b2.Disconnect();

    d->disconnect(&b1, "ConnectToServer", &a2, "Recive");
    d->disconnect(&b1, "ConnectToServer", &a1, "CheckConnect");
    d->disconnect(&b1, "ConnectToServer", &a2, "CheckConnect");

    b1.Send();
    b1.ConnectToServer();

    return 0;
}
