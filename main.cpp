#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

const int TABLE_ROWS = 8;

struct main_table {
    unsigned int id;
    string title;
    string place;
    int year;
};

void gotoxy(int x, int y) {
     HANDLE hStdout =  GetStdHandle(STD_OUTPUT_HANDLE);
     COORD position = {x, y};
     SetConsoleCursorPosition(hStdout, position);
}

void clear_all() {
    for(int y=0; y < 30; ++y) {
        for(int x=0; x < 80; ++x) {
            gotoxy(x, y);
            cout << " " << endl;
        }    
    }
    gotoxy(0,0);
}

class DataTable {
    private:
        main_table data[100];
        int table_length;
        unsigned int id;
        unsigned int first_index; 
    public:
        bool change;
        DataTable();
        void show();
        void clear_table();
        void add_line(string title, string place, int year);
        void data_up();
        void data_down();
};

DataTable::DataTable() {
     /* Производим иницализацию данных начальными значениями.
        Считываем данные из файла data.db 
     */
     this->table_length = 0;
     this->id = 1;
     this->first_index = 1;
     this->change = false;
     main_table row;
     ifstream f;
     f.open("data.db", ios::binary);
     if (f) {
        while (f.good()) {
            if( !f.read((char *) &row, sizeof(row)) )
                break; 
            f.read((char *) &row, sizeof(row));
            cout << row.title <<  row.place << row.year << endl; getch();
            /*this->add_line(row.title, row.place, row.year); */
        }
        
     } else { 
         /* если файл базы данных отсутствует, то создаём пустой */
         cout << "Не найден файл данных!" << endl; getch();
         ofstream f("data.db");
         f.close();
         exit(1);
     }
     f.close(); // закрываем файл
}

void DataTable::show() {
    gotoxy(0, 0);
    cout << "+----+-----------------------------+----------------------------+-------------+" << endl;
    cout << "| ID |    Название                 |  Место положения           |Год создания |" << endl;              
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
    int len = this->table_length;
    int id = this->first_index;
    if (len) {
        if (len <= TABLE_ROWS) {
            len = len + 1;
        } else {
            len = TABLE_ROWS + 1;   
        }
        for (int i=1;i < len; i++, id++) {
            gotoxy(2, 3+((i-1)*2));
            cout << this->data[id].id << endl;
            
            gotoxy(6, 3+((i-1)*2));
            cout << this->data[id].title << endl;
            
            gotoxy(36, 3+((i-1)*2));
            cout << this->data[id].place << endl;
            
            gotoxy(65, 3+((i-1)*2));
            cout << this->data[id].year << endl;
            
            gotoxy(0, 4+((i-1)*2));
            cout << "+----+-----------------------------+----------------------------+-------------+" << endl;    
        }
    }
    gotoxy(0, 24);
    cout << "Введите команду -> ";
};   

void DataTable::data_down() {
     unsigned int id;
     unsigned int first_index = this->first_index;
     first_index++;
     if ( (first_index + TABLE_ROWS - 1) <= this->table_length) {
     } else {
         first_index--;   
     }
     this->first_index = first_index;
     this->show();      
}

void DataTable::data_up() {
     unsigned int first_index = this->first_index;
     first_index--;
     if ( first_index == 0) {
        first_index = 1;
     }
     this->first_index = first_index;
     this->show();      
}


void DataTable::clear_table() {
     for(int y=0; y < 19; ++y) {
        for(int x=0; x < 80; ++x) {
            gotoxy(x, y);
            cout << " " << endl;
        }    
     }
}

void DataTable::add_line(string title, string place, int year) {
    this->table_length++;
    this->change = true;
    int len = this->table_length;
    this->data[len].id    = this->id;
    this->data[len].title = title;
    this->data[len].place = place;
    this->data[len].year  = year;
    this->id++;     
};


class Dialog {
    private:
        char * title;
        char * place;
        int year;
        DataTable * tab;
        
    public:
        void show();
        void save();
        void show_help();
        Dialog(DataTable * tab);
        Dialog();
};

void Dialog::show() {
    clear_all();
    char ch;
    string title1 = "";
    string place1 = "";
    int year1;
    cout << "Добавление памятника архитектуры Санкт-Петербурга" << endl << endl;
    cin.clear();
    cout << "Название      "; getline(cin, title1);
    cout << "мето          "; getline(cin, place1);
    cout << "Год создания  "; cin >> year1;
    cout << "Сохранить? [y/n] "; ch = getch();
    if (ch == 'y') {
        /* Save data in table */ 
        this->tab->add_line(title1, place1, year1);
        this->tab->show();     
    } else {
        /*  Exit from dialog without saved  */
        this->tab->show();       
    } 
}

void Dialog::show_help() {
    clear_all();
    char ch;
    ifstream input("help.txt");
    string line;
    while( getline( input, line ) ) {
        cout << line << endl;
    }
    ch = getch();
            
}


void Dialog::save() {
     clear_all();
     char ch;
     cout << "You change table data saved it ? [y/n] "; cin >> ch;
     if ((ch== 'Y') || (ch == 'y')) {
         cout << "Save data in file" << endl;
     }
     
     if ((ch== 'n') || (ch == 'N')) {
         cout << "Exit without saved." << endl;      
     }
     getch();
}

Dialog::Dialog(DataTable * tab) {
    this->tab = tab; 
}

Dialog::Dialog() {
    /* empty contructor */ 
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    char c;
    DataTable t1;
/*    t1.add_line("dfdf", "23213", 1998);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("aaaaaaa", "aaaaaaaa", 2000);
    t1.add_line("bbbbbbb", "vvvvvvvv", 2001);
    t1.add_line("ccccccc", "wwwwwwww", 2001); */
    t1.show();
    int up = 0;
    unsigned int ch;
    while(1) {
      if(kbhit()) {
           ch = getch();
           if (ch == 27) {  // выходим из программы клавишей Esc
              if (t1.change) {
                 Dialog dialog(& t1);
                 dialog.save();
              }
              break;
           }
           
           if (ch ==  113 ) { // up key
              gotoxy(40, 24); cout << ++up;  
           }
           if (ch ==  97) { // down key
              gotoxy(40, 24);
              if (up == 0) { 
                  cout << up;
              } else {
                  cout << --up;
              }
           }
           if (ch ==  110) {
               Dialog dialog(& t1);
               dialog.show();
           }
           
           if ((ch == 'q') || (ch == 'Q')) { // пролистывание содержимого вверх
               t1.data_up();   
           }
           
           if ((ch == 'a') || (ch == 'A')) { // пролистывание таблицы вниз
              t1.data_down();              
           }
           
           if ((ch == 'h') || (ch == 'H')) { // справка по использованию программы
               Dialog help;
               help = Dialog();
               help.show_help();
               t1.show();       
           }
           gotoxy(30, 24);  cout << (int) ch;
           while(kbhit()) getch();  //clear the buffer again although it is not necessary, remove this to make the game smoother
       }
    }
    return 0;
}
