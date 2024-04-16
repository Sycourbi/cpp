/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:23:07 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 16:43:05 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<typename T>
Array<T>::Array() : _elements(NULL), _size(0) {
    
}
template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n) {
    for (unsigned int i = 0; i < n; ++i) {
        _elements[i] = T(); // Initialisation par default
    }
}
template<typename T>
Array<T>::Array(const Array& other) : _elements(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; ++i) {
        _elements[i] = other._elements[i];
    }
}
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _elements;
        _size = other._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _elements[i] = other._elements[i];
        }
    }
    return *this;
}
template<typename T>
Array<T>::~Array() {
    delete[] _elements;
    std::cout << "Destructor called" << std::endl;
}

// Accès aux éléments
template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        // Ceci est une manière standard de signaler une erreur d'accès hors limites en C++
        throw std::out_of_range("Index hors limites");
    return _elements[index];
}

// Taille de l'array
template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}
