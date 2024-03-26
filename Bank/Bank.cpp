#include <iostream>
#include <map>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    // Конструктор
    BankAccount(int accountNumber, double initialBalance) : accountNumber(accountNumber), balance(initialBalance), interestRate(0.0) {}

    // Пополнение счета
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Аккаунт " << accountNumber << " пополнен на " << amount << std::endl;
        }
        else {
            std::cout << "Неверная сумма пополнения" << std::endl;
        }
    }

    // Вывод со счета аккаунта
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "С аккаунта " << accountNumber << " списано " << amount << std::endl;
        }
        else {
            std::cout << "Ошибка при выводе средств" << std::endl;
        }
    }

    // Получить текущий баланс
    double getBalance() {
        return balance;
    }

    // Calculate and return the interest earned
    double getInterest() {
        return balance * interestRate * (1 / 12);
    }

    // Update the interest rate
    void setInterestRate(double newRate) {
        interestRate = newRate;
        std::cout << "Процентная ставка обновлена: " << interestRate << std::endl;
    }

    // Get the account number
    int getAccountNumber() {
        return accountNumber;
    }

    // Friend function for transferring funds between accounts
    friend bool transfer(BankAccount& from, BankAccount& to, double amount) {
        if (amount > 0 && amount <= from.balance) {
            from.withdraw(amount);
            to.deposit(amount);
            std::cout << "Переведено: " << amount << " со счета " << from.accountNumber << " на счет " << to.accountNumber << std::endl;
            return true;
        }
        else {
            std::cout << "Перевод не удался. Неверная сумма или недостаточно средств на счете " << from.accountNumber << std::endl;
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    BankAccount account1(1, 1000.0);
    BankAccount account2(2, 500.0);

    int choice;
    double amount;
    double newInterestRate;

    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Внести средства" << std::endl;
        std::cout << "2. Снять средства" << std::endl;
        std::cout << "3. Перевод" << std::endl;
        std::cout << "4. Проверить баланс" << std::endl;
        std::cout << "5. Установить процентную ставку" << std::endl;
        std::cout << "6. Рассчитать проценты" << std::endl;
        std::cout << "7. Выход" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите сумму для внесения: ";
            std::cin >> amount;
            account1.deposit(amount);
            break;
        case 2:
            std::cout << "Введите сумму для снятия: ";
            std::cin >> amount;
            account1.withdraw(amount);
            break;
        case 3:
            int num1;
            int num2;
            std::cout << "Введите сумму для перевода: ";
            std::cin >> amount;
            std::cout << "Номер счета для списания: ";
            std::cin >> num1;
            std::cout << "Номер счета для пополнения: ";
            std::cin >> num2;
            if (num2 == account2.getAccountNumber()) {
                transfer(account1, account2, amount);
            }
            else if (num1 == account1.getAccountNumber()) {
                transfer(account2, account1, amount);
            }
            else {
                std::cout << "Один или оба счета не найдены." << std::endl;
            }
            break;
        case 4:
            std::cout << "Баланс на счете 1: " << account1.getBalance() << std::endl;
            break;
        case 5:
            std::cout << "Введите новую процентную ставку: ";
            std::cin >> newInterestRate;
            account1.setInterestRate(newInterestRate);
            break;
        case 6:
            std::cout << "Проценты на счете 1: " << account1.getInterest() << std::endl;
            break;
        case 7:
            std::cout << "Завершение программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 7);

    return 0;
}