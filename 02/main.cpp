#include <iostream>
#include <string>

class Counter {
private:
	int i;

public:

	int work_i;

	Counter(int i) {
		this->i = i;
		this->work_i = i;
	}
	Counter() {
		i = 1;
		work_i = i;
	}

	void increase(int &i) {
		this->i = ++i;
	}

	void reduce(int &i) {
		this->i = --i;
	}

	void show_counter(int i) {
		this->i = i;
		std::cout << this->i << std::endl;
	}
};

int main(int argc, char** argv) {

	system("chcp 1251");

	Counter count;

	std::string answer;

	do {
		std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
		(std::cin >> answer).get();

		if (answer != "да" && answer != "нет") {
			std::cout << "Некорректное сообщение!" << std::endl;
		}

	} while (answer != "да" && answer != "нет");


	if (answer == "да") {
		std::cout << "Введите начальное значение счетчика: ";
		std::cin >> count.work_i;
	}

	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		
		(std::cin >> answer).get();
		
		if (answer == "+") {
			count.increase(count.work_i);
		}
		else if (answer == "-") {
			count.reduce(count.work_i);
		}
		else if (answer == "=") {
			count.show_counter(count.work_i);
		}
		else if (answer == "x") {
			std::cout << "До свидания!" << std::endl;
		}
		else {
			std::cout << "Некорректный ввод операции!" << std::endl;
			if (answer == "х") { std::cout << "Вводите операцию 'x' в ENG раскладке" << std::endl; }
		}

	} while (!(answer == "x"));

	return 0;
}