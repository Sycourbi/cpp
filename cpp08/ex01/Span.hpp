/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:55:48 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/26 12:14:46 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <exception> // std::exception
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator> // Pour std::iterator
#include <stdexcept> // Pour std::logic_error et std::length_error

class Span {

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(unsigned int number);
    long int shortestSpan();
    long int longestSpan();
    template<class InputIterator>
    void addRange(InputIterator begin, InputIterator end);

private:
    unsigned int _max_size;
    std::vector<int> _numbers;
};

template<class InputIterator>
void Span::addRange(InputIterator begin, InputIterator end) {
    // Vérifier que l'ajout ne dépasse pas la capacité.
    // Note : Cette vérification pourrait être plus coûteuse en C++98 sans std::distance pour certains itérateurs.
    unsigned int count = 0;
    for (InputIterator it = begin; it != end; ++it) {
        ++count;
    }
    if (count > _max_size - _numbers.size()) {
        throw std::length_error("Adding range exceeds Span capacity");
    }

    // Insérer les éléments dans le Span.
    for (InputIterator it = begin; it != end; ++it) {
        _numbers.push_back(*it);
        if (_numbers.size() > _max_size) { // Sécurité supplémentaire, bien que normalement non nécessaire grâce à la vérification ci-dessus.
            throw std::length_error("Span is full");
        }
    }
}


# endif