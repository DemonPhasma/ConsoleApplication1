#include <iostream>

using namespace std;

const int pizzaPrices[7] = { 450, 420, 450, 400, 500, 310, 550 }; const char* pizzaNames[7] = { "Маргарита", "Двойной Сыр", "Пепперони", "Гавайская", "Мясная", "Вегетарианская", "Сырная" };

const int snackPrices[4] = { 100, 150, 200, 250 }; const char* snackNames[4] = { "Картофель фри", "Куриные крылышки", "Салат Цезарь", "Луковые кольца" };

const int drinkPrices[5] = { 80, 100, 120, 150, 180 }; const char* drinkNames[5] = { "Злая Пепси", "Чай О Лонг", "Имба", "Чай", "Кофе" };

int main() {
    setlocale(LC_ALL, "ru"); int pizzaCount = 0; int snackCount = 0; int drinkCount = 0; int totalPizzas = 0; int totalSnacks = 0; int totalDrinks = 0; double totalSum = 0;

    char repeat;

    do {
        pizzaCount = 0;
        snackCount = 0;
        drinkCount = 0;
        totalPizzas = 0;
        totalSnacks = 0;
        totalDrinks = 0;
        totalSum = 0;

        while (true) {
            cout << "Выберите пиццу (1-7) или введите 0 для продолжения:" << endl;
            for (int i = 0; i < 7; i++) {
                cout << i + 1 << ". " << pizzaNames[i] << " - " << pizzaPrices[i] << " рублей" << endl;
            }
            int pizzaChoice;
            cin >> pizzaChoice;
            if (pizzaChoice == 0) break;
            if (pizzaChoice < 1 || pizzaChoice > 7) {
                cout << "Неправильный выбор. Попробуйте снова." << endl;
                continue;
            }
            totalPizzas += pizzaPrices[pizzaChoice - 1];
            pizzaCount++;
        }

        while (true) {
            cout << "Выберите закуску (1-4) или введите 0 для продолжения:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << i + 1 << ". " << snackNames[i] << " - " << snackPrices[i] << " рублей" << endl;
            }
            int snackChoice;
            cin >> snackChoice;
            if (snackChoice == 0) break;
            if (snackChoice < 1 || snackChoice > 4) {
                cout << "Неправильный выбор. Попробуйте снова." << endl;
                continue;
            }
            totalSnacks += snackPrices[snackChoice - 1];
            snackCount++;
        }

        while (true) {
            cout << "Выберите напиток (1-5) или введите 0 для продолжения:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << drinkNames[i] << " - " << drinkPrices[i] << " рублей" << endl;
            }
            int drinkChoice;
            cin >> drinkChoice;
            if (drinkChoice == 0) break;
            if (drinkChoice < 1 || drinkChoice > 5) {
                cout << "Неправильный выбор. Попробуйте снова." << endl;
                continue;
            }
            totalDrinks += drinkPrices[drinkChoice - 1];
            drinkCount++;
        }

        totalSum = totalPizzas + totalSnacks + totalDrinks;

        // Каждая 5 пицца в подарок
        if (pizzaCount >= 5) {
            totalSum -= pizzaPrices[pizzaCount / 5];
        }

        // Если напитков ценой от 500 рублей в заказе больше чем 4, то одна в подарок
        int expensiveDrinksCount = 0;
        for (int i = 0; i < drinkCount; i++) {
            if (drinkPrices[i] >= 500) {
                expensiveDrinksCount++;
            }
        }
        if (expensiveDrinksCount > 4) {
            totalSum -= drinkPrices[expensiveDrinksCount - 1];
        }

        // Если сумма заказа превышает 2000 рублей, то скидка 15% на весь заказ
        if (totalSum > 2000) {
            totalSum -= (totalSum * 0.15);
        }

        cout << "Ваш заказ:" << endl;
        cout << "Пиццы: " << totalPizzas << " рублей" << endl;
        cout << "Закуски: " << totalSnacks << " рублей" << endl;
        cout << "Напитки: " << totalDrinks << " рублей" << endl;
        cout << "Итого: " << totalSum << " рублей" << endl;

        cout << "Хотите повторить заказ? (да/нет): ";
        cin >> repeat;

    } while (repeat == 'да');

    return 0;

}