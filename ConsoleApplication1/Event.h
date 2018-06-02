// �������� ������ Event (�������)
#pragma once

// ����� �������
constexpr int evNothing = 0;	// ������ �������
constexpr int evMessage = 100;	// �������� �������
constexpr int quit = 101;		// ����� 'q'
constexpr int help = 102;		// ����� �������� ���� '?'
constexpr int r_file = 103;		// ������ ����� 'r'
constexpr int w_file = 104;		// ������ � ���� 'w'
constexpr int add = 105;		// �������� �������� � ���� ������ '+'
constexpr int del = 106;		// ������� �������� �� ���� ������ '-'
constexpr int back = 107;		// �������� ��������� �������� 'b'
constexpr int cor = 108;		// �������������� ���� ������ 'c'
constexpr int show = 109;		// ����������� ���� ������ 's'

// ������� �����������
constexpr int temperature = 110;// ������� ������ ������� �����������
constexpr int temp_max_min = 1;	// ���������� ����� ������ ���� ������ 'm1'
constexpr int av_temp = 2;		// ���������� ������� ����������� ������ ������ 'm2'

// ����� �������
struct TEvent
{
	int what;	// ��� �������
	int a;		// �������� �������
	// union ���������� command � message, �� ���� ��� ���������� ���� ������� ������.
	// ��� ��������� �������� command �������� message, � ��������
	union
	{
		int command; // ��� �������
		int message; // ���������
	};
};