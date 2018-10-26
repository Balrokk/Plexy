#pragma once

#include <string>
#include <fstream>
#include "TBase.h"
#include "TPoint.h"
#include "TLine.h"
#include "TStack.h"

using namespace System;
using namespace System::Drawing;
using namespace std;


class TPlex
{
private:
	TBase *start;
public:

	TPlex(TBase* _start = nullptr)
	{
		start = _start;
	}

	TPlex(const TPlex &temp)
	{

	}

	~TPlex()
	{
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);

		TBase *current = start;
		while (current != nullptr)
		{
			if (current->getType() == TypeFigure::_Point)
			{
				current = LineStack.Get();
				current->incRate();
			}
			else
			{
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					delete current;
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}
			}
		}
	}

	TPlex &operator=(const TPlex temp)
	{
		if (start != nullptr)
			delete start;
		TPlex *tmp = new TPlex(temp);
		start = tmp->start;
	}

private:

	TPoint* SearchPoint(const string name)
	{
		TPoint* result = 0;
		TBase* current = start;
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);
		while ((current != nullptr) && (result == 0))
			if (current->getType() == TypeFigure::_Point)
			{
				if (current->getName() == name)
					result = (TPoint*)current;
				else
				{
					current = LineStack.Get();
					current->incRate();
				}
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					current->incRate();
					current = LineStack.Get();
					current->incRate();
					break;
				}
		while (LineStack.Show() != nullptr)
		{
			current = LineStack.Get();
			while (current->getRate() != 1)
				current->incRate();
		}

		return result;
	}

	TLine* SearchLineContainingPoint(const string name)
	{
		TLine* result = 0;
		TBase* current = start;
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);
		while ((current != nullptr) && (result == nullptr))
			if (current->getType() == TypeFigure::_Point)
			{
				if (current->getName() == name)
					result = (TLine*)LineStack.Show();
				else
				{
					current = LineStack.Get();
					current->incRate();
				}
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					current->incRate();
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}
		while (LineStack.Show() != nullptr)
		{
			current = LineStack.Get();
			while (current->getRate() != 1)
				current->incRate();
		}

		return result;
	}

	void InsertLine(TLine *temp, TLine *res)
	{

		if (res->getName().find(temp->getLeft()->getName()) == 0)
		{
			temp->setLeft(res->getLeft());
			res->setLeft(temp);
		}
		else
		{
			temp->setLeft(res->getRight());
			res->setRight(temp);
		}

	}

public:

	TPoint* CheckPoint(const int _x, const int _y)
	{
		TPoint *result = nullptr;

		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);

		TBase *current = start;
		while (current != nullptr)
			if (current->getType() == TypeFigure::_Point)
			{
				if (current->isInArea(_x, _y))
					result = (TPoint*)current;
				current = LineStack.Get();
				current->incRate();
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					current->incRate();
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}

		return result;
	}

	TLine* CheckLine(const int _x, const int _y)
	{
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);
		TStack<TBase*> PointStack;

		TLine *result = nullptr;

		TBase *current = start;
		while (current != nullptr)
			if (current->getType() == TypeFigure::_Point)
			{
				PointStack.Put(current);
				current = LineStack.Get();
				current->incRate();
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					TLine *temp = new TLine(*((TLine*)current));
					temp->setRight(PointStack.Get());
					temp->setLeft(PointStack.Show());

					if (temp->isInArea(_x, _y))
						result = (TLine*)current;

					temp->setLeft(nullptr);
					temp->setRight(nullptr);
					delete temp;

					current->incRate();
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}
		return result;
	}

	bool AddLine(TLine *temp)
	{

		if (start == nullptr)
		{
			start = temp;
			return true;
		}

		TLine *Left = SearchLineContainingPoint(temp->getLeft()->getName()),
			*Right = SearchLineContainingPoint(temp->getRight()->getName());

		if (Left == Right)
			return false;

		if (Left != nullptr)
		{
			InsertLine(temp, Left);
			if (Right != nullptr)
			{
				if (Right->getName().find(temp->getRight()->getName()) == 0)
				{
					temp->setRight(Right->getLeft());
					Right->getLeft()->incRate();
				}
				else
				{
					temp->setRight(Right->getRight());
					Right->getRight()->incRate();
				}
			}
		}
		else
			if (Right != nullptr)
			{
				temp->Inverse();
				InsertLine(temp, Right);
			}

		return true;
	}

	void Draw(Graphics ^g)
	{
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);
		TStack<TBase*> PointStack;

		TBase *current = start;
		while (current != nullptr)
			if (current->getType() == TypeFigure::_Point)
			{
				PointStack.Put(current);
				current = LineStack.Get();
				current->incRate();
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					TLine *temp = new TLine(*((TLine*)current));
					temp->setRight(PointStack.Get());
					temp->setLeft(PointStack.Show());

					temp->Draw(g);

					temp->setLeft(nullptr);
					temp->setRight(nullptr);
					delete temp;

					current->incRate();
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}
	}

	void Move(const int dx, const int dy)
	{
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);

		TBase *current = start;
		while (current != nullptr)
			if (current->getType() == TypeFigure::_Point)
			{
				((TPoint*)current)->Move(dx / current->getRate(), dy / current->getRate());
				current = LineStack.Get();
				current->incRate();
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					current->incRate();
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}
	}

	void Move(TBase *temp, const int dx, const int dy)
	{
		if (temp->getType() != TypeFigure::_Point)
			Move(((TLine*)temp)->getLeft(), dx, dy);
		else
		{
			((TPoint*)temp)->Move(dx / temp->getRate(), dy / temp->getRate());
			return;
		}
		Move(((TLine*)temp)->getRight(), dx, dy);
	}

	TBase* getStart()
	{
		return start;
	}

	void MovePoint(const string name, const int dx, const int dy)
	{
		TPoint *tmp = SearchPoint(name);
		if (tmp != nullptr)
			tmp->Move(dx, dy);
	}

	void Save(const string filename)
	{
		ofstream fout(filename);

		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);

		TBase *current = start;
		while (current != nullptr)
			if (current->getType() == TypeFigure::_Point)
			{
				fout << ((TPoint*)current)->Pack() << endl;
				current = LineStack.Get();
				current->incRate();
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					current->incRate();
					fout << ((TLine*)current)->Pack() << endl;
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}
		fout.close();
	}

	void Load(const string filename)
	{
		if (start != nullptr)
			this->~TPlex();

		ifstream fin(filename);
		string str;
		TStack<TBase*> stack;

		TPoint *point;
		TLine *line;

		getline(fin, str);
		while (str != "")
		{

			if (str.find("_Point") == 0)
			{
				point = new TPoint(str);
				stack.Put(point);
			}
			else
			{
				line = new TLine(str, nullptr, nullptr);
				line->setRight(stack.Get());
				line->setLeft(stack.Get());
				stack.Put(line);
			}
			getline(fin, str);
		}
		start = stack.Get();
		fin.close();
	}

	bool isNotEmpty()
	{
		return (start == nullptr) ? false : true;
	}

	string getLastPoint()
	{
		TStack<TBase*> LineStack;
		LineStack.Put(nullptr);

		string result = "";

		TBase *current = start;
		while (current != nullptr)
			if (current->getType() == TypeFigure::_Point)
			{
				if (current->getName() > result)
					result = current->getName();
				current = LineStack.Get();
				current->incRate();
			}
			else
				switch (current->getRate())
				{
				case 1:
					LineStack.Put(current);
					current = ((TLine*)current)->getLeft();
					break;
				case 2:
					LineStack.Put(current);
					current = ((TLine*)current)->getRight();
					break;
				case 3:
					current->incRate();
					current = LineStack.Get();
					if (current != nullptr)
						current->incRate();
					break;
				}

		return result;
	}
};

