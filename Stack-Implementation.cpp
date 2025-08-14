#include <iostream>

using namespace std;


class myStack
{
private:
    int size;
    int *st;
    int tos;
    int counter;

public:
    //constructor 1
    myStack(int n=10)
    {
        tos = 0;
        size = n;
        st = new int[size];
        cout<<"This is constructor of stack object with size "<<n<<endl;
        counter++;
    }

    //passing two parameters(this:new one, z:old one)
    //constructor 2
    myStack(myStack &z)
    {
        tos = z.tos;
        size = z.size;
        st = new int [size]; //new allocation

        for(int i=0; i<tos; i++)
        {
            st[i] = z.st[i];
        }

        counter++;
    }

    //destructor
    ~myStack()
    {
        delete[ ] st;
        cout<<"This is destructor"<<endl;
        counter--;
    }

    void push(int);
    int pop();

    //friend void viewContent(myStack &x);

    friend void viewContent(myStack x);
    void operator = (myStack s);
};





int main()
{
    myStack s1(3);
    s1.push(5);
    s1.push(6);
    s1.push(7);

    myStack s2(3);
    s2.push(8);
    s2.push(9);
    s2.push(1);

    s2 = s1;

    viewContent(s1);
    viewContent(s2);
    return 0;
}


void myStack::push(int n)
{
    if(tos == size)
    {
        cout<<"Stack is Full"<<endl;
    }
    else
    {
        st[tos] = n;
        tos++;
    }

};


int myStack::pop()
{
    int retVal;
    if(tos == 0)
    {
        cout<<"Stack is empty"<<endl;
        retVal = -1;
    }
    else
    {
        tos--;
        retVal = st[tos];
    }
    return retVal;
}


void viewContent(myStack x)
{

    int t = x.tos;
    while(t != 0)
    {

        cout<<x.st[--t]<<endl;
    }

}


void myStack::operator= (myStack s)
{
    delete[] this->st;
    this->tos = s.tos;
    this->size = s.size;
    this->st = new int [size];
    for(int i=0; i<tos; i++)
    {
        this->st[i] = s.st[i];
    }
}

