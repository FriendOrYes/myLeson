#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class String
{
    char* m_buffer;
    int* m_counter;
public:
    String(const char* c)
        :m_buffer(new char[strlen(c) + 1])
        ,m_counter(new int(0))
    {
        strcpy(m_buffer, c);
        (*m_counter)++;
    }

    String(const String& obj)
        :m_buffer(obj.m_buffer)
        ,m_counter(obj.m_counter)
    {
        cout << "String copy\n";
        (*m_counter)++;
    }

    ~String()
    {
        cout << "~String \n";
        (*m_counter)--;
<<<<<<< HEAD
        cout << "m_counter = " << *m_counter  << endl ;
=======
        cout << *m_counter;
>>>>>>> 2950e3d337bc2197aa3e64f5626d567df6467164
        if( (*m_counter) == 0 )
        {
            if(m_buffer)
            {
                cout << "delete m_buffer\n";
                delete []m_buffer;
                m_buffer = nullptr;
            }
        }
    }
    String& operator=(const String& obj)
    {
        (*m_counter)--;
        if(*m_counter == 0)
        {
            cout << "delete" << endl;
            delete []m_buffer;
        }
        m_buffer = obj.m_buffer;
        m_counter = obj.m_counter;
        (*m_counter)++;

        return *this;
    }
    String& operator=(const char* value)
    {
        (*m_counter)--;
        if(*m_counter == 0)
        {
            cout << "delete" << endl;
            delete []m_buffer;
        }

        m_counter = new int(1);

        m_buffer = new char[strlen(value) + 1];
        strcpy(m_buffer, value);

        return *this;
    }

    void SetChar(const char& c, int index)
    {
        (*m_counter)--;
        if(*m_counter == 0)
        {
            cout << "delete" << endl;
            delete []m_buffer;
        }
        m_counter = new int(1);

        char *tempBuffer = new char[strlen(m_buffer) + 1];
        strcpy(tempBuffer, m_buffer);

        m_buffer = tempBuffer;
        m_buffer[index] = c;

    }

    const char* operator +(const String& obj)
    {

        char* c = new char[strlen(m_buffer) + strlen(obj.m_buffer) + 1];
        strcpy(c, m_buffer);
        strcat(c, obj.m_buffer);

        return c;
    }

    const char& operator[](size_t index)
    {
        return m_buffer[index];
    }


    char *GetString()
    {
        return m_buffer;
    }

    int GetCounter()
    {
        return *m_counter;
    }

};

int main(int argc, char *argv[])
{
    char c[20] = "dsdsd";
    String s("dsds   ffsfs");
    String s1("ewewew");
    String ss("sdsd");
    ss.SetChar('1',2);
    String s6("dsd");
    s6 = s1 + s;
    assert(s.GetCounter()  == 1);
    assert(s1.GetCounter() == 1);

    cout << s1.GetString()  << " - s1 "<< endl;
    cout << s.GetString()   << "- s "  << endl;
    cout << s6.GetString()  << "- s6 " << endl;

    String s2 = s1;
    String s3 = s;
    String s4 = s3;

    s = s4;
    s3 = s;

    cout << s.GetCounter() << endl;
    assert(s1.GetCounter() == 2);
    assert(s.GetCounter()  == 3);

    s4.SetChar('u', 2);
    cout << s1.GetString() << " - s1 " << endl;
    cout << s.GetString()  << "- s "   << endl;
    cout << s4.GetString() << "- s4 "  << endl;
    assert(s4.GetCounter() == 1);
    assert(s2.GetCounter() == 2);

    s2 = c;

    cout << "string s2--"<< s2.GetString() << endl;
    cout << "string s1--"<< s1.GetString() << endl;

    return 0;
}
