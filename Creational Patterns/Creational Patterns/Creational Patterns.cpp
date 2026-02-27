#include <iostream> 
#include <Windows.h>

using namespace std;

//---------------------------------------------

class Character {
public:
    virtual string getType() = 0;
    virtual void attack() = 0;
    virtual int getHealth() = 0;
};

/// \brief Класс с настройками для персонажа ВОИН
class Warrior : public Character {
public:
    /**
    * brief Фнункция для получения типа персонажа
    * return string - строку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Воин"; }
    /**
    * brief Фнункция для выполения действия персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Воин атакует мечом!" << endl; }
    /**
    * brief Фнункция для обозначения здоровья персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    int getHealth() override { return 100; }
};
/// \brief Класс с настройками для персонажа МАН
class Mage : public Character {
public:
    /**
    * brief Фнункция для получения типа персонажа
    * return string - строку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Маг"; }
    /**
    * brief Фнункция для выполения действия персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }
    /**
    * brief Фнункция для обозначения здоровья персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    int getHealth() override { return 50; }
};
/// \brief Класс с настройками для персонажа ЛУЧНИК
class Archer : public Character {
public:
    /**
    * brief Фнункция для получения типа персонажа
    * return string - строку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Лучник"; }
    /**
    * brief Фнункция для выполения действия персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Лучик стреляет из лука!" << endl; }
    /**
    * brief Фнункция для обозначения здоровья персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    int getHealth() override { return 70; }
};
/// \brief Класс с настройками для персонажа РЫЦАРЬ
class Knight : public Character {
public:
    /**
    * brief Фнункция для получения типа персонажа
    * return string - строку, название персонажа
    * remark Получаем только имя персонажа т.к. это учебный код
    */
    string getType() override { return "Рыцарь"; }
    /**
    * brief Фнункция для выполения действия персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }
    /**
    * brief Фнункция для обозначения здоровья персонажа
    * note Не влияет ни на что. Это учебный код
    * todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    int getHealth() override { return 120; }
};

class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    /**
    * brief Фнункция для создания персонажа и выполнения базовых его действий 
    * note После создания объекта, выполняет действие персонажа и уничтожает объект
    * warning Нельзя будет использовтаь созданных персонжаей в других частях кода
    */
    void spawnAndAttack() {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getType() << ", " << "со здоровьем: " << chara->getHealth() << " ";
        chara->attack();
        delete chara;
    }
};

class WarriorFactory : public CharacterFactory {
public:
    /**
    * brief Фнункция для выделения памяти на класс персонажа 
    * return Возвращает указатель на созданного персонажа
    * 
    */
    Character* createCharacter() override { return new Warrior(); }
};
class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Mage(); }
};
class ArcherFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Archer(); }
};
class KnightFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Knight(); }
};

/// \brief Функция для запуска конвеера с персонажами
/// \note Испольузется для учебного кода
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttack();

    factory = new MageFactory();
    factory->spawnAndAttack();

    factory = new ArcherFactory();
    factory->spawnAndAttack();

    factory = new KnightFactory();
    factory->spawnAndAttack();
    delete factory;
}