template<class T, size_t W, size_t Z, size_t Y, size_t X>
class vec {
private:
	static constexpr size_t N = W * Z * Y * X;
	T data[W][Z][Y][X];

public:
};
