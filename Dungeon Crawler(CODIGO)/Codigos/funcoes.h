

void posicaoObjetos(char mapa[][col], posicao* p, posicao* chave,posicao* posporta, posicao* npclv,posicao* botao){


    for(int i = 0; i < lin;i++){
    for(int j = 0; j < col;j++){
    
    

    if(mapa[i][j] == '&')p->x = i,p->y = j;//define a posicao inicial do player
    
    if(mapa[i][j] == '@')chave->x = i,chave->y = j;//define a posicao inicial da chave
    
    if(mapa[i][j] == 'D')posporta->x = i,posporta->y = j;//define a posicao inicial da chave

    if(mapa[i][j] == 'X'){npclv->x = i,npclv->y = j; npc1 = true;}//define a posicao inicial da chave

    if(mapa[i][j] == 'V'){npclv->x = i,npclv->y = j; npc2 = true;}//define a posicao inicial da chave

    if(mapa[i][j] == 'O'){botao->x = i, botao->y = j;}//define a posicao inicial do botao

    if(mapa[i][j] == '#'){espinhosxy[x] = (posicao) {i,j}; x++; mapa[i][j] = '.';}//define a posicao dos espinhos
    
    if(mapavez == 0){
    if(mapa[i][j] == '~'){trilha[t] = (posicao) {i,j}; t++;}//define a posicao da trilha
    }

    if(mapa[i][j] == '>'){teleport[tp] = (posicao) {i,j}; tp++;}//define a posicao dos portais
    
     if(mapa[i][j] == 'P'){npcInte.x = i, npcInte.y = j;}//define a posicao inicial do botao


    }
    }


}

void escreverLetraPorLetra(const char* texto, int delayMs) {
int letras = 40;
int linha = 0;
    for (int i = 0; i < strlen(texto); i++) {
    letras++;
    if(letras >= 38){
        gotoxy(40,18+linha);
        linha++;
        letras = 0;
    }
        putchar(texto[i]);
        fflush(stdout);       // Garante que a letra será impressa imediatamente
        Sleep(delayMs);       // Pausa em milissegundos
    
    }
}

