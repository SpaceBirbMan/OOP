//Auth: Sosnov K A CMC-22
#pragma once
#include <string>
///класс региональной радиостанции

using namespace std;

class LRS 
{
private:
	string sname = ""; //название
	float sfrequency = 0.0; //частота вещани€
	string sinfo = ""; //обща€ информаци€
	bool sonline_status = false; //статус вещани€
	float scov_radius = 0.0; //радиус покрыти€ территории дл€ вещани€
	float* slocation = new float[2]; //координаты станции

public:
	LRS(string nm = "Untitled", float freq = 0.0, float rad = 1.0, float* loc = nullptr); //конструктор

	//сеттеры дл€ параметров


	void set_name(string& nm);
	void set_freq(float fr);
	void set_info(string& inf);
	void set_stat(bool s);
	void set_rad(float r);
	void set_loc(float* l); //косвенное задание
	void set_loc(float x, float y);//пр€мое задание
	//геттеры дл€ параметров
	string get_name() const;
	float get_freq() const;
	string get_info() const;
	bool get_stat() const;
	float get_rad() const;
	float* get_loc() const;
	string get_locs() const;

	void switch_stat(); //переключение статуса вещани€
	string to_string() const; //вывести в строку всю информацию

	~LRS();
};