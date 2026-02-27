#include <iostream> 
#include <Windows.h>

using namespace std;

/// \brief Класс напитка
class Beverage
{
public:
    /**
    * brief Получение описания напитка
    * return string - название напитка
    */
    virtual std::string getDescription() = 0;

    /**
    * brief Получение стоимости напитка
    * return double - цена напитка
    */
    virtual double cost() = 0;
};

/// \brief Класс кофе
class Espresso : public Beverage
{
public:
    /**
    * brief Функция получения описания кофе
    */
    string getDescription() override
    {
        return "Эспрессо";
    }

    /**
    * brief Функция получения стоимости кофе
    */
    double cost() override
    {
        return 1.99;
    }
};

/// \brief Класс чай
class Tea : public Beverage
{
public:
    /**
    * brief Функция получения описания чая
    */
    string getDescription() override
    {
        return "Чай";
    }

    /**
    * brief Функция получения стоимости чая
    */
    double cost() override
    {
        return 1.50;
    }
};

/// \brief Класс декоратора
class CondimentDecorator : public Beverage
{
protected:
    Beverage* beverage;

public:
    /**
    * brief Конструктор декоратора
    */
    CondimentDecorator(Beverage* b) : beverage(b) {}

    /**
    * brief Получение описания 
    */
    string getDescription() override
    {
        return beverage->getDescription();
    }

    /**
    * brief Получение стоимости 
    */
    double cost() override
    {
        return beverage->cost();
    }
};

/// \brief Декоратор Молока
class Milk : public CondimentDecorator
{
public:
    /**
    * brief Конструктор молока
    */
    Milk(Beverage* b) : CondimentDecorator(b) {}
    /**
    * brief Добавление молока к описанию
    */
    string getDescription() override
    {
        return beverage->getDescription() + ", Молоко";
    }
    /**
    * brief Добавление стоимости молока
    */
    double cost() override
    {
        return beverage->cost() + 0.10;
    }
};

/// \brief Декоратор Сахара
class Sugar : public CondimentDecorator
{
public:
    /**
    * brief Конструктор сахара
    */
    Sugar(Beverage* b) : CondimentDecorator(b) {}

    /**
    * brief Добавление сахара к описанию
    */
    string getDescription() override
    {
        return beverage->getDescription() + ", Сахар";
    }

    /**
    * brief Добавление стоимости сахара
    */
    double cost() override
    {
        return beverage->cost() + 0.05;
    }
};

/// \brief Декоратор Сиропа
class Syrup : public CondimentDecorator
{
public:
    /**
    * brief Конструктор сиропа
    */
    Syrup(Beverage* b) : CondimentDecorator(b) {}

    /**
    * brief Добавление сиропа к описанию
    */
    string getDescription() override
    {
        return beverage->getDescription() + ", Сироп";
    }

    /**
    * brief Добавление стоимости сиропа
    */
    double cost() override
    {
        return beverage->cost() + 0.15;
    }
};

/// \brief Декоратор Шоколада
class Chocolate : public CondimentDecorator
{
public:
    /**
    * brief Конструктор шоколада
    */
    Chocolate(Beverage* b) : CondimentDecorator(b) {}

    /**
    * brief Добавление шоколада к описанию
    */
    string getDescription() override
    {
        return beverage->getDescription() + ", Шоколад";
    }

    /**
    * brief Добавление стоимости шоколада
    */
    double cost() override
    {
        return beverage->cost() + 0.20;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /// Эспрессо с молоком, сахаром и сиропом
    Beverage* drink = new Espresso();
    drink = new Milk(drink);
    drink = new Sugar(drink);
    drink = new Syrup(drink);

    cout << drink->getDescription()
        << " стоит $"
        << drink->cost() << endl;

    /// Чай с молоком и сахаром
    Beverage* drink1 = new Tea();
    drink1 = new Milk(drink1);
    drink1 = new Sugar(drink1);

    cout << drink1->getDescription()
        << " стоит $"
        << drink1->cost() << endl;

    Beverage* simpleDrink = new Espresso();

    cout << simpleDrink->getDescription()
        << " стоит $"
        << simpleDrink->cost() << endl;

    delete drink;
    delete simpleDrink;

    return 0;
}