#include <iostream>
#include <cstring>

//#define NDEBUG
#include <cassert>

using namespace std;

class String
{
private:
    char* m_buffer;
    int* m_counter;

    void CheckCounter()
    {
        (*m_counter)--;
        if(*m_counter == 0)
        {
            cout << "delete" << endl;
            delete []m_buffer;
            delete []m_counter;
        }
    }
    void AttachToBuffer(const String& obj)
    {
        m_buffer = obj.m_buffer;
        m_counter = obj.m_counter;
        (*m_counter)++;
    }

public:
    String()
        :m_counter(new int(1))
        ,m_buffer(nullptr)
    {
        cout << "String : "<< this <<endl;
    }
    String(const char* c)
        :m_buffer(new char[strlen(c) + 1])
        ,m_counter(new int(0))
    {
        cout << "String(St): "<< this <<endl;
        strcpy(m_buffer, c);
        (*m_counter)++;
    }

    String(const String& obj)
    {
        AttachToBuffer(obj);
        cout << "String copy\n";
    }

    ~String()
    {
        cout << "~String : "<< this <<"\n";
        (*m_counter)--;

        cout << "m_counter = " << *m_counter  << endl ;

        cout << *m_counter;

        if( (*m_counter) == 0 )
        {
            if(m_buffer)
            {
                cout << "delete m_buffer\n";
                delete []m_buffer;
                delete []m_counter;
                m_counter = nullptr;
                m_buffer = nullptr;
            }
        }
    }
    String& operator=(const String& obj)
    {
        CheckCounter();

        AttachToBuffer(obj);

        return *this;
    }
    String& operator=(const char* value)
    {
        CheckCounter();

        m_counter = new int(1);

        m_buffer = new char[strlen(value) + 1];
        strcpy(m_buffer, value);

        return *this;
    }

    void SetChar(const char& c, int index)
    {
        CheckCounter();
        m_counter = new int(1);

        char *tempBuffer = new char[strlen(m_buffer) + 1];
        strcpy(tempBuffer, m_buffer);

        m_buffer = tempBuffer;
        m_buffer[index] = c;

    }

    const char* operator +(const String& obj)const
    {

        char* c = new char[strlen(m_buffer) + strlen(obj.m_buffer) + 1];
        strcpy(c, m_buffer);
        strcat(c, obj.m_buffer);

        return c;
    }

    const char& operator[](size_t index)const
    {
        return m_buffer[index];
    }


    const char *GetString()const
    {
        return m_buffer;
    }

    const int GetCounter()const
    {
        return *m_counter;
    }

    inline const int* GetAdressCounter()const
    {
        return m_counter;
    }

};




int main(int argc, char *argv[])
{

    String s = "anton";
    {
        String s1 = s;
        String s2 = "dssaa";
        assert("Test 1 m_counter in s crash : mismatch with counter " &&
               s.GetCounter() == 2 );
        assert("Test 1 m_counter in s2 crash : mismatch with counter" &&
               s2.GetCounter() == 1 );

    }
    cout << "======================="<<endl;
    assert("Test 2 m_counter in s crash : The counter has not decreased" &&
           s.GetCounter() == 1 );
    String s2 = "chaban";
    {
        String s3 = s + s2;
        String s4;
        assert("Test 3 adress m_counter  : semy with adress counter s2 or s " &&
               (s3.GetAdressCounter() != s.GetAdressCounter()) &&
               (s3.GetAdressCounter() != s2.GetAdressCounter()));
    }

    return 0;
}
