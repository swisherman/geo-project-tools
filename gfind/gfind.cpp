// gfind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <string>
std::string word;

std::vector<std::string> arguments = { "-t=","--recursive =","--extension="};


struct Finder {
    std::string word;
    bool recursive;
    std::string extension;
};

template <typename T>
int MyResult(T t)
{}


template <typename T>
class M {
public:
    M<T>(T n)
    {
        int i = 0;
        u = n;
        
    }
    std::string u;
};



void GatherArgs(int argCounter, char* argv[])
{
    if (argCounter < 0)
        return;
    for (std::string item : arguments) {
        if (strstr(argv[argCounter], item.c_str())) 
        {

        }
    }

    GatherArgs(argCounter,argv);
}

#define TEXTPARAM "-t"


template <class T, T & v>
void foo()
{
    T n = v;
    std::cout << n << std::endl;
}

auto mim = TEXTPARAM;

int fun = 9;

const char* yodel = TEXTPARAM;

#define goo foo<int, fun>();
#define hoo foo< const char *, yodel>(); 

template <class T>
struct S
{
    T t;
};

S< std::string> s;

typedef S< double > VDouble;

template <class T, T   u>
class Model {

    T d;
public:
    Model<T,u >() 
    {
        d = u;
    }
    void print()
    {
        std::cout << "the value of d is: " << d << std::endl;
    }
};



int main(int argc, char *argv[])
{
   const  double g = 4000.10;
    Model< double, g > model;

    model.print();


    
    

}

