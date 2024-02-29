#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

std::string reverse(std::string word) {
    std::reverse(word.begin(), word.end());
    return word;
}

std::string removeVowels(std::string word) {
    std::string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    word.erase(std::remove_if(word.begin(), word.end(), [&vowels](char c) { return vowels.find(c) != std::string::npos; }), word.end());
    return word;
}

std::string removeConsonants(std::string word) {
    std::string consonants = "бвгджзйклмнпрстфхцчшщьъБВГДЖЗЙКЛМНПРСТФХЦЧШЩЬЪ";
    word.erase(std::remove_if(word.begin(), word.end(), [&consonants](char c) { return consonants.find(c) != std::string::npos; }), word.end());
    return word;
}

std::string shuffle(std::string word) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(word.begin(), word.end());
    return word;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string word;
    int choice;

    std::cout << "Введите слово: ";
    std::cin >> word;

    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Слово задом наперед" << std::endl;
        std::cout << "2. Вывести слово без гласных" << std::endl;
        std::cout << "3. Вывести слово без согласных" << std::endl;
        std::cout << "4. Рандомно раскидать буквы" << std::endl;
        std::cout << "5. Выйти" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Результат: " << reverse(word) << std::endl;
            break;
        case 2:
            std::cout << "Результат: " << removeVowels(word) << std::endl;
            break;
        case 3:
            std::cout << "Результат: " << removeConsonants(word) << std::endl;
            break;
        case 4:
            std::cout << "Результат: " << shuffle(word) << std::endl;
            break;
        case 5:
            std::cout << "До свидания!" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
