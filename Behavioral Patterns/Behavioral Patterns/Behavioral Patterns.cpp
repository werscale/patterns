#include <iostream> 
#include <Windows.h>
#include <vector>

using namespace std;

/// \brief Класс системы компьютера
class ComputerSystem
{
public:
    /**
    * brief Открытие файла
    * note Метод выводит сообщение об открытии файла
    */
    void openFile(const string& file)
    {
        cout << "Открываем файл: " << file << endl;
    }

    /**
    * brief Выключение компьютера
    */
    void shutdown()
    {
        cout << "Выключаем компьютер" << endl;
    }

    /**
    * brief Запуск браузера
    */
    void launchBrowser()
    {
        cout << "Запускаем браузер" << endl;
    }
};

/// \brief Абстрактный класс команды
class Command
{
public:
    /**
    * brief Выполнение команды
    */
    virtual void execute() = 0;

    /**
    * brief Отмена команды
    */
    virtual void undo() = 0;
};

/// \brief Команда открытия файла
class OpenFileCommand : public Command
{
private:
    ComputerSystem* system;   ///< Указатель на систему
    string fileName;          ///< Имя файла

public:
    /**
    * brief Конструктор команды открытия файла
    * note Сохраняет ссылку на систему и имя файла
    */  
    OpenFileCommand(ComputerSystem* s, const string& fn)
        : system(s), fileName(fn) {
    }

    /**
    * brief Выполнение команды
    */
    void execute() override
    {
        system->openFile(fileName);
    }

    /**
    * brief Отмена команды
    */
    void undo() override
    {
        cout << "Закрываем файл: " << fileName << endl;
    }
};

/// \brief Команда выключения компьютера
class ShutdownCommand : public Command
{
private:
    ComputerSystem* system;   ///< Указатель на систему

public:
    /**
    * brief Конструктор команды выключения
    */
    ShutdownCommand(ComputerSystem* s)
        : system(s) {
    }

    /**
    * brief Выполнение команды
    */
    void execute() override
    {
        system->shutdown();
    }

    /**
    * brief Отмена команды
    */
    void undo() override
    {
        cout << "Отмена: Включаем компьютер обратно" << endl;
    }
};

/// \brief Команда запуска браузера
class LaunchBrowserCommand : public Command
{
private:
    ComputerSystem* system;   ///< Указатель на систему

public:
    /**
    * brief Конструктор команды запуска браузера
    * note Сохраняет ссылку на систему
    */
    LaunchBrowserCommand(ComputerSystem* s)
        : system(s) {
    }

    /**
    * brief Выполнение команды
    */
    void execute() override
    {
        system->launchBrowser();
    }

    /**
    * brief Отмена команды
    */
    void undo() override
    {
        cout << "Закрываем браузер" << endl;
    }
};

/// \brief Класс пульта управления
class RemoteControl
{
private:
    vector<Command*> commands;

public:
    /**
    * brief Добавление команды в список
    */
    void addCommand(Command* cmd)
    {
        commands.push_back(cmd);
    }

    /**
    * brief Нажатие кнопки 
    */
    void pressButton()
    {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }

    /**
    * brief Отмена последней добавленной команды
    * note Вызывает undo() и удаляет команду из списка
    */
    void undoLast()
    {
        if (!commands.empty())
        {
            commands.back()->undo();
            commands.pop_back();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /// Создание системы (получателя)
    ComputerSystem system;

    /// Создание конкретных команд
    Command* openCmd = new OpenFileCommand(&system, "document.txt");
    Command* shutdownCmd = new ShutdownCommand(&system);
    Command* browserCmd = new LaunchBrowserCommand(&system);

    /// Создание пульта (инициатора)
    RemoteControl remote;

    /// Добавление команд в пульт
    remote.addCommand(openCmd);
    remote.addCommand(browserCmd);
    remote.addCommand(shutdownCmd);

    /// Выполнение всех команд
    remote.pressButton();

    /// Отмена последней команды
    remote.undoLast();

    /// Освобождение памяти
    delete openCmd;
    delete shutdownCmd;
    delete browserCmd;

    return 0;
}