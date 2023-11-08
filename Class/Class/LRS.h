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
	//конструктор
	LRS(string nm = "Untitled", float freq = 0.0, float rad = 1.0, float* loc = nullptr); 

	//сеттеры для параметров
	//задать название
	void set_name(const string& nm); 
	//задать частоту вещания
	void set_freq(float fr);
	//задать описание
	void set_desc(const string& inf); 
	//задать статус вещания
	void set_stat(bool s); 
	//задать радиус покрытия
	void set_rad(float r); 
	//косвенное задание координат (ссылкой на массив)
	void set_loc(float* l); 
	//прямое задание (координатами на плоскости)
	void set_loc(float x, float y);
	//геттеры для параметров
	//получить название //const не меняет поля класса, вызывается для объекта константы
	string get_name() const; 
	//получить частоту вещания
	float get_freq() const; 
	//получить описание
	string get_desc() const; 
	//получить статус вещания
	bool get_stat() const; 
	//получить радиус вещания
	float get_rad() const; 
	//получить координаты массивом
	float* get_loc() const; 
	//получить координаты строкой
	string get_locs() const; 

	//переключение статуса вещания
	void switch_stat(); 
	//вывести в строку всю информацию
	string to_string() const; 
	//строка в класс
	void in_class(const string& ins); 

	//деструктор
	~LRS(); 
};