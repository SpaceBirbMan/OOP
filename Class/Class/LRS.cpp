//Auth: Sosnov K A CMC-22
#include <iostream>
#include <string>
#include "LRS.h"

using namespace std;

LRS::LRS(string nm, float freq, float rad, float* loc) //конструктор
{
	sname = nm;
	sfrequency = freq;
	scov_radius = rad;

	if (loc == nullptr)
	{
		slocation[0] = 0.0;
		slocation[1] = 0.0;
	}
	else
	{
		slocation[0] = loc[0];
		slocation[1] = loc[1];
	}
}
//сеттеры для параметров
void LRS::set_name(string& nm) { sname = nm; }
void LRS::set_freq(float fr) { fr >= 0 ? sfrequency = fr : sfrequency; }
void LRS::set_desc(string& inf) { sdescription = inf; }
void LRS::set_stat(bool s) { sonline_status = s; }
void LRS::set_rad(float r) { r >= 0 ? scov_radius = r : scov_radius; }
void LRS::set_loc(float* l) { slocation = l; } //косвенное задание
void LRS::set_loc(float x, float y) { slocation[0] = x; slocation[1] = y; } //прямое задание
//геттеры для параметров
string LRS::get_name() const { return sname; }
float LRS::get_freq() const { return sfrequency; }
string LRS::get_desc() const { return sdescription; }
bool LRS::get_stat() const { return sonline_status; }
float LRS::get_rad() const { return scov_radius; }
float* LRS::get_loc() const { return slocation; }
string LRS::get_locs() const { return std::to_string(slocation[0]) + ' ' + std::to_string(slocation[1]); }

void LRS::switch_stat() //переключение статуса вещания
{
	sonline_status = !sonline_status;
}
string LRS::to_string() const //вывести в строку всю информацию
{

	string stat = "";
	if (sonline_status) stat = "Online";
	else stat = "Offline";
	string res = sname + '\n'
		+ std::to_string(sfrequency) + '\n'
		+ sdescription + '\n'
		+ stat + '\n'
		+ std::to_string(scov_radius) + '\n'
		+ std::to_string(slocation[0]) + ' ' + std::to_string(slocation[1]) + '\n';
	return res;
		
}

LRS:: ~LRS() {}

