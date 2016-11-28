#include"Big5Char.h"

#include<cstdio>

Big5Char::Big5Char(char* big5ch){
    if((big5ch[0]&0xFF)>127) {
        this->ch[0]=big5ch[0];
        this->ch[1]=big5ch[1];
    }
    else {
        this->ch[0]=big5ch[0];
    }
}

Big5Char::Big5Char(char h,char l){
    this->ch[0]=h;
    this->ch[1]=l;
}

Big5Char& Big5Char::operator=(const Big5Char& rhs){
    const char* temp = rhs.c_str();
    this->ch[0]=temp[0];
    this->ch[1]=temp[1];
}

bool Big5Char::operator==(const Big5Char& rhs)const{
    const char* temp = rhs.c_str();
    return this->ch[0]==temp[0] && this->ch[1]==temp[1];
}

bool Big5Char::operator!=(const Big5Char& rhs)const{
    return !(*this==rhs);
}

std::ostream& operator<<(std::ostream& os, const Big5Char& b5c)
{
    os << b5c.ch[0];
    if(b5c.ch[1])os << b5c.ch[1];
    return os;
}

bool cBig5reader(Big5Char* b5c,FILE* fp){
    char ch=fgetc(fp);
    if(ch!=EOF){
        if((ch&0xFF) > 127){
            *b5c = Big5Char(ch,fgetc(fp));
        }
        else{
            *b5c = Big5Char(ch,'\0');
        }
        return true;
    }
    return false;
}
