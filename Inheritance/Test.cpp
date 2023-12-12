#include "header_array.h"

#if TEST == true
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "inheritance_source.h"


using namespace boost::unit_test;

cs::chas_type wh = cs::wheels;
cs::engine_type et = cs::T_5;

//Ќабор "рабочих" объектов
cabin* tcab = new cabin(cs::DLT, cs::F);
engine* teng = new engine(cs::T_5, cs::ARJ, cs::B, cs::no_exs, cs::NN, cs::GTRX, cs::JX_77);
chassis* tch = new chassis(cs::wheels, cs::DLT, cs::F, cs::GS, cs::NN, cs::RET, cs::RTG_B);
weapon* tweap = new weapon(cs::DLT, cs::ARG_2);
extra_modules* tem = new extra_modules(cs::DLT, cs::J5);
factor test_factor(cs::XiFa, cs::JD, cs::GTT, cs::BS, cs::RET, cs::ARG_2);
vechicle TST(tcab, teng, tch, tweap, tem);

BOOST_AUTO_TEST_CASE(test_factor_calculation)
{

    // ѕровер€ем, что множители были рассчитаны верно
    BOOST_CHECK_CLOSE(test_factor.get_part_mass_fac(), 1.1265 * 2.5, 0.1);
    BOOST_CHECK_CLOSE(test_factor.get_vech_mass_fac(), 0.99984 * 4.1 * 2.35 * 1.7 * 2.6, 0.1);
    BOOST_CHECK_CLOSE(test_factor.get_cost_fac(), 1.7 * 3.12  * 2.3 * 2.9 * 7 * 2.3, 0.1);
    BOOST_CHECK_CLOSE(test_factor.get_speed_fac(), 1.2 * 0.3 * 70000 * 0.86, 0.1);
}
BOOST_AUTO_TEST_CASE(test_cabin)
{
    // ѕровер€ем, что конструктор кабины правильно устанавливает массу, стоимость и модификатор скорости
    
    BOOST_CHECK_CLOSE(tcab->get_mass(), 500 * 1.0045, 0.1);
    BOOST_CHECK_CLOSE(tcab->get_cost(), 1200 * 1.9 * 1.4597 * 1.5, 0.1);
    BOOST_CHECK_CLOSE(tcab->get_speed_mod(), 2.05 * 200 * 0.75, 0.1);

}

BOOST_AUTO_TEST_CASE(test_engine)
{
    // ѕровер€ем, что конструктор двигател€ правильно устанавливает массу, стоимость и модификатор скорости
   
    BOOST_CHECK_CLOSE(teng->get_mass(), 800 * 1.25, 0.1);
    BOOST_CHECK_CLOSE(teng->get_cost(), 1200 * 1.34 * 8.14 * 1.5 * 4.21 * 1.56, 0.1);
    BOOST_CHECK_CLOSE(teng->get_speed_mod(), 0.75 * 0.75 * 1500 * 1.69, 0.1);

}

BOOST_AUTO_TEST_CASE(test_chassis)
{
    // ѕровер€ем, что конструктор шасси правильно устанавливает массу, стоимость и модификатор скорости
    
    BOOST_CHECK_CLOSE(tch->get_mass(), 2500 * 1.0045, 0.1);
    BOOST_CHECK_CLOSE(tch->get_cost(), 3100 * 1.9 * 1.4597 * 2.1463 * 1.5 * 7 * 1.55, 0.1);
    BOOST_CHECK_CLOSE(tch->get_speed_mod(), 2.05 * 200 * 0.75 * 0.5 * 1.01, 0.1);
}

BOOST_AUTO_TEST_CASE(test_weapon)
{
    // ѕровер€ем, что конструктор оружи€ правильно устанавливает массу, стоимость и модификатор скорости
   
    BOOST_CHECK_CLOSE(tweap->get_mass(), 400 * 1.0045, 0.1);
    BOOST_CHECK_CLOSE(tweap->get_cost(), 2900 * 1.9 * 2.3 * 1.5, 0.1);

}

BOOST_AUTO_TEST_CASE(test_extra_modules)
{
    // ѕровер€ем, что конструктор надстройки правильно устанавливает массу, стоимость и модификатор скорости
    
    BOOST_CHECK_CLOSE(tem->get_mass(), 700 * 1.0045, 0.1);
    BOOST_CHECK_CLOSE(tem->get_cost(), 350 * 1.9 * 1.5 * 1.15, 0.1);

}

BOOST_AUTO_TEST_CASE(test_vechicle)
{

    //ѕровер€ем корректность расчЄта переменных характеристик в транспорте

    BOOST_CHECK_CLOSE(TST.get_vmass(), 1.5 * 1 * 1.29 * 2.6 * (tcab->get_mass() + teng->get_mass() + tch->get_mass() + tweap->get_mass() + tem->get_mass()), 0.1);
    BOOST_CHECK_CLOSE(TST.get_vcost(), 1.2 * 1.5 * 2.3 * 1.15 * TST.get_std_cost_factor() * (tcab->get_cost() + teng->get_cost() + tch->get_cost() + tweap->get_cost() + tem->get_cost()), 0.1);
    BOOST_CHECK_CLOSE(TST.get_vspeed(), 1.5 * 0.75 * 0.001 * (tcab->get_speed_mod() * teng->get_speed_mod() * tch->get_speed_mod()), 0.1);
    /*TST.~vechicle();*/
  /*  delete tcab;
    delete teng;
    delete tch;
    delete tweap;
    delete tem;*/
}

#endif