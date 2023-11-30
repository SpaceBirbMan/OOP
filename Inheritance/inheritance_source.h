#pragma once

#include "header_array.h"

//auth: Sosnov.K

// Представленные в программе вещи и результат её работы не имеют отношения к реальному миру

////////////////////////////////////// И С П О Л Ь З У Е М Ы Е  Д А Н Н Ы Е //////////////////////////////////////


/// Конструкционный стандарт для транспорта и всех его компонентов
struct construction_standart
{
	enum part_vech_standart_corp
	{
		XiFa,
		ARJ,
		SaaRHa,
		TarJer,
		DLT,
		other,
		abs_std
	};

	enum standart_vech_name
	{
		J, //шаттлы и челноки атмосферно-вакуумного типа с дальностю до 2000000 км
		JD, //челнок вакуумного типа с дальностью сыше 2000000 км
		F, //автомобильный транспорт
		FDS, //рельсовый транспорт
		MA, //водный и подводный транспорт
		E, //самолёты и вертолёты
		B, //транспорт ракетного типа
		YT, //мехи и боты
		no_name //отсутствует определение типа
	};
	
	enum standart_vech_spec
	{
		GS, //транспорт специального назначения
		R, //военная техника
		RTT, //грузовой транспорт
		N, //пассажирские и грузоперевозки
		GTT, //научно-исследовательская техника
		P, //спортивный транспорт
		no_exs //техника не имеет специального определения
	};

	enum standart_vech_form_factor
	{
		X, //микро
		X4, //мини
		T, //стандартный
		B2, //большой
		BS, //сверхбольшой
		NN, //нет точного определения
	};
	
};

////////////////////////////////////// П С Е В Д О Н И М Ы //////////////////////////////////////

using cs = construction_standart;

	using pvsc = cs::part_vech_standart_corp;
	using svt = cs::standart_vech_name;
	using svs = cs::standart_vech_spec;
	using svff = cs::standart_vech_form_factor;

/////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// П Р И К Л А Д Н Ы Е  К Л А С С Ы ////////////////////////////////////// 

class factor
{
private:

	pvsc _corp = cs::abs_std;
	//svt _vech = cs::no_name;

	float _part_mass_fac = 0;
	float _vech_mass_fac = 0;
	float _cost_fac = 0;

	void set_corp(pvsc corparation) { _corp = corparation; }



	void get_factor()
	{
		switch (_corp)
		{
		case cs::XiFa: {_part_mass_fac = 1.1265; _vech_mass_fac = 0.99984; _cost_fac = 1.7;  break; }
		case cs::ARJ: {_part_mass_fac = 1.25; _vech_mass_fac = 1.67; _cost_fac = 1.34;  break; }
		case cs::SaaRHa: {_part_mass_fac = 0.87; _vech_mass_fac = 1.2; _cost_fac = 0.6;  break; }
		case cs::TarJer: {_part_mass_fac = 0.87; _vech_mass_fac = 1.2; _cost_fac = 2.4;  break; }
		case cs::DLT: {_part_mass_fac = 1.0045; _vech_mass_fac = 1.09; _cost_fac = 1.9;  break; }
		case cs::other: {_part_mass_fac = 1.5; _vech_mass_fac = 1.5; _cost_fac = 1.2;  break; }
		}

		//todo: не хватает дополнения коэффициента в зависимости от вида транспорта
	}

public:

	factor(pvsc corparation) { set_corp(corparation);  get_factor(); }

	float  get_part_mass_fac() const { return _part_mass_fac; }
	float  get_vech_mass_fac() const { return _vech_mass_fac; }
	float  get_cost_fac() const { return _cost_fac; }
};

///////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// К Л А С С Ы  Д Е Т А Л Е Й //////////////////////////////////////

class part
{
protected:
	pvsc part_standart = cs::abs_std;
	float part_mass = 0;
	float cost = 0;

	virtual float get_mass() { return part_mass; }
	virtual float get_cost() { return cost; }
	virtual pvsc get_part_standart() { return part_standart; }

	virtual void set_part_standart(pvsc std) { part_standart = std; }
	virtual void set_mass(float m) { part_mass = m; }
	virtual void set_cost(float c) { cost = c; }

	part (pvsc prt_std, float ms, float cst)
		: part_standart(prt_std), part_mass(ms), cost(cst)
	{
		factor tk(prt_std);
		float k = tk.get_part_mass_fac();
		float m = tk.get_cost_fac();

		part_mass *= k;
		cost *= m;
	}

	part() {}

	virtual std::string to_string() = 0;
};

class cabin : virtual protected part
{
public:

	svff cab_fac = cs::NN;

	cabin(pvsc prt_std) : part(prt_std, part_mass, cost) { set_mass(500); set_cost(1200); }

	std::string to_string() override { return ""; }
	cabin() { part_mass = 500; cost = 1200; }

};

class engine: virtual protected part
{
public:

	engine(pvsc prt_std) : part(prt_std, 800, 1200) { }
	float speed_modif = 1; //надо установить зависимость с компанией и типом транспорта

	engine() {}
	//тип двигателя (прямая связь с типом транспорта)
};

class chassis : virtual protected part
{
public:

	chassis(pvsc prt_std) : part(prt_std, 2500, 3100) {}


	chassis() {}
	//todo: тип шасси
};

class weapon : virtual protected part
{
public:

	weapon(pvsc prt_std) : part(prt_std, 400, 2900) {}

	weapon() {}
	//todo: раскрть оружие
};

class extra_modules : virtual protected part
{
public:

	extra_modules(pvsc prt_std) : part(prt_std, 700, 350) {}

	extra_modules() {}
	//todo: раскрть расширения
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// К Л А С С  Т Р А Н С П О Р Т А //////////////////////////////////////

class vechicle : public cabin, engine, chassis, weapon, extra_modules
{
protected:

	pvsc vech_standart = cs::abs_std;
	svt vech_type = cs::no_name;
	svs vech_spec = cs::no_exs;

	float vech_mass = 0;
	float speed = 0;
	svt type = cs::no_name;
	float cost = 0;

private:
	pvsc convertCompToPvsc(std::string comp)
	{
		if (comp == "Xi-Fa") return cs::XiFa;
		if (comp == "ARJ") return cs::ARJ;
		if (comp == "SaarHa") return cs::SaaRHa;
		if (comp == "TarJer") return cs::TarJer;
		if (comp == "DLT") return cs::DLT;
		if (comp == "other") return cs::other;

		// Вернуть значение по умолчанию или обработать ошибку
		return cs::abs_std;
	}

	float standart_cost_factor = 1.45;
public:

	vechicle(pvsc corp, svt v_type, svs v_spec /*, extens_type, weapons_pair */ ) :
		cabin(vech_standart), 
		engine(vech_standart), 
		chassis(vech_standart), 
		weapon(vech_standart), 
		extra_modules(vech_standart) 
	{
		vech_standart = corp;
		vech_type = v_type;
		vech_spec = v_spec;

		factor K(corp);
		/*vech_standart = convertCompToPvsc(corp);*/
		vech_mass = K.get_vech_mass_fac() * get_mass();
		speed = engine::speed_modif * 200;
		cost = standart_cost_factor * get_cost();
	}

	vechicle()
	{}


	//нужен детальный конструктор для создания сборной солянки
	//нужен псевдоним

	virtual std::string get_long_description()
	{
		std::string temp = "";
		std::string ext = "";

		ext = "_______Description_______";
		ext += "\n\n";
		ext += "Mass: " + std::to_string(vech_mass) + "\n";
		ext += "Speed: " + std::to_string(speed) + "\n" + "\n";
		ext += "Cost: " + std::to_string(cost) + "\n" + "\n" + "\n";

		ext += "Manufacturer/Standart: ";

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

		ext += temp + "\n";
		ext += "Vechicle type: ";

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
			ext += temp + ":";

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

		ext += temp;

		return ext;
	}

	virtual std::string get_short_description()
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

	//todo: допилить вывод по типам вооружения и расширений
};