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
    gotoxy(0,0);
}

class DataTable {
    private:
        main_table data[100];
        int table_length;
        unsigned int id;
        unsigned int first_index; 
    public:
        DataTable();
        void show();
        void clear_table();
        void add_line(char * title, char * place, int year);
        void data_up();
        void data_down();
};

DataTable::DataTable() {
     this->table_length = 0;
     this->id = 1;
     this->first_index = 1;
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
    int len = this->table_length;
    int id = this->first_index;
    for (int i=1; i <(TABLE_ROWS+1); i++, id++) {
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
    char title1[64];
    char place1[64];
    int year1;
    cout << "Add new cultural item" << endl << endl;
    cout << "Title = ";    cin >> title1;
    cout << "Place = ";    cin >> place1;
    cout << "Year =  ";    cin >> year1;
    cout << "Save? [y/n] "; ch = getch();
    if (ch == 'y') {
        /* Save data in table */ 
        this->tab->add_line(title1, place1, year1);
        this->tab->show();     
    } else {
        /*  Exit from dialog without saved  */
        this->tab->show();       
    } 
}

Dialog::Dialog(DataTable * tab) {
    this->tab = tab; 
}


int main(int argc, char *argv[])
{
    char c;
    DataTable t1;
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
    t1.show();
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
               Dialog dialog(& t1);
               dialog.show();
           }
           
           if (ch == 113) { // scroll table up
               t1.data_up();   
           }
           
           if (ch == 97) { // scroll table donwn
              t1.data_down();              
           }
           gotoxy(30, 24);  cout << (int) ch;
           while(kbhit()) getch();  //clear the buffer again although it is not necessary, remove this to make the game smoother
       }
       //add a wait here if you want
    }
    return 0;
}
