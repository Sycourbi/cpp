/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:30:23 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/27 16:35:49 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <iostream>

// Définition de la fonction template iter
template<typename T>
void iter(T* array, size_t length, void (*func)(const T& element)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// Exemple de fonction qui peut être passée à iter
template<typename T>
void print(const T& element) {
    std::cout << "tab : " << element << std::endl;
}

# endif