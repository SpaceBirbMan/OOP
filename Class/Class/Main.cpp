#include <iostream>
#include <string>
#include "LRS.h"

using namespace std;

int main()
{
	//проверка работоспособности
	string name = "Ffehwuh";
	LRS B[3]; //массив из объектов
	B[1].set_name(name);
	cout << B[0].get_name() << endl;
	B[3].switch_stat();
	cout << B[1].to_string() << endl;
	B[2].set_rad(3);
	cout << B[2].get_rad() << endl;
	for (int i = 0; i < 3; i++) { cout << B[i].get_rad() << endl << endl; }
	LRS A; //инициализация
	cout << A.to_string() << endl; //вывод всего
	A.set_info(name); //изменения поля с инфой
	cout << A.to_string() << endl; //вывод всего
	cout << A.get_info() << endl; //вывод только инфы
	A.set_loc(2, 3); //задание координат станции прямым способом
	cout << A.get_locs() << endl; //вывод координат
	cout << '\n';
	A.switch_stat(); //переключатель статуса вещания
	cout << A.to_string() << endl; //вывод всего
}
