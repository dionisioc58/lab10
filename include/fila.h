/**
* @file     fila.h
* @brief 	Definição da classe Fila
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    20/06/2017
* @date     20/06/2017
*/
#ifndef FILA_H
    #define FILA_H

    #include <iostream>
    #include <string>
    using std::cout;
    using std::endl;
    using std::cerr;
    using std::string;

    #include "erros.h"

    /**
    * @class   Fila fila.h
    * @brief   Classe que representa uma fila
    * @details Os atributos de uma lista são: dados, qtde e max
    */
    template<typename T>
    class Fila {
    private:
        T *dados;                           /**< Dados */
        int qtde;                           /**< Quantidade */
        int max;                            /**< Máximo */
    public:
        Fila(int tam);                     /**< Construtor padrão */
        ~Fila();                           /**< Destrutor padrão */
        void Push(T val);                   /**< Inserir um dado na Fila */
        T Pop();                            /**< Retirar um dado da Fila */
        bool Vazio();                       /**< Testa se a Fila está vazia */
        bool Cheio();                       /**< Testa se a Fila está cheia */
    };

    /**
    * @details Os valores de dados e max são inicializados com o tamanho
    *          informado e a qtde com 0
    */
    template<typename T>
    Fila<T>::Fila(int tam) {
        dados = new T[tam];
        max = tam;
        qtde = 0;
    }

    /**
    * @details Destrutor padrão
    */
    template<typename T>
    Fila<T>::~Fila() {
        delete[] dados;
    }

    /**
    * @details Inserir um dado na Fila
    */
    template<typename T>
    void Fila<T>::Push(T val) {
        if(!Cheio())
            dados[qtde++] = val;
        else {
            //Cheia - lançar exceção
            try {
                throw FilaCheia();
            } catch (FilaCheia &ex) {
                cerr << ex.what() << endl;
            }
        }
    }
    
    /**
    * @details Retirar um dado da Fila
    */
    template<typename T>
    T Fila<T>::Pop() {
        if(!Vazio()) {
            qtde--;
            T retorno = dados[0];
            for(int i = 0; i < qtde; i++)
                dados[i] = dados[i + 1];
            return retorno;
        } else  {
            try {
                throw FilaVazia();
            } catch (FilaVazia &ex) {
                cerr << ex.what() << endl;
            }
            return dados[0];
        }
    }

    /**
    * @details Testa se a Fila está vazia
    */
    template<typename T>
    bool Fila<T>::Vazio() {
        return (qtde == 0);
    }

    /**
    * @details Testa se a Fila está cheia
    */
    template<typename T>
    bool Fila<T>::Cheio() {
        return (qtde == max);
    }

#endif