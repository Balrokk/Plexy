#pragma once

#include <string>
#include "TBase.h"
#include "TPoint.h"

using namespace System;
using namespace System::Drawing;
using namespace std;

class TLine : public TBase
{
private:
	TBase *left;
	TBase *right;
public:

	TLine(TBase *_left, TBase *_right) : TBase(_left->getName() + "," + _right->getName(),
		TypeFigure::_Line)
	{
		left = _left;
		right = _right;

		width = 2;
	}

	TLine(const TLine &temp) : TBase(temp.name, temp.type, temp.visible,
		Color::FromArgb(temp.color), temp.width, temp.rate)
	{
		region = temp.region;

		left = temp.left;
		right = temp.right;
	}

	TLine(const string temp, TBase *_left, TBase *_right) : TBase("", TypeFigure::_Line)
	{
		string W[7];
		int k = 0;
		StrToArray(temp, W, k);

		name = W[1];
		visible = (bool)atoi(W[2].c_str());
		color = atoi(W[3].c_str());
		width = atoi(W[4].c_str());

		left = _left;
		right = _right;
	}

	~TLine()
	{
		if (left != nullptr)
			if (left->getType() == TypeFigure::_Point)
				if (left->getRate() == 1)
					delete left;
				else
					((TPoint*)left)->decRate();
		if (right != nullptr)
			if (right->getType() == TypeFigure::_Point)
				if (right->getRate() == 1)
					delete right;
				else
					((TPoint*)right)->decRate();
	}

	TLine &operator=(const TLine &temp)
	{
		left = temp.left;
		right = temp.right;

		name = temp.name;
		visible = temp.visible;
		color = temp.color;
		width = temp.width;
		region = temp.region;
		rate = temp.rate;

		return *this;
	}

	TBase* getLeft()
	{
		return left;
	}

	TBase* getRight()
	{
		return right;
	}

	void setLeft(TBase* temp)
	{
		left = temp;
	}

	void setRight(TBase* temp)
	{
		right = temp;
	}

	void Inverse()
	{
		TBase *temp = left;
		left = right;
		right = temp;

		name = left->getName() + "," + right->getName();
	}

	void incRate()
	{
		if (rate < 3)
			rate++;
		else
			rate = 1;
	}

	void Draw(Graphics^ g)
	{
		if ((left->getType() == TypeFigure::_Point) && (right->getType() == TypeFigure::_Point))
		{
			g->DrawLine(%Pen(Color::FromArgb(color), (float)width), ((TPoint*)left)->getX(),
				((TPoint*)left)->getY(), ((TPoint*)right)->getX(), ((TPoint*)right)->getY());
			left->Draw(g);
			right->Draw(g);
		}
	}

	bool isInArea(const int _x, const int _y)
	{

		float abs1 = (float)Math::Abs((((TPoint*)left)->getX() - _x) * (((TPoint*)right)->getY() - _y)
			- (((TPoint*)right)->getX() - _x) * (((TPoint*)left)->getY() - _y));
		float length = (float)Math::Sqrt((((TPoint*)right)->getX() - ((TPoint*)left)->getX()) * (((TPoint*)right)->getX() - ((TPoint*)left)->getX())
			+ (((TPoint*)right)->getY() - ((TPoint*)left)->getY()) * (((TPoint*)right)->getY() - ((TPoint*)left)->getY()));
		float OH = abs1 / length;

		int AOAB = ((_x - ((TPoint*)left)->getX()) * (((TPoint*)right)->getX() - ((TPoint*)left)->getX())
			+ (_y - ((TPoint*)left)->getY()) * (((TPoint*)right)->getY() - ((TPoint*)left)->getY()));

		int BOBA = ((_x - ((TPoint*)right)->getX()) * (((TPoint*)left)->getX() - ((TPoint*)right)->getX())
			+ (_y - ((TPoint*)right)->getY()) * (((TPoint*)left)->getY() - ((TPoint*)right)->getY()));

		if ((OH <= (float)region) && (AOAB * BOBA >= 0))
			return true;
		else
			return false;
	}

	string Pack()
	{
		string res = "_Line";
		res += "|" + name + "|" +
			to_string(visible) + "|" +
			to_string(color) + "|" +
			to_string(width) + "|" +
			to_string(rate);
		return res;
	}
};

