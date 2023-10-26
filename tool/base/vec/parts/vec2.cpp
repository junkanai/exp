template<class T, size_t Y, size_t X>
class Vec<T, Y, X, 1, 1> {
private:
	static constexpr size_t D = 2;
	static constexpr size_t N = Y * X;
	static constexpr size_t W = 1;
	static constexpr size_t Z = 1;

	using Self = Vec<T, Y, X, 1, 1>;
	std::valarray<T> data;

public:
#include "shares/constructors.cpp"
#include "shares/sizes.cpp"
#include "shares/operators.cpp"
#include "shares/funcs.cpp"

	template<class U>
	Vec<U, Y, X> to() const
	{
		Vec<U, Y, X> rtn;
		rep(i, N) rtn(i) = (U)data[i];
		return rtn;
	}

	T&              operator[](size_t y, size_t x)
	{
		return data[y*X + x];
	}

	const T&        operator[](size_t y, size_t x) const
	{
		return data[y*X + x];
	}

	Vec<T, X>       operator[](size_t y)
	{
		Vec<T, X> rtn;
		rep(x, X) rtn(x) = data[y*X + x];
		return rtn;
	}

	const Vec<T, X> operator[](size_t y) const
	{
		Vec<T, X> rtn;
		rep(x, X) rtn(x) = data[y*X + x];
		return rtn;
	}

	static constexpr size_t len() { return Y; }

	Vec<T, Y> max() const noexcept
	{
		Vec<T, Y> rtn;
		rep(y, Y) {
			rtn[y] = operator[](y).max();
		}
		return rtn;
	}

	Vec<T, Y> min() const noexcept
	{
		Vec<T, Y> rtn;
		rep(y, Y) {
			rtn[y] = operator[](y).min();
		}
		return rtn;
	}

	Vec<size_t, Y> argmax() const
	{
		Vec<size_t, Y> rtn;
		rep(y, Y) {
			rtn[y] = operator[](y).argmax();
		}
		return rtn;
	}

	Vec<size_t, Y> argmin() const
	{
		Vec<size_t, Y> rtn;
		rep(y, Y) {
			rtn[y] = operator[](y).argmin();
		}
		return rtn;
	}

	template<class U = T>
	Vec<U, Y> sum() const noexcept
	{
		Vec<U, Y> rtn;
		rep(y, Y) {
			rtn[y] = operator[](y).sum();
		}
		return rtn;
	}

	template<class U = T>
	Vec<U, Y> mean() const noexcept
	{
		return sum<U>() / N;
	}

	Self& reverse()
	{
		rep(y, Y) {
			std::reverse(std::begin(data) + y*X,
						 std::begin(data) + y*X + X);
		}
		return *this;
	}

	Self& sort()
	{
		rep(y, Y) {
			std::sort(std::begin(data) + y*X,
					  std::begin(data) + y*X + X);
		}
		return *this;
	}

	Vec<size_t, Y, X> argsort() const noexcept
	{
		auto indices = Vec<size_t, Y, X>::seq(1);
		auto y = 1;
		rep(y, Y) {
			std::sort(indices.begin() + y*X,
					  indices.begin() + y*X + X,
					  [this, y](T left, T right) -> bool { return data[left + y*X] < data[right + y*X]; }
					);
		}
		return indices;
	}
};
