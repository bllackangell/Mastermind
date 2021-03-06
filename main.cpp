#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Menu(int,char[],char[],int,int,int);
int Jogo(char[],int,int);
void Instrucoes();
void Configuracoes(int&,int&,int&,int&);
void Identificacao(int,char[],char[]);
void Random(char[],int,int,int);
void Tabuleir(char[][12],int,int,int,char[8]);
void Recorde(int,char[]);
void Verificarepeticao(char[],int,int);
int main()
{
    int jogadores=1,dificuldade=1,repeticao=2,tempo=2;
    char jogador1[20]="Jogador 1",jogador2[20]="Jogador 2";
    Menu(jogadores,jogador1,jogador2,dificuldade,repeticao,tempo);
}
void Menu(int jogadores,char jogador1[20], char jogador2[20], int dificuldade, int repeticao,int tempo)
{
    int partidas,pontosjog1=0,pontosjog2=0,pinos,maior;
    system("cls");
    int escolha;
    char senha[8];
    cout<<"\n                     ___  ___             _                           _             _ \n";
    cout<<"                     |  \\/  |            | |                         (_)           | |\n";
    cout<<"                     |      |  __ _  ___ | |_   ___  _ __  _ __ ___   _  _ __    __| |\n";
    cout<<"                     | |\\/| | / _` |/ __|| __| / _ \\| '__|| '_ ` _ \\ | || '_ \\  / _` |\n";
    cout<<"                     | |  | || (_| |\\__ \\| |_ |  __/| |   | | | | | || || | | || (_| |\n";
    cout<<"                     \\_|  |_/ \\__,_||___/ \\__| \\___||_|   |_| |_| |_||_||_| |_| \\__,_|\n";
    cout<<"\nDesenvolvedores: Victor Angelo, Marcos Paulo, Erickson.\n";
    cout<<"\n1-Jogar\n";
    cout<<"2-Instrucoes\n";
    cout<<"3-Configuracoes\n";
    cout<<"4-Identificacao\n";
    cout<<"5-Sair\n";
    cin>>escolha;
    while(escolha<1 || escolha>5)
        cin>>escolha;
    system("cls");
    cin.ignore();
    switch(escolha)
    {
    case 1:
        if(dificuldade==1)
        {
            pinos=4;
            maior=54;
        }
        else if(dificuldade==2)
        {
            pinos=5;
            maior=55;
        }
        else
        {
            pinos=6;
            maior=56;
        }
        while(escolha==1)
        {
            if(jogadores==1)
                partidas=1;
            else
            {
                cout<<"Quantas partidas deseja jogar? ";
                cin>>partidas;
                while(partidas%2!=0 || partidas<0)
                {
                    cout<<"Numero de partidas precisa ser par e maior que 0.\n";
                    cin>>partidas;
                }
            }
            for(int jogada=0; jogada<partidas; jogada++)
            {
                system("cls");
                if(jogadores==1)
                {
                    jogador2="jogador 2";
                    Random(senha,repeticao,maior,pinos);
                    pontosjog1=pontosjog1+10-Jogo(senha,dificuldade,tempo);
                    if(pontosjog1>0)
                    {
                        cout<<"Parabens "<<jogador1<<" Voce ganhou!\n";
                        ifstream fin("recorde.txt");
                        char ch;
                        int pontos;
                        while(fin.get(ch))
                        {
                            pontos=ch-'0';
                        }
                        fin.close();
                        if(pontosjog1>pontos)
                            Recorde(pontosjog1,jogador1);
                    }
                }
                else
                {
                    if(jogada%2==0)
                    {
                        char ch;
                        cout<<jogador1<<"\nDigite a senha: ";
                        for(int i=0; i<pinos; i++)
                        {
                            cin>>ch;
                            while(ch<49 || ch>maior)
                            {
                                cout<<i<<" Numero repetido. Digite novamente: ";
                                cin>>ch;
                            }
                            senha[i]=ch;
                        }
                        if(repeticao==2)
                            Verificarepeticao(senha,pinos,maior);
                        fflush(stdin);
                        system("cls");
                        cout<<"Partida "<<jogada+1<<endl;
                        cout<<"Restam "<<partidas-1-jogada<<endl;
                        cout<<jogador2<<" sua vez.\n";
                        pontosjog1=pontosjog1+Jogo(senha,dificuldade,tempo);
                    }
                    else
                    {
                        char ch;
                        cout<<jogador2<<"\nDigite a senha: ";
                        for(int i=0; i<pinos; i++)
                        {
                            cin>>ch;
                            while(ch<49 || ch>maior)
                            {
                                cout<<i<<" Numero repetido. Digite novamente: ";
                                cin>>ch;
                            }
                            senha[i]=ch;
                        }
                        if(repeticao==2)
                            Verificarepeticao(senha,pinos,maior);
                        fflush(stdin);
                        system("cls");
                        cout<<"Partida "<<jogada+1<<endl;
                        cout<<"Restam "<<partidas-1-jogada<<endl;
                        cout<<jogador1<<" sua vez.\n";
                        pontosjog2=pontosjog2+Jogo(senha,dificuldade,tempo);
                    }
                    cout<<jogador1<<": "<<pontosjog1<<"\t"<<jogador2<<": "<<pontosjog2<<endl;
                    system("pause");
                    if(jogadores==2)
                    {
                        if(pontosjog1>pontosjog2)
                            cout<<"Parabens "<<jogador1<<" Voce ganhou!\n";
                        else if(pontosjog2>pontosjog1)
                            cout<<"Parabens "<<jogador2<<" Voce ganhou!\n";
                        else
                            cout<<"Empate!\n";
                    }
                }
            }
            cout<<"Deseja jogar novamente?(1-sim, 2-nao)\n";
            cin>>escolha;
            while(escolha<1 || escolha>2)
            {
                cout<<"Numero invalido.\n";
                cin>>escolha;
            }
            system("cls");
        }
        break;
    case 2:
        Instrucoes();
        break;
    case 3:
        Configuracoes(jogadores,dificuldade,repeticao,tempo);
        break;
    case 4:
        Identificacao(jogadores,jogador1,jogador2);
        break;
    case 5:
        return;
    }
    Menu(jogadores,jogador1,jogador2,dificuldade,repeticao,tempo);
}
int Jogo(char senha[8],int dificuldade,int tempo)
{
    int l=0,cont=0,pinos,cores,limjogadas,fin,decorrido;
    double inicio=0;
    char tabuleiro[14][12],c, corespossiveis[9]= {"12345678"};
    if(tempo==1)
        decorrido=time(0);
    if(dificuldade==1)
    {
        pinos=4;
        cores=6;
        limjogadas=10;
        fin=900;
    }
    else if(dificuldade==2)
    {
        pinos=5;
        cores=7;
        limjogadas=12;
        fin=600;
    }
    else
    {
        pinos=6;
        cores=8;
        limjogadas=14;
        fin=300;
    }
    for(int i=0; i<limjogadas; i++)
        for(int j=0; j<pinos*2; j++)
            tabuleiro[i][j]='*';
    Tabuleir(tabuleiro,limjogadas,pinos,cont,senha);
    cout<<"As opcoes de cores sao: ";
    cout<<corespossiveis[0]<<"-Azul, ";
    cout<<corespossiveis[1]<<"-Vermelho, ";
    cout<<corespossiveis[2]<<"-Amarelo, ";
    cout<<corespossiveis[3]<<"-Verde, ";
    cout<<corespossiveis[4]<<"-Roxo, ";
    cout<<corespossiveis[5];
    if(cores==6)
        cout<<"-Marrom.";
    else if(cores==7)
    {
        cout<<"-Marrom, ";
        cout<<corespossiveis[6]<<"-Cinza.";
    }
    else if(cores==8)
    {
        cout<<corespossiveis[6]<<"-Cinza, ";
        cout<<corespossiveis[7]<<"-Laranja.";
    }
    cout<<endl;
    while((l<limjogadas and cont!=pinos) and inicio<=fin)
    {
        cout<<"Digite a senha: ";
        cont=0;
        for(int i=0; i<pinos; i++)
        {
            cin>>c;
            while(c<49 || c>56)
            {
                fflush(stdin);
                cout<<"Digite novamente. ";
                cin>>c;
            }
            tabuleiro[l][i]=c;
        }
        system("cls");
        fflush(stdin);
        for(int i=0; i<pinos; i++)
        {
            if(tabuleiro[l][i]==senha[i])
            {
                tabuleiro[l][i+pinos]='P';
                cont++;
            }
        }
        if(cont!=pinos)
            for(int a=0; a<pinos; a++)
                for(int j=0; j<pinos; j++)
                {
                    if(senha[a]==tabuleiro[l][j] and tabuleiro[l][a+pinos]=='*')
                    {
                        tabuleiro[l][a+pinos]='B';
                        break;
                    }
                }
        Tabuleir(tabuleiro,limjogadas,pinos,cont,senha);
        l++;
        if(tempo==1)
        {
            inicio=time(0)-decorrido;
            if(inicio>=60)
                cout<<"Tempo: "<<inicio/60<<" minutos."<<endl;
            else
                cout<<"Tempo: "<<inicio<<" segundos."<<endl;
        }
    }
    if(cont==pinos)
        return l;
    else
        return 0;
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
void Configuracoes(int& jogadores, int& dificuldade, int& repeticao, int& tempo)
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
    while(repeticao>2 || repeticao<1)
        cin>>repeticao;
    cout<<"Ativar limite de tempo?(1-sim, 2-nao): ";
    cin>>tempo;
    while(tempo>2 || tempo<1)
        cin>>tempo;
}
void Identificacao(int jogadores,char jogador1[20], char jogador2[20])
{
    cout<<"Recorde: ";
    char ch;
    ifstream fin("recorde.txt");
    while(fin.get(ch))
        cout.put(ch);
    fin.close();
    cout<<" pontos.";
    cout<<"\nDigite o nome do jogador 1: ";
    cin.getline(jogador1,20);
    if(jogadores==2)
    {
        cout<<"Digite o nome do jogador2: ";
        cin.getline(jogador2,20);
    }
}
void Random(char senha[8],int repeticao, int maior, int pinos)
{
    srand(time(0));
    for (int i=0; i<pinos; i++)
    {
        do
        {
            senha[i]=rand()%maior;
        }
        while(senha[i]<49 || senha[i]>maior);
    }
    if(repeticao==2)
        for (int i=0; i<pinos; i++)
        {
            for(int j=0; j<pinos; j++)
            {
                if( i!=j and senha[i]==senha[j])
                {
                    do
                    {
                        senha[j]=rand()%maior;
                    }
                    while(senha[j]<49 || senha[j]>maior);
                    i=0;
                }
            }
        }
}
void Tabuleir(char tabuleiro[][12],int limjogadas,int pinos,int cont,char senha[8])
{
    if(pinos==4)
    {
        cout<<"             _________________________________________________";
        cout<<"\n            |                                                 |\n            |Senha:";
    }
    else if(pinos==5)
    {
        cout<<"             _____________________________________________________________";
        cout<<"\n            |                                                             |\n            |Senha:";
    }
    else
    {
        cout<<"             _________________________________________________________________________";
        cout<<"\n            |                                                                         |\n            |Senha:";
    }
    for(int i=0; i<pinos; i++)
    {
        if(cont==4)
            cout<<"("<<senha[i]<<")";
        else
        cout<<"(x)";
    }
    if(pinos==4)
    {
        cout<<"                               |\n";
        cout<<"            |_________________________________________________|\n";
    }
    else if(pinos==5)
    {
        cout<<"                                        |\n";
        cout<<"            |_____________________________________________________________|\n";
    }
    else
    {
        cout<<"                                                 |\n";
        cout<<"            |_________________________________________________________________________|\n";
    }
    for(int i=0; i<limjogadas; i++)
    {
        cout<<"            |";
        for(int j=0; j<pinos*2; j++)
        {
            cout<<"(_"<<tabuleiro[i][j]<<"_)|";
            if(j==pinos-1)
                cout<<" |";
        }
        cout<<endl;
    }
    if(pinos==4)
        cout<<"             ------------------------ ------------------------\n";
    else if(pinos==5)
        cout<<"             ------------------------------ ------------------------------\n";
    else
        cout<<"             ------------------------------------ ------------------------------------\n";
}
void Recorde(int pontosjog1,char jogador[20])
{
    ofstream fout("recorde.txt");
    for(int i=0; jogador[i]!='\0'; i++)
        fout<<jogador[i];
    fout<<":"<<pontosjog1;
    fout.close();
}
void Verificarepeticao(char senha[8],int pinos,int maior)
{
    char ch;
    int repetido=0;
    do
    {
        for(int i=0; i<pinos; i++)
        {
            for(int j=0; j<pinos; j++)
            {
                if(i!=j and senha[i]==senha[j])
                {
                    repetido=1;
                    break;
                }
                else
                    repetido=0;
            }
            if(repetido==1)
                break;
        }
        if(repetido==1)
        {
            cout<<"Numeros repetidos. Digite outra senha: ";
            for(int i=0; i<pinos; i++)
            {
                do
                {
                    cin>>ch;
                }
                while(ch<49 || ch>maior);
                senha[i]=ch;
            }
        }
    }
    while(repetido==1);
}
