//Auth: Sosnov K A CMC-22
#pragma once
#include <string>


using namespace std;

///����� ������������ ������������
class LRS
{
private:
	string sname = ""; //��������
	float sfrequency = 0.0; //������� �������
	string sdescription = ""; //��������
	bool sonline_status = false; //������ �������
	float scov_radius = 0.0; //������ �������� ���������� ��� �������
	float* slocation = new float[2]; //���������� �������

public:
	LRS(string nm = "Untitled", float freq = 0.0, float rad = 1.0, float* loc = nullptr); //�����������

	//������� ��� ����������
	void set_name(string& nm); //������ ��������
	void set_freq(float fr); //������ ������� �������
	void set_desc(string& inf); //������ ��������
	void set_stat(bool s); //������ ������ �������
	void set_rad(float r); //������ ������ ��������
	void set_loc(float* l); //��������� ������� ��������� (������� �� ������)
	void set_loc(float x, float y);//������ ������� (������������ �� ���������)
	//������� ��� ����������
	string get_name() const; //�������� ��������
	float get_freq() const; //�������� ������� �������
	string get_desc() const; //�������� ��������
	bool get_stat() const; //�������� ������ �������
	float get_rad() const; //�������� ������ �������
	float* get_loc() const; //�������� ���������� ��������
	string get_locs() const; //�������� ���������� �������

	void switch_stat(); //������������ ������� �������
	string to_string() const; //������� � ������ ��� ����������

	~LRS(); //����������
};