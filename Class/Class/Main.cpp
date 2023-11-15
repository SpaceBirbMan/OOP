#include <iostream>
#include <string>
#include "LRS.h"
#include <cassert>
#include <fstream>
#include "C:\Users\kiril\OneDrive\Рабочий стол\FINAL_COUNTDOWN\FINAL_COUNTDOWN\matrx.h"


using namespace std;


int main()
{

	//проверка работоспособности
	string name = "Ffehwuh";

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
		assert(Test.get_desc() == "");
		assert(Test.get_name() == "Untitled");
		assert(Test.get_loc() != nullptr);
		assert(Test.get_stat() == false);
		assert(Test.get_locs() == "0.000000 0.000000");

		string test_inf = "";
		Test.set_desc("test_desc");
		Test.set_freq(2.4);
		Test.set_loc(5, 4);
		Test.set_name("test_name");
		Test.set_rad(150.0);
		Test.set_stat(false);
		Test.switch_stat();
		
		string tn = "test_name"; //костыль, без которого кусок строки просто не запишется

		test_inf = tn + '\n'
			+ to_string(2.400000) + '\n'
			+ "test_desc" + '\n'
			+ "Online" + '\n'
			+ to_string(150.000000) + '\n'
			+ to_string(5.000000) + ' ' + to_string(4.000000) + '\n';

		cout << Test.to_string() << endl;
		cout << test_inf;
		assert(Test.to_string() == test_inf);

		test_inf = tn + '\n'
			+ to_string(9.000000) + '\n'
			+ "test_desc" + '\n'
			+ "Online" + '\n'
			+ to_string(158.000000) + '\n'
			+ to_string(50.000000) + ' ' + to_string(40.000000) + '\n';
	
		Test.in_class(test_inf);
		assert(Test.to_string() == test_inf);
	}

	LRS* G = new LRS; //динамический объект
	float* Coords = new float[2] {0, 1}; //массив из координат
	G->set_loc(Coords);
	cout << "G:" << G->get_locs() << endl;
	string desc = "void string_to_file(string inp);";
	G->set_desc(desc);
	cout << G->get_desc() << endl;
	delete G;

	LRS* D_Arr = new LRS[129]; //динамический массив с динамическими объектами (сразу создаётся 129 объектов)

	cout << endl;

	for (int i = 0; i < 129; i++)
	{
		cout << D_Arr[i].get_stat() << endl;
		D_Arr[i].~LRS(); //деинициализация объекта
	}
	
	cout << endl;
	
	//массив из указателей на дин.объекты
	LRS** DArr_DObj = new LRS*[129]; //это просто массив из указателей на тип

	for (int i = 0; i < 129; i++)
	{
		DArr_DObj[i] = new LRS(); //соответственно надо вызывать конструкторы отдельно
		DArr_DObj[i]->set_desc(to_string(i));
		cout << "darr_dobj.lrs->" << DArr_DObj[i]->get_desc() << endl;
		DArr_DObj[i]->~LRS(); //деинициализация объекта
	}

	delete[] D_Arr; //очищение памяти от массива
	delete[] DArr_DObj; //очищение памяти от массива

	LRS* B = new LRS[3]; //массив из объектов
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

	ifstream fromf;
	ofstream inf;

	A.set_desc("This message will be in next class");

	inf.open("class_obj_example.txt"); //в файл
	if (inf.is_open())
	{
		inf << A.to_string();
	}
	inf.close();

	LRS FC;
	cout << "before: \n" << FC.to_string() << endl;


	string line = "";
	fromf.open("class_obj_example.txt"); //из файла
	if (fromf.is_open())
	{
		
		string fstr = "";
		while (getline(fromf, line))
		{
			fstr = fstr + line + '\n';
		}
		FC.in_class(fstr);
	}

	cout << "after: \n" << FC.to_string(); 
}

