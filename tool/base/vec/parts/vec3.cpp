template<class T, size_t Z, size_t Y, size_t X>
class Vec<T, Z, Y, X, 1> {
private:
	static constexpr size_t D = 3;
	static constexpr size_t N = Z * Y * X;
	static constexpr size_t W = 1;

	using Self = Vec<T, Z, Y, X, 1>;
	std::valarray<T> data;

public:
#include "shares/constructors.cpp"
#include "shares/sizes.cpp"
#include "shares/operators.cpp"
#include "shares/funcs.cpp"

	T&                 operator[](size_t z, size_t y, size_t x)
	{
		return data[z*Y*X + y*X + x];
	}

	const T&           operator[](size_t z, size_t y, size_t x) const
	{
		return data[z*Y*X + y*X + x];
	}

	Vec<T, X>          operator[](size_t z, size_t y)
	{
		Vec<T, X> rtn;
		rep(x, X) rtn(x) = data[z*Y*X + y*X + x];
		return rtn;
	}

	const Vec<T, X>    operator[](size_t z, size_t y) const
	{
		Vec<T, X> rtn;
		rep(x, X) rtn(x) = data[z*Y*X + y*X + x];
		return rtn;
	}

	Vec<T, Y, X>       operator[](size_t z)
	{
		Vec<T, Y, X> rtn;
		rep(i, Y*X) rtn(i) = data[z*Y*X + i];
		return rtn;
	}

	const Vec<T, Y, X> operator[](size_t z) const
	{
		Vec<T, Y, X> rtn;
		rep(i, Y*X) rtn(i) = data[z*Y*X + i];
		return rtn;
	}

	static constexpr size_t len() { return Z; }

	Vec<T, Z, Y> max() const noexcept
	{
		Vec<T, Z, Y> rtn;
		rep(z, Z) rep(y, Y) {
			rtn[z, y] = operator[](z, y).max();
		}
		return rtn;
	}

	Vec<T, Z, Y> min() const noexcept
	{
		Vec<T, Z, Y> rtn;
		rep(z, Z) rep(y, Y) {
			rtn[z, y] = operator[](z, y).min();
		}
		return rtn;
	}

	Vec<size_t, Z, Y> argmax() const
	{
		Vec<size_t, Z, Y> rtn;
		rep(z, Z) rep(y, Y) {
			rtn[z, y] = operator[](z, y).argmax();
		}
		return rtn;
	}

	Vec<size_t, Z, Y> argmin() const
	{
		Vec<size_t, Z, Y> rtn;
		rep(z, Z) rep(y, Y) {
			rtn[z, y] = operator[](z, y).argmin();
		}
		return rtn;
	}

	template<class U = T>
	Vec<U, Z, Y> sum() const noexcept
	{
		Vec<U, Z, Y> rtn;
		rep(z, Z) rep(y, Y) {
			rtn[z, y] = operator[](z, y).sum();
		}
		return rtn;
	}

	template<class U = T>
	Vec<U, Z, Y> mean() const noexcept
	{
		return sum<U>() / N;
	}

	Self& reverse()
	{
		rep(z, Z) rep(y, Y) {
			std::reverse(std::begin(data) + z*Y*X + y*X,
						 std::begin(data) + z*Y*X + y*X + X);
		}
		return *this;
	}

	Self& sort()
	{
		rep(z, Z) rep(y, Y) {
			std::sort(std::begin(data) + z*Y*X + y*X,
					  std::begin(data) + z*Y*X + y*X + X);
		}
		return *this;
	}

	Vec<size_t, Z, Y, X> argsort() const noexcept
	{
		auto indices = Vec<size_t, Z, Y, X>::seq(1);
		rep(z, Z) rep(y, Y) {
			std::sort(indices.begin() + z*Y*X + y*X,
					  indices.begin() + z*Y*X + y*X + X,
					  [this, z, y](T left, T right) -> bool { return data[left + z*Y*X + y*X] < data[right + z*Y*X + y*X]; }
					);
		}
		return indices;
	}
};
