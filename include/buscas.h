/**
* @file     buscas.h
* @brief 	Arquivo com definições de funções de busca
* @author   Dionísio Carvalho (dionisio@naracosta.com.br)
* @since    20/06/2017
* @date     20/06/2017
*/

#ifndef BUSCAS_H
    #define BUSCAS_H

    #include <iostream>
    using std::cerr;
    using std::endl;

    #include "erros.h"
    
    /**
    * @brief    Função de busca linear iterativa
    * @param    A Vetor com os dados
    * @param    first Posição mais à esquerda no vetor para a busca
    * @param    end Posição mais à direita para busca
    * @param    k Elemento a ser buscado
    * @return   Posição do elemento no vetor ou -1 caso não seja encontrado
    */
    extern "C++" template<typename T>
    int linear_search_i(T A[], int first, int end, T k) {
        int i, size = end - first;
        for(i = 0; i < size; i++)
            if(A[i] == k)
                return i;

        //Não encontrado - lançar exceção
        try {
            throw ElementoNaoEncontrado();
        } catch (ElementoNaoEncontrado &ex) {
            cerr << ex.what() << endl;
        }
        return -1;
    }

    /**
    * @brief        Função de busca linear recursiva
    * @param[in]    A Vetor com os dados
    * @param[in]    first Posição mais à esquerda no vetor para a busca
    * @param[in]    end Posição mais à direita para busca
    * @param[in]    k Elemento a ser buscado
    * @return       Posição do elemento no vetor ou -1 caso não seja encontrado
    */
    extern "C++" template<typename T>
    int linear_search_r(T A[], int first, int end, T k) {
        int n = (end - first);
        if(n < 0) {
            //Não encontrado - lançar exceção
            try {
                throw ElementoNaoEncontrado();
            } catch (ElementoNaoEncontrado &ex) {
                cerr << ex.what() << endl;
            }
            return -1;
        }
        if(A[n] == k){
            return n;
        } else
            return linear_search_r(A, 0, (n - 1), k);
    }

    /**
    * @brief        Função de busca binária iterativa
    * @param[in]    A Vetor com os dados
    * @param[in]    first Posição mais à esquerda no vetor para a busca
    * @param[in]    end Posição mais à direita para busca
    * @param[in]    k Elemento a ser buscado
    * @return       Posição do elemento no vetor ou -1 caso não seja encontrado
    */
    extern "C++" template<typename T>
    int binary_search_i(T A[], int first, int end, T k) {
        int middle;
        while(first <= end){
            middle = (first + end)/2;
            if(A[middle] == k)
                return middle;
            if(A[middle] < k)
                first = middle + 1;
            else
                end = middle - 1;
        }

        //Não encontrado - lançar exceção
        try {
            throw ElementoNaoEncontrado();
        } catch (ElementoNaoEncontrado &ex) {
            cerr << ex.what() << endl;
        }
        return -1;
    }

    /**
    * @brief        Função de busca binária recursiva
    * @param[in]    A Vetor com os dados
    * @param[in]    first Posição mais à esquerda no vetor para a busca
    * @param[in]    end Posição mais à direita para busca
    * @param[in]    k Elemento a ser buscado
    * @return       Posição do elemento no vetor ou -1 caso não seja encontrado
    */
    extern "C++" template<typename T>
    int binary_search_r(T A[], int first, int end, T k) {
        int middle = (first + end)/2;
        if(A[middle] == k)
            return middle;
        if(first >= end) {
            //Não encontrado - lançar exceção
            try {
                throw ElementoNaoEncontrado();
            } catch (ElementoNaoEncontrado &ex) {
                cerr << ex.what() << endl;
            }
            return -1;
        }
        if(A[middle] < k)
            return binary_search_r(A, (middle + 1), end, k);
        else
            return binary_search_r(A, first, (middle - 1), k);
        
        return -1;
    }

    /**
    * @brief        Função de busca ternária iterativa
    * @param[in]    A Vetor com os dados
    * @param[in]    first Posição mais à esquerda no vetor para a busca
    * @param[in]    end Posição mais à direita para busca
    * @param[in]    k Elemento a ser buscado
    * @return       Posição do elemento no vetor ou -1 caso não seja encontrado
    */
    extern "C++" template<typename T>
    int ternary_search_i(T A[], int first, int end, T k) {
        int middle1, middle2;
        int left = first;
        int right = end;
        do {
            middle1 = ((right - left) / 3) + left;
            middle2 = (((right - left) / 3) * 2) + left;
            if(k == A[middle1])	
                return middle1;
            if(k == A[middle2]) 
                return middle2;
            if(k < A[middle1])
                right = middle1 - 1;
            if(k > A[middle1] && k < A[middle2]){
                left = middle1 + 1;
                right = middle2 - 1;
            } else if(k > A[middle2])
                left = middle2 + 1;

        } while(left <= right);
            
        //Não encontrado - lançar exceção
        try {
            throw ElementoNaoEncontrado();
        } catch (ElementoNaoEncontrado &ex) {
            cerr << ex.what() << endl;
        }
        return -1;
    }

    /**
    * @brief        Função de busca ternária recursiva
    * @param[in]    A Vetor com os dados
    * @param[in]    first Posição mais à esquerda no vetor para a busca
    * @param[in]    end Posição mais à direita para busca
    * @param[in]    k Elemento a ser buscado
    * @return       Posição do elemento no vetor ou -1 caso não seja encontrado
    */
    extern "C++" template<typename T>
    int ternary_search_r(T A[], int first, int end, T k) {
        if((first < 0) || (end < (end-first)-1) || (first > end)) {
            //Não encontrado - lançar exceção
            try {
                throw ElementoNaoEncontrado();
            } catch (ElementoNaoEncontrado &ex) {
                cerr << ex.what() << endl;
            }
            return -1;
        }
        if(k == A[first])
            return first;
        if(k == A[end])
            return end;
        if(k < A[first])
            return ternary_search_r(A, (first - 1), end, k);
        if ((k > A[first]) && (k < A[end]))
            return ternary_search_r(A, (first + 1), (end - 1), k);
        if(k > A[end])
            return ternary_search_r(A, first, (end + 1), k);
        return -1;
    }

#endif