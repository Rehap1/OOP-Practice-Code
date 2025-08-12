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

    void Print();
};


int main()
{
    Complex com1, com2, resCom;

    com1.setReal(7);
    com1.setImag(2);

    com2.setReal(5);
    com2.setImag(3);

    resCom = com1.add(com2);
    resCom.Print();
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

