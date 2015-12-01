//
//  main.cpp
//  B.a

//  Copyright (c) 2015 Anees Attarwala. All rights reserved.
//
/*  a)Program the perpetual american put and call formulae. Done using an AmericanOptions class with formulaes implemented for call and put options.
    parameters (no T parameter!). Write separate functions for puts and calls.
     b) Test the data with K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106).
     c) Calculating call and put prices as function of S*/
   

#include <iostream>
#include <cmath>
#include <vector>
#include<iomanip>
#include "AmericanOptions.h"
// Global function to print a vector <double>
void print(const vector<double>& v)
{
    vector<double>::const_iterator it;
    for (it=v.begin();it!=v.end();++it)
    {
        cout<<*it<<" ";
    }
    
}
// Mesher returns a vector <double> array of mesh points
vector<double> mesher (double start, double end, double size)
{
    double n_steps = (end - start) / double (size);  //no of steps in mesh
    double temp=start;
    vector<double> result;
    result.push_back(start);
    for (int j = 1; j < n_steps+1; j++)
    {
        temp = temp+size;
        result.push_back(temp);
    }
    
    return result;
}


int main()
{
    double K=100, sig=.1, r=.1,b=.02, S=110;  //option parameters
    AmericanOptions call(K,sig,r,b);
    AmericanOptions put(K,sig,r,b);
    cout<<"SOLUTION TO PART a) AND b) "<<endl;
    
    cout<<"Perpetual Americal Call option value :"<<call.PerpetualCall(S)<<endl;
    cout<<"Perpetual Americal Put option value :"<<call.PerpetualPut(S)<<endl;
    cout<<endl<<"SOLUTION TO PART c) "<<endl;
    cout<<"***Call and Put variation as function of underlying equity***"<<endl;
    
    vector<double> equity; // equity mesh
    vector<double> AmericanCall; // call option data
    vector<double> AmericanPut; // put option data
    equity=mesher(50,150,10);       // creating equity mesh
    cout<<"Equity variation :"<<endl;
    print(equity);
    cout<<endl;
    //calling call and put pricers with equity mesh as argument and returning results as a vector.
    
    AmericanCall=call.PerpetualCall(equity);
    AmericanPut=put.PerpetualPut(equity);
    
    cout<<setprecision(4);
    cout<<"Call values :"<<endl;
    print(AmericanCall);  //printing call option values
    cout<<endl;
    cout<<"Put values :"<<endl;
    print(AmericanPut);  //printing put option values
    cout<<endl;
    return 0;
}

