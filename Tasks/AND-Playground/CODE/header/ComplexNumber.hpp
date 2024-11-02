#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
    double dReal;
    double dImag;
} COMPLEXNUMBER;

namespace ComplexNumberCal {

    class ComplexNumber {
    private: 
        COMPLEXNUMBER typComplex;

    public: 
    //CON//DES/////////////////////////////////////////////////////
    // constructor, sets up the function when first instaniated. 
    ComplexNumber() {
        this->typComplex.dReal = 0;
        this->typComplex.dImag = 0;
        cout << "Welcome to the Complex Number Calculator" << endl;
    }

    //copy constructor for copying one class to another. 
    ComplexNumber(const COMPLEXNUMBER source) {
        this->typComplex.dReal = source.dReal;
        this->typComplex.dImag = source.dImag;
    }

    // destructor - This operates when the class closes down. 
    ~ComplexNumber() {
        cout << "Complex Number Calculator Shutting Down" << endl;
    }

    //GET//SET////////////////////////////////////////////////////////
    // Real getter
    double GETReal() {
        return this->typComplex.dReal;
    }

    // Imaj getter
    double GETImaj() {
        return this->typComplex.dImag;
    }

      // Real setter
    void SETReal(double dRealInput) {
        this->typComplex.dReal = dRealInput;
    }

    // Imaj setter
    void SETImaj(double dImajInput) {
        this->typComplex.dImag = dImajInput;
    }

    //METHODS////////////////////////////////////////////////////////
    //conjugate
    COMPLEXNUMBER mConjugate(const COMPLEXNUMBER source) {
        COMPLEXNUMBER output;
        output.dReal = source.dReal;
        output.dImag = source.dImag;
        output.dImag *= 1;
        return output;
    }

    //add - NOT FINISHED
    COMPLEXNUMBER mAdd(COMPLEXNUMBER a, COMPLEXNUMBER b) {
        COMPLEXNUMBER c;
        c.dReal = (a.dReal + b.dReal);
        c.dImag = (a.dImag + b.dImag);
        return c;
    }

    //subtract - NOT FINISHED
    COMPLEXNUMBER mSubstract(COMPLEXNUMBER a, COMPLEXNUMBER b) {
        COMPLEXNUMBER c;
        c.dReal = (a.dReal - b.dReal);
        c.dImag = (a.dImag - b.dImag);
        return c;
    }

    //multiply - NOT FINISHED
    COMPLEXNUMBER mMultiply(COMPLEXNUMBER a, COMPLEXNUMBER b) {
        COMPLEXNUMBER c;
        c.dReal = (a.dReal * b.dReal);
        c.dImag = (a.dImag * b.dImag);
        return c;
    }

    //divide - NOT FINISHED
    COMPLEXNUMBER mDivide(COMPLEXNUMBER a, COMPLEXNUMBER b) {
        COMPLEXNUMBER c;
        c.dReal = (a.dReal / b.dReal);
        c.dImag = (a.dImag / b.dImag);
        return c;
    }

    //absolute
    double mAbsolute(COMPLEXNUMBER input) {
        double a = (input.dReal * input.dReal);
        double b = (input.dImag * input.dImag);
        double result = a + b;
        result = sqrt(result);
        return result;
    }
      

};
}

#endif