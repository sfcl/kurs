#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct main_table {
    unsigned int id;
    char * title;
    char * place;
    char year;
};

void gotoxy(int x, int y) {
     HANDLE hStdout =  GetStdHandle(STD_OUTPUT_HANDLE);
     COORD position = {x, y};
     SetConsoleCursorPosition(hStdout, position);
}

class DataTable {
    private:
        main_table data[100];
        int table_length;
    public:
        DataTable();
        void show();
        void add_line(int id, char * title, char * place, int year);
};

DataTable::DataTable() {
     this->table_length = 0;
}

void DataTable::show() {
    cout << "+----+-----------------------------+----------------------------+-------------+" << endl;
    cout << "| ID |    Название                 |  Местоположение            | Год создания|" << endl;              
    cout << "+----+-----------------------------+----------------------------+-------------+" << endl;                  
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "|    |                             |                            |             |" << endl;
    cout << "+----+-----------------------------+----------------------------+-------------+" << endl;
};   


void DataTable::add_line(int id, char * title, char * place, int year) {
    /* Максимальное количество отображаемых строк 8 
    если больше то производим перегруппировку таблицы
     */
    int len = this->table_length;
    if (len < 9) {
        
        gotoxy(2, 3+(len*2));
        cout << id << endl;
        
        gotoxy(6, 3+(len*2));
        cout << title << endl;
        
        gotoxy(36, 3+(len*2));
        cout << place << endl;
        
        gotoxy(65, 3+(len*2));
        cout << year << endl;
        
        gotoxy(0, 4+(len*2));
        cout << "+----+-----------------------------+----------------------------+-------------+" << endl;    
        
        this->table_length++;
        
    } else {
        
    }
    this->data[len].id    = len;
    this->data[len].title = title;
    this->data[len].place = place;
    this->data[len].year  = year;
};

int main(int argc, char *argv[])
{
    char c;
    DataTable t1;
    t1.show();
    t1.add_line(1, "dfdf", "23213", 1998);
    t1.add_line(2, "dsdsd", "sdsd13", 1999);
    t1.add_line(3, "dsdsd", "sdsd13", 1999);
    t1.add_line(4, "dsdsd", "sdsd13", 1999);
    t1.add_line(5, "dsdsd", "sdsd13", 1999);
    t1.add_line(6, "dsdsd", "sdsd13", 1999);
    t1.add_line(7, "dsdsd", "sdsd13", 1999);
    t1.add_line(8, "dsdsd", "sdsd13", 1999);
    gotoxy(0, 24);
    cout << "Введите команду -> ";c = getchar();
    return 0;
}
