
void menu(char nomeB1[], void botao1(), char nomeB2[], void (*botao2)()){

HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
   
int menux = 0,menuy = 8; 
int lin1x=0, lin2x = 0;
int op = 0;

char *menu[]= {nomeB1,nomeB2,"SAIR"};

char *tela[] = {
    "                                 ",
    "                                 ",
    "  D U N G E O N  C R A W L E R   ",
    " ------------------------------- ",
    "                                 ",
    "                                 ",
    "                                 ",
    "                                 ",
    "                                 ",
    "                                 ",
};

int novolinx = lin1x;
gotoxy(menux,menuy);
printf(">-------------------------------<");
Sleep(500);
gotoxy(menux,menuy);
printf("                                 ");

for(int i = 0; i < 10;i++){
gotoxy(menux,novolinx+menuy+1);
printf(">-------------------------------<");

gotoxy(menux,menuy+i);
printf("%s", tela[i]);

novolinx++;
lin1x = novolinx;

Sleep(100);

printf("\n");
}

gotoxy(menux,lin1x+menuy);
printf("                                 ");

while(1){

for(int i = 0; i < 10;i++){

gotoxy(menux,menuy+i);
printf("%s", tela[i]);

printf("\n");
}



for(int i = 0; i < 3;i++){
gotoxy(menux+4,(menuy+5)+i);

if(i == op){
SetConsoleTextAttribute(cor,2);
printf("> %s <\n", menu[i]);
SetConsoleTextAttribute(cor,7);
}else{
printf("%s     \n", menu[i]);
}
}


while(kbhit())getch();
int tecla = getch();

if(tecla == 'w' && op > 0)op--;
if(tecla == 's'&& op < 2)op++;

if(tecla == 13){
switch (op){

case 0:
botao1(&op);
    break;

case 1:
botao2(&op);
    break;
}

if(op == 2){
gotoxy(47,16);
printf("(Tem Certeza?)");
tecla = getch();
if(tecla == 13){
break;
}
}

}

}
gotoxy(0,30);


}
