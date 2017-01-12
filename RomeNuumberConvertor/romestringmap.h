#ifndef ROMESTRINGMAP_H
#define ROMESTRINGMAP_H

class RomeStringMap
{
//public:
//    int operator[](const char& keyChar)const;
//    char operator[](const int& keyInt)const;
//    int operator[](const size_t& index)const;
//    int GetSize()const;
//    const int m_size;
//    const int m_arab[7];
//    const char m_romen[8];
//    RomeStringMap();
    const int m_size = 7;
    const int m_arab[7] = {1, 5, 10, 50, 100, 500, 1000};
    const char m_romen[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M','\0'};
public:
    int operator[](const char& keyChar)const
    {
        for( int i = 0; i < strlen(m_romen); ++i)
        {
            if(m_romen[i] == keyChar)
            {
                return m_arab[i];
            }
        }
        return -1;
    }
    int operator[](const size_t& index)const
    {
        return m_arab[index];
    }

    char operator[](const int& keyInt)const
    {
        for( int i = 0; i < strlen(m_romen); ++i)
        {
            if(m_arab[i] == keyInt)
            {
                return m_romen[i];
            }
        }
        return 0;
    }

    int GetSize()const
    {
        return m_size;
    }
};


#endif // ROMESTRINGMAP_H
