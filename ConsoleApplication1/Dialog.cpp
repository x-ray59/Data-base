// ����������� ������� ������ Dialog
#include "stdafx.h"
#include "Dialog.h"

// �����������
Dialog::Dialog()
{
	EndState = 0;
}

// ����������
Dialog::~Dialog()
{
}

// �������
void Dialog::Get_help()
{
	cout << endl;
	cout << 'r' << "\t" << "������� ������ � ������� ����������� �� �����.\n";
	cout << 'w' << "\t" << "��������� ������ � ������� ����������� � �����.\n";
	cout << '+' << "\t" << "�������� ������ � ������� ����������� �� �������� �������.\n";
	cout << '-' << "\t" << "������� ������ � ������� ����������� �� �����.\n";
	cout << 'b' << "\t" << "�������� ��������� �������� ��������.\n";
	cout << 'c' << "\t" << "�������������� ������ � ������� ����������� �� �����.\n";
	cout << 's' << "\t" << "����������� ������ � ������� ����������� �� �����.\n";
	cout << "m1" << "\t" << "���������� ����� ������ � �������� ��� ������.\n";
	cout << "m2" << "\t" << "���������� ������� ����������� ������ ������.\n";
	cout << 'q' << "\t" << "�����.\n";
}

// ��������� �������
void Dialog::GetEvent(TEvent &event)
{
	string menu = "?rw+-bcsmq";
	string s;
	string param;
	char code;
	cout << "\n>";
	// ��������� ������� ������� �������
	cin >> s; code = s[0]; 
	// �������� �� ������ ����� �������� 
	if (menu.find(code) < 10)	
	{
		// ���������� ������� ������� ���������
		event.what = evMessage;	
		// ����� ��������� ��������
		switch (code) 
		{
		// ������������ �������� ����� ��������
		case '?': event.command = help; break;
		case 'r': event.command = r_file; break;
		case 'w': event.command = w_file; break;
		case '+': event.command = add; break;
		case '-': event.command = del; break;
		case 'b': event.command = back; break;
		case 'c': event.command = cor; break;
		case 's': event.command = show; break;
		case 'm': event.command = temperature; break;
		case 'q': event.command = quit; break;
		}
		if (s.length()>1)
		{
			param = s.substr(1, s.length() - 1);
			// ����������� �������� � �����
			int A = atoi(param.c_str()); 
			// ���������� � ���������
			event.a = A; 
		}
	}
	// ���������� ������� ������� �������
	else
	{
		event.what = evNothing;
		cout << "\n������� �� �������! ����� ������� ������ ������ ������� '?'.\n";
	}
}

// ������� ���� ��������� �������
int Dialog::Execute()
{
	TEvent event;
	do {
		ClearEvent(event);	// ������� ���������� �������
		GetEvent(event);	// �������� ����� �������
		HandleEvent(event); // ������������ ���������� �������
	} while (!Valid());		// �������� �� �����
	return EndState;
}

// �������� ������ �� �������
int Dialog::Valid()
{
	// ���� �����, �� EndState == 1
	if (EndState == 0) return 0;
	else return 1;
}

// �������� �������
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;		// ������ �������
	event.command = evNothing;	// ������ �������
	event.a = evNothing;		// ������ �������� �
}

// ����� ���������� �������, �����
void Dialog::EndExec() 
{
	EndState = 1;
}

// ���������� �������
void Dialog::HandleEvent(TEvent& event)
{

	if (event.what == evMessage) // �������� �� �������� �������
	{

		switch (event.command) // ��� �������
		{
		case help:		// ����� �������
			Get_help();
			break;
		case r_file:	// ������ �����
			Read_file();
			break;
		case w_file:	// ������ � ����
			Write_file();
			break;
		case add:		// �������� �������� � ���� ������
			Add();
			break;
		case del:		// ������� �������� �� ���� ������
			Cor_Del('d');
			break;
		case back:		// �������� ��������� ��������
			Cancel();
			break;
		case cor:		// �������������� ���� ������
			Cor_Del('c');
			break;
		case show:		// ����������� ���� ������
			Show();
			break;
		case temperature:
			switch (event.a)
			{
			case temp_max_min:	// ���������� ����� ������ � �������� ��� ������
				Temp_max_min();
				break;
			case av_temp:		// ���������� ������� ����������� ������ ������
				Av_temp();
				break;
			default:
				break;
			}
			break;
		case quit:		// ����� � main
			// ���� �� ������� ������ �� �����
			if (first)
			{
				cout << "\n��������� ���������? y/n\n";
				cout << "\n>"; char n; cin >> n;
				if (n == 'y')
				{
					Write_file();	// ������ � ����
				}
			}
			EndExec();
			break;
		default:
			break;
		};
	};
}