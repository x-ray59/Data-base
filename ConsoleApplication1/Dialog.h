// �������� ������ Dialog (������)
#pragma once
#include "Event.h"
#include "Data_base.h"
class Dialog : 
	// ��������� ������� ������ ���� ������
	public Data_base
{
public:
	// ����������� ��� ����������
	Dialog();
	// ����������
	~Dialog();
	// �������� ������
	void Get_help();
	// �������� �������
	void GetEvent(TEvent&);
	// ������� ���� ��������� �������
	int Execute();
	// ����������
	void HandleEvent(TEvent&);
	// �������� �������
	void ClearEvent(TEvent&);
	// �������� �������� EndState
	int Valid();
	// ��������� ������� ������ �������
	void EndExec();
protected:
	// �������� ��������� (�������� �� ����� �� ������� ��� ����������� ������ � ��������)
	int EndState;
};