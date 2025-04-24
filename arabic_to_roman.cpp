/*
    arabic_to_roman
    Converts Hindu Arabic Numeral in Integer form from ARG input
    into Roman Numeral printed in Terminal. Accepts multiple ARGs.

    For submission to https://code.golf/arabic-to-roman#cpp

    Created by amd

*/


// ------------------------------
// ******************************
// Preprocessor Declaration
// ******************************
// ------------------------------

#define P_OK 0
#define P_ERR_RANGE -10
#define P_ERR_NUM -25

#include <iostream>
#include <string>
#include <numbers>

using namespace std;


// ------------------------------
// ******************************
// Class Declaration
// numeral
// ******************************
// ------------------------------


// ------------------------------
// Class Prototype
// ------------------------------
class numeral
{
    public:
    string roman;
    int arabic;

    int convert_ar();

};


// ------------------------------
// Class Members - method
// convert_ar() method
// ------------------------------
int numeral::convert_ar()
{
    // ----------------------------
    // Variable declaration
    int res;

    int num01;
    int i;

    // ---------------------------
    // Actual Function Run

    // clear the roman string for use
    this->roman.erase();

    // get the number to be  processes
    num01=this->arabic;

    // Test number for accepted Range
    if(num01>=0 && num01<5000)
    {
        // If within range

        // process for 1000s to <4000
        if(num01>=1000 && num01<4000)
        {
            i=num01/1000;

            while(i>0)
            {
                this->roman+="M";
                num01-=1000;
                i--;
            };

        };

        // For 900
        if(num01>=900 && num01<1000)
        {
            this->roman+="CM";
            num01-=900;
        };

        // For 400
        if(num01>=400 && num01<500)
        {
            this->roman+="CD";
            num01-=400;
        };

        // For 100 to <400 and 500 to <900
        if(num01>=100 && num01<400 || num01>=500 && num01<900)
        {
            // 500
            if(num01>=500 && num01<900)
            {
                this->roman+="D";
                num01-=500;
            };

            // 100 to 300 and 600 to 800
            i=num01/100;
            while(i>0)
            {
                this->roman+="C";
                num01-=100;
                i--;
            };
        };

        // For 90
        if(num01>=90 && num01<100)
        {
            this->roman+="XC";
            num01-=90;
        };

        // For 40
        if(num01>=40 && num01<50)
        {
            this->roman+="XL";
            num01-=40;
        };

        // For 10 to 30 and 50 to 80
        if(num01>=10 && num01<40 || num01>=50 && num01<90)
        {
            // 50
            if(num01>=50 && num01<90)
            {
                this->roman+="L";
                num01-=50;
            };

            // 10 to 30 and 50 to 80
            i=num01/10;
            while(i>0)
            {
                this->roman+="X";
                num01-=10;

                i--;
            };
        };

        // For 9
        if(num01>=9 && num01<10)
        {
            this->roman+="IX";
            num01-=9;
        };

        // For 4
        if(num01>=4 && num01<5)
        {
            this->roman+="IV";
            num01-=4;
        };

        // For 1 to 3 and 5 to 8
        if(num01>=1 && num01<4 || num01>=5 && num01<9)
        {
            // 5
            if(num01>=5 && num01<9)
            {
                this->roman+="V";
                num01-=5;
            };

            // 1 to 3 and 5 to 8
            i=num01/1;
            while(i>0)
            {
                this->roman+="I";
                num01-=1;

                i--;
            };

        };

        res=P_OK;

    }else
    {
        // For out of  range
        res=P_ERR_RANGE;
    };
    
    // End method with return result
    return res;

};


// ------------------------------
// ******************************
// Program Entry Point
// ******************************
// ------------------------------
int main(int argc, char* argv[])
{

    // ----------------------------
    // Variable declaration
    int number01;
    int count;
    string str01;

    // Object creation form class
    numeral convert01;


    // ---------------------------
    // Actual program Run

    // Test ARG for any inputs
    if(argc>1)
    {
        // Processing the ARG to process
        count=1;
        while(count<argc)
        {
            // Converting ARG to number
            str01=argv[count];
            number01=stoi(str01);

            // placing number to be  processed
            convert01.arabic=number01;

            // processing the number
            if( (convert01.convert_ar() ) == P_OK )
            {
                // Situation if OK or with range
                cout<<convert01.roman<<endl;
            }else
            {
                // Situation if Out of Range
                cout<<"ERROR: Out of Range..."<<endl;
            };
            
            count++;

        };

    }else
    {
        // If No ARG
        cout<<"Enter integer number as ARG..."<<endl;
    };



    //Program END with return of 0
    return  0;

};
