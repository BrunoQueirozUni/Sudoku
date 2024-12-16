#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

#define TAM 9
#define POSICAO 41

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    int opcao, definidor;
    int aleaI, aleaJ;
    int linha, coluna;

    do
    {
        int jogadas = 0, acerto = 0, count = 0;
        int jogo[TAM][TAM] = {}, gabarito[TAM][TAM] = {}, original[TAM][TAM] = {
                                                            4, 9, 5, 2, 8, 7, 3, 6, 1,
                                                            7, 2, 8, 6, 1, 3, 4, 9, 5,
                                                            3, 6, 1, 9, 5, 4, 7, 2, 8,
                                                            6, 5, 3, 8, 4, 9, 2, 1, 7,
                                                            9, 8, 4, 1, 7, 2, 6, 5, 3,
                                                            2, 1, 7, 5, 3, 6, 9, 8, 4,
                                                            1, 3, 2, 4, 6, 5, 8, 7, 9,
                                                            5, 4, 6, 7, 9, 8, 1, 3, 2,
                                                            8, 7, 9, 3, 2, 1, 5, 4, 6};
        system("cls");

        // Bruno: Menu de opções.
        cout << "--------------------------------\n";
        cout << "|     Bem-vindo ao Sudoku!     |\n";
        cout << "--------------------------------\n";
        cout << "| Escolha uma opcao:           |\n";
        cout << "| 1 - Jogar                    |\n";
        cout << "| 2 - Sobre                    |\n";
        cout << "| 3 - Fim                      |\n";
        cout << "--------------------------------\n";
        cout << "Opcao: ";
        cin >> opcao;

        // Bruno: Opções de jogo
        switch (opcao)
        {
            case 1:
                // Bruno: Definir tipo da matriz ao começar o jogo.
                definidor = rand() % 4;

                // Bruno: Matriz original, transposta, invertida por linha ou coluna.
                switch (definidor)
                {
                case 0: // Bruno: Matriz original.
                    for (int i = 0; i < TAM; i++)
                        for (int j = 0; j < TAM; j++)
                            gabarito[i][j] = original[i][j]; 
                    break;
                case 1: // Bruno: Matriz transposta.
                    for (int i = 0; i < TAM; i++)
                        for (int j = 0; j < TAM; j++)
                            gabarito[j][i] = original[i][j];
                    break;
                case 2: // Bruno: Matriz invertida por linha.
                    for (int i = 0; i < TAM; i++)
                        for (int j = 0; j < TAM; j++)
                            gabarito[i][j] = original[TAM - 1 - i][j];
                    break;
                case 3: // Bruno: Matriz invertida por coluna.
                    for (int i = 0; i < TAM; i++)
                        for (int j = 0; j < TAM; j++)
                            gabarito[i][j] = original[i][TAM - 1 - j];
                    break;
                }

                // Angelo - Bruno: Gera matriz gabarito.            
                for (int i = 0; i < TAM; i++)
                {
                    for (int j = 0; j < TAM; j++)
                    {
                        jogo[i][j] = gabarito[i][j];
                    }
                }

                // Angelo - Bruno: Gera 41 posições aleatórias.
                while (count <= POSICAO)
                {
                    aleaI = rand() % TAM;
                    aleaJ = rand() % TAM;
                    if (jogo[aleaI][aleaJ] != 0)
                    {
                        jogo[aleaI][aleaJ] = 0;
                        count++;
                    }
                }

                // Angelo - Bruno: Loop principal do jogo.
                while (acerto < POSICAO)
                {
                    system("cls");

                    // Angelo - Bruno: Mostra o jogo na tela.
                    for (int i = 0; i < TAM; i++)
                    {
                        for (int j = 0; j < TAM; j++)
                        {
                            if (jogo[i][j] == 0)
                            {
                                cout << "#" << "\t";
                            }
                            else
                            {
                                cout << jogo[i][j] << "\t";
                            }
                        }
                        cout << endl;
                    }

                    // Angelo - Bruno: Seleciona a linha e coluna para modificar.
                    int escolha;
                    cout << "\n\nEscolha uma linha (1-9): ";
                    cin >> linha;
                    linha--;
                    cout << "\nEscolha uma coluna (1-9): ";
                    cin >> coluna;
                    coluna--;
                    cout << "\nEscolha um numero (1-9): ";
                    cin >> escolha;

                    // Angelo - Bruno: Verifica se o número escolhido é o correto.
                    if (gabarito[linha][coluna] == escolha)
                    {
                        if (jogo[linha][coluna] == 0) {
                            acerto++;
                        }
                        jogo[linha][coluna] = escolha;
                    }
                    else
                    {
                        cout << "----------------------------------------------------------\n";
                        cout << "| Número errado ou posição inexistente, tente novamente! |\n";
                        cout << "----------------------------------------------------------\n";
                        system("pause");
                    }

                    jogadas++;
                }

                cout << "-----------------------------------------------------------------------------\n";
                cout << "| Parabéns, você ganhou!\n" << "Você precisou de " << jogadas << " jogadas. |\n";
                cout << "-----------------------------------------------------------------------------\n";
                system("pause");
                break;


            case 2:
                system("cls");
                cout << "-------------------------------\n";
                cout << "|            SOBRE            |\n";
                cout << "-------------------------------\n";
                cout << "| Nome dos desenvolvedores:   |\n";
                cout << "| - Angelo Miguel Requenha    |\n";
                cout << "| - Bruno de Queiroz          |\n";
                cout << "| - Leandro Gabardo           |\n";
                cout << "| - Carlos Eduardo Serafim    |\n";
                cout << "| - Luiz Eduardo Oro de Souza |\n";
                cout << "-------------------------------\n";
                cout << "| Data: Novembro/2024         |\n";
                cout << "-------------------------------\n";
                cout << "| Professor: Rafael Ballottin |\n";
                cout << "|            Martins          |\n";
                cout << "|                             |\n";
                cout << "| Disciplina: Algoritimos e   |\n";
                cout << "|             Programação     |\n";
                cout << "-------------------------------\n";
                system("pause");
                break;

            default:
                if (opcao == 3)
                {
                    system("cls");
                    cout << "Saindo do jogo! Volte sempre!\n";
                    system("pause");
                    break;
                }
                cout << "Opção inválida, tente novamente!\n";
                system("pause");
                break;
        }

    } while (opcao != 3);

    return 0;
}
