#include <iostream>
#include <string>
using namespace std;

string step(string, string, string, int, int); //given proper input, prints hundreds, tens, and ones
string get_1000s(int);

int main()
{
    int input;
    cin>>input;
    if(input>9999)
    {
    cout<<'\n'<<"Input is too large. Roman system is not a practical way of expressing it."<<"\n\n";
    return 0;
    }

    cout<<get_1000s(input);            //prints the thousands; it is a separate function, as M is the uppermost character
    string s1="I", s2="V", s3="X", s4="L", s5="C", s6="D", s7="M";
    cout<<step(s5, s6, s7, input, 1000)
             <<step(s3, s4, s5, input, 100)
             <<step(s1, s2, s3, input, 10)<<"\n\n";

    return 0;
}

    string step(string x, string y, string z, int input, int upperLimit)
{
    int i=0;
    while(input>=upperLimit) input-=upperLimit;
    do{input-=(upperLimit/10); ++i;}
    while(input>=0);
    --i;
    input+=(upperLimit/10);

    string b;
    switch(i){
    case 1: b=x; break;
    case 2: b=x+x; break;
    case 3: b=x+x+x; break;
    case 4: b=x+y; break;
    case 5: b=y; break;
    case 6: b=y+x; break;
    case 7: b=y+x+x; break;
    case 8: b=y+x+x+x; break;
    case 9: b=x+z; break;}

    return b;
}
string get_1000s(int input)
{
string final;
    while(input>=1000)
    {
        input-=1000;
        final+='M';
    }

    return final;
}
