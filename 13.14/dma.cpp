#include "dma.h"
#include <cstring>
using namespace std;
baseDMA::baseDMA(const char * l,int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	delete [] label;
	label = new char[std::strlen(rs.label) + 1);
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os<< "Label: "<< rs.label << std::endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}

lacksDMA::lacksDMA(const char *c,const char * l, int r) : baseDMA(l, r)
{
	std::strcpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs)
{
	std::strcpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	os << (const baseDMA &) ls;
	os << "Color: " << ls.color << endl;
}

hasDMA::hasDMA(const char * s, const char * l