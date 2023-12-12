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

	enum standart_vech_name //(name -> type)
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

 
///  ����� � �������� ������� ���������� ����, �������� � ���������
 
class factor
{
private:

	 
	/// ������� ����������
	 
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

	 
	/// ������ �������� ��������-�������������
	void set_corp(pvsc corparation) { _corp = corparation; }

	 
	/// ������ ��� ����������
	void set_vech_type(svt type) { _vech = type; }

	 
	/// ������ ���������� �������
	void set_vech_spec(svs specialization) { _spec = specialization; }

	 
	/// ������ ����-������ ������
	void set_cab_fac(scff cabin) { _cab = cabin; }

	 
	/// ������ ���������� ��� ����������
	void set_extens(sve extensions) { _ext = extensions; }


	/// ������ ����������
	void set_weapons(wp weapon) { _arm = weapon; }


	 
	/// ��������� ���������
	void get_factor();

public:

	 
	/// ����������� ���������
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
		 
		/// ������� ����������
		 
		set_corp(corparation);  
		set_vech_type(type);
		set_vech_spec(specialization);
		set_cab_fac(cabin);
		set_extens(extensions);
		set_weapons(weapon);

		 
		/// ������
		 
		get_factor(); 
	}

	 
	/// �������� ��������� ����� ������ 
	float  get_part_mass_fac() const { return _part_mass_fac; }

	 
	/// �������� ��������� ����� ���������� 
	float  get_vech_mass_fac() const { return _vech_mass_fac; }

	 
	/// �������� ��������� ��������� 
	float  get_cost_fac() const { return _cost_fac; }

	 
	/// �������� ��������� �������� 
	float  get_speed_fac() const { return _speed_fac; }
};

///////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////// � � � � � �  � � � � � � � //////////////////////////////////////

 
/// ���������� ������
 
class part
{
protected:
	pvsc part_standart = cs::abs_std;
	float part_mass = 0;
	float cost = 0;
	float max_speed_mod = 1;

	 
	/// ������� �����
	 
	virtual float get_mass() { return part_mass; }

	 
	/// �������� ���������
	 
	virtual float get_cost() { return cost; }

	 
	/// �������� ����������� ��������
	 
	virtual float get_speed_mod() { return max_speed_mod; }

	 
	/// �������� ��������������� ��������
	 
	virtual pvsc get_part_standart() { return part_standart; }

	 
	/// ������ ��������������� ��������
	 
	virtual void set_part_standart(pvsc std) { part_standart = std; }

	 
	/// ������ �����
	 
	virtual void set_mass(float m) { part_mass = m; }

	 
	/// ������ ���������
	 
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

	 
	///  ������ ���������� ��������� ������ � ������
	 
	
	virtual std::string get_string() const = 0;

	/// ��������� ������ ��������� �������
	virtual std::string get_std_string() const;
};

///����� ������
class cabin : virtual protected part
{
private:
	scff cab_fac = cs::NN; //����-������ ������

	///������ ����������� ��������
	void set_speed_mod(float sf) override { max_speed_mod = sf; }

	///�������� ������ � ����-������� �������
	std::string get_string() const override;

public:

	///�����������
	cabin(
		pvsc corparation = cs::abs_std,
		svt type = cs::no_name,
		svs specialization = cs::no_exs,
		scff cabin = cs::NN,
		sve extensions = cs::none_ext,
		wp weapon = cs::non_arm
	);

	 
	/// ������ ���� ������ � ������
	std::string to_string();

	cabin() {}

	 
	/// �������� ����������� ��������
	 
	float get_speed_mod() override { return max_speed_mod; }

	 
	/// �������� �����
	 
	float get_mass() override { return part::get_mass(); } 

	///�������� ���������
	float get_cost() override { return part::get_cost(); }

	pvsc get_part_standart() override { return part::get_part_standart(); }

	scff get_FF() { return cab_fac; }

};

///����� ���������
class engine: virtual protected part
{
private:

	cs::engine_type et; //��� ��������� (�������)


	///������ ����������� ��������
	void set_speed_mod(float sf) override;

	 
	/// �������� ������ ���� ���������
	 
	std::string get_string() const override;

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
	);

	engine() {}

	 
	/// ������ � ������
	std::string to_string() override;

	 
	/// �������� ����������� �������� 
	float get_speed_mod() override { return max_speed_mod; }

	 
	/// �������� �����
	float get_mass() override { return part::get_mass(); }

	 
	/// �������� ���������
	float get_cost() override { return part::get_cost(); }

};

 
/// ����� �����
class chassis : virtual protected part
{
private:

	cs::chas_type tp = cs::non; //��� ����� (�������)
	

	 
	/// ������ ����������� ��������
	void set_speed_mod(float sf) override;

	///�������� ��� �����
	std::string get_string() const override;

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
	);

	chassis() {}

	///�������� ������ � �������
	std::string to_string() override;

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

///����� ���������
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

	float standart_cost_factor = 1.0646712346443756; //������������� ���������

	cabin* CAB;
	engine* ENG;
	chassis* CHA;
	weapon* WPN;
	extra_modules* XMD;
	factor* KP;

	//������� (���������)(������ �� ��� � ��������� ����������) [����� �����-������]

	///������ ������������� ����������
	void data_calc();

public:

	///������������ �����������
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

	 
	/// ������ �����������
	vechicle()
	{}

	 
	/// �����������-������� 
	vechicle(cabin* cab, engine* eng, chassis* chas, weapon* weap, extra_modules* em,  svt vtp = cs::no_name, svs vs = cs::no_exs);

	virtual std::string get_long_description();

	virtual std::string get_short_description();

	~vechicle();
};