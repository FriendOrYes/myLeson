#include <iostream>
#include <cstring>

#include <cassert>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
using namespace std;
////--------
///
/// Test 1
///

//template<class T>
//class ImmutableBuffer
//{
//public:
//    ImmutableBuffer(T *arr, const int size)
//        :m_buffer(new T[size])
//        ,m_size(size)
//    {
//        for(int i = 0; i < size; ++i)
//        {
//            m_buffer[i] = arr[i];
//        }
//    }
//    ImmutableBuffer(const ImmutableBuffer& obj)
//        :m_buffer(new T[obj.m_size])
//        ,m_size(obj.m_size)
//    {
//        for(int i = 0; i < obj.m_size; ++i)
//        {
//            m_buffer[i] = obj.m_buffer[i];
//        }
//    }
//    ~ImmutableBuffer()
//    {
//        if(m_buffer)
//        {
//            delete []m_buffer;
//            m_buffer = nullptr;
//        }
//    }
//    const T& operator[](const size_t index)const
//    {
//        return m_buffer[index];
//    }
//    template<typename U>
//    friend ostream& operator << (ostream& os, const ImmutableBuffer<U>& obj);
//    const bool operator == (const ImmutableBuffer& obj)const
//    {
//        if(m_size != obj.m_size)
//        {
//            return false;
//        }
//        for(int i = 0; i < m_size; ++i)
//        {
//            if(m_buffer[i] != obj.m_buffer[i])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    const bool operator == (const T* arr)const
//    {
//        if(m_size != ARRAY_SIZE(arr))
//        {
//            return false;
//        }
//        for(int i = 0; i < m_size; ++i)
//        {
//            if(m_buffer[i] != arr[i])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    const bool operator !=(const ImmutableBuffer& obj)const
//    {
//        return !(this == obj);
//    }
//    const bool operator !=(const T *arr)const
//    {
//        return !(this == arr);
//    }
//private:
//    const ImmutableBuffer& operator=(const ImmutableBuffer& obj){}
//    T *m_buffer;
//    size_t m_size;

//};

//template<class T>
//ostream& operator<< (ostream& os, const ImmutableBuffer<T>& obj)
//{
//    for(int i = 0; i < obj.m_size; ++i)
//    {
//        os << obj.m_buffer[i] << " ";
//    }
//    return os;
//}
///int main(int argc, char *argv[])
//{
//    int arr2[] ={1,2};


//    double arr[] = {1.0, 2.0, 3.0};
//    ImmutableBuffer<double> buff(arr, ARRAY_SIZE(arr));
//    ImmutableBuffer<double> buff2 = buff;
//        arr[0] = 0;
//        assert(buff[0] == 1.0);

//        // equal
//        assert(buff == buff2);

//        // should fail
//        // buff[0] = 42.0;
//        // buff    = buff2;

//        cout << buff << endl;

//    return 0;
///}
/// Finish Test 1
///-----------------------------------------------------------------------------------------------------------------
///

//template<>
//class ImmutableBuffer<char>
//{
//public:
//    ImmutableBuffer(char *arr)
//        :m_buffer(new char[strlen(arr) + 1])
//    {
//        for(unsigned int i = 0; i < strlen(arr); ++i)
//        {
//            m_buffer[i] = arr[i];
//        }
//    }
//    ImmutableBuffer(const ImmutableBuffer& obj)
//        :m_buffer(new char[strlen(obj.m_buffer + 1)])
//    {
//        strcpy(m_buffer,obj.m_buffer);
//    }
//    ~ImmutableBuffer()
//    {
//        if(m_buffer)
//        {
//            delete []m_buffer;
//            m_buffer = nullptr;
//        }
//    }
//    const bool operator == (const ImmutableBuffer& obj)const
//    {
//        return strcmp(m_buffer,obj.m_buffer);
//    }
//    const bool operator == (const char* str)const
//    {
//        return strcmp(m_buffer,str);
//    }
//    const bool operator !=(const ImmutableBuffer& obj)const
//    {
//        return !(this == obj);
//    }
//    const bool operator !=(const string& str)const
//    {
//        return !(this == str);
//    }
//    friend ostream& operator<<(ostream& os, const ImmutableBuffer& obj);
//private:
//    const ImmutableBuffer& operator=(const ImmutableBuffer& obj){}
//    char *m_buffer;
//};
////-----------------------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------------------
//template<>
//class ImmutableBuffer<string>
//{
//public:
//    ImmutableBuffer(string str)
//        :m_buffer(str)
//    {
//    }
//    ImmutableBuffer(const ImmutableBuffer& obj)
//        :m_buffer(obj.m_buffer)
//    {
//    }

//    friend ostream& operator<<(ostream& os, const ImmutableBuffer& obj);
//private:
//    string m_buffer;
//};
////-----------------------------------------------------------------------------------------------------------------
//ostream& operator<< (ostream& os, const ImmutableBuffer<int>& obj)
//{
//    for(int i = 0; i < obj.m_size; ++i)
//    {
//        os << obj.m_buffer[i] << " ";
//    }
//    return os;
//}
////----------------------------------------------------------------------------------------
//ostream& operator<< (ostream& os, const ImmutableBuffer<double>& obj)
//{
//    for(int i = 0; i < obj.m_size; ++i)
//    {
//        os << obj.m_buffer[i] << " ";
//    }
//    return os;
//}
////----------------------------------------------------------------------------------------

//ostream& operator<<(ostream& os, const ImmutableBuffer<char>& obj)
//{
//    os << obj.m_buffer;
//    return os;
//}
//----------------------------------------------------------------------------------------

//template<class T> error: undefined reference to `operator<<(std::ostream&, ImmutableBuffer<double> const&)'
//ostream& operator<< (ostream& os, const ImmutableBuffer<T>& obj)
//{
//    for(int i = 0; i < obj.m_size; ++i)
//    {
//        os << obj.m_buffer[i] << " ";
//    }
//    return os;
//}
//------------------------------------------------------------------------------------------------------------------



///-
/// Test 2
class HTMLElement
{
public:
     unsigned Width() const
     {
         return m_width;
     }
     unsigned Height() const
     {
         return m_height;
     }
     bool Hidden() const
     {
         return m_hidden;
     }
     HTMLElement(unsigned width,unsigned height,bool hidden)
         :m_width(width)
         ,m_height(height)
         ,m_hidden(hidden)
     {}
     virtual string Render() = 0;
     virtual ~HTMLElement(){}
private:
    unsigned m_width;
    unsigned m_height;
    bool m_hidden;
};

//-----------------------------------------------
class HTMLButtonElement:public HTMLElement
{
public:
    HTMLButtonElement(const string& str,unsigned width,unsigned height,bool hidden)
        :HTMLElement(width,height,hidden)
        ,m_button(str)
    {

    }
    const string& Title() const;
    string Render() override
    {
        return m_button;
    }
private:
    string m_button;
};

//-----------------------------------------------
class HTMLImageElement:public HTMLElement
{
public:
    HTMLImageElement(const string& str,unsigned width,unsigned height,bool hidden)
        :HTMLElement(width,height,hidden)
        ,m_image(str)
    {

    }
    const string& Url() const;
    string Render() override
    {
        "<img src='../../smiley.gif' height= + '42' width='42'>"
    }
private:
    string m_image;
};
//-----------------------------------------------
class HTMLTextAreaElement:public HTMLElement
{
public:
    HTMLTextAreaElement(const string& str,unsigned width,unsigned height,bool hidden)
        :HTMLElement(width,height,hidden)
        ,m_content(str)
    {

    }
    const string& Content() const
    {
        return m_content;
    }
    string Render() override
    {
        return "<textarea>\n" + m_content+ "\n" + "</textarea>\n";
    }

private:
    string m_content;
};
int main(int argc, char *argv[])
{
    const int size = 3;
    HTMLTextAreaElement textAreaElement("title-of-the-button",40,20,0);

    HTMLElement *sh = &textAreaElement;
    cout << sh->Render();
    return 0;
}
