/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:56:43 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 12:29:21 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    // Convertit un pointeur de type Data* en une adresse mémoire brute de type uintptr_t.
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw) {
    // Convertit une adresse mémoire (raw) en un pointeur de type Data* sans changer la valeur.
    return reinterpret_cast<Data*>(raw);
}