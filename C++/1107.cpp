#include <iostream>
using namespace std;

int main()
{
    int altura, comprimento, xi, xanterior, quant;
    
    while (true)
    {
        cin >> altura >> comprimento;
        if (altura == 0 && comprimento == 0)
        {
            break;
        }
        
        quant = 0;
        for (int i = 0; i < comprimento; i++)
        {
            cin >> xi;
            if (i == 0)
            {
                quant += altura - xi;
            }
            else if (xi < xanterior)
            {
                quant += xanterior - xi;
            }
            xanterior = xi;
        }
        cout << quant << endl;
    }
}