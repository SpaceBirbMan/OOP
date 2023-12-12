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

	enum standart_vech_name //(name -> type)
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

	enum standart_cab_form_factor
	{
		X, //микро
		X4, //мини
		T, //стандартный
		B2, //большой
		BS, //сверхбольшой
		NN, //нет точного определения
	};

	enum standart_vech_ext
	{
		J5,
		RET,
		RX,
		NG,
		GTRX,
		none_ext
	};

	enum weapons
	{
		RTX_12,
		JX_77,
		JX_145,
		RTG_B,
		ARG_2,
		AB_7,
		non_arm
	};

	enum engine_type
	{
		R_1, //реактивный стандартный
		R_5, //реактивный сверхзвуковой или ракетный
		RX_15, //дальний варп
		RX_12, //ближний варп
		T_5, //ДВС
		YX_3, //ДЭП
		E_2, //ДВС-В (H2)
		mus_or_else //мускульный или иной
	};

	enum chas_type
	{
		tracks,
		wheels,
		legs,
		rods,
		non
	};

};

////////////////////////////////////// П С Е В Д О Н И М Ы //////////////////////////////////////

using cs = construction_standart;

	using pvsc = cs::part_vech_standart_corp;
	using svt = cs::standart_vech_name;
	using svs = cs::standart_vech_spec;
	using scff = cs::standart_cab_form_factor;
	using sve = cs::standart_vech_ext;
	using wp = cs::weapons;

/////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// П Р И К Л А Д Н Ы Е  К Л А С С Ы ////////////////////////////////////// 

 
///  Класс с функцией расчёта множителей масс, скорости и стоимости
 
class factor
{
private:

	 
	/// Рабочие переменные
	 
	pvsc _corp = cs::abs_std;
	svt _vech = cs::no_name;
	svs _spec = cs::no_exs;
	scff _cab = cs::NN;
	sve _ext = cs::none_ext;
	wp _arm = cs::non_arm;


	float _part_mass_fac = 0;
	float _vech_mass_fac = 0;
	float _cost_fac = 0;
	float _speed_fac = 1;

	 
	/// Задать стандарт компании-производителя
	void set_corp(pvsc corparation) { _corp = corparation; }

	 
	/// Задать тип транспорта
	void set_vech_type(svt type) { _vech = type; }

	 
	/// Задать назначение техники
	void set_vech_spec(svs specialization) { _spec = specialization; }

	 
	/// Задать форм-фактор кабины
	void set_cab_fac(scff cabin) { _cab = cabin; }

	 
	/// Задать расширения для транспорта
	void set_extens(sve extensions) { _ext = extensions; }


	/// Задать вооружение
	void set_weapons(wp weapon) { _arm = weapon; }


	 
	/// Расчитать множитель
	void get_factor();

public:

	 
	/// Конструктор множителя
	factor
	(
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
	) 
	{ 
		 
		/// Задание параметров
		 
		set_corp(corparation);  
		set_vech_type(type);
		set_vech_spec(specialization);
		set_cab_fac(cabin);
		set_extens(extensions);
		set_weapons(weapon);

		 
		/// Расчёт
		 
		get_factor(); 
	}

	 
	/// Получить множитель массы детали 
	float  get_part_mass_fac() const { return _part_mass_fac; }

	 
	/// Получить множитель массы транспорта 
	float  get_vech_mass_fac() const { return _vech_mass_fac; }

	 
	/// Получить множитель стоимости 
	float  get_cost_fac() const { return _cost_fac; }

	 
	/// Получить множитель скорости 
	float  get_speed_fac() const { return _speed_fac; }
};

///////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// К Л А С С Ы  Д Е Т А Л Е Й //////////////////////////////////////

 
/// Суперкласс детали
 
class part
{
protected:
	pvsc part_standart = cs::abs_std;
	float part_mass = 0;
	float cost = 0;
	float max_speed_mod = 1;

	 
	/// Полуить массу
	 
	virtual float get_mass() { return part_mass; }

	 
	/// Получить стоимость
	 
	virtual float get_cost() { return cost; }

	 
	/// Получить модификатор скорости
	 
	virtual float get_speed_mod() { return max_speed_mod; }

	 
	/// Получить конструкторский стандарт
	 
	virtual pvsc get_part_standart() { return part_standart; }

	 
	/// Задать конструкторский стандарт
	 
	virtual void set_part_standart(pvsc std) { part_standart = std; }

	 
	/// Задать массу
	 
	virtual void set_mass(float m) { part_mass = m; }

	 
	/// Задать стоимость
	 
	virtual void set_cost(float c) { cost = c; }

	/// Задать модификатор скорости
	virtual void set_speed_mod(float sf) = 0;


	///Конструктор детали
	part (pvsc prt_std, float ms, float cst)
		: part_standart(prt_std), part_mass(ms), cost(cst)
	{
	}

	part() {}

	/// Запись данных в строку
	virtual std::string to_string() = 0;

	 
	///  Запись конкретных локальных данных в строку
	 
	
	virtual std::string get_string() const = 0;

	/// Получение данных стандарта строкой
	virtual std::string get_std_string() const;
};

///Класс кабины
class cabin : virtual protected part
{
private:
	scff cab_fac = cs::NN; //форм-фактор кабины

	///Задать модификатор скорости
	void set_speed_mod(float sf) override { max_speed_mod = sf; }

	///Получить данные о форм-факторе строкой
	std::string get_string() const override;

public:

	///Конструктор
	cabin(
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
	);

	 
	/// Запись всех данных в строку
	std::string to_string();

	cabin() {}

	 
	/// Получить модификатор скорости
	 
	float get_speed_mod() override { return max_speed_mod; }

	 
	/// Получить массу
	 
	float get_mass() override { return part::get_mass(); } 

	///Получить стоимость
	float get_cost() override { return part::get_cost(); }

	pvsc get_part_standart() override { return part::get_part_standart(); }

	scff get_FF() { return cab_fac; }

};

///Класс двигателя
class engine: virtual protected part
{
private:

	cs::engine_type et; //тип двигателя (костыль)


	///Задать модификатор скорости
	void set_speed_mod(float sf) override;

	 
	/// Получить данные типа двигателя
	 
	std::string get_string() const override;

public:

	///Конструктор
	engine(
		cs::engine_type ET = cs::mus_or_else,
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
	);

	engine() {}

	 
	/// Запись в строку
	std::string to_string() override;

	 
	/// Получить модификатор скорости 
	float get_speed_mod() override { return max_speed_mod; }

	 
	/// Получить массу
	float get_mass() override { return part::get_mass(); }

	 
	/// Получить стоимость
	float get_cost() override { return part::get_cost(); }

};

 
/// Класс шасси
class chassis : virtual protected part
{
private:

	cs::chas_type tp = cs::non; //тип шасси (костыль)
	

	 
	/// Задать модификатор скорости
	void set_speed_mod(float sf) override;

	///Получить тип шасси
	std::string get_string() const override;

public:

	///Конструктор
	chassis(
		cs::chas_type CT = cs::non,
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
	);

	chassis() {}

	///Получить строку с данными
	std::string to_string() override;

	///Получить моддификатор скорости
	float get_speed_mod() override { return max_speed_mod; }
	float get_mass() override { return part::get_mass(); }
	float get_cost() override { return part::get_cost(); }

};

///Класс оружия
class weapon : virtual protected part
{
private:

	wp twv = cs::non_arm;

	///Получить тип оружия
	std::string get_string() const;

	void set_speed_mod(float sf) override { max_speed_mod = sf; }

public:

	weapon(pvsc prt_std, wp weap_);

	weapon() {}

	std::string to_string() override;

	float get_mass() override { return part::get_mass(); }
	float get_cost() override { return part::get_cost(); }
	pvsc get_part_standart() override { return part::get_part_standart(); }
	wp get_arm() { return twv; }

};

///Класс надстроек
class extra_modules : virtual protected part
{
private:

	sve _ext = cs::none_ext;

	std::string get_string() const;

	void set_speed_mod(float sf) override { max_speed_mod = sf; }

public:

	extra_modules(pvsc prt_std, sve ext_);

	extra_modules() {}

	std::string to_string() override;

	float get_mass() override { return part::get_mass(); }
	float get_cost() override { return part::get_cost(); }
	pvsc get_part_standart() override { return part::get_part_standart(); }
	sve get_xtra_mod() { return _ext; }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// К Л А С С  Т Р А Н С П О Р Т А //////////////////////////////////////

class vechicle
{
protected: //зачем?

	pvsc vech_standart = cs::abs_std;
	svt vech_type = cs::no_name;
	svs vech_spec = cs::no_exs;

	float vech_mass = 0;
	float speed = 0;
	svt type = cs::no_name;
	float cost = 0;

private:

	float standart_cost_factor = 1.0646712346443756; //перерасчётчик стоимости

	cabin* CAB;
	engine* ENG;
	chassis* CHA;
	weapon* WPN;
	extra_modules* XMD;
	factor* KP;

	//размеры (обобщённо)(влияют на вес и стоимость транспорта) [потом когда-нибудь]

	///Расчёт характеристик транспорта
	void data_calc();

public:

	///Классический конструктор
	vechicle
	(
		cs::engine_type et = cs::mus_or_else,
		cs::chas_type ct = cs::non,
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin_ = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon_ = cs::non_arm
	);

	float get_vmass() const { return vech_mass; }

	float get_vcost() const { return cost; }

	float get_vspeed() const { return speed; }

	float get_std_cost_factor() const { return standart_cost_factor; }

	 
	/// Пустой конструктор
	vechicle()
	{}

	 
	/// Конструктор-солянка 
	vechicle(cabin* cab, engine* eng, chassis* chas, weapon* weap, extra_modules* em,  svt vtp = cs::no_name, svs vs = cs::no_exs);

	virtual std::string get_long_description();

	virtual std::string get_short_description();

	~vechicle();
};