#include <iostream>
#include <string>
#include "circle.h"
#include "point.h"

void isInCircle(Circle &c, Point &p)
{
	//计算两点之间的平�?
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
					(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	//计算半径的平�?
	int rdistance = c.getR() * c.getR();

	//判断关系
	if(distance > rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else if(distance == rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����԰��" << endl;
	}
}

int main()
{
	//创建�?
	Point center;
	center.setX(10);
	center.setY(0);

	Circle c;
	c.setR(10);
	c.setCenter(center);

	//创建�?
	Point p;
	p.setX(10);
	p.setY(11);

	//判断关系
	isInCircle(c,p);

	system("pause");
	return 0;
}