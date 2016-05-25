#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void Menu(int,int,int);
void Jogo();
void Instrucoes();
void Configuracoes(int,int,int);
void Identificacao();

int main()
{
    int jogadores=1,dificuldade=1,repeticao=2;
    Menu(jogadores,dificuldade,repeticao);
}
void Menu(int jogadores=1, int dificuldade=1, int repeticao=2)
{
    system("cls");//para n�o colocar um system cls em cada fun��o achei melhor deixar 2 no menu
    int escolha;
    cout<<"\n                     ___  ___             _                           _             _ \n";
    cout<<"                     |  \\/  |            | |                         (_)           | |\n";
    cout<<"                     |      |  __ _  ___ | |_   ___  _ __  _ __ ___   _  _ __    __| |\n";
    cout<<"                     | |\\/| | / _` |/ __|| __| / _ \\| '__|| '_ ` _ \\ | || '_ \\  / _` |\n";
    cout<<"                     | |  | || (_| |\\__ \\| |_ |  __/| |   | | | | | || || | | || (_| |\n";
    cout<<"                     \\_|  |_/ \\__,_||___/ \\__| \\___||_|   |_| |_| |_||_||_| |_| \\__,_|\n";
    cout<<"\nComponentes: Victor Angelo, Marcos Paulo, Erickson.\n";
    cout<<"\n1-Jogar\n";
    cout<<"2-Instrucoes\n";
    cout<<"3-Configuracoes\n";
    cout<<"4-Identificacao\n";
    cin>>escolha;
    while(escolha<1 || escolha>4)
        cin>>escolha;
    system("cls");
    switch(escolha)
    {
    case 1:
        Jogo();
        break;
    case 2:
        Instrucoes();
        break;
    case 3:
        Configuracoes(jogadores,dificuldade,repeticao);
        break;
    case 4:
        Identificacao();
        break;
    }
    Menu(jogadores,dificuldade,repeticao);
}
void Jogo()
{
    cout<<"Ainda n esta pronto";
}
void Instrucoes()
{
    ifstream instrucao("instru��o.txt");
    char ch;
    while(instrucao.get(ch))
        cout.put(ch);
    instrucao.close();
    cout<<endl;
    system("pause");
}
void Configuracoes(int& jogadores, int& dificuldade, int& repeticao)
{
    cout<<"Digite a quantidade de jogadores: ";
    cin>>jogadores;
    while(jogadores>2 || jogadores<1)
        cin>>jogadores;
    cout<<"Escolha a dificulade do jogo(nivel 1, nivel 2, nivel 3): ";
    cin>>dificuldade;
    while(dificuldade>3 || dificuldade<1)
        cin>>dificuldade;
    cout<<"Podera repetir cores na senha?(1-sim, 2-nao): ";
    cin>>repeticao;
    while(repeticao>3 || repeticao<1)
        cin>>repeticao;
}
void Identificacao()
{
}