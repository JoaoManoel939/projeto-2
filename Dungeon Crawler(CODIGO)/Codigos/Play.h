   



void play(int *opcao){

do{
    
    for(int i = 0 ; i < MAX_espinhos; i++){
    espinhosxy[i] = (posicao) {0,0};
    }

    srand(time(NULL));
    status player,npcstatuslv;
    player.vidamax = 3;
    vidaantiga = player.vidamax;
    posicao p = {0,0},chave = {0,0},npclv = {0,0},posporta = {0,0},botao = {0,0};

    

    while (continuar) {//selecao dos mapas

    


    char lobby[lin][col] = {

        "                                                                           ",
        "  ..................................&....................................  ",
        "  ..................................~....................******..........  ",
        "  .....******.......................~....................*....*..........  ",
        "  .....*    *.......................~....................*....*..........  ",
        "  .....*    *.......................~....................******..........  ",
        "  .....*    *.......................~....................................  ",
        "  .....*    *.......................~....................................  ",
        "  .....******.......................~....................................  ",
        "  ........P.........................~.............................******.  ",
        "  .......~.~........................~.............................*....*.  ",
        "  ........~.~.......................~.............................*....*.  ",
        "  .........~.~......................~.......................*******....*.  ",
        "  ..........~.~.....................~.................................@*.  ",
        "  ...........~.~....................~.......................*******....*.  ",
        "  ............~.~...................~.............................*....*.  ",
        "  .............~.~..................~.............................*....*.  ",
        "  ..............~.~.~.~.~.~.~.~.~.~.~.............................******.  ",
        "  ..................................~....................................  ",
        "  ..................................~....................................  ",
        "  ..................................~....................................  ",
        "  ..................................~....................................  ",
        "  ..................................D....................................  ",
        "                                                                           ",
    };
    
    char mapaNivel1[lin][col] = {

        "                                                                           ",
        "               . . . . . . . . . . . . . . . . . . . . . . . . . .         ",
        "               .                                                 .         ",
        "               /* * * * * * * * * * * * *        * * * * * * *   .         ",
        "                &.......................*        *......@....*   .         ",
        "               /* * * ...* * * * *......*        *...........*   .         ",
        "               .     *...*       *......*        *...........*   .         ",
        "               .     *...*       *......*        *...........*   .         ",
        "               .     *...*       *.......* * * * * * * *...* * * .         ",
        "               .     *...*       *.............................* .         ",
        "               .     *...*       *...* * * * * * * *...* * * * * .         ",
        "               .     *...*       *...*             *...*         .         ",
        "               .     *...*       *...*             *...*         .         ",
        "               .     *...*       *...* * * * * * * *...*         .         ",
        "               .     *...*       *.....................*         .         ",
        "               .     *...*       * * * * * * * * * *...*         .         ",
        "               .     *...*                         *...*         .         ",
        "               .     *...* * * * * * * * * * * * * *...*         .         ",
        "               .     *.................................*         .         ",
        "               .     * * * * * * * * * * * * * * *...*           .         ",
        "               . . . . . . . . . . . . . . . . . .|D|. . . . . . .         ",
        
        

    };

    char mapaNivel2[lin][col] = {
        "                                    _                                      ",
        "                                  .| |.                                    ",
        "                                . *.&.* .                                  ",
        "                              .   *...*   .                                ",
        "                            .     *...*     .                              ",
        "                          .       *...*       .                            ",
        "                        .         *...*         .                          ",
        "                      .           *...*           .                        ",
        "                    .             *...**********    .                      ",
        "                  .      *****    *............*      .                    ",
        "                .        *...*    *...*******..*        .                  ",
        "              .          *.@.*    *...*     *..*          .                ",
        "            .       ******...*******O********..*            .              ",
        "            .       *..........................*              .            ",
        "             .      *.#.#......................*             .             ",
        "              .     *##...*******************..********     .              ",
        "               .    *..#...............*    *.........*    .               ",
        "                .   ****************...*    *....X....*   .                ",
        "                 .                 *...*    *.........*  .                 ",
        "                  .              ...|D|...  *********** .                  ",
        "                   .           .           .           .                   ",
        "                    .        .               .        .                    ",
        "                     .     .                   .     .                     ",
        "                      .  .                       .  .                      ",
        "                       .                           .                       ",
        "                                                                           ",
    };
    
    char mapaNivel3[lin][col] = {
        "                                                                                      ",
        "                       * * * * *              * * *      * * * * * * * * * * * * *    ",
        "                     *...........*            *.>.*      *.......................*    ",
        "                  * * ............*           *...*      *.......................*    ",
        "                  *....##..........*          *...*     *..........* * *...* * * *    ",
        "                  *..##............ * * * * * *...*    *.........*     *...*          ",
        "   * * *          *.......* ..................*...*   *..........*     *...*          ",
        " *...@...* * * * * *.......*....................... *...........*      *...*          ",
        " *...O..#...................*..................................*       *...*          ",
        " *.#....#....* * * * * * * * * * * * * * *............ * * * *         *...*          ",
        " *.....#...#....*                        *............*                *...*          ",
        " *.........##.....* * * * * * * * * * * *..............* * * * * * * * *...* */       ",
        " *..#......##.........#.....................................................&.        ",
        " *......#...* * * * * * * * * * * * * * *..............* * * * * * * * * * * */       ",
        " *>.......*                              *.............*                              ",
        " *.V..#..*                             *...............*                              ",
        " *.....*                             *................*                               ",
        " *##.*                             *... * * *.......*                                 ",
        " *...*                           *... *      *...*                                    ",
        " *...*                         *... *        *...*                                    ",
        " *...*                       *... *          *...*                                    ",
        " *...* * * * * * * * * * * *.....*           *...*                                    ",
        " *..............................*            *...*                                    ",
        " * * * * * * * * * * * * * * * *             *|D|*                                    ",
        "                                                                                      ",

    };

    if(morto){
        player.vidamax-=1;
        tp = 0;
        morto = false;
    }
   
    
    

    
    player.vida = player.vidamax;//vida do player

    
    
    system("cls");
        switch(mapavez){

    case 0:
    /*                   [ LOBBY ]                   */

    posicaoObjetos(lobby,&p,&chave,&posporta,&npclv, &botao);//posiciona os objetos usando de base a matriz
    
    
    player.vida = vidaantiga;
            
    pegouChave = false;// false = chaveNpega | true  = chavepega
    porta = false;//false = porta fechada | true = porta aberta
    npcvivo = true;// false = npc morto | true = npc vivo
    botaopress = false;
    espinhos = false;

    gerarmapa(lobby,&p,&npclv,&chave,&posporta,&player,&npcstatuslv,&botao,mapavez);//gerar mapa
        break;

        
    case 1:

    /*                  [ DUNGEON 1 ]                   */

    posicaoObjetos(mapaNivel1,&p,&chave,&posporta,&npclv,&botao);//posiciona os objetos usando de base a matriz

    player.vida = vidaantiga;
    
    pegouChave = false;// false = chaveNpega | true  = chavepega
    porta = false;//false = porta fechada | true = porta aberta
    npcvivo = true;// false = npc morto | true = npc vivo
    botaopress = false;
    espinhos = false;


    gerarmapa(mapaNivel1,&p,&npclv,&chave,&posporta,&player,&npcstatuslv,&botao,mapavez);//gerar mapa
         
        break;

    case 2:
    
    /*                  [ DUNGEON 2 ]                   */

    posicaoObjetos(mapaNivel2,&p,&chave,&posporta,&npclv,&botao);//posiciona os objetos usando de base a matriz
    
    

    pegouChave = false;// false = chaveNpega | true  = chavepega
    porta = false;//false = porta fechada | true = porta aberta
    npcvivo = true;// false = npc morto | true = npc vivo
    botaopress = false;
    espinhos = false;

    
    

    gerarmapa(mapaNivel2,&p,&npclv,&chave,&posporta,&player,&npcstatuslv,&botao,mapavez);//gerar mapa

        break;


    case 3:
    /*                  [ DUNGEON 3 ]                   */

    posicaoObjetos(mapaNivel3,&p,&chave,&posporta,&npclv, &botao);//posiciona os objetos usando de base a matriz
    
            
    pegouChave = false;// false = chaveNpega | true  = chavepega
    porta = false;//false = porta fechada | true = porta aberta
    npcvivo = true;// false = npc morto | true = npc vivo
    botaopress = false;
    espinhos = false;


    gerarmapa(mapaNivel3,&p,&npclv,&chave,&posporta,&player,&npcstatuslv,&botao,mapavez);//gerar mapa
        break;



    
    }//switch

    
    }//loop


if(!sair){
continuar = true;
}
opcao = 0;

}while(continuar);

    getch();
    gotoxy(0,20);


}


void vitoria(){

char* vitoria[] = {

    "       * Vitoria *       ",
    "                         ",
    "  Parabens, voce ganhou  ",
    "    Obrigado por jogar   ",

};

for(int i = 0;vitoria[i] >= NULL;i++){
gotoxy(40,3+i);
printf("%s\n", vitoria[i]);
}

}

void gameOver(){


int op = 1;
system("cls");
while(1){
HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);

char *menufim[4] = {"Voce Morreu!", "Tentar Novamente", "Menu Principal", "Sair"};


for(int i = 0; i < 4;i++){
if(i == 0){gotoxy(45,3+i); SetConsoleTextAttribute(cor,4);}

if(i == 1){gotoxy(43,4+i);SetConsoleTextAttribute(cor,7);}

if(i == 2)gotoxy(44,5+i);

if(i == 3)gotoxy(49,6+i);

if(i != op){
printf("   %s      ", menufim[i]);
}else{

printf(" [ %s ]", menufim[i]);

}

}

gotoxy(0,0);
printf("%d", op);

int tecla = getch();

if(tecla == 'w' && op > 1)op--;
if(tecla == 's' && op < 3)op++;

if(tecla == 13){

if(op == 1){continuar = false; mapavez = 0;break;}
if(op == 2){continuar = false; sair = true; break;}

}


}


}
