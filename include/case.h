#include <iostream>
#ifndef CASE_H
#define CASE_H


using namespace std;

class Case
{

    public:
        char aff;
        char val;
        int dec;
        Case() {aff='#';
        dec=0;}
        virtual ~Case() {}

    protected:

    private:

};

#endif // CASE_H
