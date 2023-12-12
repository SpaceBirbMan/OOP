#include "header_array.h"
#include "inheritance_source.h"

//auth: Sosnov.K

void factor::get_factor()
{
	/// Расчёт по конструкорскому стандарту
	switch (_corp)
	{
	case cs::XiFa: { _part_mass_fac = 1.1265; _vech_mass_fac = 0.99984; _cost_fac = 1.7; _speed_fac = 1.2;  break; }
	case cs::ARJ: { _part_mass_fac = 1.25; _vech_mass_fac = 1.67; _cost_fac = 1.34; _speed_fac = 1.69; break; }
	case cs::SaaRHa: { _part_mass_fac = 0.87; _vech_mass_fac = 1.2; _cost_fac = 0.6; _speed_fac = 1.33; break; }
	case cs::TarJer: { _part_mass_fac = 0.87; _vech_mass_fac = 1.2; _cost_fac = 2.4; _speed_fac = 2; break; }
	case cs::DLT: { _part_mass_fac = 1.0045; _vech_mass_fac = 1.09; _cost_fac = 1.9; _speed_fac = 2.05; break; }
	case cs::other: { _part_mass_fac = 1.5; _vech_mass_fac = 1.5; _cost_fac = 1.2; _speed_fac = 1.5; break; }
	}

	/// Расчёт по типу техники
	switch (_vech)
	{
	case cs::J: { _vech_mass_fac *= 1.2; _cost_fac *= 1.45; _speed_fac *= 2500; break; }
	case cs::JD: { _vech_mass_fac *= 4.1; _cost_fac *= 3.12; _speed_fac *= 70000; break; }
	case cs::F: { _vech_mass_fac *= 1.32; _cost_fac *= 1.4597; _speed_fac *= 200; break; }
	case cs::FDS: { _vech_mass_fac *= 1.97; _cost_fac *= 1.99; _speed_fac *= 670; break; }
	case cs::MA: { _vech_mass_fac *= 1.14; _cost_fac *= 2.5; _speed_fac *= 300; break; }
	case cs::E: { _vech_mass_fac *= 0.85; _cost_fac *= 2.2; _speed_fac *= 700; break; }
	case cs::B: { _vech_mass_fac *= 1.66; _cost_fac *= 8.14; _speed_fac *= 1500; break; }
	case cs::YT: { _vech_mass_fac *= 1.035; _cost_fac *= 1.23; _speed_fac *= 50; break; }
	case cs::no_name: { _vech_mass_fac *= 1; _cost_fac *= 1; break; }
	}


	/// Расчёт по назанчению техники
	switch (_spec)
	{
	case cs::GS: { _cost_fac *= 2.1463; _vech_mass_fac *= 1.2; _speed_fac *= 0.5; break; }
	case cs::R: { _cost_fac *= 2.67; _vech_mass_fac *= 1.8; _speed_fac *= 0.9; break; }
	case cs::RTT: { _cost_fac *= 1.3; _vech_mass_fac *= 1.87; _speed_fac *= 0.2; break; }
	case cs::N: { _cost_fac *= 1.05; _speed_fac *= 0.4; break; }
	case cs::GTT: { _cost_fac *= 2.3; _speed_fac *= 0.86; break; }
	case cs::P: { _part_mass_fac *= 0.5; _vech_mass_fac *= 0.45; _cost_fac *= 2; _speed_fac *= 1.7; break; }
	case cs::no_exs: {}
	}

	///Расчёт по форм-фактору кабины
	switch (_cab)
	{
	case cs::X: { _part_mass_fac *= 0.12; _vech_mass_fac *= 0.2; _cost_fac *= 0.5; _speed_fac *= 0.95; break; }
	case cs::X4: { _part_mass_fac *= 0.35; _vech_mass_fac *= 0.5; _cost_fac *= 0.9; _speed_fac *= 1.2; break; }
	case cs::T: { _part_mass_fac *= 1; _vech_mass_fac *= 1; _cost_fac *= 1; _speed_fac *= 0.7; break; }
	case cs::B2: { _part_mass_fac *= 1.4; _vech_mass_fac *= 1.35; _cost_fac *= 1.25; _speed_fac *= 1.25; break; }
	case cs::BS: { _part_mass_fac *= 2.5; _vech_mass_fac *= 2.35; _cost_fac *= 2.9; _speed_fac *= 0.3; break; }
	case cs::NN: { _part_mass_fac *= 1; _vech_mass_fac *= 1; _cost_fac *= 1.5; _speed_fac *= 0.75; break; }
	}

	///Расчёт по расширениям
	switch (_ext)
	{
	case cs::J5: {_vech_mass_fac *= 1.29; _cost_fac *= 1.15; break; }
	case cs::RET: {_vech_mass_fac *= 1.7; _cost_fac *= 7; break; }
	case cs::RX: {_vech_mass_fac *= 1.9; _cost_fac *= 2.45; break; }
	case cs::NG: {_vech_mass_fac *= 1.85; _cost_fac *= 5.3; break; }
	case cs::GTRX: {_vech_mass_fac *= 1.13; _cost_fac *= 4.21; break; }
	case cs::none_ext: {_vech_mass_fac *= 1; _cost_fac *= 1; break; }
	}

	/// Расчёт по вооружению
	switch (_arm)
	{
	case cs::RTX_12: {_vech_mass_fac *= 1.3145; _cost_fac *= 1.25; break; }
	case cs::JX_77: {_vech_mass_fac *= 1.15; _cost_fac *= 1.56; break; }
	case cs::JX_145: {_vech_mass_fac *= 1.54; _cost_fac *= 1.6; break; }
	case cs::RTG_B: {_vech_mass_fac *= 1.2; _cost_fac *= 1.55; break; }
	case cs::ARG_2: {_vech_mass_fac *= 2.6; _cost_fac *= 2.3; break; }
	case cs::AB_7: {_vech_mass_fac *= 2.21; _cost_fac *= 2.23; break; }
	case cs::non_arm: {_vech_mass_fac *= 1; _cost_fac *= 1; break; }
	}

}



/// Стандарт детали в строку
std::string part::get_std_string() const
{
	switch (part_standart)
	{
	case cs::XiFa: { return "Xi-Fa";  break; }
	case cs::ARJ: { return "ARJ"; break; }
	case cs::SaaRHa: { return "Saaren-Ha"; break; }
	case cs::TarJer: { return "TaranJero"; break; }
	case cs::DLT: { return "Delita"; break; }
	case cs::other: { return "other"; break; }
	}
}


/// Данные которые есть только у кабины (форм-фактор) в строку
std::string cabin::get_string() const
{
	switch (cab_fac)
	{
	case cs::X: { return "X"; break; }
	case cs::X4: {  return "X4"; break; }
	case cs::T: {  return "T"; break; }
	case cs::B2: {  return "B2"; break; }
	case cs::BS: {  return "BS"; break; }
	case cs::NN: {  return "NN"; break; }
	}
}


/// Все данные кабины в строку
std::string cabin::to_string()
{
	float m = get_mass();
	float c = get_cost();

	return std::to_string(m) + " " + std::to_string(c) + " " + std::to_string(get_speed_mod()) + " " + get_std_string() + " " + get_string();
}


/// Задать модификатор скорости исходя из характеристик двигателя
void engine::set_speed_mod(float sf)
{
	switch (et) //дорасчёт множителя скорости бредовым способом
	{
	case cs::R_1: { sf *= 1.2; break; }
	case cs::R_5: { sf *= 2.8; break; }
	case cs::RX_15: { sf *= 900; break; }
	case cs::RX_12: { sf *= 75; break; }
	case cs::T_5: { sf *= 0.75; break; }
	case cs::YX_3: { sf *= 0.9; break; }
	case cs::E_2: { sf *= 0.8; break; }
	case cs::mus_or_else: { sf *= 0.15; break; }
	}

	max_speed_mod *= sf;
}


/// Получить данные, характерные только для двигателя (тип)
std::string engine::get_string() const
{
	switch (et)
	{
	case cs::R_1: { return "R-1"; break; }
	case cs::R_5: { return "R-5"; break; }
	case cs::RX_15: { return "RX-15"; break; }
	case cs::RX_12: { return "RX-12"; break; }
	case cs::T_5: { return "T-5"; break; }
	case cs::YX_3: { return "YX-3"; break; }
	case cs::E_2: { return "E-2"; break; }
	case cs::mus_or_else: { return "muscule or other"; break; }
	}
}


/// Конструктор кабины
cabin::cabin(
	pvsc corparation,
	svt type,
	svs specialization,
	scff cabin,
	sve extensions,
	wp weapon
) : part(corparation, part_mass, cost)
{
	factor f(corparation, type, specialization, cabin, extensions, weapon); //создание уникального множителя

	float m = f.get_part_mass_fac(); //множитель массы
	float c = f.get_cost_fac(); //множитель стоимости
	set_speed_mod(f.get_speed_fac());

	set_mass(500 * m);
	set_cost(1200 * c);
}


/// Конструктор двигателя
engine::engine(
	cs::engine_type ET,
	pvsc corparation,
	svt type,
	svs specialization,
	scff cabin,
	sve extensions,
	wp weapon
) : part(corparation, part_mass, cost)
{
	factor f(corparation, type, specialization, cabin, extensions, weapon); //создание уникального множителя

	et = ET;
	float m = f.get_part_mass_fac(); //множитель массы
	float c = f.get_cost_fac(); //множитель стоимости
	set_speed_mod(f.get_speed_fac());

	set_mass(800 * m);
	set_cost(1200 * c);

}


/// Все данные двигателя в строку
std::string engine::to_string()
{
	float m = get_mass();
	float c = get_cost();

	return std::to_string(m) + " " + std::to_string(c) + " " + std::to_string(get_speed_mod()) + " " + get_std_string() + " " + get_string();
}


/// Задать модификатор скорости исходя из типа шасси
void chassis::set_speed_mod(float sf)
{
	switch (tp)
	{
	case cs::tracks: { sf *= 0.45; break; }
	case cs::wheels: { sf *= 1.01; break; }
	case cs::legs: { sf *= 0.3; break; }
	case cs::rods: { sf *= 0.35; break; }
	case cs::non: { sf *= 1; break; }
	}

	max_speed_mod *= sf;
}


/// Получить данные, характерные для шасси (тип)
std::string chassis::get_string() const
{
	switch (tp)
	{
	case cs::tracks: { return "tracks"; break; }
	case cs::wheels: { return "wheels"; break; }
	case cs::legs: { return "legs"; break; }
	case cs::rods: { return "rods"; break; }
	case cs::non: { return "none"; break; }
	}
}


/// Конструктор шасси
chassis::chassis(
	cs::chas_type CT,
	pvsc corparation,
	svt type,
	svs specialization,
	scff cabin,
	sve extensions,
	wp weapon
) : part(corparation, part_mass, cost)
{
	factor f(corparation, type, specialization, cabin, extensions, weapon); //генерация уникального множителя

	tp = CT;
	float m = f.get_part_mass_fac(); //множитель массы
	float c = f.get_cost_fac(); //множитель стоимости
	set_speed_mod(f.get_speed_fac());

	set_mass(2500 * m);
	set_cost(3100 * c);
}


/// Данные о шасси в строку
std::string chassis::to_string()
{
	float m = get_mass();
	float c = get_cost();

	return std::to_string(m) + " " + std::to_string(c) + " " + std::to_string(get_speed_mod()) + " " + get_std_string() + " " + get_string();
}



/// Данные о модели оружия в строку
std::string weapon::get_string() const
{
	switch (twv)
	{
	case cs::RTX_12: { return "RTX-12"; break; }
	case cs::JX_77: { return "JX-77"; break; }
	case cs::JX_145: { return "JX-145"; break; }
	case cs::RTG_B: { return "RTG-B"; break; }
	case cs::ARG_2: { return "ARG-2"; break; }
	case cs::AB_7: { return "AB-7"; break; }
	case cs::non_arm: { return "non-armed"; break; }
	}
}


/// Конструктор оружия
weapon::weapon(pvsc prt_std, wp weap_) : part(prt_std, 400, 2900)
{
	twv = weap_;

	factor f(prt_std, cs::no_name, cs::no_exs, cs::NN, cs::none_ext, weap_); //генерация уникального множителя

	float m = f.get_part_mass_fac(); //множитель массы
	float c = f.get_cost_fac(); //множитель стоимости
	set_speed_mod(f.get_speed_fac());

	set_mass(get_mass() * m);
	set_cost(get_cost() * c);
}


/// Все данные об оружии в строку
std::string weapon::to_string()
{
	float m = get_mass();
	float c = get_cost();

	return std::to_string(m) + " " + std::to_string(c) + " " + get_std_string() + " " + get_string();
}


/// Данные о типе надстройки в строку
std::string extra_modules::get_string() const
{
	switch (_ext)
	{
	case cs::J5: { return "J5"; break; }
	case cs::RET: { return "RET"; break; }
	case cs::RX: { return "RX"; break; }
	case cs::NG: { return "NG"; break; }
	case cs::GTRX: { return "GTRX"; break; }
	case cs::none_ext: { return "no extensions";; break; }
	}
}


/// Конструктор надстройки
extra_modules::extra_modules(pvsc prt_std, sve ext_) : part(prt_std, 700, 350)
{
	_ext = ext_;

	factor f(prt_std, cs::no_name, cs::no_exs, cs::NN, ext_, cs::non_arm);

	float m = f.get_part_mass_fac();
	float c = f.get_cost_fac();
	set_speed_mod(f.get_speed_fac());

	set_mass(get_mass() * m);
	set_cost(get_cost() * c);
}


/// Все данные о надстройке в строку
std::string extra_modules::to_string()
{
	float m = get_mass();
	float c = get_cost();

	return std::to_string(m) + " " + std::to_string(c) + " " + get_std_string() + " " + get_string();
}


/// Конструктор транспорта
vechicle::vechicle
(
	cs::engine_type et,
	cs::chas_type ct,
	pvsc corparation,
	svt type,
	svs specialization,
	scff cabin_,
	sve extensions,
	wp weapon_
)
{
	vech_standart = corparation;
	vech_type = type;
	vech_spec = specialization;

	///Заполнение указателей на детали
	CAB = new cabin(corparation, type, specialization, cabin_, extensions, weapon_);
	ENG = new engine(et, corparation, type, specialization, cabin_, extensions, weapon_);
	CHA = new chassis(ct, corparation, type, specialization, cabin_, extensions, weapon_);
	WPN = new weapon(corparation, weapon_);
	XMD = new extra_modules(corparation, extensions);

	/*factor K(corparation, type, specialization, cabin_, extensions, weapon_);*/
	KP = new factor(corparation, type, specialization, cabin_, extensions, weapon_);
	/*vech_standart = convertCompToPvsc(corp);*/
	data_calc();
}

///Расчёт характеристик транспорта
void vechicle::data_calc()
{
	vech_mass = KP->get_vech_mass_fac() * (CAB->get_mass() + ENG->get_mass() + CHA->get_mass() + WPN->get_mass() + XMD->get_mass());
	speed = (KP->get_speed_fac() * 0.001) * (CAB->get_speed_mod() * ENG->get_speed_mod() * CHA->get_speed_mod());
	cost = standart_cost_factor * KP->get_cost_fac() * (CAB->get_cost() + ENG->get_cost() + CHA->get_cost() + WPN->get_cost() + XMD->get_cost());
}

#if TEST == false
// Функция для применения цвета к строке (по приколу)
std::string applyColor(const std::string& text, const std::string& color) {
	return color + text + RESET;
}
#endif
/// Выведение в строку длинного описания
std::string vechicle::get_long_description()
{
	std::string temp = "";
	std::string ext = "";

#if TEST == false
	ext = applyColor("_______Description_______", GREEN);
#else
	ext = "_______Description_______";
#endif

	ext += "\n\n";
	ext += "Mass: " + std::to_string(vech_mass) + "\n";
	ext += "Speed: " + std::to_string(speed) + "\n" + "\n";
	ext += "Cost: " + std::to_string(cost) + "\n" + "\n" + "\n";

	ext += CAB->to_string() + '\n';
	ext += ENG->to_string() + '\n';
	ext += CHA->to_string() + '\n';
	ext += WPN->to_string() + '\n';
	ext += XMD->to_string() + '\n';


	return ext;
}


/// Выведение в строку однострочного описания
std::string vechicle::get_short_description()
{
	std::string shrt = "";
	std::string temp = "";

	switch (vech_standart)
	{
	case cs::XiFa: {temp = "Xi-Fa"; break; }
	case cs::ARJ: {temp = "ARJ"; break; }
	case cs::SaaRHa: {temp = "SaaRHa"; break; }
	case cs::TarJer: {temp = "TarJer"; break; }
	case cs::DLT: {temp = "DLT"; break; }
	case cs::other: {temp = "unknown/other"; break; }
	default: temp += "N/A";
	}

	shrt += temp + " ";

	switch (vech_type)
	{
	case cs::J: {temp = "J"; break; }
	case cs::JD: {temp = "JD"; break; }
	case cs::F: {temp = "F"; break; }
	case cs::FDS: {temp = "FDS"; break; }
	case cs::MA: {temp = "MA"; break; }
	case cs::E: {temp = "E"; break; }
	case cs::B: {temp = "B"; break; }
	case cs::YT: {temp = "YT"; break; }
	default: temp = "N/A";
	}

	if (vech_type != cs::no_name)
		shrt += temp + ":";

	switch (vech_spec)
	{
	case cs::GS: {temp = "SD"; break; }
	case cs::R: {temp = "R"; break; }
	case cs::RTT: {temp = "RTT"; break; }
	case cs::N: {temp = "N"; break; }
	case cs::GTT: {temp = "GTT"; break; }
	case cs::P: {temp = "P"; break; }
	default: temp = "";
	}

	shrt += temp;

	return shrt;
}


/// Конструктор транспорта с внешней настройкой и созданием деталей (солянка)
vechicle::vechicle(cabin* cab, engine* eng, chassis* chas, weapon* weap, extra_modules* em, svt vtp , svs vs)
{
	CAB = cab;
	ENG = eng;
	CHA = chas;
	WPN = weap;
	XMD = em;
	vech_type = vtp;
	vech_spec = vs;
	vech_standart = cs::other;
	KP = new factor(vech_standart, vech_type, vech_spec, CAB->get_FF(), XMD->get_xtra_mod(), WPN->get_arm());
	data_calc();
}

vechicle::~vechicle()
{
	delete CAB;
	delete ENG;
	delete CHA;
	delete WPN;
	delete XMD;
	delete KP;
}