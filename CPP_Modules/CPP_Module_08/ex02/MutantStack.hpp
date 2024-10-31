/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:34:46 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/18 16:52:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

template <class T>

class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& rhs);
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};


template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::~MutantStack(){}

template <class T>
MutantStack<T>::MutantStack(const MutantStack& other) {
	*this = other;
}

template <class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

#endif // !MUTANTSTACK_HPP