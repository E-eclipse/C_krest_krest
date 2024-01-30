#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(0, "");
    int choice;
    double num1, num2, result;

    while (true) {
        cout << "Калькулятор\n";
        cout << "1. Сложение\n";
        cout << "2. Вычитание\n";
        cout << "3. Деление\n";
        cout << "4. Умножение\n";
        cout << "5. Возведение в степень\n";
        cout << "6. Нахождение квадратного корня\n";
        cout << "7. Нахождение 1 процента от числа\n";
        cout << "8. Найти факториал числа\n";
        cout << "9. Выйти из программы\n";
        cout << "Выберите операцию (1-9): ";
        cin >> choice;

        if (choice == 9) {
        system("cls");
            cout << "Программа завершена.\n";
            break;
        }

        switch (choice) {
        case 1:
            cout << "Введите первое число: ";
            cin >> num1;
            cout << "Введите второе число: ";
            cin >> num2;
            result = num1 + num2;
            cout << "Результат: " << result << endl;
            break;
        case 2:
            cout << "Введите первое число: ";
            cin >> num1;
            cout << "Введите второе число: ";
            cin >> num2;
            result = num1 - num2;
            cout << "Результат: " << result << endl;
            break;
        case 3:
            cout << "Введите делимое: ";
            cin >> num1;
            cout << "Введите делитель: ";
            cin >> num2;
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Результат: " << result << endl;
            }
            else {
                cout << "Ошибка: деление на ноль.\n";
            }
            break;
        case 4:
            cout << "Введите первый множитель: ";
            cin >> num1;
            cout << "Введите второй множитель: ";
            cin >> num2;
            result = num1 * num2;
            cout << "Результат: " << result << endl;
            break;
        case 5:
            cout << "Введите число: ";
            cin >> num1;
            cout << "Введите степень: ";
            cin >> num2;
            result = pow(num1, num2);
            cout << "Результат: " << result << endl;
            break;
        case 6:
            cout << "Введите число: ";
            cin >> num1;
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << "Результат: " << result << endl;
            }
            else {
                cout << "Ошибка: невозможно извлечь квадратный корень из отрицательного числа\n";
            }
            break;
        case 7:
            cout << "Введите число: ";
            cin >> num1;
            result = num1 / 100;
            cout << "Результат: " << result << endl;
            break;
        case 8:
            cout << "Введите число: ";
            cin >> num1;
            result = 1;
            for (int i = 1; i <= num1; i++) {
                result *= i;
            }
            cout << "Результат: " << result << endl;
            break;
        default:
            cout << "Ошибка: некорректный выбор операции\n";
            break;
        }

        system("pause");
        system("cls");
        cout << endl;
        
    }

    return 0;
}
