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
        cout << *m_counter;
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

        m_buffer = obj.m_buffer;
        m_counter = obj.m_counter;
        (*m_counter)++;

        return *this;
    }

    String& operator=(const char* value)
    {
        (*m_counter)--;
        m_counter = new int(1);

        m_buffer = new char[strlen(value) + 1];
        strcpy(m_buffer, value);
        return *this;
    }
    void SetChar(const char c, int index)
    {
        (*m_counter)--;
        m_counter = new int(1);

        char tempBuffer[strlen(m_buffer) + 1];
        strcpy(tempBuffer, m_buffer);
        m_buffer = tempBuffer;
        m_buffer[index] = c;

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

    cout << s1.GetString() << " s1 "<< endl;
    cout << s.GetString()  << " s " << endl;

    String s2 = s1;
    String s3 = s;
    String s4 = s3;

    s = s4;
    s3 = s;
    s4 = s2;

    assert(s1.GetCounter() == 3);
    assert(s.GetCounter() == 2);

    s4.SetChar('d', 2);

    assert(s4.GetCounter() == 1);
    assert(s2.GetCounter() == 2);

    s2 = c;
    cout << s2.GetString() << endl;
    return 0;
}
