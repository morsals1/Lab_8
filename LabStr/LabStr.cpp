// LabStr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

char* getInput(char* str) {
	std::cout << "Введите несколько слов через пробел:\n";
	return gets_s(str, 100);
}

void printOutput(const char* str) {
	puts(str);
}

void reverseWords(char* str) {

    char* words[100 / 2];
    int count = 0;
    char* context = nullptr;

    char* token = strtok_s(str, " ", &context);
    while (token) {
        words[count++] = token;
        token = strtok_s(nullptr, " ", &context);
    }

    for (int i = 1; i < count; i += 2) {
        std::reverse(words[i], words[i] + strlen(words[i]));
    }

    char result[100] = "";
    for (int i = 0; i < count; i++) {
        strcat_s(result, words[i]);
        if (i < count - 1) strcat_s(result, " ");
    }

    strcpy_s(str, 100, result);

}

int main()
{

    setlocale(LC_ALL, "Russian");

	char str[100];

	getInput(str);
	reverseWords(str);
	printOutput(str);
	

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
