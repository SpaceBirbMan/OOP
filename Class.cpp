#include <iostream>
#include <string>
#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\Matrix.h"

using namespace std;

int main()
{
	class LRS
	{
	private:
		string sname = "";
		float sfrequency = 0.0;
		string sinfo = "";
		bool sonline_status = false;
		float scov_radius = 0.0;
		matrix slocation;
		
	public:
		LRS(string nm = "Untitled", float freq = 0.0, float rad = 1.0, matrix loc = (0, 0))
		{
			sname = nm;
			sfrequency = freq;
			scov_radius = rad;
			slocation = loc;
		}
		void set_name(string nm) { sname = nm; }
		void set_freq(float fr) { sfrequency = fr; }
		void set_info(string inf) { sinfo = inf; }
		void set_stat(bool s) { sonline_status = s; }
		void set_rad(float r) { scov_radius = r; }
		void set_loc(matrix l) { slocation = l; }

		string get_name() { return sname; }
		float get_freq() { return sfrequency; }
		string get_info() { return sinfo; }
		bool get_stat() { return sonline_status; }
		float get_rad() { return scov_radius; }
		matrix get_loc() { return slocation; }

		void switch_stat() 
		{ 
			if (sonline_status) 
				sonline_status = false; 
			else 
				sonline_status = true; 
		}
		string get_all_info() 
		{
			string stat, loc = "";
			if (sonline_status) stat = "Online";
			else stat = "Offline";
		
			return 
				sname + '\n'
				+ to_string(sfrequency) + '\n'
				+ sinfo + '\n'
				+ stat + '\n'
				+ to_string(scov_radius) + '\n'
				+ tos(slocation) + '\n';
		}
		
		~LRS();
	};
}
