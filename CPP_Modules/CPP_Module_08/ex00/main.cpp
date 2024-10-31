/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:10:35 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/18 10:13:05 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
int main() {
    try {
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
        easyfind(vec, 3);
        easyfind(vec, 6);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        int arr[] = {10, 20, 30, 40, 50};
        std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
        easyfind(lst, 20);
        easyfind(lst, 60);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
