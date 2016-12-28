#include <iostream>
#include <cstring>
#include <string>

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



//////////////////
///BEGINE TEST 2-3
//////////////////

//------------------------------------------------------------------------
class HTMLElement;



template<typename T>
bool all_of(T* arr, size_t length,bool (*p)(const T &));

template<>
bool all_of<HTMLElement>(HTMLElement* arr, size_t length, bool(*p)(const HTMLElement& elem));

//--------------------------------------------------------------------------------

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem));

template<>
bool any_of<HTMLElement>(HTMLElement* arr, size_t length, bool(*p)(const HTMLElement& elem));

//---------------------------------------------------------------------------------------

template<typename T>
bool TestIsBool(const T &elem);
template<>
bool TestIsBool<HTMLElement>(const HTMLElement& elem);

//-------------------------------------------------------------------------
class HTMLElement
{
public:

    unsigned GetWidth() const
    {
       return m_width;
    }
    void SetWidth(unsigned width)
    {
       m_width = width;
    }

    unsigned GetHeight() const
    {
       return m_height;
    }
    void SetHeight(unsigned height)
    {
       m_height = height;
    }

    bool GetHidden() const
    {
       return m_hidden;
    }
    void SetHidden(bool hidden)
    {
       m_hidden = hidden;
    }

    HTMLElement(unsigned width, unsigned height, bool hidden)
        :m_width(width)
        ,m_height(height)
        ,m_hidden(hidden)
     {}
    virtual string Render() = 0;
    virtual HTMLElement* Dublicate()= 0;
    virtual ~HTMLElement(){}

    bool operator ==(const bool rhs)const
    {
        return m_hidden == rhs? true: false;
    }
    bool operator !=(const bool rhs)const
    {
        return !(*this == rhs);
    }
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
    const string& Title() const
    {
        return  m_button;
    }
    string Render() override
    {
        return "<button>" + m_button  + "</button>";
    }
    HTMLElement* Dublicate() override
    {
        return new HTMLButtonElement(*this);
    }
private:
    string m_button;
};

//-----------------------------------------------
class HTMLImageElement:public HTMLElement
{
public:
    HTMLImageElement(const string& str, unsigned width, unsigned height, bool hidden)
        :HTMLElement(width,height,hidden)
        ,m_image(str)
    {

    }
    const string& Url() const
    {
        return m_image;
    }
    string Render() override
    {
        return "<img src= " + m_image + "height=" + to_string(GetHeight())+" "+ "width="+to_string(GetWidth())+" "+">";
    }
    HTMLElement* Dublicate() override
    {
        return new HTMLImageElement(*this);
    }
private:
    string m_image;
};
//-----------------------------------------------
class HTMLTextAreaElement:public HTMLElement
{
public:
    HTMLTextAreaElement(const string& str, unsigned width, unsigned height, bool hidden)
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
        return "<textarea>\n" + m_content + "\n" + "</textarea>\n";
    }
    HTMLElement* Dublicate() override
    {
        return new HTMLTextAreaElement(*this);
    }
private:
    string m_content;
};
//------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    const int size = 3;
    HTMLElement *htmlElement[size];
    htmlElement[0] = new HTMLButtonElement("button", 20, 30, 0);
    htmlElement[1] = new HTMLImageElement("kity.png", 20, 30, 1);
    htmlElement[2] = new HTMLTextAreaElement("content of the text area", 10, 10, 0);

    HTMLElement *htmlElementCopy[size];

    htmlElementCopy[0] = htmlElement[0]->Dublicate();
    htmlElementCopy[1] = htmlElement[1]->Dublicate();
    htmlElementCopy[2] = htmlElement[2]->Dublicate();


    delete htmlElement[0];
    delete htmlElement[1];
    delete htmlElement[2];

    delete htmlElementCopy[0];
    delete htmlElementCopy[1];
    delete htmlElementCopy[2];

    HTMLTextAreaElement ta[3] = {
        {"content of the text area", 10, 10, 1},
        {"content of the text area", 10, 10, 1},
        {"content of the text area", 10, 10, 1}
    };

    assert(all_of(ta, size, TestIsBool) == true && any_of(ta, size, TestIsBool) == true);

    ta[1].SetHidden(0);
    assert(all_of(ta, size, TestIsBool) == false && any_of(ta, size, TestIsBool) == true);

    return 0;
}

////////////////////
///END TEST 2-3
/// ///////////////
//-------------------------------------------------------------------------------------------
template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for(int i = 0; i < length; ++i)
    {
        if(p(arr[i]) != true)
        {
            return false;
        }
    }
    return true;
}
//-----------------------------------------------------------------------------------------
template<>
bool all_of<HTMLElement>(HTMLElement* arr, size_t length, bool(*p)(const HTMLElement& elem))
{
    for(int i = 0; i < length; ++i)
    {
        if(p(arr[i]) != true)
        {
            return false;
        }
    }
    return true;
}

//-------------------------------------------------------------------------------------------
template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for(unsigned int i = 0; i < length; ++i)
    {
        if(p(arr[i]) == true)
        {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------------------
template<>
bool any_of<HTMLElement>(HTMLElement* arr, size_t length, bool(*p)(const HTMLElement& elem))
{
    for(unsigned int i = 0; i < length; ++i)
    {
        if(p(arr[i]) == true)
        {
            return true;
        }
    }
    return false;
}
//--------------------------------------------------------------------------
template<typename T>
bool TestIsBool(const T& elem)
{
    if(elem == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<>
bool TestIsBool<HTMLElement>(const HTMLElement& elem)
{
    return elem.GetHidden();
}
//-----------------------------------------------------------------------------
//template<typename T>
//bool all_of(T** arr, size_t length, bool(*p)(const T& elem))
//{
//    for(int i = 0; i < length; ++i)
//    {
//        if(p(arr[i]) != true)
//        {
//            return false;
//        }
//    }
//    return true;
//}
////------------------------------------------------------------------------------------------
//template<>
//bool all_of<HTMLElement>(HTMLElement** arr, size_t length, bool(*p)(const HTMLElement& elem))
//{
//    for(int i = 0; i < length; ++i)
//    {
//        if(p(arr[i]) != true)
//        {
//            return false;
//        }
//    }
//    return true;
//}

//template<typename T>
//bool any_of(T** arr, size_t length, bool(*p)(const T& elem))
//{
//    for(unsigned int i = 0; i < length; ++i)
//    {
//        if(p(*arr[i]) == true)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//------------------------------------------------------------------------------------------
//template<>
//bool any_of<HTMLElement>(HTMLElement** arr, size_t length, bool(*p)(const HTMLElement& elem))
//{
//    for(unsigned int i = 0; i < length; ++i)
//    {
//        if(p(*arr[i]) == true)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//-------------------------------------------------------
///////////////////
///END TEST 4
///////////////////
