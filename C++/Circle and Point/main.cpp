#include <iostream>
#include <string>
#include "circle.h"
#include "point.h"

void isInCircle(Circle &c, Point &p)
{
	//è®¡ç®—ä¸¤ç‚¹ä¹‹é—´çš„å¹³æ–?
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
					(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	//è®¡ç®—åŠå¾„çš„å¹³æ–?
	int rdistance = c.getR() * c.getR();

	//åˆ¤æ–­å…³ç³»
	if(distance > rdistance)
	{
		cout << "µãÔÚÔ²Íâ" << endl;
	}
	else if(distance == rdistance)
	{
		cout << "µãÔÚÔ²ÉÏ" << endl;
	}
	else
	{
		cout << "µãÔÚÔ°ÄÚ" << endl;
	}
}

int main()
{
	//åˆ›å»ºåœ?
	Point center;
	center.setX(10);
	center.setY(0);

	Circle c;
	c.setR(10);
	c.setCenter(center);

	//åˆ›å»ºç‚?
	Point p;
	p.setX(10);
	p.setY(11);

	//åˆ¤æ–­å…³ç³»
	isInCircle(c,p);

	system("pause");
	return 0;
}