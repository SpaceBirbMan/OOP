#pragma once

#include "header_array.h"

//auth: Sosnov.K

// �������������� � ��������� ���� � ��������� � ������ �� ����� ��������� � ��������� ����

////////////////////////////////////// � � � � � � � � � � � �  � � � � � � //////////////////////////////////////


/// ��������������� �������� ��� ���������� � ���� ��� �����������
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
		J, //������ � ������� ����������-���������� ���� � ��������� �� 2000000 ��
		JD, //������ ���������� ���� � ���������� ���� 2000000 ��
		F, //������������� ���������
		FDS, //��������� ���������
		MA, //������ � ��������� ���������
		E, //������� � ��������
		B, //��������� ��������� ����
		YT, //���� � ����
		no_name //����������� ����������� ����
	};
	
	enum standart_vech_spec
	{
		GS, //��������� ������������ ����������
		R, //������� �������
		RTT, //�������� ���������
		N, //������������ � ��������������
		GTT, //������-����������������� �������
		P, //���������� ���������
		no_exs //������� �� ����� ������������ �����������
	};

	enum standart_cab_form_factor
	{
		X, //�����
		X4, //����
		T, //�����������
		B2, //�������
		BS, //������������
		NN, //��� ������� �����������
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
		R_1, //���������� �����������
		R_5, //���������� ������������� ��� ��������
		RX_15, //������� ����
		RX_12, //������� ����
		T_5, //���
		YX_3, //���
		E_2, //���-� (H2)
		mus_or_else //���������� ��� ����
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

////////////////////////////////////// � � � � � � � � � � //////////////////////////////////////

using cs = construction_standart;

	using pvsc = cs::part_vech_standart_corp;
	using svt = cs::standart_vech_name;
	using svs = cs::standart_vech_spec;
	using scff = cs::standart_cab_form_factor;
	using sve = cs::standart_vech_ext;
	using wp = cs::weapons;

/////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// � � � � � � � � � �  � � � � � � ////////////////////////////////////// 

/// <summary>
///  ����� � �������� ������� ���������� ����, �������� � ���������
/// </summary>
class factor
{
private:

	/// <summary>
	/// ������� ����������
	/// </summary>
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

	/// <summary>
	/// ������ �������� ��������-�������������
	/// </summary>
	/// <param name="corparation"></param>
	void set_corp(pvsc corparation) { _corp = corparation; }

	/// <summary>
	/// ������ ��� ����������
	/// </summary>
	/// <param name="type"></param>
	void set_vech_type(svt type) { _vech = type; }

	/// <summary>
	/// ������ ���������� �������
	/// </summary>
	/// <param name="specialization"></param>
	void set_vech_spec(svs specialization) { _spec = specialization; }

	/// <summary>
	/// ������ ����-������ ������
	/// </summary>
	/// <param name="cabin"></param>
	void set_cab_fac(scff cabin) { _cab = cabin; }

	/// <summary>
	/// ������ ���������� ��� ����������
	/// </summary>
	/// <param name="extensions"></param>
	void set_extens(sve extensions) { _ext = extensions; }

	/// <summary>
	/// ������ ����������
	/// </summary>
	/// <param name="weapon"></param>
	void set_weapons(wp weapon) { _arm = weapon; }


	/// <summary>
	/// ��������� ���������
	/// </summary>
	void get_factor()
	{
		/// ������ �� ��������������� ���������
		switch (_corp)
		{
		case cs::XiFa: { _part_mass_fac = 1.1265; _vech_mass_fac = 0.99984; _cost_fac = 1.7; _speed_fac = 1.2;  break; }
		case cs::ARJ: { _part_mass_fac = 1.25; _vech_mass_fac = 1.67; _cost_fac = 1.34; _speed_fac = 1.69; break; }
		case cs::SaaRHa: { _part_mass_fac = 0.87; _vech_mass_fac = 1.2; _cost_fac = 0.6; _speed_fac = 1.33; break; }
		case cs::TarJer: { _part_mass_fac = 0.87; _vech_mass_fac = 1.2; _cost_fac = 2.4; _speed_fac = 2; break; }
		case cs::DLT: { _part_mass_fac = 1.0045; _vech_mass_fac = 1.09; _cost_fac = 1.9; _speed_fac = 2.05; break; }
		case cs::other: { _part_mass_fac = 1.5; _vech_mass_fac = 1.5; _cost_fac = 1.2; _speed_fac = 1.5; break; }
		}

		/// ������ �� ���� �������
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
		//	J, //������ � ������� ����������-���������� ���� � ��������� �� 2000000 ��
		//	JD, //������ ���������� ���� � ���������� ���� 2000000 ��
		//	F, //������������� ���������
		//	FDS, //��������� ���������
		//	MA, //������ � ��������� ���������
		//	E, //������� � ��������
		//	B, //��������� ��������� ����
		//	YT, //���� � ����
		//	no_name //����������� ����������� ����

		/// ������ �� ���������� �������
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
		//	GS, //��������� ������������ ����������
		//	R, //������� �������
		//	RTT, //�������� ���������
		//	N, //������������ � ��������������
		//	GTT, //������-����������������� �������
		//	P, //���������� ���������
		//	no_exs //������� �� ����� ������������ �����������

		///������ �� ����-������� ������
		switch (_cab)
		{
		case cs::X: { _part_mass_fac *= 0.12; _vech_mass_fac *= 0.2; _cost_fac *= 0.5; _speed_fac *= 0.95; break; }
		case cs::X4: { _part_mass_fac *= 0.35; _vech_mass_fac *= 0.5; _cost_fac *= 0.9; _speed_fac *= 1.2; break; }
		case cs::T: { _part_mass_fac *= 1; _vech_mass_fac *= 1; _cost_fac *= 1; _speed_fac *= 0.7; break; }
		case cs::B2: { _part_mass_fac *= 1.4; _vech_mass_fac *= 1.35; _cost_fac *= 1.25; _speed_fac *= 1.25; break; }
		case cs::BS: { _part_mass_fac *= 2.5; _vech_mass_fac *= 2.35; _cost_fac *= 2.9; _speed_fac *= 0.3; break; }
		case cs::NN: { _part_mass_fac *= 1; _vech_mass_fac *= 1; _cost_fac *= 1.5; _speed_fac *= 0.75; break; }
		}

		///������ �� �����������
		switch (_ext)
		{
		case cs::J5: {_vech_mass_fac *= 1.29; _cost_fac *= 1.15; break; }
		case cs::RET: {_vech_mass_fac *= 1.7; _cost_fac *= 7; break; }
		case cs::RX: {_vech_mass_fac *= 1.9; _cost_fac *= 2.45; break; }
		case cs::NG: {_vech_mass_fac *= 1.85; _cost_fac *= 5.3; break; }
		case cs::GTRX: {_vech_mass_fac *= 1.13; _cost_fac *= 4.21; break; }
		case cs::none_ext: {_vech_mass_fac *= 1; _cost_fac *= 1; break; }
		}
		//X, //�����
		//	X4, //����
		//	T, //�����������
		//	B2, //�������
		//	BS, //������������
		//	NN, //��� ������� �����������

		/// ������ �� ����������
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

public:

	/// <summary>
	/// ����������� ���������
	/// </summary>
	/// 
	/// <param name="corparation"></param>
	/// <param name="type"></param>
	/// <param name="specialization"></param>
	/// <param name="cabin"></param>
	/// <param name="none_ext"></param>
	/// <param name=""></param>
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
		/// <summary>
		/// ������� ����������
		/// </summary>
		set_corp(corparation);  
		set_vech_type(type);
		set_vech_spec(specialization);
		set_cab_fac(cabin);
		set_extens(extensions);
		set_weapons(weapon);

		/// <summary>
		/// ������
		/// </summary>
		get_factor(); 
	}

	/// <summary>
	/// �������� ��������� ����� ������
	/// </summary>
	float  get_part_mass_fac() const { return _part_mass_fac; }

	/// <summary>
	/// �������� ��������� ����� ����������
	/// </summary>
	float  get_vech_mass_fac() const { return _vech_mass_fac; }

	/// <summary>
	/// �������� ��������� ���������
	/// </summary>
	float  get_cost_fac() const { return _cost_fac; }

	/// <summary>
	/// �������� ��������� ��������
	/// </summary>
	float  get_speed_fac() const { return _speed_fac; }
};

///////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// � � � � � �  � � � � � � � //////////////////////////////////////

/// <summary>
/// ���������� ������
/// </summary>
class part
{
protected:
	pvsc part_standart = cs::abs_std;
	float part_mass = 0;
	float cost = 0;
	float max_speed_mod = 1;

	/// <summary>
	/// ������� �����
	/// </summary>
	virtual float get_mass() { return part_mass; }

	/// <summary>
	/// �������� ���������
	/// </summary>
	virtual float get_cost() { return cost; }

	/// <summary>
	/// �������� ����������� ��������
	/// </summary>
	virtual float get_speed_mod() { return max_speed_mod; }

	/// <summary>
	/// �������� ��������������� ��������
	/// </summary>
	virtual pvsc get_part_standart() { return part_standart; }

	/// <summary>
	/// ������ ��������������� ��������
	/// </summary>
	virtual void set_part_standart(pvsc std) { part_standart = std; }

	/// <summary>
	/// ������ �����
	/// </summary>
	virtual void set_mass(float m) { part_mass = m; }

	/// <summary>
	/// ������ ���������
	/// </summary>
	virtual void set_cost(float c) { cost = c; }

	/// ������ ����������� ��������
	virtual void set_speed_mod(float sf) = 0;


	///����������� ������
	part (pvsc prt_std, float ms, float cst)
		: part_standart(prt_std), part_mass(ms), cost(cst)
	{
	}

	part() {}

	/// ������ ������ � ������
	virtual std::string to_string() = 0;

	/// <summary>
	///  ������ ���������� ��������� ������ � ������
	/// </summary>
	/// <returns></returns>
	virtual std::string get_string() const = 0;

	/// ��������� ������ ��������� �������
	virtual std::string get_std_string() const 
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
};

///����� ������
class cabin : virtual protected part
{
private:
	scff cab_fac = cs::NN; //����-������ ������

	///������ ����������� ��������
	void set_speed_mod(float sf) override { max_speed_mod = sf; }

	///�������� ������ � ����-������� �������
	std::string get_string() const override
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

public:

	///�����������
	cabin(
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
		) : part(corparation, part_mass, cost)
	{ 
		factor f(corparation, type, specialization, cabin, extensions, weapon);

		float m = f.get_part_mass_fac();
		float c = f.get_cost_fac();
		set_speed_mod(f.get_speed_fac());

		set_mass(500 * m);
		set_cost(1200 * c); 
	}

	/// <summary>
	/// ������ ���� ������ � ������
	/// </summary>
	/// <returns></returns>
	std::string to_string() override 
	{ 
		float m = get_mass();
		float c = get_cost();

		return std::to_string(m) + " " + std::to_string(c) + " " + std::to_string(get_speed_mod()) + " " + get_std_string() + " " + get_string();
	}

	cabin() {}

	/// <summary>
	/// �������� ����������� ��������
	/// </summary>
	float get_speed_mod() override { return max_speed_mod; }

	/// <summary>
	/// �������� �����
	/// </summary>
	float get_mass() override { return part::get_mass(); } 

	///�������� ���������
	float get_cost() override { return part::get_cost(); }

};

///����� ���������
class engine: virtual protected part
{
private:

	cs::engine_type et; //��� ��������� (�������)


	///������ ����������� ��������
	void set_speed_mod(float sf) override
	{ 
		switch (et) //�������� ��������� �������� �������� ��������
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

	/// <summary>
	/// �������� ������ ���� ���������
	/// </summary>
	std::string get_string() const override
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

public:

	///�����������
	engine(
		cs::engine_type ET = cs::mus_or_else,
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
		) : part(corparation, part_mass, cost)
	{
		factor f(corparation, type, specialization, cabin, extensions, weapon);

		et = ET;
		float m = f.get_part_mass_fac();
		float c = f.get_cost_fac();
		set_speed_mod(f.get_speed_fac());

		set_mass(800 * m);
		set_cost(1200 * c);

	}

	engine() {}

	/// <summary>
	/// ������ � ������
	/// </summary>
	std::string to_string() override
	{
		float m = get_mass();
		float c = get_cost();

		return std::to_string(m) + " " + std::to_string(c) + " " + std::to_string(get_speed_mod()) + " " + get_std_string() + " " + get_string();
	}

	/// <summary>
	/// �������� ����������� ��������
	/// </summary>
	float get_speed_mod() override { return max_speed_mod; }

	/// <summary>
	/// �������� �����
	/// </summary>
	float get_mass() override { return part::get_mass(); }

	/// <summary>
	/// �������� ���������
	/// </summary>
	float get_cost() override { return part::get_cost(); }

};

/// <summary>
/// ����� �����
/// </summary>
class chassis : virtual protected part
{
private:

	cs::chas_type tp = cs::non; //��� ����� (�������)
	

	/// <summary>
	/// ������ ����������� ��������
	/// </summary>
	void set_speed_mod(float sf) override
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

	///�������� ��� �����
	std::string get_string() const override
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

public:

	///�����������
	chassis(
		cs::chas_type CT = cs::non,
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
	) : part(corparation, part_mass, cost)
	{
		factor f(corparation, type, specialization, cabin, extensions, weapon);

		tp = CT;
		float m = f.get_part_mass_fac();
		float c = f.get_cost_fac();
		set_speed_mod(f.get_speed_fac());

		set_mass(2500 * m);
		set_cost(3100 * c);
	}

	chassis() {}

	///�������� ������ � �������
	std::string to_string() override
	{
		float m = get_mass();
		float c = get_cost();

		return std::to_string(m) + " " + std::to_string(c) + " " + std::to_string(get_speed_mod()) + " " + get_std_string() + " " + get_string();
	}

	///�������� ������������ ��������
	float get_speed_mod() override { return max_speed_mod; }
	float get_mass() override { return part::get_mass(); }
	float get_cost() override { return part::get_cost(); }

};

///����� ������
class weapon : virtual protected part
{
private:

	wp twv = cs::non_arm;

	///�������� ��� ������
	std::string get_string() const
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

	void set_speed_mod(float sf) override { max_speed_mod = sf; }

public:

	weapon(pvsc prt_std, wp weap_) : part(prt_std, 400, 2900) 
	{
		twv = weap_;

		factor f(prt_std, cs::no_name, cs::no_exs, cs::NN, cs::none_ext,weap_);

		float m = f.get_part_mass_fac();
		float c = f.get_cost_fac();
		set_speed_mod(f.get_speed_fac());

		set_mass(get_mass() * m);
		set_cost(get_cost() * c);
	}

	weapon() {}

	std::string to_string() override
	{
		float m = get_mass();
		float c = get_cost();

		return std::to_string(m) + " " + std::to_string(c) + " " + get_std_string() + " " + get_string();
	}

	float get_mass() override { return part::get_mass(); }
	float get_cost() override { return part::get_cost(); }

};

class extra_modules : virtual protected part
{
private:

	sve _ext = cs::none_ext;

	std::string get_string() const
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

	void set_speed_mod(float sf) override { max_speed_mod = sf; }

public:

	extra_modules(pvsc prt_std, sve ext_) : part(prt_std, 700, 350) 
	{
		_ext = ext_;

		factor f(prt_std, cs::no_name, cs::no_exs, cs::NN, ext_, cs::non_arm);

		float m = f.get_part_mass_fac();
		float c = f.get_cost_fac();
		set_speed_mod(f.get_speed_fac());

		set_mass(get_mass() * m);
		set_cost(get_cost() * c);
	}

	extra_modules() {}

	std::string to_string() override
	{
		float m = get_mass();
		float c = get_cost();

		return std::to_string(m) + " " + std::to_string(c) + " " + get_std_string() + " " + get_string();
	}

	float get_mass() override { return part::get_mass(); }
	float get_cost() override { return part::get_cost(); }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// � � � � �  � � � � � � � � � � //////////////////////////////////////

class vechicle
{
protected: //�����?

	pvsc vech_standart = cs::abs_std;
	svt vech_type = cs::no_name;
	svs vech_spec = cs::no_exs;

	float vech_mass = 0;
	float speed = 0;
	svt type = cs::no_name;
	float cost = 0;

private:

	float standart_cost_factor = 1.45; //������������� ���������

	cabin* CAB__;
	engine* ENG__;
	chassis* CHA__;
	weapon* WPN__;
	extra_modules* XMD__;

public:

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
	)
	{
		vech_standart = corparation;
		vech_type = type;
		vech_spec = specialization;

		cabin CAB (corparation, type, specialization, cabin_, extensions, weapon_);
		engine ENG (et, corparation, type, specialization, cabin_, extensions, weapon_);
		chassis CHA(ct, corparation, type, specialization, cabin_, extensions, weapon_);
		weapon WPN (corparation, weapon_);
		extra_modules XMD(corparation, extensions);

		/*CAB__ = &CAB;
		ENG__ = &ENG;
		CHA__ = &CHA; ��, ��� ��� ���������, ������� ������������ ��������� ������
		WPN__ = &WPN;
		XMD__ = &XMD;*/ 

		factor K(corparation, type, specialization, cabin_, extensions, weapon_);
		/*vech_standart = convertCompToPvsc(corp);*/
		vech_mass = K.get_vech_mass_fac() * (CAB.get_mass() + ENG.get_mass() + CHA.get_mass() + WPN.get_mass() + XMD.get_mass());
		speed = K.get_speed_fac() * (CAB.get_speed_mod() * ENG.get_speed_mod() * CHA.get_speed_mod());
		cost = standart_cost_factor * K.get_cost_fac() * (CAB.get_cost() + ENG.get_cost() + CHA.get_cost() + WPN.get_cost() + XMD.get_cost());
	}

	vechicle()
	{}


	//����� ��������� ����������� ��� �������� ������� �������
	//����� ���������

	virtual std::string get_long_description()
	{
		std::string temp = "";
		std::string ext = "";

		ext = "_______Description_______";
		ext += "\n\n";
		ext += "Mass: " + std::to_string(vech_mass) + "\n";
		ext += "Speed: " + std::to_string(speed) + "\n" + "\n";
		ext += "Cost: " + std::to_string(cost) + "\n" + "\n" + "\n";

		//ext += CAB__->to_string() + '\n';
		//ext += ENG__->to_string() + '\n';
		//ext += CHA__->to_string() + '\n';
		//ext += WPN__->to_string() + '\n';
		//ext += XMD__->to_string() + '\n';

		/*
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
		*/

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
};