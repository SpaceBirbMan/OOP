#define TEST
#include "header_array.h"
#include "inheritance_source.h"

#ifndef TEST
//auth: Sosnov.K

int main()
{
	vechicle Piezo(cs::R_5, cs::wheels, cs::XiFa, cs::B, cs::GTT);
	vechicle SK_14(cs::R_5, cs::wheels, cs::ARJ, cs::B, cs::GTT);
	std::cout << Piezo.get_short_description() << std::endl << '\n';
	std::cout << Piezo.get_long_description() << std::endl << '\n';
	std::cout << SK_14.get_short_description() << std::endl << '\n';
	std::cout << SK_14.get_long_description() << std::endl;

}
#endif