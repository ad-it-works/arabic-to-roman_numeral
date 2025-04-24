#define P_OK 0
#define P_ERR_RANGE -10
#define P_ERR_NUM -25

#include <iostream>
#include <string>
#include <numbers>

using namespace std;

class numeral
{
    public:
    string roman;
    int arabic;

    int convert_ar();

};


int numeral::convert_ar()
{
    int res;

    int num01;
    int i;

    this->roman.erase();

    num01=this->arabic;

    if(num01>=1000)
    {
        i=num01/1000;

        while(i>0)
        {
            this->roman+="M";
            num01-=1000;
            i--;
        };

    };

    if(num01>=900 && num01<1000)
    {
        this->roman+="CM";
        num01-=900;
    };

    if(num01>=400 && num01<500)
    {
        this->roman+="CD";
        num01-=400;
    };

    if(num01>=100 && num01<400 || num01>=500 && num01<900)
    {
        if(num01>=500 && num01<900)
        {
            this->roman+="D";
            num01-=500;
        };

        i=num01/100;
        while(i>0)
        {
            this->roman+="C";
            num01-=100;
            i--;
        };
    };

    if(num01>=90 && num01<100)
    {
        this->roman+="XC";
        num01-=90;
    };

    if(num01>=40 && num01<50)
    {
        this->roman+="XL";
        num01-=40;
    };

    if(num01>=10 && num01<40 || num01>=50 && num01<90)
    {
        if(num01>=50 && num01<90)
        {
            this->roman+="L";
            num01-=50;
        };

        i=num01/10;
        while(i>0)
        {
            this->roman+="X";
            num01-=10;

            i--;
        };
    };

    if(num01>=9 && num01<10)
    {
        this->roman+="IX";
        num01-=9;
    };

    if(num01>=4 && num01<5)
    {
        this->roman+="IV";
        num01-=4;
    };

    if(num01>=1 && num01<4 || num01>=5 && num01<9)
    {
        if(num01>=5 && num01<9)
        {
            this->roman+="V";
            num01-=5;
        };

        i=num01/1;
        while(i>0)
        {
            this->roman+="I";
            num01-=1;

            i--;
        };


    };


    res=P_OK;


    return res;
};


int main(int argc, char* argv[])
{

    int number01;
    int count;
    string str01;

    numeral convert01;

    if(argc>1)
    {
        count=1;
        while(count<argc)
        {
            str01=argv[count];
            number01=stoi(str01);

            convert01.arabic=number01;
            convert01.convert_ar();
            cout<<convert01.roman<<endl;


            count++;
        };

    }



    return  0;
}