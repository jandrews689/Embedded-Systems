#include "mbed.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <array>

using namespace std;

//Week2 - In class coursework 

//Write a program to achieve the following functions:
    //1 ) Can calculate the absolute value of the imaginary number. Output the results in the console display.
    //2 ) Can convert the binary to hexadecimal. Output the results in the console display.


//Part 1 - Complex Number absolute value. 
namespace ComplexNumberCal { //Define a namespace

    typedef struct { //Define a structure for the complex parts. 
        double dReal;
        double dImag;
    } COMPLEXNUMBER;

    class ClassComplexNumber { //Define the class for the complex number machine
        private: //Attributes
            COMPLEXNUMBER typComplex;
        public: 
        //CON//DES/////////////////////////////////////////////////////
        // constructor, sets up the function when first instaniated. 
        ClassComplexNumber() {
            this->typComplex.dReal = 0;
            this->typComplex.dImag = 0;
            cout << "Welcome to the Complex Number Calculator" << endl;
        }

        // destructor - This operates when the class closes down. 
        ~ClassComplexNumber() {
            cout << "Complex Number Calculator Shutting Down" << endl;
        }

        //METHODS////////////////////////////////////////////////////////
        //absolute complex value.
        double mAbsoluteValue(COMPLEXNUMBER typInput) {
            double a = (typInput.dReal * typInput.dReal);
            double b = (typInput.dImag * typInput.dImag);
            double dResult = a + b;
            dResult = sqrt(dResult);
            return dResult;
        }
    };
}

//Part 2 - Binary to Hexidecimal conversion
namespace NumberConversion{

    class ClassBinaryHexConverter{
        private: 
        //METHODS//////////////////////////////////////////////////////////
        //Stores the binary input into nibble array
        std::array<std::string, 8> mStoreBinaryIntoArray(std::string input){ //Max binary size is 32
            std::array<std::string, 8> asNibble; //Stores the nibbles into elements
            std::string sNibble; //Stores the bits into nibble

            int j = 0;      //Used to inc nibble array
            string sBit;    //Stores bits of binary value
            int iNibbleCount = 0; 

            //Check the size of the input string and pad with zeros if not 32
            if (input.size() < 32) {
                input = std::string(32 - input.size(), '0') + input;
            }

            //Cycles through the input and stores the nibbles into asNibble array. 
            for (int i = 0; i < 32; i++) {
                sNibble += input[i];
                iNibbleCount += 1;

                if(iNibbleCount % 4 == 0) {
                    //Store the completed nibble into the nibble array element.
                    asNibble[j] = sNibble;
                    j += 1;
                    sNibble.clear(); //clears the nibble for the next loop
                }
            }
            return asNibble;
        }

        //Takes a single array element and converts into HEX
        std::string mBinary2Hex(std::string input) {
            int iValue = 0;
            //std::printf("%s" ,input.c_str());

            if (input[0] == '1') {
                iValue += 8;
            }
            if (input[1] == '1') {
                iValue += 4;
            }
            if (input[2] == '1') {
                iValue += 2;
            }
            if (input[3] == '1') {
                iValue += 1;
            }

            std::string result;

            if (iValue < 10) {
                result = std::to_string(iValue);
            } else if  (iValue == 10) {
                result = "A";
            } else if  (iValue == 11) {
                result = "B";
            } else if  (iValue == 12) {
                result = "C";
            } else if  (iValue == 13) {
                result = "D";
            } else if  (iValue == 14) {
                result = "E";
            } else if  (iValue == 15) {
                result = "F";
            } 
            
            //printf("%d \n", iValue);
            return result;
        } 


        //Combines the array elements back into a single string
        std::string mCombineElementsIntoString(const std::array<std::string, 8> input) {
            std::string sCompletedString;
            //take each element and append on string 
            for (int i = 0; i < 8; i++) {
                std::string sElement = input[i];
                sCompletedString.append(sElement);
            }
            return sCompletedString;
        }

        public:
        //CON//DES/////////////////////////////////////////////////////////
        ClassBinaryHexConverter() {
            cout << "Welcome to the Binary2Hexidecimal Convertor" << endl;
        }
        //Destructor
        ~ClassBinaryHexConverter() {
            cout << "Binary2Hexideciaml Convertor Shutting Down" << endl;
        }

        //Binary to Hex Converter method. Incorporates all the hidden methods to convert the binary string into hex string. 
        std::string mBinaryHexConverter(std::string input) {
            std::array<std::string, 8> asBinaryValue;
            std::array<std::string, 8> asHexValues;
            std::string sHexValue;
            std::string sHexOutput;

            //Splits up the binary values into nibbles, stores into array of nibbles for processing
            asBinaryValue = mStoreBinaryIntoArray(input);

            //Loops through Binary2Hex convertor and stores hex values into array
            for (int i = 0; i < 8; i++){
                sHexValue = mBinary2Hex(asBinaryValue[i]);
                asHexValues[i] = sHexValue;
            }

            //Combines elements back into a string.
            sHexOutput = mCombineElementsIntoString(asHexValues);

            return sHexOutput;

            //Printfs the values in the std::array<std::string, 8>
            //for (const auto& str : asBinaryValue) {
            //    std::printf("%s\n", str.c_str());
            //}
        }
    };
}

 


int main()
{
    //Part 1 ) Complex Number Aboslute Value. 
        ComplexNumberCal::ClassComplexNumber ComplexNumberMachine; //Instantiate the class

        ComplexNumberCal::COMPLEXNUMBER typValueA; //Define the complex number varaible using the structure. 
        double dResult; //Define the variable to hold the result. 

        typValueA.dReal = 25.6; //Set some values
        typValueA.dImag = 14.3;
        
        //Call the ComplexNumberMachine method. 
        dResult = ComplexNumberMachine.mAbsoluteValue(typValueA);

        //Prints out the result to console. 
        printf("The absolute value of the complex number %.2f + j %.2f is %.2f\n" ,typValueA.dReal, typValueA.dImag, dResult);

    //Part 2 ) Binary to Hexidecimal Conversion 
        NumberConversion::ClassBinaryHexConverter BinaryHexMachine; //Instantiate the class

        std::string sInput = "11111110110111000101010000100001"; //"11111110110111000101010000100001" F E D C 5 4 2 1
        std::string sHexOutput;

        //Binary string to hex string converter. max size 32 bits. 
        sHexOutput = BinaryHexMachine.mBinaryHexConverter(sInput);

        //Prints out the result into console. 
        std::printf("The resultant HEX value is....%s \n" ,sHexOutput.c_str());
}
