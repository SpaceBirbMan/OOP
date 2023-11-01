#include <iostream>
#include <string>
#include "LRS.h"
#include <cassert>

using namespace std;



int main()
{
	//проверка работоспособности
	string name = "Ffehwuh";
	LRS* B = new LRS[3]; //массив из объектов

	{
		LRS Test;
		Test.set_rad(-2);
		Test.set_freq(-2);
		assert(Test.get_rad() == 1.0);
		assert(Test.get_freq() == 0.0);
		Test.set_rad(0);
		Test.set_freq(0);
		assert(Test.get_rad() == 0.0);
		assert(Test.get_freq() == 0.0);
	}


	B[1].set_name(name);
	cout << B[0].get_name() << endl;
	B[3].switch_stat();
	cout << B[1].to_string() << endl;
	B[2].set_rad(3);
	cout << B[2].get_rad() << endl;
	for (int i = 0; i < 3; i++) { cout << B[i].get_rad() << endl << endl; }
	LRS A; //инициализация
	cout << A.to_string() << endl; //вывод всего
	A.set_desc(name); //изменения поля с инфой
	cout << A.to_string() << endl; //вывод всего
	cout << A.get_desc() << endl; //вывод только инфы
	A.set_loc(2, 3); //задание координат станции прямым способом
	cout << A.get_locs() << endl; //вывод координат
	cout << '\n';
	A.switch_stat(); //переключатель статуса вещания
	cout << A.to_string() << endl; //вывод всего

}
