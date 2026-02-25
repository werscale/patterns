#include <iostream> 
#include <Windows.h>

using namespace std;

class Beverage
{
public:
    virtual std::string getDescription() = 0;
    virtual double cost() = 0;
};

class Espresso : public Beverage
{
public:
    string getDescription() override { return "Эспрессо"; }
    double cost() override { return 1.99; }
};

class Tea : public Beverage
{
public:
    string getDescription() override { return "Чай"; }
    double cost() override { return 1.50; }
};

class CondimentDecorator : public Beverage
{
protected:
    Beverage* beverage;
public:
    CondimentDecorator(Beverage* b) : beverage(b) {}
    string getDescription() override { return beverage->getDescription(); }
    double cost() override { return beverage->cost(); }
};

class Milk : public CondimentDecorator
{
public:
    Milk(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Молоко"; }
    double cost() override { return beverage->cost() + 0.10; }
};

class Sugar : public CondimentDecorator
{
public:
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Сахар"; }
    double cost() override { return beverage->cost() + 0.05; }
};

class Syrup : public CondimentDecorator
{
public:
    Syrup(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Сироп"; }
    double cost() override { return beverage->cost() + 0.15; }
};

class Chocolate : public CondimentDecorator
{
public:
    Chocolate(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override { return beverage->getDescription() + ", Шоколад"; }
    double cost() override { return beverage->cost() + 0.20; }
};
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Beverage* drink = new Espresso();
    drink = new Milk(drink);
    drink = new Sugar(drink);
    drink = new Syrup(drink);
    cout << drink->getDescription() << " стоит $" << drink->cost() << endl;

    Beverage* drink1 = new Tea();
    drink1 = new Milk(drink1);
    drink1 = new Sugar(drink1);
    cout << drink1->getDescription() << " стоит $" << drink1->cost() << endl;

    Beverage* simpleDrink = new Espresso();
    cout << simpleDrink->getDescription() << " стоит $" << simpleDrink->cost() << endl;

    delete drink;
    delete simpleDrink;
}