/**
* @file     main.cpp
* @brief 	Arquivo fonte para execução do projeto
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    21/06/2017
* @date     21/06/2017
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dionisio.h"

using std::cout;
using std::cerr;
using std::endl;
using namespace edb1;

/**
* @brief        Função principal do programa
* @param[in]	argc	Quantidade de argumentos
* @param[in]    *argv[]	Lista de argumentos
* @return		Retorno
*/
int main(int argc, char* argv[]) {
    //Testa a classe lista
    cout << "-------------------------\nTeste de lista ligada" << endl;
    Lista<int> *nova = new Lista<int>();
    nova->Insere(12);
    nova->Insere(22);
    nova->Insere(32);
    nova->Exibe();
    nova->RemovePos(0);
    nova->RemovePos(0);
    nova->RemovePos(0);
    nova->RemovePos(0);//Deve dar erro - lista vazia
    
    //Testa a classe pilha
    cout << "-------------------------\nTeste de pilha" << endl;
    Pilha<int> piula(3);
    piula.Push(30);
    piula.Push(40);
    piula.Push(55);
    piula.Push(100); //4º Elemento - deve dar erro - pilha cheia
    while(!piula.Vazio())
        cout << piula.Pop() << endl;
    piula.Pop(); //Pilha vazia - Deve dar erro - pilha vazia

    //Testa a classe fila
    cout << "-------------------------\nTeste de fila" << endl;
    Fila<int> fila(3);
    fila.Push(30);
    fila.Push(40);
    fila.Push(55);
    fila.Push(100); //4º Elemento - deve dar erro - fila cheia
    while(!fila.Vazio())
        cout << fila.Pop() << endl;
    fila.Pop(); //Fila vazia - Deve dar erro - fila vazia

    //Testa as buscas
    cout << "-------------------------\nTestes de buscas" << endl;
    int V[100];
    for(int i = 0; i < 100; i++)
        V[i] = i + 1;
    cout << "-------------------------\nBusca sequencial iterativa" << endl;
    cout <<  linear_search_i(V, 0, 100, 30) << endl;
    cout << "Busca sequencial recursiva" << endl;
    cout <<  linear_search_r(V, 0, 100, 60) << endl;
    cout << "Busca sequencial iterativa" << endl;
    cout <<  linear_search_i(V, 0, 100, 1030) << endl;  //Deve dar erro - elemento não encontrado
    cout << "Busca sequencial recursiva" << endl;
    cout <<  linear_search_r(V, 0, 100, 1060) << endl;  //Deve dar erro - elemento não encontrado

    cout << "-------------------------\nBusca binária iterativa" << endl;
    cout <<  binary_search_i(V, 0, 100, 30) << endl;
    cout << "Busca binária recursiva" << endl;
    cout <<  binary_search_r(V, 0, 100, 60) << endl;
    cout << "Busca binária iterativa" << endl;
    cout <<  binary_search_i(V, 0, 100, 1030) << endl;  //Deve dar erro - elemento não encontrado
    cout << "Busca binária recursiva" << endl;
    cout <<  binary_search_r(V, 0, 100, 1060) << endl;  //Deve dar erro - elemento não encontrado
    
    cout << "-------------------------\nBusca ternária iterativa" << endl;
    cout << ternary_search_i(V, 0, 100, 30) << endl;
    cout << "Busca ternária recursiva" << endl;
    cout << ternary_search_r(V, 0, 100, 60) << endl;
    cout << "Busca ternária iterativa" << endl;
    cout << ternary_search_i(V, 0, 100, 1030) << endl;  //Deve dar erro - elemento não encontrado
    cout << "Busca ternária recursiva" << endl;
    cout << ternary_search_r(V, 0, 100, 1060) << endl;  //Deve dar erro - elemento não encontrado

    //Testa as ordenações

    srand(time(NULL));
    double *X = new double[10];
    //Inicializa aleatoriamente
    cout << "-------------------------\nInsertion sort" << endl;
    for(int i = 0; i < 10; i++)
        X[i] = rand() % 100;
    //Exibe o vetor
    cout << "Vetor desordenado" << endl;
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Ordena o vetor
    cout << "Ordena vazio" << endl;
    insertionSort(X, 0);          //Deve dar erro - vetor vazio
    cout << "Ordena com insertion sort" << endl;
    insertionSort(X, 10);
    //Exibe o vetor
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Inicializa aleatoriamente
    cout << "-------------------------\nSelection Sort" << endl;
    for(int i = 0; i < 10; i++)
        X[i] = rand() % 100;
    //Exibe o vetor
    cout << "Vetor desordenado" << endl;
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Ordena o vetor
    cout << "Ordena vazio" << endl;
    selectionSort(X, 0);          //Deve dar erro - vetor vazio
    cout << "Ordena com selection sort" << endl;
    selectionSort(X, 10);
    //Exibe o vetor
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Inicializa aleatoriamente
    cout << "-------------------------\nMerge sort" << endl;
    for(int i = 0; i < 10; i++)
        X[i] = rand() % 100;
    //Exibe o vetor
    cout << "Vetor desordenado" << endl;
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Ordena o vetor
    cout << "Ordena vazio" << endl;
    mergeSort(X, 1, 0);          //Deve dar erro - vetor vazio
    cout << "Ordena com merge sort" << endl;
    mergeSort(X, 0, 9);
    //Exibe o vetor
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Inicializa aleatoriamente
    cout << "-------------------------\nQuick Sort" << endl;
    for(int i = 0; i < 10; i++)
        X[i] = rand() % 100;
    //Exibe o vetor
    cout << "Vetor desordenado" << endl;
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Ordena o vetor
    cout << "Ordena vazio" << endl;
    quickSort(X, 1, 0);          //Deve dar erro - vetor vazio
    cout << "Ordena com quick sort" << endl;
    quickSort(X, 0, 9);
    //Exibe o vetor
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Inicializa aleatoriamente
    cout << "-------------------------\nBubble Sort" << endl;
    for(int i = 0; i < 10; i++)
        X[i] = rand() % 100;
    //Exibe o vetor
    cout << "Vetor desordenado" << endl;
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    //Ordena o vetor
    cout << "Ordena vazio" << endl;
    bubbleSort(X, 0);          //Deve dar erro - vetor vazio
    cout << "Ordena com bubble sort" << endl;
    bubbleSort(X, 10);
    //Exibe o vetor
    for(int i = 0; i < 10; i++)
        cout << X[i] << "  ";
    cout << endl;

    return 0;
}