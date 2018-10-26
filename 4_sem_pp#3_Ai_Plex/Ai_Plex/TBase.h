#pragma once

#include <string>

using namespace System;
using namespace System::Drawing;
using namespace std;

enum TypeFigure { _Point, _Line, _Rectangle, _Circle };

class TBase
{
protected:
	TypeFigure type;
	string name;
	bool visible;
	int color;
	int width;
	int region;
	int rate;
public:
	TBase(string _name, TypeFigure _type, bool _visible = true,
		Color _color = Color::Black, int _width = 5, int _rate = 1)
	{
		name = _name;
		type = _type;
		visible = _visible;
		color = _color.ToArgb();
		width = _width;
		region = 2 * width;
		rate = _rate;
	}

	virtual ~TBase()
	{
	}

	string getName() { return name; }

	TypeFigure getType() { return type; }

	bool getVisibility() { return visible; }

	void setVisibility() { visible = !visible; }

	Color getColor() { return Color::FromArgb(color); }

	void setColor(Color _color) { color = _color.ToArgb(); }

	int getWidth() { return width; }

	void setWidth(const int _width) { width = _width; region = 2 * width; }

	int getRate() { return rate; }

	virtual void incRate() = 0;

	virtual void Draw(Graphics^ g) = 0;

	virtual bool isInArea(const int _x, const int _y) = 0;
};

void StrToArray(string Pst, string PW[], int &Pk)
{
	string t;
	int l;
	t = Pst + "|";
	Pk = 0;
	while (t.length()>0)
	{
		l = t.find("|");
		if (l>0)
			PW[Pk++] = t.substr(0, l);
		t.erase(0, l + 1);
	}
}

