
void gerarmapa(char mapa[][col], posicao* p,posicao * npc,posicao* chave, posicao* posporta,status* player,status* npcstatus,posicao* botao, int proxmap){ 


char *mapaMostrar[] = {"VILA", "DUNGEON (sala 1)", "DUNGEON (sala 2)", "DUNGEON (sala 3)"};

gotoxy(0,0);
printf("Mapa: %s", mapaMostrar[mapavez]);//mostra no canto superior esquerdo qual mapa 

    
HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
int vidamaxn = npcstatus->vida;



while(continuar && !morto){

    posicao novo;
    novo.x = p->x;
    novo.y = p->y;



        if (!pegouChave) {//PORTA | CHAVE
            if(chave->x != 0 && chave->y != 0)mapa[chave->x][chave->y] = '@';//chave
            
            
        } else {
            if(chave->x != 0 && chave->y != 0)mapa[chave->x][chave->y] = '.';//chave (dps de coletada)
        }

        if(!porta){
        if(posporta->x != 0 && posporta->y != 0)mapa[posporta->x][posporta->y] = 'D';//porta trancada
        }else{
        if(posporta->x != 0 && posporta->y != 0)mapa[posporta->x][posporta->y] = '=';//porta (dps de usar a chave)
        }
        
        // Atualiza personagens no mapa
        if (player->vida > 0 && p->x != 0 && p->y != 0) mapa[p->x][p->y] = '&';//player 
        if(npc1){
        if (npcstatus->vida > 0 && (npc->x != 0 && npc->y != 0) ) mapa[npc->x][npc->y] = 'X';// monstro
        }
        if(npc2){
        if (npcstatus->vida > 0 && (npc->x != 0 && npc->y != 0) ) mapa[npc->x][npc->y] = 'V';// monstro
        }
    


        // Exibe mapa
        for (int x = 0; x < lin; x++){
            gotoxy(22, x + 3);
            printf("%s\n", mapa[x]);
        }
        

         // Exibe vida
        
        gotoxy(30, 0);
        printf("VIDA PLAYER: ");
        for(int i = 0; i < player->vida;i++){
            printf("%c ",219);
        }
        
        gotoxy(65, 0);
        if(npc->x == 0 && npc->y == 0){}

        else if(npcvivo){printf("NPC LVL 1   ", npcstatus->vida, vidamaxn);}

        gotoxy(0,0);


        

        
    int npcintx = 53,npcinty = 22;  
    bool conversando;
    if((p->x >= npcInte.x-1 && p->x <= npcInte.x+1) && (p->y >= npcInte.y-1 && p->y <= npcInte.y+1)){
    gotoxy(npcintx,npcinty);
    printf("  [ NPC ]  ");
    gotoxy(npcintx,npcinty+1);
    printf("'E' Falar");  
    
    }

            //funcao do player
            int tecla = getch();
            if (tecla == 'w') novo.x--;//Player anda para cima
            else if (tecla == 's') novo.x++;//Player anda para baixo
            else if (tecla == 'a') novo.y--;//Player anda para esquerda
            else if (tecla == 'd') novo.y++;//Player anda para direita
            
    if((p->x >= npcInte.x-1 && p->x <= npcInte.x+1) && (p->y >= npcInte.y-1 && p->y <= npcInte.y+1)){
    if(tecla == 'e')conversando = true;
    if(conversando){

    gotoxy(npcintx,npcinty);
    printf("           ");
    gotoxy(npcintx,npcinty+1);
    printf("         ");  
    
    char* mensagem = "Ha muito tempo, Vaeloria era protegidapor um artefato sagrado  o Cristal de   Eldros. Dizem que foi dado pelos      proprios deuses, um presente para     selar os horrores que viviam sob      nossos pes. Enquanto o cristal        brilhava no santuario, nenhuma        criatura ousava se aproximar.  ";
    escreverLetraPorLetra(mensagem,10);
    getch();
    conversando = false;
    }
    
    }
    
            
            if(novo.x == teleport[0].x && novo.y == teleport[0].y){
            gotoxy(0,5);
            mapa[p->x][p->y] = '.';
            p->x = teleport[1].x;
            p->y = teleport[1].y+1;
            }
            if(novo.x == teleport[1].x && novo.y == teleport[1].y){
            gotoxy(0,5);
            mapa[p->x][p->y] = '.';
            p->x = teleport[0].x;
            p->y = teleport[0].y+1;
            }
            

            if((p->x != 0 && p->y != 0)){//(so funciona se player existir na matriz)
                
                mapa[p->x][p->y] = '.';//apaga rastro do player

                
                //BOTAO 
                if(botao->x != 0 && botao->y != 0){

                if(novo.x == botao->x && novo.y == botao->y){//BOTAO PRESSIONADO
                gotoxy(0,0); printf("%s",botaopress ? "* Botao ja foi pressionado *": "* Botao Pressionado *");
                mapa[p->x][p->y] = '.';
                botaopress = true;
                espinhos = true;
                }
                else if(!botaopress ){//botao antes de ser pressionado
                mapa[botao->x][botao->y] = 'O';
                }else{//botao depois de ser pressionado
                gotoxy(0,0); printf("                            ");
                mapa[botao->x][botao->y] = 'o';
                }

                }
                //BOTAO 

                
            } //(so funciona se player existir na matriz)
        
            if(npc->x != 0 && npc->y != 0)mapa[npc->x][npc->y] = '.';//limpa rastro do npc(so funciona se npc existir na matriz)
            // Limpa posições anteriores


            if (mapa[novo.x][novo.y] == '.' || mapa[novo.x][novo.y] == 'O' || mapa[novo.x][novo.y] == 'o' 
                || mapa[novo.x][novo.y] == '#' || mapa[novo.x][novo.y] == '~') {//pode se mover se...
                *p = novo;
            } else {//se nao
                novo = *p;
            }

            //funcao do player


        if (npcstatus->vida <= 0 && npcvivo) {
            gotoxy(30, 5);
            printf("NPC DERROTADO!");
            npcstatus->vida = 0;
            npcvivo = false;
            mapa[npc->x][npc->y] = '.';
        }

        
            if ((p->x >= chave->x - 1 && p->x <= chave->x + 1) &&
                (p->y >= chave->y - 1 && p->y <= chave->y + 1) && !pegouChave) {//interacao com a chave
                
                gotoxy(52, 1);
                printf("  [ CHAVE ]");
                
                gotoxy(52, 2);
                printf("[E interagir]");
                
            if (tecla == 'e') pegouChave = true;

            } else {
                gotoxy(52, 1); printf("             ");
                gotoxy(48, 2); printf("                       ");
            }


            if ((p->x >= posporta->x - 1 && p->x <= posporta->x + 1) &&
                (p->y >= posporta->y - 1 && p->y <= posporta->y + 1)) {//interacao com a porta
                

                if(pegouChave && !porta){
                gotoxy(52, 1);
                printf("  [ PORTA ]");
                
                gotoxy(48, 2);
                printf("[E interagir (ABRIR)]"); 

                if (tecla == 'e'){ 
                    porta = true;
                    tecla = 0;
                }
                }
                else{
                gotoxy(52, 1);
                printf("  [ PORTA ]");

                gotoxy(53, 2);
                printf(" *TRANCADA*");
                }

                if(porta){
                gotoxy(52, 1);
                printf("  [ PORTA ]");
                
                gotoxy(48, 2);
                printf("[E interagir (ENTRAR)"); 

                if (tecla == 'e'){ 
                    system("cls");
                    mapavez = proxmap+1;
                    vidaantiga = player->vida;
                    break;
                }
            }

            }

               

        if(movimento > 6){//sistema de 'cansaço'
        movimento = 0;
        mover = false;
        }else{
        movimento++;
        mover = true;
        }

        if(mover){// Movimento do NPC

        
        int dx = p->x - npc->x;
        int dy = p->y - npc->y;
        int movs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ordem[4];

        if (abs(dx) > abs(dy)) {
            ordem[0] = (dx > 0) ? 2 : 3;
            ordem[1] = (dy > 0) ? 0 : 1;
            ordem[2] = (dy > 0) ? 1 : 0;
            ordem[3] = (dx > 0) ? 3 : 2;
        } else {
            ordem[0] = (dy > 0) ? 0 : 1;
            ordem[1] = (dx > 0) ? 2 : 3;
            ordem[2] = (dx > 0) ? 3 : 2;
            ordem[3] = (dy > 0) ? 1 : 0;
        }


        for (int i = 0; i < 4; i++) {
            int nx = npc->x + movs[ordem[i]][0];
            int ny = npc->y + movs[ordem[i]][1];

            if (nx >= 0 && nx < lin && ny >= 0 && ny < col &&
            (mapa[nx][ny] == '.' || mapa[nx][ny] == '#' || mapa[nx][ny] == 'O') && !(nx == p->x && ny == p->y)) {//npc pode andar

                npc->x = nx;
                npc->y = ny;
                break;
            }
        }
        // Movimento do NPC
    }

    
    if(espinhos && (botao->x != 0 && botao->y != 0) && mapavez != 0){//espinhos ativados

    for(int i = 0 ; i < MAX_espinhos; i++){
    mapa[espinhosxy[i].x][espinhosxy[i].y] = '#';
    }

    if(mapa[p->x][p->y] == '#'){morto = true;}

    }

    if(mapavez == 0){

    for(int i = 0 ; i < 50; i++){
    mapa[trilha[i].x][trilha[i].y] = '~';
    }

    }

    // Combate automático
        if (proximos(*p, *npc) && npcvivo) {
            morto = true;
            
        }
        // Combate automático
    
    

    // Verifica fim de jogo
        if (player->vida <= 0) {
           gameOver();
           system("cls");
        }



}

}
