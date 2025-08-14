#include <iostream>
#include <cmath>

using namespace std;


class Complex
{
    float real;
    float imag;

public:
    void setReal(float);
    void setImag(float);

    float getReal();
    float getImag();

    Complex add(Complex c);
    Complex sub(Complex c);

    Complex operator + (Complex c);
    Complex operator + (float x);
    friend Complex operator + (float x, Complex c);

    int operator == (Complex c);

    void Print();
};


int main()
{
    Complex com1, com2, resCom;

    com1.setReal(7);
    com1.setImag(2);

    com2.setReal(5);
    com2.setImag(3);

    //resCom = com1.add(com2);
    //resCom.Print();

    resCom = com1 + com2;
    resCom.Print();

    resCom = com1 + 10;
    resCom.Print();

    resCom = 10 + com2;
    resCom.Print();


    com1 = com2;
    int x = (com1 == com2);
    cout<<x<<endl;
    return 0;
}

void Complex::setReal(float r)
{
    real = r;
}

void Complex::setImag(float i)
{
    imag = i;
}

float Complex::getReal()
{
    return real;
}

float Complex::getImag()
{
    return imag;
}



void Complex::Print()
{
    if(imag < 0)
        cout << real << " - " << fabs(imag) << "i" << endl;
    else
        cout << real << " + " << imag << "i" << endl;
}

Complex Complex::add(Complex c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;

    return temp;
}

Complex Complex::sub(Complex c)
{
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.imag;

    return temp;
}

//Operator Overloading (Complex + Complex)
Complex Complex::operator+ (Complex c)
{
    Complex b;
    b.real = this->real + c.real;
    b.imag = this->imag + c.imag;

    return b;
}

//Operator Overloading (Complex + float)
Complex Complex::operator+ (float x)
{
    Complex b;
    b.real = this->real + x;
    b.imag = this->imag ;

    return b;
}

//Operator Overloading (float + complex)

Complex operator+ (float x, Complex c)
{
    Complex b;
    b.real = c.real + x;
    b.imag = c.real;

    return b;
}

//Operator Overloading (complex == complex)
int Complex::operator== (Complex c)
{
   if(this->real == c.real && this->imag == c.imag)
   {
       return 1;
   }
   else
   {
       return -1;
   }

}
