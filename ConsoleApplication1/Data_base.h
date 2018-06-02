#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

// Структура Узел
struct Node
{
	// Конструктор с параметрами
	Node(const int&, const double&, Node* = nullptr, Node* = nullptr);
	int key;		// Ключ
	double value;	// Информационное поле списка
	Node *previous;	// Предыдущий адрес узла
	Node *next;		// Следующий адрес узла
};

// Класс База данных
class Data_base
{
public:
	// Конструктор по умолчанию
	Data_base();
	// Деструктор
	~Data_base();
	// Создание базы данных
	void Сreate_list(const int&, const double&);
	// Добавить элементы на заданную позицию
	void Add();
	// Тригер выбора удаления или корректировки 
	void Cor_Del(const char&);
	// Корректировать базу данных
	void Correct();
	// Удаление элемента из бд
	void Delete();
	// Вернуть последний удаленный объект
	void Cancel();
	// Просмотреть базу данных
	void Show();
	// Определить самый теплый и холодный дни месяца
	void Temp_max_min();
	// Определить среднюю температуру каждой недели
	void Av_temp();
	// Считать данные из файла
	void Read_file();
	// Записать данные в файл
	void Write_file();
protected:
	Node *first;	// Первый узел списка
	Node *last;		// Последний узел списка
	Node *temp;		// Временный хранитель узла
	vector<Node*> cancel; // Вектор, хранящий указатели на удаленные объекты
};