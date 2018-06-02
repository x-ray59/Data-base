// Описание класса Event (Событие)
#pragma once

// Общие команды
constexpr int evNothing = 0;	// Пустое событие
constexpr int evMessage = 100;	// Непустое событие
constexpr int quit = 101;		// Выход 'q'
constexpr int help = 102;		// Вызов описания меню '?'
constexpr int r_file = 103;		// Чтение файла 'r'
constexpr int w_file = 104;		// Запись в файл 'w'
constexpr int add = 105;		// Добавить элементы в базу данных '+'
constexpr int del = 106;		// Удалить элементы из базы данных '-'
constexpr int back = 107;		// Отменить последнее удаление 'b'
constexpr int cor = 108;		// Корректировать базу данных 'c'
constexpr int show = 109;		// Просмотреть базу данных 's'

// Команды температуры
constexpr int temperature = 110;// Триггер выбора команды температуры
constexpr int temp_max_min = 1;	// Определить самый теплый день месяца 'm1'
constexpr int av_temp = 2;		// Определить среднюю температуру каждой недели 'm2'

// Класс событие
struct TEvent
{
	int what;	// Тип события
	int a;		// Параметр команды
	// union объединяет command и message, то есть они используют одну область памяти.
	// При изменении значения command меняется message, и наоборот
	union
	{
		int command; // Код команды
		int message; // Сообщение
	};
};