
void creditos(int *opcao){
    HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
   
int creditosx = 46,creditosy = 8; 

char *creditos[] = {
    "                                 ",
    "           [ CRIADORES ]         ",
    "                                 ",
    "            JOAO MANOEL          ",
    "             MARCELLO            ",
    "              HENRY              ",
    "                                 ",
    "                                 ",
    "                                 ",
    "                                 ",
};



for(int i = 0; i < 10;i++){
gotoxy(creditosx,creditosy+i);
printf("%s\n", creditos[i]);
}

int tecla = getch();

*opcao = 0;

gotoxy(0,30);


}

