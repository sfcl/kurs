#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

const int TABLE_ROWS = 8;

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
    cout << "| ID |    Ќазвание                 |  ћестоположение            | √од создани€|" << endl;              
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
    /* ћаксимальное количество отображаемых строк 8 
    если больше то производим перегруппировку таблицы
     */
    int len = this->table_length;
    if (len < (TABLE_ROWS+1)) {
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
        
        /* косвеенное вычисление координаты следующей строки */
        this->table_length++; 
        
    } else {
        int int_id, i, j;
        char * int_title;
        char * int_place;
        int int_year; 
        for(i=len, j=1; j<=TABLE_ROWS ; --i, j++ ) {
            /* i осуществ€ет перебор id */
            /* j осуществ€ет перебор строк */
            if (j == TABLE_ROWS) {
               int_id    = id;
               int_title = title;
               int_place = place;
               int_year  = year;          
            } else {
               int_id    = this->data[i-TABLE_ROWS].id;
               int_title = this->data[i-TABLE_ROWS].title;
               int_place = this->data[i-TABLE_ROWS].place;
               int_year  = this->data[i-TABLE_ROWS].year;              
            }    
            gotoxy(2, 3+((j-1)*2));
            cout << int_id << endl;
            
            gotoxy(6, 3+((j-1)*2));
            cout << int_title << endl;
            
            gotoxy(36, 3+((j-1)*2));
            cout << int_place << endl;
            
            gotoxy(65, 3+((j-1)*2));
            cout << int_year << endl;
            
            gotoxy(0, 4+((j-1)*2));
            cout << "+----+-----------------------------+----------------------------+-------------+" << endl; 
            cout << "Debug " << j - 1 << endl;               
        }
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
    t1.add_line(9, "aaaaaaa", "aaaaaaaa", 2000);
    gotoxy(0, 24);
    cout << "¬ведите команду -> ";c = getchar();
    return 0;
}
