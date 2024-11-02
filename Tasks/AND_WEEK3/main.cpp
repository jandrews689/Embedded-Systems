#include "mbed.h"

namespace Shape { //Define a namespace. 

    typedef struct {
        int iLength;
        int iWidth;
    } DIMENSIONS;

    class ClassRectangle { //Class 
        private:
            DIMENSIONS typDim; //Define the private structured variables. 
        public:

        //Constructor - Initialise the shapes dimensions 
        ClassRectangle() {
            this->typDim.iLength = 0;
            this->typDim.iWidth = 0;
        }

        //Method to return the area of the rectangle.
        int mArea() {
            int iArea = 0;
            iArea = typDim.iLength * typDim.iWidth;
            return iArea;
        }

        //Method to return the perimeter of the rectangle.
        int mPerimeter() {
            int iPerimeter = 0;
            iPerimeter = ((2*typDim.iLength) + (2*typDim.iWidth));
            return iPerimeter;
        }

        //Sets the length of the rectangle. 
        void mSetLength(int input){
            typDim.iLength = input;
        }

        //Sets the width of the rectangle. 
        void mSetWidth(int input){
            typDim.iWidth = input;
        }
    };
}


// main() runs in its own thread in the OS
int main()
{
    Shape::ClassRectangle BasicRectangle; //Define the class of a rectangle under namespace. 

    Shape::DIMENSIONS typRectangle; //Define the datatype structure. 

    typRectangle.iLength = 100; //Set some values. 
    typRectangle.iWidth = 200;

    BasicRectangle.mSetLength(typRectangle.iLength); //Set the length via the Set method
    BasicRectangle.mSetWidth(typRectangle.iWidth); //Set the width via the Set method

    //Print out the area 
    printf("The area of the rectangle is: %d mm^2\n", BasicRectangle.mArea());
    //Print out the perimeter
    printf("The perimeter of the rectangle is: %d mm \n", BasicRectangle.mPerimeter());

}

