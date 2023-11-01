#include <iostream>
#include <string>
#include "LRS.h"
#include <cassert>

using namespace std;



int main()
{
	//�������� �����������������
	string name = "Ffehwuh";
	LRS* B = new LRS[3]; //������ �� ��������

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
	LRS A; //�������������
	cout << A.to_string() << endl; //����� �����
	A.set_desc(name); //��������� ���� � �����
	cout << A.to_string() << endl; //����� �����
	cout << A.get_desc() << endl; //����� ������ ����
	A.set_loc(2, 3); //������� ��������� ������� ������ ��������
	cout << A.get_locs() << endl; //����� ���������
	cout << '\n';
	A.switch_stat(); //������������� ������� �������
	cout << A.to_string() << endl; //����� �����

}
