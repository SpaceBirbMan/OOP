#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "inheritance_source.h"
#include "inheritance.cpp"

#ifdef TEST

using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(myFirstTestCase)
{
    BOOST_TEST(1 == 1);
    BOOST_TEST_PASSPOINT("checkoint_message");
    BOOST_TEST(2 == 2);
    BOOST_TEST_CHECKPOINT("checkoint_message");
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(mySecondTestCase)
{
    BOOST_TEST(1 == 1);
    BOOST_TEST(2 == 2);
    BOOST_TEST(true);
}

#endif