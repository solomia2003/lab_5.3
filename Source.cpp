#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double j(const double x);

int main()
{
    double kp, kk, z;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;

    double dk = (kk - kp) / n;
    double k = kp;

    cout << "--------------------" << endl;
    cout << "|" << setw(5) << "z" << setw(2) << "|" << setw(10) << "k" << setw(2) << "|" << endl;
    cout << "--------------------" << endl;


    while (k <= kk)
    {
        z = j(1 + k + j(k)) + pow(j(1 + k * k), 2);
        cout << "|" << setw(5) << k << setw(2) << "|" << setw(10) << z << setw(2) << "|" << endl;
        k += dk;
    }
    return 0;
}
double j(const double x)
{
    if (abs(x) >= 1)
        return (cos(x) + exp(-abs(x))) / (cos(x * x + 1));
    else
    {
        double S = 0;
        int i = 0;
        double a = x;
        S = a;
        do
        {
            i++;
            double R = (x * x) / (4 * i * i + 2 * i);
            a *= R;
            S += a;
        } while (i < 5);
        return S;
    }

}