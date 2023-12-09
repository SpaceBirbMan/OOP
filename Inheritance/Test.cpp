#define BOOST_TEST_MODULE mytests
#include "inheritance.cpp"
#ifdef TEST
#include <boost/test/included/unit_test.hpp>
#include "inheritance_source.h"


using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(test_factor_calculation)
{
    // Создаем объект factor с заданными параметрами
    factor test_factor(cs::XiFa, cs::JD, cs::GTT, cs::BS, cs::RET, cs::ARG_2);

    // Проверяем, что множители были рассчитаны верно
    BOOST_CHECK_CLOSE(test_factor.get_part_mass_fac(), 1.1265 * 2.5, 0.1);
    BOOST_CHECK_CLOSE(test_factor.get_vech_mass_fac(), 0.99984 * 4.1 * 2.35 * 1.7 * 2.6, 0.1);
    BOOST_CHECK_CLOSE(test_factor.get_cost_fac(), 1.7 * 1.5 * 3.12 * 2.3 * 2.9 * 7 * 2.3, 0.1);
    BOOST_CHECK_CLOSE(test_factor.get_speed_fac(), 1.2 * 0.75 * 70000 * 0.86 * 0.3, 0.1);
}

BOOST_AUTO_TEST_CASE(test_parts)
{

}


BOOST_AUTO_TEST_CASE(test_vechicle)
{

}

#endif