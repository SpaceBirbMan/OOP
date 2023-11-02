#include <iostream>
#include <string>

using namespace std;

int main()
{
	class LRS //класс региональной радиостанции
	{
	private:
		string sname = ""; //название
		float sfrequency = 0.0; //частота вещания
		string sinfo = ""; //общая информация
		bool sonline_status = false; //статус вещания
		float scov_radius = 0.0; //радиус покрытия территории для вещания
		float* slocation = new float[2]; //координаты станции
		
	public:
		LRS(string nm = "Untitled", float freq = 0.0, float rad = 1.0, float* loc = nullptr) //конструктор
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
		void set_name(string nm) { sname = nm; }
		void set_freq(float fr) { sfrequency = fr; }
		void set_info(string inf) { sinfo = inf; }
		void set_stat(bool s) { sonline_status = s; }
		void set_rad(float r) { scov_radius = r; }
		void set_loc(float* l) { slocation = l; } //косвенное задание
		void set_loc(float x, float y) { slocation[0] = x; slocation[1] = y; } //прямое задание
		//геттеры для параметров
		string get_name() { return sname; }
		float get_freq() { return sfrequency; }
		string get_info() { return sinfo; }
		bool get_stat() { return sonline_status; }
		float get_rad() { return scov_radius; }
		float* get_loc() { return slocation; }
		string get_locs() { return to_string(slocation[0]) + ' ' + to_string(slocation[1]); }

		void switch_stat() //переключение статуса вещания
		{ 
			if (sonline_status) 
				sonline_status = false; 
			else 
				sonline_status = true; 
		}
		string get_all_info() //вывести в строку всю информацию
		{
			string stat = "";
			if (sonline_status) stat = "Online";
			else stat = "Offline";
		
			return 
				sname + '\n'
				+ to_string(sfrequency) + '\n'
				+ sinfo + '\n'
				+ stat + '\n'
				+ to_string(scov_radius) + '\n'
				+ to_string(slocation[0]) + ' ' + to_string(slocation[1]) + '\n';
		}
		
		~LRS() {} //деструктор
	};

	//проверка работоспособности

	LRS A; //инициализация
	cout << A.get_all_info() << endl; //вывод всего
	A.set_info("ABCDEFG"); //изменения поля с инфой
	cout << A.get_all_info() << endl; //вывод всего
	cout << A.get_info() << endl; //вывод только инфы
	A.set_loc(2, 3); //задание координат станции прямым способом
	cout << A.get_locs() << endl; //вывод координат
	cout << '\n';
	A.switch_stat(); //переключатель статуса вещания
	cout << A.get_all_info() << endl; //вывод всего
}
