/**
* @file     erros.h
* @brief 	Arquivo com definições de classes de erro
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    25/06/2017
* @date     25/06/2017
*/

#ifndef ERROS_H
    #define ERROS_H

    #include <stdexcept>
    using std::range_error;
    using std::length_error;
    using std::overflow_error;
    
    /**
    * @brief Erro de elemento não encontrado
    **/
    class ElementoNaoEncontrado : public range_error {
    public:
        ElementoNaoEncontrado() : range_error("Elemento não encontrado!") {}
    };

    /**
    * @brief Erro de ordenação em vetor vazio
    **/
    class OrdenarVazio : public length_error {
    public:
        OrdenarVazio() : length_error("Não é possível ordenar vetor vazio!") {}
    };

    /**
    * @brief Erro de pilha vazia
    **/
    class PilhaVazia : public range_error {
    public:
        PilhaVazia() : range_error("Esta pilha está vazia!") {}
    };

    /**
    * @brief Erro de pilha cheia
    **/
    class PilhaCheia : public range_error {
    public:
        PilhaCheia() : range_error("Não pode inserir. Esta pilha está cheia!") {}
    };

    /**
    * @brief Erro de fila vazia
    **/
    class FilaVazia : public range_error {
    public:
        FilaVazia() : range_error("Esta fila está vazia!") {}
    };

    /**
    * @brief Erro de fila cheia
    **/
    class FilaCheia : public range_error {
    public:
        FilaCheia() : range_error("Não pode inserir. Esta fila está cheia!") {}
    };

    /**
    * @brief Erro de lista vazia
    **/
    class ListaVazia : public range_error {
    public:
        ListaVazia() : range_error("Esta lista está vazia!") {}
    };

    /**
    * @brief Erro de falta de memória para alocação de objeto
    **/
    class SemMemoria : public overflow_error {
    public:
        SemMemoria() : overflow_error("Sem memória disponível!") {}
    };

    /**
    * @brief Erro de posição solicitada inválida
    **/
    class PosicaoInvalida : public range_error {
    public:
        PosicaoInvalida() : range_error("Posição inválida!") {}
    };
    
#endif