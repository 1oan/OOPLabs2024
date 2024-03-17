#pragma once
class Canvas
{
    // add private data members
    char** canva;
    int width, height;
public:
    Canvas(int width, int height); // constructoru sa apele metoda Clear !!!
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void print(); // shows what was printed
    void Clear(); // clears the canvas
    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);
    // tuples of x, y, value
    void set_pixels(int count, ...);
};
