//Reloj Digital funciona no al 100 pero es con mucho esfuerzo 
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<fstream>
#include<dos.h>
#include<iostream>
using namespace std;
void reloj();
void escribir();
//Aqui lo quise hacer de la manera mas creativa y lo hice con @ para que diera otro toque mas ironico, también el tamaño que no se vea tan grande ni pequeño  
const char *a0[7][4] ={  "@@","@@","@@","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@@","@@","@@","@"};

const char *a1[7][4] ={  "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@"};

const char *a2[7][4] ={  "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "@@","@@","@@","@",
                         "@ ","  ","  "," ",
                         "@ ","  ","  "," ",
                         "@@","@@","@@","@"};

const char *a3[7][4] ={  "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "@@","@@","@@","@"};

const char *a4[7][4] ={  "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@"};

const char *a5[7][4] ={  "@@","@@","@@","@",
                         "@ ","  ","  "," ",
                         "@ ","  ","  "," ",
                         "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "@@","@@","@@","@"};

const char *a6[7][4] ={  "@@","@@","@@","@",
                         "@ ","  ","  "," ",
                         "@ ","  ","  "," ",
                         "@@","@@","@@","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@@","@@","@@","@"};

const char *a7[7][4] ={  "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@"};

const char *a8[7][4] ={  "@@","@@","@@","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@@","@@","@@","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@@","@@","@@","@"};

const char *a9[7][4] ={  "@@","@@","@@","@",
                         "@ ","  ","  ","@",
                         "@ ","  ","  ","@",
                         "@@","@@","@@","@",
                         "  ","  ","  ","@",
                         "  ","  ","  ","@",
                         "@@","@@","@@","@"};

const char *Yes[7][4] ={ "  ","  ","  "," ",
                         "  ","  ","  "," ",
                         "  ","@@","@@"," ",
                         "  ","  ","  "," ",
                         "  ","@@","@@"," ",
                         "  ","  ","  "," ",
                         "  ","  ","  "," "};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoxy(int x, int y)                              
{
     CursorPosition.X =x;                              
     CursorPosition.Y =y;                              
     SetConsoleCursorPosition(console, CursorPosition);
};
void setcursor (bool visible, DWORD size){          
    if(size == 0)
      size =20;                                      
    CONSOLE_CURSOR_INFO lpCursor;                   
    lpCursor.bVisible = false;                      
    lpCursor.dwSize = size;                          
    SetConsoleCursorInfo(console, &lpCursor);
};
//Aqui le indico sobre la función de Gotoxy y que me haga el maching para que me funcione bien 
void printDigit(int no, int x, int y)                 
{
  for(int i=0;i<7;i++){
    for(int j=0; j<4;j++){
        switch(no){
          case 0: gotoxy(x+j, y+i); cout<< a0[i][j]; break;
          case 1: gotoxy(x+j, y+i); cout<< a1[i][j]; break;
          case 2: gotoxy(x+j, y+i); cout<< a2[i][j]; break;
          case 3: gotoxy(x+j, y+i); cout<< a3[i][j]; break;
          case 4: gotoxy(x+j, y+i); cout<< a4[i][j]; break;
          case 5: gotoxy(x+j, y+i); cout<< a5[i][j]; break;
          case 6: gotoxy(x+j, y+i); cout<< a6[i][j]; break;
          case 7: gotoxy(x+j, y+i); cout<< a7[i][j]; break;
          case 8: gotoxy(x+j, y+i); cout<< a8[i][j]; break;
          case 9: gotoxy(x+j, y+i); cout<< a9[i][j]; break;
          case 10: gotoxy(x+j, y+i); cout<<Yes[i][j]; break;
      }
    }
  }
};
int main()
{
    system("cls");
    setcursor(0,0);                     
    srand((unsigned) time (NULL));                                         
    time_t now = time(0);                
    char *dt= ctime(&now);            
    tm *lotm = localtime(&now);         
    dt = asctime(lotm);
    int hour = lotm->tm_hour;           
    int min = lotm->tm_min;
    int sec = lotm->tm_sec;
    int gap=8;                         
    int posX;                            
    int posY= 8;
    int op;
    do{
    	// Aqui lo que estoy haciendo es que al momento que me ingrese al Reloj mueste a primera vista lo que se vera reflejado en el reloj 
    	system("cls");
        gotoxy(45,5); cout<<" Reloj Digital :D "<<endl;
        gotoxy(35,17); cout<<"Hola Bienvenido A Mi Trabajo! xD"<<endl;
        posX= 15;
        if(kbhit()){                     
            char ch = getch();          
            if(ch==27){                
                break;
            }
        }
        if(hour< 10){                    
            printDigit(0,posX,posY);
            printDigit(hour,posX+=gap, posY);
        }
        else{
            printDigit(hour/10,posX,posY);
            printDigit(hour%10,posX+=gap, posY);
        }
        printDigit(10,posX+=gap,posY);     
        if(min< 10){                      
            printDigit(0,posX+=gap,posY);
            printDigit(min,posX+=gap, posY);
        }
        else{
            printDigit(min/10,posX+=gap,posY);
            printDigit(min%10,posX+=gap, posY);
        }
        printDigit(10,posX+=gap,posY);     
        if(sec< 10){                        
            printDigit(0,posX+=gap,posY);
            printDigit(sec,posX+=gap, posY);
        }
        else{
            printDigit(sec/10,posX+=gap,posY);
            printDigit(sec%10,posX+=gap, posY);
        }
        Sleep(950);                         
        sec++;
        if(sec>=60){
            sec =0;
            min++;
        }
        if(min>=60){
            min=0;
            hour++;
        }
        if(hour>=24){
            sec=0;
            min=0;
            hour =0;
        }
        //Palabras para poder configurar y programar una Alarma 
    }while(true);
    system("cls");
	gotoxy(45,5); cout<<" Â¡Bienvenido!"<<endl;
	gotoxy(45,7); cout<<" Menu Principal"<<endl;
	gotoxy(45,9); cout<<" 1. Ingreso de  Alarma"<<endl;
	gotoxy(45,11); cout<<"2. Puede eliminar la Alarma"<<endl;
	gotoxy(45,13); cout<<"3. Puede ver la  alarmas"<<endl;
	gotoxy(45,15); cout<<"4. USted ha salido del reloj"<<endl;
	gotoxy(45,18); cout<<"configuración: ";
	gotoxy(54,18); cin>>op;
	switch(op){
		case 1:
			escribir();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
			getchar()!='\n';
	}
};
// Aqui se puede cambiar el nombre y configurar la Alarma 
void escribir(){
	ofstream archivo;
	int alarma;
	string descripcion;
	cout<<"Ingrese a su alarma para configurarla"<<endl;
	cin>>alarma;
	cout<<"Escriba el nombre de la alarma que le pondra"<<endl;
	getline(cin,descripcion);
	
	archivo.open("alarmas.txt",ios::out);
	if(archivo.fail()){
		cout<<"No se obtuvo exito para abrir su alarma"<<endl;
	}
	archivo.close();
};
