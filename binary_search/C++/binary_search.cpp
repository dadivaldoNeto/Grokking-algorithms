#include <iterator>
#include <vector>
#include <list>
#include <iostream>

template<class ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type >
// [begin, end)
ForwardIt binary_search(ForwardIt begin, ForwardIt end, const T& value) {
	typedef typename std::iterator_traits<ForwardIt>::difference_type difference_type;

	difference_type left = 0;
	difference_type right;
	difference_type mid;

	right = std::distance(begin, end) - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		ForwardIt it_mid = std::next(begin, mid);
		if (*it_mid == value)
			return (it_mid);
		if (*it_mid > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (end);
}

/***
 * V2: 
 * 		Abordagem por Saltos (ou Busca por Tamanho de Passo/Passo Monótono) 
 ***/

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50, 60, 70};

    auto vec_it1 = binary_search(vec.begin(), vec.end(), 40);
    if (vec_it1 != vec.end() && *vec_it1 == 40) {
        std::cout << "Success: Found 40 at index " << std::distance(vec.begin(), vec_it1) << "\n";
    } else {
        std::cout << "Failure: Could not find 40 in vector\n";
    }

    auto vec_it2 = binary_search(vec.begin(), vec.end(), 25);
    if (vec_it2 == vec.end()) {
        std::cout << "Success: Correctly identified 25 is missing\n";
    } else {
        std::cout << "Failure: Incorrectly found 25\n";
    }

    std::list<int> lst = {5, 15, 25, 35, 45};

    auto lst_it = binary_search(lst.begin(), lst.end(), 15);
    if (lst_it != lst.end() && *lst_it == 15) {
        std::cout << "Success: Found 15 in std::list\n";
    } else {
        std::cout << "Failure: Could not find 15 in std::list\n";
    }

    std::vector<int> empty_vec;
    auto empty_it = binary_search(empty_vec.begin(), empty_vec.end(), 10);
    
    if (empty_it == empty_vec.end()) {
        std::cout << "Success: Safely handled empty container\n";
    } else {
        std::cout << "Failure: Exploded on empty container\n";
    }

    return 0;
}

