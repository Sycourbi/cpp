/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:57:14 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/26 12:12:09 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max_size(0) {
    
}
Span::Span(unsigned int N) : _max_size(N) {
    
}
Span::Span(const Span& other) {
    *this = other;
}
Span& Span::operator=(const Span& other) {
    if (this != &other)
    {
        _numbers = other._numbers;
        _max_size = other._max_size;
    }
    return *this;
}
Span::~Span() {
    std::cout << "Destructor called" << std::endl;
}
void Span::addNumber(unsigned int number) {
    if (_numbers.size() >= _max_size) {
        throw std::length_error("Span is already full.");
    }
    _numbers.push_back(number);
}
long int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Pas assez de numbers pour calculer");
    std::vector<int> sortedNumbers = _numbers; // Copie des nombres pour le tri
    //trie sorteNumbers du plus petit nombre au plus grand;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    long int minSpan = std::numeric_limits<int>::max();
    for (std::vector<int>::size_type i = 0; i < sortedNumbers.size() - 1; ++i) {
        long int actuelSpan = sortedNumbers[i + 1] - sortedNumbers[i];
        if (actuelSpan < minSpan) {
            minSpan = actuelSpan;
        }
    }
    return minSpan;
}
long int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Pas assez de numbers pour calculer");
    long int min = *std::min_element(_numbers.begin(), _numbers.end());
    long int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}