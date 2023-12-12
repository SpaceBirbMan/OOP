#include "header_array.h"
#if TEST == false
#include "inheritance_source.h"

//auth: Sosnov.K

int main()
{
	vechicle Piezo(cs::R_5, cs::wheels, cs::XiFa, cs::B, cs::GTT); //а что если поменять цвет некоторых данных в консоли?
	vechicle SK_14(cs::R_5, cs::wheels, cs::ARJ, cs::B, cs::GTT);
	std::cout << Piezo.get_short_description() << std::endl << '\n';
	std::cout << Piezo.get_long_description() << std::endl << '\n';
	std::cout << SK_14.get_short_description() << std::endl << '\n';
	std::cout << SK_14.get_long_description() << std::endl;

}
#endif