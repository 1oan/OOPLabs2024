#include "Canvas.h"

int main()
{
    Canvas canva(100, 40);
    canva.FillCircle(15, 12, 8, '^');
    canva.DrawCircle(15, 12, 8, '$');
    canva.SetPoint(15, 12, '@');

    canva.DrawRect(40, 1, 95, 20, 'L');
    canva.FillRect(40, 1, 95, 20, 'J');

    canva.Print();
    return 0;
}