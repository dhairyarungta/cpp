#include<iostream>
#include<cstring>

class CText{
private:
    char*pText;
public:
    char& operator[](std::size_t position)const
    { return pText[position];}
    
    CText(char*text)
    {
        size_t n = strlen(text);
        pText = new char[n];
        strncpy(pText,text,n);
        
    }
};

int main()
{
const CText a("hello");
char*p = &a[0];
*p = 'b';
std::cout<<p;//changes to "bello",
// which shouldn't happen if variable a is declared const.

}
