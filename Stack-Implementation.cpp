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
    myStack(int n=10)
    {
        tos = 0;
        size = n;
        st = new int[size];
        cout<<"This is constructor of stack object with size "<<n<<endl;
        counter++;
    }


    //passing two parameters(this:new one, z:old one)
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
};





int main()
{
    myStack s1(2);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    //cout<<s1.pop();

    viewContent(s1);
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




