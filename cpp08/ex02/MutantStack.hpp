/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:54 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/11 18:02:50 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <deque>
#include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:
    MutantStack() : std::stack<T, Container>() {} // Constructeur par défaut// Utilisez le constructeur de la stack

    // Type d'itérateur exposé par MutantStack
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    // Fonctions pour obtenir les itérateurs
    iterator begin() {
        return this->c.begin(); // 'c' est le conteneur sous-jacent de std::stack
    }
    iterator end() {
        return this->c.end();
    }
};

# endif