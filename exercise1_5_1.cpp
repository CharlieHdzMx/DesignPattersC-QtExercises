#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

static double toCelsius(const double& temp);
static double toFahrenheit(const double& temp);

/* */
static double toCelsius(const double& tempFahrenheit)
{
    return (tempFahrenheit - 32u)*5/9;
}

/* */
static double toFahrenheit(const double& tempCelsius)
{
    return (tempCelsius*(9/5)) + 32u;
}

/* 1.5.1 escribe las funciones para habilitar al usuario el hacer la conversion de temperatura (en cualquier direccion) entre Celsius and Fahrenheit.*/
int main()
{

    return 0;
}
