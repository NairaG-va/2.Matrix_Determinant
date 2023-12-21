//Нахождение определителя матрицы
#include <iostream>
#include <math.h>

bool function(double a, double b, double c, double m, double *det, double *eps)
{
    if(b*b - 4*a*c < 0)
		return false;

    double lambda1 = (b + sqrt(b*b - 4*a*c))/2;
    double lambda2 = (b - sqrt(b*b - 4*a*c))/2;
    
    if(lambda1 - lambda2 < *eps)
		return false;
   
    double A,B;

    A = (b-lambda2)/(b-2*lambda2);
    B = (b-A*lambda1)/lambda2;

    *det = A*pow(lambda1, m) + B*pow(lambda2, m);
    
    return true;
}

int main(int argc, char* argv[]){
	
if(argc < 5)
{
    std::cout << "No arguments" << "\n";
	return 1;
}

double a, b, c;
double m;
double det;
double eps = 1e-32;

try
{
     a = std :: stod(argv[1]);
     b = std :: stod(argv[2]);
     c = std :: stod(argv[3]);
     m = std :: stod(argv[4]);
}
catch(...)
{
     std::cout << "Not able to parse arguments" << "\n";
     return 1;
}

if(function(a, b, c, m, &det, &eps) != 1)
{ 
	std::cout << "Error" << "\n";
    return -1;
}
   
std::cout << "Determinant is " << det << "\n";

return 0;
}

