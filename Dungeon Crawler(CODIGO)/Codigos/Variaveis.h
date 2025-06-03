#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>



#define lin 25//evite passar de 25 para nao ficar piscando o mapa
#define col 100
#define MAX_espinhos 30
#define portais 2


void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
   
typedef struct {
    int x, y;
} posicao;

bool proximos(posicao a, posicao b) {//comparar a distancia do player e do npc  
    return (abs(a.x - b.x) + abs(a.y - b.y)) == 1;
}

typedef struct{
    int vida;
    int vidamax;
    int dano;
    
}status;



    
void gerarmapa(char mapa[][col], posicao* p,posicao * npc,posicao* chave, posicao* posporta,status* player,status* npcstatuslv1,posicao* botao, int proxmapa);
void posicaoObjetos(char mapa[][col], posicao* p, posicao* chave,posicao* posporta, posicao* npc,posicao* botao);
void escreverLetraPorLetra(const char* texto, int delayMs);

void menu(char nomeB1[], void botao1(), char nomeB2[], void (*botao2)());
void play(int *opcao);
void creditos(int *opcao);
void vitoria();
void gameOver();

    bool npc1;
    bool npc2;
    bool mover;
    bool porta = false;
    bool pegouChave = false;
    bool npcvivo = true;
    bool botaopress = false;
    bool espinhos = false;
    bool continuar = true;
    bool sair = false;
    posicao espinhosxy[MAX_espinhos];
    posicao teleport[portais];
    posicao trilha[50];
    posicao npcInte = {0,0};
    
    int vidaantiga;
    int movimento = 0;
    int mapavez = 0;
    int x = 0, t = 0, tp = 0;

    bool morto = false;
    

#include "Menu.h"
#include "telaMenus.h"
#include "Play.h"
#include "funcoes.h"
#include "CarregarMapa.h"
