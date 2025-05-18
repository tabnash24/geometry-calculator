#include <stdio.h>
#include <math.h>
#define PI 3.14

float AreaRectangle(float length, float breadth){
    return length*breadth;
}

float PerimeterRectangle(float length, float breadth){
    return 2 * (length + breadth);
}

float AreaCircle(float radius){
    return PI*(pow(radius,2));
}

float CircumferenceCircle(float radius){
    return 2*PI*radius;
}

float LateralSurfaceAreaCylinder(float radius, float cylinder_height){
    return 2*PI*radius*cylinder_height;
}

float TotalSurfaceAreaCylinder(float radius,float cylinder_height){
    return LateralSurfaceAreaCylinder(radius,cylinder_height)+2*AreaCircle(radius);
}

float  VolumeCylinder(float radius, float cylinder_height){
    return PI*(pow(radius,2))*cylinder_height;
}

float AreaTriangle(float base,float triangle_height){
    return 0.5*base*triangle_height;
}

float PerimeterTriangle(float side1,float side2,float base){
    return side1+side2+base;
}

float AreaSquare(float sq_side){
    return pow(sq_side,2);
}

float PerimeterSquare(float sq_side){
    return 4*sq_side;
}

float DiagonalSquare(float sq_side){
    return sq_side*sqrt(2);  //pow(sq_side*pow(2,0.5))  because sqrt of 2 = 2 to the power of 1/2 (2^0.5)
}

// Integer input with validation
int getIntInput(const char *prompt) {
    int value;
    char ch;

    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &ch) != 2 || ch != '\n') {
            printf(" Invalid input! Please enter a whole number only.\n");
            while (getchar() != '\n'); // clear input buffer
        } else {
            return value;
        }
    }
}


// Float input with validation
float getFloatInput(const char *prompt) {
    float value;
    char ch;

    while (1) {
        printf("%s", prompt);
        if (scanf("%f%c", &value, &ch) != 2 || ch != '\n') {
            printf(" Invalid input! Please enter a valid number (e.g., 5 or 3.14).\n");
            while (getchar() != '\n'); // clear input buffer
        } else {
            return value;
        }
    }
}


int main(){
    float length, breadth, radius, cylinder_height, base, triangle_height, side1, side2, sq_side; 
    int op1, op2, op3, op4, op5;
    int operation;
    
    printf("Enter the shape you want operations done in:\n");
    printf("1 - Rectangle\n2 - Circle\n3 - Cylinder\n4 - Triangle\n5 - Square\n");
 
    operation = getIntInput("Select shape (1-5): ");
    
        switch (operation)
        {
            case 1:
                //to perform opeartion on a rectangle
                length = getFloatInput("Enter the length of a rectangle: ");
                breadth = getFloatInput("Enter the breadth of a rectangle: ");

                op1 = getIntInput("1 - Area\n2 - Perimeter\n3 - Both\nSelect: ");

                if(op1 == 1){
                    printf("The area of the rectangle = %.2f\n",AreaRectangle(length,breadth));
                }
                else if(op1 == 2){
                    printf("The perimeter of the rectangle = %.2f\n",PerimeterRectangle(length,breadth));
                }
                else if (op1 == 3){
                    printf("The area of the rectangle = %.2f\n",AreaRectangle(length,breadth));
                    printf("The perimeter of the rectangle = %.2f\n",PerimeterRectangle(length,breadth));
                }
                else {
                    printf("Invalid option.\n");
                }
                break;
            case 2:
                //to perform operations on a circle
                radius = getFloatInput("Enter the radius: ");

                if (radius <= 0) {
                    printf("Radius must be a positive number.\n");
                    return 1;
                }

                op2 = getIntInput("1 - Area\n2 - Circumference\n3 - Both\nSelect: ");

                if(op2 == 1){
                    printf("The area of the circle = %.2f\n",AreaCircle(radius));
                }
                else if(op2 == 2){
                    printf("The circumference of the circle = %.2f\n",CircumferenceCircle(radius));
                }
                else if(op2 == 3){
                    printf("The area of the circle = %.2f\n",AreaCircle(radius));
                    printf("The circumference of the circle = %.2f\n",CircumferenceCircle(radius));
                }
                else {
                    printf("Invalid option.\n");
                }
                break;
            case 3:
                //to perform operations on a cylinder
                radius = getFloatInput("Enter the radius of the base: ");

                if (radius <= 0) {
                    printf("Radius must be a positive number.\n");
                    return 1;
                }
                cylinder_height = getFloatInput("Enter the height of the cylinder: ");

                op3 = getIntInput("1 - Lateral Surface Area\n2 - Top & Bottom Area Only\n3 - Total Surface Area\n4 - Volume\n5 - Show All\nSelect: ");       

                if(op3 == 1){
                    printf("The lateral surface area of the cylinder = %.2f\n",LateralSurfaceAreaCylinder(radius,cylinder_height));
                }
                else if(op3 == 2){
                    printf("The area of the top and bottom circles = %.2f\n",2*AreaCircle(radius));
                }
                else if(op3 == 3){
                    printf("Total Surface Area = %.2f\n", TotalSurfaceAreaCylinder(radius, cylinder_height));
                }
                else if(op3 == 4){
                    printf("Total Volume of the cylinder = %.2f\n", VolumeCylinder(radius, cylinder_height));
                }
                else if(op3 == 5){
                    printf("The lateral surface area of the cylinder = %.2f\n",LateralSurfaceAreaCylinder(radius,cylinder_height));
                    printf("The area of the top and bottom circles = %.2f\n",2*AreaCircle(radius));
                    printf("Total Surface Area = %.2f\n", TotalSurfaceAreaCylinder(radius, cylinder_height));
                    printf("Total Volume of the cylinder = %.2f\n", VolumeCylinder(radius, cylinder_height));
                }
                else{
                    printf("Invalid option.\n");
                }
                break;
            case 4:
                //to perform operations on a triangle
                while (1) {

                    side1 = getFloatInput("Enter the length of a side1 : ");
                    if (side1 <= 0){
                        printf("Length must be a positive number.\n");
                        continue;
                    }

                    side2 = getFloatInput("Enter the length of a side2 : ");
                    if (side2 <=0){
                        printf("Length must be a positive number.\n");
                        continue;
                    }

                    base = getFloatInput("Enter the length of a base : ");
                    if (base <=0){
                        printf("Length must be a positive number.\n");
                        continue;
                    }

                    
                    // Triangle inequality theorem validation
                    if (side1 + side2 <= base || side1 + base <= side2 || side2 + base <= side1){
                        printf("The entered side lengths do not form a valid triangle.\n");
                        continue;;
                    }
                    break;
                }


            //Now that we have valid sides, ask for the height of the triangle in a separate loop.
            while (1) {
                    triangle_height = getFloatInput("Enter the height of the triangle: ");
                    if (triangle_height <= 0) {                            
                        printf("Height must be a positive number. Please try again.\n");
                        continue;  // If height is invalid, ask again
                    }
                        break;  // Exit the loop once the height is valid
                    }
                
                op4 = getIntInput("1 - Area\n2 - Perimeter\n3 - Both\nSelect: ");
                if(op4 == 1){
                    printf("The area of a triangle = %.2f\n",AreaTriangle(base,triangle_height));
                }
                else if(op4 == 2){
                    printf("The perimeter of a triangle = %.2f\n",PerimeterTriangle(side1,side2,base));
                }
                else if(op4 == 3){
                    printf("The area of a triangle = %.2f\n",AreaTriangle(base,triangle_height));
                    printf("The perimeter of a triangle = %.2f\n",PerimeterTriangle(side1,side2,base));
                }
                else{
                    printf("Invalid option\n");
                }
                break;

            case 5:
                //to perform operations on a square
                sq_side = getFloatInput("Enter the length of a side of a square: ");

                if (sq_side <= 0) {
                    printf("Length must be a positive number.\n");
                    return 1;
                }
                op5 = getIntInput("1 - Area\n2 - Perimeter\n3 - Diagonal\n4 - All\nSelect: ");

                if(op5 == 1){
                    printf("The area of the square = %.2f\n",AreaSquare(sq_side));
                }
                else if(op5 == 2){
                    printf("The perimeter of the square = %.2f\n",PerimeterSquare(sq_side));
                }
                else if(op5 == 3){
                    printf("The diagonal of the square = %.2f\n",DiagonalSquare(sq_side));
                }
                else if(op5 == 4){
                    printf("The area of the square = %.2f\n",AreaSquare(sq_side));
                    printf("The perimeter of the square = %.2f\n",PerimeterSquare(sq_side));
                    printf("The diagonal of the square = %.2f\n",DiagonalSquare(sq_side));
                }
                else{
                    printf("Invalid option.\n");
                }
                break;
            default:
                    printf("Invalid option! Shape not found.\n");
                break;
            }

    return 0;
}