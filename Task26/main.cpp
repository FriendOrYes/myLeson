#include <iostream>
#include <string>

using namespace std;




//----------------------------------------------
class Device
{
public:

    Device()
        : m_status(false)
        , m_nameDevice("N/A")
    {
        m_numberDevice++;
        m_id = m_numberDevice;

        cout << __FUNCTION__ << endl;
    }
    Device(string name, bool status = false)
        : m_status(status)
        , m_nameDevice(name)
    {
        m_numberDevice++;
        m_id = m_numberDevice;

        cout << __FUNCTION__ << endl;
    }
    virtual ~Device()
    {
         cout << "Delete device whis pure id - " << m_id << endl;
         m_numberDevice--;
    }
    void TurnOn()
    {
        m_status = true;
    }
    void TurnOff()
    {
        m_status = false;
    }
    static void GetNumberDevice()
    {
        cout << "Number device now : " << m_numberDevice << endl;
    }
    virtual void GetStatus()const = 0;
    virtual void GetId()const = 0;

protected:
    bool m_status;
    string m_nameDevice;
    static int m_numberDevice;
    int m_id;

};
int Device::m_numberDevice = 0;

//----------------------------------------------
class Printer: virtual public Device
{
public:
    Printer()
        : Device()
    {
        cout << __FUNCTION__ << endl;
    }
    Printer(string name, bool status = false)
        : Device(name, status)
    {
        cout << __FUNCTION__ << endl;
    }
    ~Printer()
    {
        cout << __FUNCTION__ << endl;
    }
    void Print()
    {
        cout << "print" << endl;
    }
    void GetStatus()const override
    {
        cout << "Status of Printer: ";
        if(m_status) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    void GetId()const override
    {
        cout << "Id device " << m_nameDevice << " - PriX" << m_id << endl;
    }

};

//----------------------------------------------
class Scanner: virtual public Device
{
public:
    Scanner()
        : Device()
    {

        cout << __FUNCTION__ << endl;
    }
    Scanner(string name, bool status = false)
        : Device(name, status)
    {

        cout << __FUNCTION__ << endl;
    }
    ~Scanner()
    {
        cout << __FUNCTION__ << endl;
    }
    void Scan()
    {
        cout << "scan" << endl;
    }
    void GetStatus()const override
    {
        cout << "Status of Scaner: " ;
        if( m_status) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    void GetId()const override
    {
        cout << "Id device " << m_nameDevice << " - ScaX" << m_id << endl;
    }

};

//----------------------------------------------
class MFU:  public Scanner,  public Printer
{
public:
    MFU()
        : Device()
    {

    }
    MFU(string name, bool status = false)
        : Device(name, status)
    {

    }

    ~MFU()
    {
        cout << __FUNCTION__ << endl;
    }
    void GetStatus()const override
    {
        cout << "Status of MFU: ";
        if(m_status) cout << "ON" << endl;
        else cout << "OFF" << endl;
    }
    void GetId()const override
    {
        cout << "Id device " << m_nameDevice << " - MFUX" << m_id << endl;
    }

};

//----------------------------------------------
int main()
{
    {
        MFU mf("mb19");
        mf.GetStatus();
        mf.Print();
        mf.Scan();
        MFU mf2("f22" , true);
        mf2.GetStatus();
        mf2.TurnOff();
        mf2.GetStatus();
        Scanner sc("sss" , true);
        sc.GetStatus();
        sc.TurnOff();
        sc.GetStatus();
        Device::GetNumberDevice();

        Device *df = new MFU("123", true);

        df->GetId();
        df->GetStatus();
        delete df;
    }
    Device::GetNumberDevice();
    return 0;
}
