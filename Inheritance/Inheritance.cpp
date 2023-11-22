
#include "header_array.h"
#include "inheritance_source.h"

//auth: Sosnov.K

int main()
{
	vechicle Piezo(cs::ARJ, cs::B, cs::GTT);
	std::cout << Piezo.get_short_description() << std::endl << '\n';
	std::cout << Piezo.get_long_description() << std::endl;
}