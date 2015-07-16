#include<iostream>
#include<cmath>
struct polar
{
	double distance;
	double angle;
};
struct rect
{
	double x;
	double y;
};
polar rect_to(rect xypos);
void show_polar(polar dapos);
int main()
{
	using namespace std;
	rect rplace;
	polar pplace;
	cout<<"Enter the x and y values: ";
	while(cin>>rplace.x>>rplace.y)
	{
		pplace=rect_to(rplace);
		show_polar(pplace);
		cout<<"Next  two number (q to quit): ";
	}
	cout<<"Done\n";
	return 0;
}
polar rect_to(rect xypos)
{
	polar answer;
	answer.distance=std::sqrt(xypos.x*xypos.x+xypos.y*xypos.y);
	answer.angle=std::atan2(xypos.y,xypos.x);
	return answer;
}
void show_polar(polar dapos)
{
	const double Red_to_deg=57.29577951;
	std::cout<<"distance= "<<dapos.distance<<",angle="<<dapos.angle*Red_to_deg<<"degrees.\n";
}