#pragma once

#include <string>
#include "TBase.h"

using namespace System;
using namespace System::Drawing;
using namespace std;

class TPoint : public TBase
{
private:
	int x;
	int y;
public:

	TPoint(string _name, int _x, int _y) : TBase(_name, TypeFigure::_Point)
	{
		x = _x;
		y = _y;
	}

	TPoint(const TPoint &temp) : TBase(temp.name, temp.type, temp.visible,
		Color::FromArgb(temp.color), temp.width, temp.rate)
	{
		region = temp.region;
		x = temp.x;
		y = temp.y;
	}

	TPoint(const string temp) : TBase("", TypeFigure::_Point)
	{
		string W[9];
		int k = 0;
		StrToArray(temp, W, k);

		name = W[1];
		visible = (bool)atoi(W[2].c_str());
		color = atoi(W[3].c_str());
		width = atoi(W[4].c_str());
		rate = atoi(W[5].c_str());
		x = atoi(W[6].c_str());
		y = atoi(W[7].c_str());
	}

	~TPoint()
	{
	}

	TPoint &operator=(const TPoint %temp)
	{
		x = temp.x;
		y = temp.y;

		name = temp.name;
		visible = temp.visible;
		color = temp.color;
		width = temp.width;
		region = temp.region;
		rate = temp.rate;

		return *this;
	}

	int getX() { return x; }

	int getY() { return y; }

	void Move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

	void incRate()
	{
		rate++;
	}

	bool isInArea(const int _x, const int _y)
	{
		return ((x - _x) * (x - _x) + (y - _y) * (y - _y) <= region * region);
	}

	void Draw(Graphics^ g)
	{
		g->FillEllipse(%SolidBrush(Color::FromArgb(color)), (float)x - (float)width / 2.0f,
			(float)y - (float)width / 2.0f, (float)width, (float)width);
		g->DrawString(%String(name.c_str()), %Font("Arial", 10, FontStyle::Bold), %SolidBrush(Color::Black), (float)x, (float)y);
	}

	void decRate()
	{
		if (rate > 1)
			rate--;
	}

	string Pack()
	{
		string res = "_Point";
		res += "|" + name + "|" +
			to_string(visible) + "|" +
			to_string(color) + "|" +
			to_string(width) + "|" +
			to_string(rate) + "|" +
			to_string(x) + "|" +
			to_string(y);
		return res;
	}
};


class PointName
{
private:
	string lastname;
public:

	PointName()
	{
		lastname = "A0";
	}

	string Get()
	{
		string temp = lastname;
		int i;
		for (i = lastname.length() - 1; (i >= 0) && (lastname[i] == 'Z'); i--);

		if (i < 0)
		{
			lastname.insert(0, "A");
			i = 1;
		}
		else
			lastname[i++]++;

		while (i < lastname.length())
			lastname[i++] = 'A';

		return temp;
	}

	void SetLastName(const string temp)
	{
		lastname = temp;
	}
};

