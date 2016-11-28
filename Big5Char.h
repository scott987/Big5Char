#ifndef BIG5CHAR_H_INCLUDED
#define BIG5CHAR_H_INCLUDED

#include<ostream>

class Big5Char{
public:
    Big5Char(){};
    Big5Char(char* big5ch);
    Big5Char(char h,char l);

    const char* c_str()const{return ch;};
    Big5Char& operator=(const Big5Char& rhs);
    bool operator==(const Big5Char& rhs)const;
    bool operator!=(const Big5Char& rhs)const;
    friend std::ostream& operator<<(std::ostream& os, const Big5Char& b5c);

    bool isChinese(){
        return (ch[0]&0xFF) >= 0xA4;
    }
private:
    char ch[3]={0};
};

std::ostream& operator<<(std::ostream& os, const Big5Char& b5c);

// read one big5 character
bool cBig5reader(Big5Char* b5c,FILE* fp);

#endif // BIG5CHAR_H_INCLUDED
