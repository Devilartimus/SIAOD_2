#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Queue
{
    char info;
    Queue* next;
};
Queue* beginVow;
Queue* endVow;
Queue* beginCons;
Queue* endCons;


void InitVow(); //инициализация очереди гласных букв
void InitCons();    //инициализация очереди согласных букв
void EnQueueVow(char);  //добавление элемента в очередь гласных букв
void EnQueueCons(char); //добавление элемента в очередь согласных букв
char DeQueueVow();      //удаление элемента из очереди гласных букв
char DeQueueCons();     //удаление элемента из очереди согласных букв
bool IsEmptyVow();      //проверка на пусоту очереди гласных букв
bool IsEmptyCons();     //проверка на пустоту очереди согласных букв
bool CheckVow(char);
bool CheckCons(char);


int main()
{
    ifstream fin;   //файл ввода
    fin.open("E:/3 term/SIAOD/lab3/fin.txt");
    if (!fin.is_open())
        cout << "Errror! File can't be opened\n\n";
    else
    {
        char a;
        InitCons();
        InitVow();
        while(1)
        {
            fin.get(a);
            if (!fin.eof())
            {
                if (CheckCons(a))
                    EnQueueCons(a);
                else if (CheckVow(a))
                    EnQueueVow(a);
                else
                    continue;
            }
            else
                break;
        }
        cout << "Your Vow Queue: " << endl;
        while(!IsEmptyVow())
            cout << DeQueueVow() << " ";

        cout << endl << "Your Cons Queue: " << endl;
        while(!IsEmptyCons())
            cout << DeQueueCons() << " ";

    }
    return 0;
}

bool CheckVow(char a)
{
    string Vow = "AaEeIiOoUuYy";
    for(int i = 0; i < 12; i++)
        if (a == Vow[i])
            return true;
    return false;
}

bool CheckCons(char a)
{
    string Cons = "QqWwRrTtPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
    for(int i = 0; i < 40; i++)
        if (a == Cons[i])
            return true;
    return false;
}

void InitCons()
{
    beginCons = NULL;
    endCons = NULL;
}

void InitVow()
{
    beginVow = NULL;
    endVow = NULL;
}

void EnQueueCons(char a)
{
    Queue* p;
    p = new Queue;
    if (p == NULL)
    {
        cout << "p = NULL";
        return;
    }
    p->info = a;
    p->next = NULL;
    if (beginCons == NULL)
        beginCons = p;
    else
        endCons->next = p;
    endCons = p;

}

void EnQueueVow(char a)
{
    Queue* p;
    p = new Queue;
    if (p == NULL)
    {
        cout << "p = NULL";
        return;
    }
    p->info = a;
    p->next = NULL;
    if (beginVow == NULL)
        beginVow = p;
    else
        endVow->next = p;
    endVow = p;

}

char DeQueueCons()
{
    int val;
    Queue* p = new Queue;
    p = beginCons;
    val = beginCons->info;
    beginCons = p->next;
    if (beginCons == NULL)
        endCons = NULL;
    delete p;
    return(val);
}

char DeQueueVow()
{
    char val;
    Queue* p = new Queue;
    p = beginVow;
    val = beginVow->info;
    beginVow = p->next;
    if (beginVow == NULL)
        endVow = NULL;
    delete p;
    return(val);
}

bool IsEmptyCons()
{
    return (beginCons == NULL && endCons == NULL);
}


bool IsEmptyVow()
{
    return (beginVow == NULL && endVow == NULL);
}


