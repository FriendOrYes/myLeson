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

    bool CheckCounter()
    {
        (*m_counter)--;
        if(*m_counter == 0)
        {
            return 1;
        }
        return 0;
    }

    void AttachToBuffer(const String& obj)
    {
        m_buffer = obj.m_buffer;
        m_counter = obj.m_counter;
        (*m_counter)++;
    }

    void DettachFromBuffer()
    {
        if(CheckCounter())
        {
            if(m_counter) delete m_counter;
            if(m_buffer) delete []m_buffer;

            m_counter = nullptr;
            m_buffer = nullptr;
        }
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
        DettachFromBuffer();
    }
    String& operator = (const String& obj)
    {
        if(&obj != this)
        {
            String tmp(obj);
            tmp.CheckCounter();
            tmp.AttachToBuffer(obj);
            Swap(tmp);
        }
        return *this;
    }
    String& operator=(const char* value)
    {
        String tmp(value);
        std::swap(tmp, *this);
    }

    void SetChar(const char& c, const int& index)
    {
        String tmp(m_buffer);
        std::swap(tmp, *this);
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

    void Swap(String& obj)
    {
        std::swap(obj.m_counter, this->m_counter);
        std::swap(obj.m_buffer, this->m_buffer);
    }
    friend ostream& operator << (ostream& os, const String& obj);
};

ostream& operator << (ostream& os, const String& obj)
{
    os << obj.m_buffer;
    return os;
}


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

    s.SetChar('s', 1);

    String s3;//= s2 + s;

    cout << "////" << endl;

    cout << s3.GetAdressCounter()  << endl;
    cout << s.GetAdressCounter()  << endl;

    assert("Test 4 adress m_counter  : semy with adress counter s2 or s " &&
           (s3.GetAdressCounter() != s.GetAdressCounter()) &&
           (s3.GetAdressCounter() != s2.GetAdressCounter()));

    cout << s;

    {
       String s1("abc");
       s1.SetChar('x', 0);
       assert(s1.GetCounter() == 1);
    }

    return 0;
}
