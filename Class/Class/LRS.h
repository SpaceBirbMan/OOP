//Auth: Sosnov K A CMC-22
#pragma once
#include <string>


using namespace std;

///класс региональной радиостанции
class LRS
{
private:
	string sname = ""; //название
	float sfrequency = 0.0; //частота вещания
	string sdescription = ""; //описание
	bool sonline_status = false; //статус вещания
	float scov_radius = 0.0; //радиус покрытия территории для вещания
	float* slocation = new float[2]; //координаты станции

public:
	LRS(string nm = "Untitled", float freq = 0.0, float rad = 1.0, float* loc = nullptr); //конструктор

	//сеттеры для параметров
	void set_name(string& nm); //задать название
	void set_freq(float fr); //задать частоту вещания
	void set_desc(string& inf); //задать описание
	void set_stat(bool s); //задать статус вещания
	void set_rad(float r); //задать радиус покрытия
	void set_loc(float* l); //косвенное задание координат (ссылкой на массив)
	void set_loc(float x, float y);//прямое задание (координатами на плоскости)
	//геттеры для параметров
	string get_name() const; //получить название
	float get_freq() const; //получить частоту вещания
	string get_desc() const; //получить описание
	bool get_stat() const; //получить статус вещания
	float get_rad() const; //получить радиус вещания
	float* get_loc() const; //получить координаты массивом
	string get_locs() const; //получить координаты строкой

	void switch_stat(); //переключение статуса вещания
	string to_string() const; //вывести в строку всю информацию

	~LRS(); //деструктор
};