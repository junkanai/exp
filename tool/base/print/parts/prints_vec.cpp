template<class T, size_t W, size_t Z, size_t Y, size_t X>
void prints(const Vec<T, W, Z, Y, X>& v) const
{
	std::cout << "[";
	rep(w, W) {
		if ( w != 0 ) std::cout << "\n\n\n ";
		std::cout << "[";
		rep(z, Z) {
			if ( z != 0 ) std::cout << "\n\n  ";
			std::cout << "[";
			rep(y, Y) {
				if ( y != 0 ) std::cout << "\n   ";
				std::cout << "[";
				rep(x, X) {
					if ( x != 0 ) std::cout << sep_with;
					prints(v[w, z, y, x]);
				}
				std::cout << "]";
			}
			std::cout << "]";
		}
		std::cout << "]";
	}
	std::cout << "]";
}

template<class T, size_t Z, size_t Y, size_t X>
void prints(const Vec<T, Z, Y, X, 1>& v) const
{
	std::cout << "[";
	rep(z, Z) {
		if ( z != 0 ) std::cout << "\n\n ";
		std::cout << "[";
		rep(y, Y) {
			if ( y != 0 ) std::cout << "\n  ";
			std::cout << "[";
			rep(x, X) {
				if ( x != 0 ) std::cout << sep_with;
				prints(v[z, y, x]);
			}
			std::cout << "]";
		}
		std::cout << "]";
	}
	std::cout << "]";
}

template<class T, size_t Y, size_t X>
void prints(const Vec<T, Y, X, 1, 1>& v) const
{
	std::cout << "[";
	rep(y, Y) {
		if ( y != 0 ) std::cout << "\n ";
		std::cout << "[";
		rep(x, X) {
			if ( x != 0 ) std::cout << sep_with;
			prints(v[y, x]);
		}
		std::cout << "]";
	}
	std::cout << "]";
}

template<class T, size_t X>
void prints(const Vec<T, X, 1, 1, 1>& v) const
{
	std::cout << "[";
	rep(x, X) {
		if ( x != 0 ) std::cout << sep_with;
		prints(v[x]);
	}
	std::cout << "]";
}
