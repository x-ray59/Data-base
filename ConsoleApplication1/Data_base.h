#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

// ��������� ����
struct Node
{
	// ����������� � �����������
	Node(const int&, const double&, Node* = nullptr, Node* = nullptr);
	int key;		// ����
	double value;	// �������������� ���� ������
	Node *previous;	// ���������� ����� ����
	Node *next;		// ��������� ����� ����
};

// ����� ���� ������
class Data_base
{
public:
	// ����������� �� ���������
	Data_base();
	// ����������
	~Data_base();
	// �������� ���� ������
	void �reate_list(const int&, const double&);
	// �������� �������� �� �������� �������
	void Add();
	// ������ ������ �������� ��� ������������� 
	void Cor_Del(const char&);
	// �������������� ���� ������
	void Correct();
	// �������� �������� �� ��
	void Delete();
	// ������� ��������� ��������� ������
	void Cancel();
	// ����������� ���� ������
	void Show();
	// ���������� ����� ������ � �������� ��� ������
	void Temp_max_min();
	// ���������� ������� ����������� ������ ������
	void Av_temp();
	// ������� ������ �� �����
	void Read_file();
	// �������� ������ � ����
	void Write_file();
protected:
	Node *first;	// ������ ���� ������
	Node *last;		// ��������� ���� ������
	Node *temp;		// ��������� ��������� ����
	vector<Node*> cancel; // ������, �������� ��������� �� ��������� �������
};