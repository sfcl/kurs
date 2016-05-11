#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

const int TABLE_ROWS = 8;

struct main_table {
    unsigned int id;
    char * title;
    char * place;
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
}

class DataTable {
    private:
        main_table data[100];
        int table_length;
        unsigned int id; 
    public:
        DataTable();
        void show();
        void clear_table();
        void add_line(char * title, char * place, int year);
};

DataTable::DataTable() {
     this->table_length = 0;
     this->id = 1;
}

void DataTable::show() {
    gotoxy(0, 0);
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

void DataTable::clear_table() {
     for(int y=0; y < 19; ++y) {
        for(int x=0; x < 80; ++x) {
            gotoxy(x, y);
            cout << " " << endl;
        }    
     }
}

void DataTable::add_line(char * title, char * place, int year) {
    /* Максимальное количество отображаемых строк 8 
    если больше то производим перегруппировку таблицы
     */
    this->table_length++;
    int len = this->table_length;
    /* косвеенное вычисление координаты следующей строки */
    this->data[len].id    = this->id;
    this->data[len].title = title;
    this->data[len].place = place;
    this->data[len].year  = year;
    this->id++;
    if (len < (TABLE_ROWS+1)) {
        gotoxy(2, 3+((len-1)*2));
        cout << id << endl;
        
        gotoxy(6, 3+((len-1)*2));
        cout << title << endl;
        
        gotoxy(36, 3+((len-1)*2));
        cout << place << endl;
        
        gotoxy(65, 3+((len-1)*2));
        cout << year << endl;
        
        gotoxy(0, 4+((len-1)*2));
        cout << "+----+-----------------------------+----------------------------+-------------+" << endl;    
    } 
    /*else { */
        /* очищаем экран */
    /*    this->clear_table();
        this->show();
        int i, j;

        for(i=(len - TABLE_ROWS + 1), j=0; j<TABLE_ROWS ; i++, j++ ) {
            /* i осуществяет перебор id */
            /* j осуществяет перебор строк */         
      /*     gotoxy(2, 3+(j*2));
           cout << this->data[i].id << endl;
            
           gotoxy(6, 3+(j*2));
           cout << this->data[i].title << endl;
            
           gotoxy(36, 3+(j*2));
           cout << this->data[i].place << endl;
            
           gotoxy(65, 3+(j*2));
           cout << this->data[i].year << endl;
            
           gotoxy(0, 4+(j*2));
           cout << "+----+-----------------------------+----------------------------+-------------+" << endl; 
                       
        }
    }  */
    
};


class Dialog {
    private:
        char * title;
        char * place;
        int year;
        DataTable * tab;
        
    public:
        void show();
        Dialog(DataTable * tab);

};

void Dialog::show() {
    clear_all();
    char ch;
    cout << "Title = ";    cin >> this->title;
    cout << "Place = ";    cin >> this->place;
    cout << "Year =  ";    cin >> this->year;
    cout << "Save? [y/n]"; ch = getch();
    if (ch == 'y') {
        /* Save data in table */ 
        tab->add_line(this->title, this->place, this->year);     
    } else {
        /*  Exit from dialog without saved  */       
    } 
}

Dialog::Dialog(DataTable * tab) {
    this->tab = tab; 
}


int main(int argc, char *argv[])
{
    char c;
    DataTable t1;
    t1.show();
    t1.add_line("dfdf", "23213", 1998);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("dsdsd", "sdsd13", 1999);
    t1.add_line("aaaaaaa", "aaaaaaaa", 2000);
    t1.add_line("bbbbbbb", "vvvvvvvv", 2001);
    t1.add_line("ccccccc", "wwwwwwww", 2001);
    gotoxy(0, 24);
    cout << "Введите команду -> ";
    int up = 0;
    unsigned int ch;
    while(1) {
      if(kbhit()) {
           ch = getch();
           if ((ch == 'e') || (ch == 'E')) {
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
           if (ch ==  110) { //  create new object by n key
              
           }
           gotoxy(30, 24);  cout << (int) ch;
           while(kbhit()) getch();  //clear the buffer again although it is not necessary, remove this to make the game smoother
       }
       //add a wait here if you want
    }
    return 0;
}
