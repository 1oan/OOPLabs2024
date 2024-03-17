#include "Canvas.h"
#include <iostream>
#include <cstdarg>

using namespace std;

Canvas::Canvas(int width, int height)
{
	this->height = height;
	this->width = width;
	canva = new char*[height];
	for (int i = 0; i < height; i++)
		canva[i] = new char[width];
	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) &&
				(i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				SetPoint(i, j, ch);
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if(((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray))
				SetPoint(i, j, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		SetPoint(i, top, ch), SetPoint(i, bottom, ch);
	for (int i = top; i <= bottom; i++)
		SetPoint(left, i, ch), SetPoint(right, i, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1; i < bottom; i++)
		for (int j = left + 1; j < right; j++)
			SetPoint(j, i, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if(x >= 0 && x < width && y >= 0 && y < height)
	canva[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, D, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	D = 2 * dy - dx;
	y = y1;
	for (x = x1; x <= x2; x++)
	{
		SetPoint(x, y, ch);
		if (D > 0)
		{
			y++;
			D -= 2 * dx;
		}
		D += 2 * dy;
	}
}

void Canvas::print()
{
	for (int i = 0; i < height; ++i) 
	{
		for (int j = 0; j < width; ++j)
			cout << canva[i][j];
		cout << "\n";
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			SetPoint(i, j, ' ');
}

void Canvas::set_pixel(int x, int y, char value)
{
	SetPoint(x, y, value);
}

void Canvas::set_pixels(int count, ...)
{
	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++)
	{
		int x = va_arg(ptr, int);
		int y = va_arg(ptr, int);
		char ch = va_arg(ptr, char);
		set_pixel(x, y, ch);
	}
	va_end(ptr);
}
