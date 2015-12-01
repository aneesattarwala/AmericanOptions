//
//  AmericanOptions.h
//  B
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// American options class defining perpetual call and perpetual put options

#ifndef B_a_AmericanOptions_h
#define B_a_AmericanOptions_h
#include<iostream>
#include<cmath>

using namespace std;

// !! The variable b is cost of carry (b = r -q for a dividend-paying stock)
class AmericanOptions
{
    double K,sig,r,b;
public:
    //constructor
    AmericanOptions(double _K,double _sig,double _r,double _b):K(_K),sig(_sig),r(_r),b(_b){}
    
    //perpetual american call formula
double PerpetualCall (double S)
{ // Dividend q = r - b
    
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	
    
	if (1.0 == y1)
		return S;
    
	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);
    
	return c;
}
    // vector returning call prices on a vector of equity prices. Overload PerpetualCall function

    vector<double> PerpetualCall (vector<double> S)
    { // Dividend q = r - b
        
        vector<double> result;
        for (int i=0;i<S.size();++i){
            result.push_back(PerpetualCall(S[i]));
        }
        return result;
    }
    
    
// perpetual american put formula
double PerpetualPut (double S)
{
    
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;
    
	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);
    
	return p;
}
   // vector returning put prices on a vector of equity prices. Overloaded PerpetualPut function
    vector<double> PerpetualPut (vector<double> S)
    { // Dividend q = r - b
        
        vector<double> result;
        for (int i=0;i<S.size();++i){
            result.push_back(PerpetualPut(S[i]));
        }
        return result;
    }
    
    
};

#endif
