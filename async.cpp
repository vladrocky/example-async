#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>

using namespace std;

// в данном случае мы не достигнем асинхронности,
// задачи будут выполненеы последовательно
namespace syncExamle
{

    int value = 0;

    void worker()
    {

        cout << "=========== worker start ===============" << endl;

        for (int index = 0; index < 10; index++)
        {
            ++value;
            cout << "(id thread = " << this_thread::get_id() << ") "
                 << "Value = " << value << endl;
            this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        cout << "=========== worker end ===============" << endl;
    }

    void showExample()
    {

        // передаем в async ссылку на функциональную сущьность
        std::async(worker);
        cout << "(id thread = " << this_thread::get_id() << ") "
             << "Value = " << value << endl;
    }
}

// инициализируем объект класса future вызовом async
namespace asyncExample
{

    int value = 0;

    void worker()
    {

        // this_thread::sleep_for(chrono::microseconds(15));

        cout << "=========== worker start ===============" << endl;

        for (int index = 0; index < 10; index++)
        {
            ++value;
            cout << "(id thread = " << this_thread::get_id() << ") "
                 << "Value = " << value << endl;
            this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        cout << "=========== worker end ===============" << endl;
    }

    void showExample()
    {

        // передаем в async ссылку на функциональную сущность
        // инициализируем объект класса future
        future<void> simple_futer = async(worker);
        cout << "(id thread = " << this_thread::get_id() << ") "
             << "Value = " << value << endl;
    }
}

int main()
{
    // syncExamle::showExample();
    asyncExample::showExample();

    return 0;
}