#include <iostream>
#include <locale.h>
#include <windows.h>

/*
Задание 1.
Реализуйте класс Дробь. Необходимо хранить числитель
и знаменатель в качестве переменных-членов. Реализуйте
функции-члены для ввода данных в переменные-члены,
для выполнения арифметических операций (сложение,
вычитание, умножение, деление, и т.д.).
*/

template <typename T>
class Fraction {
private:
	T _numerator;
	T _denominator;

public:
	Fraction() : _numerator(0.0), _denominator(1.0)
	{}
	
	Fraction(T numerator, T denominator) : _numerator(numerator), _denominator(denominator)
	{}
	
	void SetDenominator(T denominator) {
		_denominator = denominator;
	}

	
	void SetNumerator(T numerator) {
		_numerator = numerator;
	}

	
	void SetBoth(T numerator, T denominator) {
		_denominator = denominator;
		_numerator = numerator;
	}

	T GetDenominator() const {
		return _denominator;
	}

	T GetNumerator() const {
		return _numerator;
	}

	void Print() const {
		std::cout << "Numerator = " << _numerator << std::endl;
		std::cout << "Denominator = " << _denominator << std::endl;
	}

	T Addition() const {
		return _numerator + _denominator;
	}

	T Substraction() const {
		return _numerator - _denominator;
	}

	T Multiplication() {
		return _numerator * _denominator;
	}

	float Division() const {
		if (_denominator == 0) {
			std::cout << "Деление на ноль запрещено!\n";
			return -1;
		}
		return (float)_numerator / _denominator;
	}

};


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	int num1, num2;
	std::cout << "Введите первое число -> ";
	std::cin >> num1;
	std::cout << "Введите второе число -> ";
	std::cin >> num2;

	Fraction<int> f1(num1, num2);
	std::cout << num1 << " / " << num2 << " = " << f1.Division() << std::endl;
	std::cout << num1 << " + " << num2 << " = " << f1.Addition() << std::endl;
	std::cout << num1 << " * " << num2 << " = " << f1.Multiplication() << std::endl;
	std::cout << num1 << " - " << num2 << " = " << f1.Substraction() << std::endl;

	float num3, num4;
	std::cout << "Введите первое число -> ";
	std::cin >> num3;
	std::cout << "Введите второе число -> ";
	std::cin >> num4;
	Fraction<float> f2(num3, num4);
	std::cout << num3 << " / " << num4 << " = " << f2.Division() << std::endl;
	std::cout << num3 << " + " << num4 << " = " << f2.Addition() << std::endl;
	std::cout << num3 << " * " << num4 << " = " << f2.Multiplication() << std::endl;
	std::cout << num3 << " - " << num4 << " = " << f2.Substraction() << std::endl;

	f1.Print();
	std::cout << f1.GetDenominator() << std::endl;
	std::cout << f1.GetNumerator() << std::endl;

	f1.SetBoth(2, 3);
	f1.Print();
	f1.SetDenominator(4);
	f1.Print();
	f1.SetNumerator(5);
	f1.Print();

	return 0;
}
