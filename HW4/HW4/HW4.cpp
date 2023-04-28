// Sam Ruggiero Homework 4

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    // create stacks
    Stack<int>* sInt = new Stack<int>(1);
    Stack<bool>* sBool = new Stack<bool>(2);
    Stack<float>* sFloat = new Stack<float>(3);

    // test stacks
    cout << endl << " --- Testing Int Stack --- " << endl;
    sInt->Push(1);
    sInt->Push(2);
    sInt->Push(3);
    sInt->Push(4);
    sInt->Print();
    sInt->Pop();
    sInt->Pop();
    sInt->Print();
    cout << endl << " --- Testing Bool Stack --- " << endl;
    sBool->Push(false);
    sBool->Push(true);
    sBool->Print();
    sBool->Pop();
    sBool->Pop();
    sBool->Pop();
    sBool->Print();
    cout << endl << " --- Testing Float Stack --- " << endl;
    sFloat->Push(0.1f);
    sFloat->Push(1.56f);
    sFloat->Push(-10.0f);
    sFloat->Push(5.7f);
    sFloat->Print();
    sFloat->Pop();
    sFloat->Pop();
    sFloat->Print();

    // test copy constructor and copy assignment
    cout << endl << " --- Testing Copy Constructor --- " << endl;
    Stack<int>* sIntCpy = new Stack<int>(*sInt);
    sIntCpy->Print();
    sIntCpy->Pop();
    sIntCpy->Pop();
    sIntCpy->Print();
    *sIntCpy = *sInt;
    sIntCpy->Print();

    // delete stacks
    cout << endl;
    delete sInt;
    delete sBool;
    delete sFloat;
    delete sIntCpy;

    // test for memory leaks
    if (_CrtDumpMemoryLeaks()) std::cout << "// MEMORY LEAKS FOUND //";
}