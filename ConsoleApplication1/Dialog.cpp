// Определение методов класса Dialog
#include "stdafx.h"
#include "Dialog.h"

// Конструктор
Dialog::Dialog()
{
	EndState = 0;
}

// Деструктор
Dialog::~Dialog()
{
}

// Справка
void Dialog::Get_help()
{
	cout << endl;
	cout << 'r' << "\t" << "Считать данные о средней температуре из файла.\n";
	cout << 'w' << "\t" << "Сохранить данные о средней температуре в файле.\n";
	cout << '+' << "\t" << "Добавить данные о средней температуре на заданную позицию.\n";
	cout << '-' << "\t" << "Удалить данные о средней температуре за месяц.\n";
	cout << 'b' << "\t" << "Отменить последнюю операцию удаления.\n";
	cout << 'c' << "\t" << "Корректировать данные о средней температуре за месяц.\n";
	cout << 's' << "\t" << "Просмотреть данные о средней температуре за месяц.\n";
	cout << "m1" << "\t" << "Определить самый теплый и холодные дни месяца.\n";
	cout << "m2" << "\t" << "Определить среднюю температуру каждой недели.\n";
	cout << 'q' << "\t" << "Выход.\n";
}

// Получение события
void Dialog::GetEvent(TEvent &event)
{
	string menu = "?rw+-bcsmq";
	string s;
	string param;
	char code;
	cout << "\n>";
	// Получение первого символа команды
	cin >> s; code = s[0]; 
	// Является ли символ кодом операции 
	if (menu.find(code) < 10)	
	{
		// Присвоение событию статуса непустого
		event.what = evMessage;	
		// Поиск введенной операции
		switch (code) 
		{
		// Присваивание командам кодов операций
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
			// Преобразуем параметр в число
			int A = atoi(param.c_str()); 
			// Записываем в сообщение
			event.a = A; 
		}
	}
	// Присвоение событию статуса пустого
	else
	{
		event.what = evNothing;
		cout << "\nКоманда не найдена! Чтобы увидеть список команд нажмите '?'.\n";
	}
}

// Главный цикл обработки событий
int Dialog::Execute()
{
	TEvent event;
	do {
		ClearEvent(event);	// Очищаем предыдущее событие
		GetEvent(event);	// Получаем новое событие
		HandleEvent(event); // Обрабатываем полученное событие
	} while (!Valid());		// Проверка на выход
	return EndState;
}

// Проверка выхода из диалога
int Dialog::Valid()
{
	// Если выход, то EndState == 1
	if (EndState == 0) return 0;
	else return 1;
}

// Очистить событие
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;		// Пустое событие
	event.command = evNothing;	// Пустая команда
	event.a = evNothing;		// Пустой параметр а
}

// Конец выполнения диалога, выход
void Dialog::EndExec() 
{
	EndState = 1;
}

// Обработчик событий
void Dialog::HandleEvent(TEvent& event)
{

	if (event.what == evMessage) // Проверка на непустое событие
	{

		switch (event.command) // Код команды
		{
		case help:		// Вызов справки
			Get_help();
			break;
		case r_file:	// Чтение файла
			Read_file();
			break;
		case w_file:	// Запись в файл
			Write_file();
			break;
		case add:		// Добавить элементы в базу данных
			Add();
			break;
		case del:		// Удалить элементы из базы данных
			Cor_Del('d');
			break;
		case back:		// Отменить последнее удаление
			Cancel();
			break;
		case cor:		// Корректировать базу данных
			Cor_Del('c');
			break;
		case show:		// Просмотреть базу данных
			Show();
			break;
		case temperature:
			switch (event.a)
			{
			case temp_max_min:	// Определить самый теплый и холодный дни месяца
				Temp_max_min();
				break;
			case av_temp:		// Определить среднюю температуру каждой недели
				Av_temp();
				break;
			default:
				break;
			}
			break;
		case quit:		// Выход в main
			// Были ли считаны данные из файла
			if (first)
			{
				cout << "\nСохранить изменения? y/n\n";
				cout << "\n>"; char n; cin >> n;
				if (n == 'y')
				{
					Write_file();	// Запись в файл
				}
			}
			EndExec();
			break;
		default:
			break;
		};
	};
}