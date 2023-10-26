template<class T>
void prints(const T& t) const
{
	if constexpr ( std::is_integral<T>() ) {
		std::printf(int_format.c_str(), t);
	} else if constexpr ( std::is_floating_point<T>() ) {
		std::printf(flt_format.c_str(), t);
	} else {
		std::cout << t;
	}
}

#include "prints_vec.cpp"
