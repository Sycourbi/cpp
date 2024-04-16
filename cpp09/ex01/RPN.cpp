/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:22:50 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/29 14:59:47 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cmath> // Pour std::isnan()
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib> // pour std::atof

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        // Copie des attributs si nécessaire
    }
    return *this;
}
bool RPN::isOperator(const char& token) const {
    return token == '+' || token == '-' || token == '*' || token == '/';
}
void RPN::evaluate(const std::string& expression) {
    // Création d'une pile pour stocker les nombres de l'expression.
    std::stack<double> stack;

    // Utilisation d'un flux de chaînes pour parcourir l'expression.
    std::istringstream iss(expression);

    // Variable pour stocker chaque élément (nombre ou opérateur) de l'expression.
    std::string token;

    // Boucle pour lire chaque élément de l'expression.
    while (iss >> token) {
        // Vérifie si l'élément actuel est un opérateur et s'assure qu'il est seul caractère.
        if (isOperator(token[0]) && token.size() == 1) {
            // Vérifie si la pile contient au moins deux nombres avant de faire une opération.
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return ;
            }
            // Récupère les deux derniers nombres de la pile.
            //stack.top recupere la reference et stack.pop le suprime de stack
            double val2 = stack.top(); stack.pop(); // Second opérande
            double val1 = stack.top(); stack.pop(); // Premier opérande

            // Effectue l'opération et ajoute le résultat à la pile.
            stack.push(performOperation(val1, val2, token[0]));
                
        } else {
            // Si l'élément n'est pas un opérateur, le convertit en nombre et l'ajoute à la pile.
            stack.push(std::atof(token.c_str()));
        }
    }
    // Après avoir traité toute l'expression, vérifie si la pile contient un seul élément (le résultat final).
    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return ;
    }
    // Print le résultat final.
    if (!std::isnan(stack.top())) 
        std::cout << stack.top() << std::endl;
    return ;
}
double RPN::performOperation(const double& val1, const double& val2, const char& op) const {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': 
            if (val2 == 0)
            {
                std::cerr << "Error: Division by zero" << std::endl;
                return 0.0 / 0.0; // Retourne une valeur qui produit NaN
            }
            return val1 / val2;
        default:
            std::cerr << "Error: Unknown operator" << std::endl;
        return 0.0 / 0.0; // Retourne une valeur qui produit NaN
    }
}
/*
    std::stack : Un conteneur de type pile qui stocke des éléments dans un
ordre Last-In-First-Out (LIFO). C'est utile pour évaluer des expressions
en notation polonaise inversée (RPN), car il permet de traiter les opérandes
et les opérateurs dans l'ordre approprié. L'utilisation d'une pile simplifie
le processus en permettant l'application des opérateurs aux derniers nombres
extraits de la pile et en stockant les résultats intermédiaires.
*/ 