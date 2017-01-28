#include <iostream>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

template<class T>
class Stack
{
    size_t m_maxSize;
    T* m_stackPtr;
    int m_top;
public:
    Stack(const int& size = 10)
        : m_maxSize(size)
        , m_stackPtr(new T[m_maxSize])
        , m_top(0)
    {

    }
    Stack(const Stack& obj)
        : m_maxSize(obj.m_maxSize)
        , m_stackPtr(new T[m_maxSize])
        , m_top(obj.m_top)
    {
        for(size_t i = 0; i < m_top; ++i)
        {
            m_stackPtr[i] = obj.m_stackPtr[i];
        }
    }
    ~Stack()
    {
        delete []m_stackPtr;
    }

    inline void Push(const T& elem)
    {
        if(m_top > m_maxSize)
        {
            return;
        }

        m_stackPtr[m_top++] = elem;
    }
    inline const T& Pop()
    {
        if(m_top < 1)
        {
            return 0;
        }

        return m_stackPtr[m_top--];
    }

    const size_t& GetStackSize()const
    {
        return m_maxSize;
    }

    T *GetPtr()const
    {
        return m_stackPtr;
    }

    const int& GetTop()const
    {
        return m_top;
    }

    template<typename U>
    friend ostream& operator << (ostream &os, const Stack<U>& obj);
    const T& operator = (const Stack& obj) = delete;
};
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
template<>
class Stack<bool>
{
    size_t m_maxSize;
    char* m_stackPtr;
    int m_top;

    size_t SizeСalculation(const int& size)
    {
        m_maxSize = size / 8;
        if( size%8 )
        {
            m_maxSize++;
        }

        return m_maxSize;
    }
public :
    Stack(const int& size = 15)
        : m_stackPtr(new char[SizeСalculation(size)])
        , m_top(0)
    {
    }

    Stack(const Stack& obj)
        : m_maxSize(obj.m_maxSize)
        , m_stackPtr(new char[m_maxSize])
        , m_top(obj.m_top)
    {
        cout << "Stack(copy) " << endl;
        memcpy(m_stackPtr,obj.m_stackPtr,sizeof(m_stackPtr));
    }

    ~Stack()
    {
        delete []m_stackPtr;
    }
//-------------------------------------------------------------------------
    inline void Push(const bool& elem)
    {
        cout << __FUNCTION__ << endl ;
        if(m_top > m_maxSize * 8)
        {
            cout << " Overflow Stack" << endl;
            return ;
        }

        int numElem = m_top / 8;
        int offsetElem = m_top % 8;

        m_stackPtr[numElem] ^= (-elem ^ m_stackPtr[numElem])
                & (1 << (7 - offsetElem));
        m_top++;
        cout << m_top << endl;
    }
//-------------------------------------------------------------------------
    bool Pop()
    {
        if(m_top > 0)
        {
            return 0;
        }

        int numElemet = m_top / 8;
        int offsetElem = m_top % 8;

        m_top--;

        return (1 & (m_stackPtr[numElemet] >> offsetElem));
    }
//-------------------------------------------------------------------------
    size_t GetMaxStackLenght()const
    {
        return m_maxSize * 8;
    }

    const int& GetTop()const
    {
        return m_top;
    }
//-------------------------------------------------------------------------
    const Stack& operator = (const Stack& obj)
    {
        cout << __FUNCTION__ << endl;
        delete []m_stackPtr;

        m_maxSize = obj.m_maxSize;
        m_stackPtr = new char[m_maxSize];
        m_top = obj.m_top;

        for(size_t i = 0; i < m_maxSize; ++i)
        {
            m_stackPtr[i] = obj.m_stackPtr[i];
        }
    }

    friend ostream& operator << (ostream &os, const Stack& obj);
};


//-------------------------------------------------------------------------

template<typename T>
ostream& operator << (ostream &os, const Stack<T>& obj)
{
    for(size_t i = 0; i < obj.m_top; i++)
    {
        os << obj.m_stackPtr[i] << endl;
    }
    return os;
}

//--------------------------------------------------------------------------
ostream& operator << (ostream &os, const Stack<bool>& obj)
{
    os << __FUNCTION__ << endl ;

    int i = 0, k = 7;
    int offsetElem = k % 8, top = obj.m_top;

    while(top--)
    {
        os << (1 & (obj.m_stackPtr[i] >> offsetElem)) << " | ";

        if(k-- == 0)
        {
            k = 7;
        }
        i = (obj.m_top - top) / 8;
        offsetElem = k % 8;
    }
    os << endl;
    return os;
}


int main(int argc, char *argv[])
{
    const int size = 10;

    Stack<bool> st;

    st.Push(1);
    st.Push(1);
    st.Push(1);
    st.Push(0);
    st.Push(1);
    st.Push(1);
    st.Push(0);
    st.Push(0);


    Stack<double> stD(8);

    stD.Push(5);
    stD.Push(3.4);
    stD.Push(2.3);
    stD.Push(1.4);
    stD.Push(-6.1);

    cout << st;
    cout << stD;
    return 0;
}
