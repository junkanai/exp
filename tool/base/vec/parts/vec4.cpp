template<class T, size_t W, size_t Z = 1, size_t Y = 1, size_t X = 1>
class Vec {
private:
	static constexpr size_t D = 4;
	static constexpr size_t N = W * Z * Y * X;

	using Self = Vec<T, W, Z, Y, X>;
	std::valarray<T> data;

public:
#include "shares/constructors.cpp"
#include "shares/sizes.cpp"
#include "shares/operators.cpp"
#include "shares/funcs.cpp"

	T&                    operator[](size_t w, size_t z, size_t y, size_t x)
	{
		return data[w*Z*Y*X + z*Y*X + y*X + x];
	}

	const T&              operator[](size_t w, size_t z, size_t y, size_t x) const
	{
		return data[w*Z*Y*X + z*Y*X + y*X + x];
	}

	Vec<T, X>             operator[](size_t w, size_t z, size_t y)
	{
		Vec<T, X> rtn;
		rep(i, X) rtn[i] = data[w*Z*Y*X + z*Y*X + y*X + i];
		return rtn;
	}

	const Vec<T, X>       operator[](size_t w, size_t z, size_t y) const
	{
		Vec<T, X> rtn;
		rep(x, X) rtn[x] = data[w*Z*Y*X + z*Y*X + y*X + x];
		return rtn;
	}

	Vec<T, Y, X>          operator[](size_t w, size_t z)
	{
		Vec<T, Y, X> rtn;
		rep(i, Y*X) rtn(i) = data[w*Z*Y*X + z*Y*X + i];
		return rtn;
	}

	const Vec<T, Y, X>    operator[](size_t w, size_t z) const
	{
		Vec<T, Y, X> rtn;
		rep(i, Y*X) rtn(i) = data[w*Z*Y*X + z*Y*X + i];
		return rtn;
	}

	Vec<T, Z, Y, X>       operator[](size_t w)
	{
		Vec<T, Z, Y, X> rtn;
		rep(i, Z*Y*X) rtn(i) = data[w*Z*Y*X + i];
		return rtn;
	}

	const Vec<T, Z, Y, X> operator[](size_t w) const
	{
		Vec<T, Z, Y, X> rtn;
		rep(i, Z*Y*X) rtn(i) = data[w*Z*Y*X + i];
		return rtn;
	}

	static constexpr size_t len() { return W; }

	Vec<T, W, Z, Y> max() const noexcept
	{
		Vec<T, W, Z, Y> rtn;
		rep(w, W) rep(z, Z) rep(y, Y) {
			rtn[w, z, y] = operator[](w, z, y).max();
		}
		return rtn;
	}

	Vec<T, W, Z, Y> min() const noexcept
	{
		Vec<T, W, Z, Y> rtn;
		rep(w, W) rep(z, Z) rep(y, Y) {
			rtn[w, z, y] = operator[](w, z, y).min();
		}
		return rtn;
	}

	Vec<size_t, W, Z, Y> argmax() const
	{
		Vec<size_t, W, Z, Y> rtn;
		rep(w, W) rep(z, Z) rep(y, Y) {
			rtn[w, z, y] = operator[](w, z, y).argmax();
		}
		return rtn;
	}

	Vec<size_t, W, Z, Y> argmin() const
	{
		Vec<size_t, W, Z, Y> rtn;
		rep(w, W) rep(z, Z) rep(y, Y) {
			rtn[w, z, y] = operator[](w, z, y).argmin();
		}
		return rtn;
	}

	template<class U = T>
	Vec<U, W, Z, Y> sum() const noexcept
	{
		Vec<U, W, Z, Y> rtn;
		rep(w, W) rep(z, Z) rep(y, Y) {
			rtn[w, z, y] = operator[](w, z, y).sum();
		}
		return rtn;
	}

	template<class U = T>
	Vec<U, W, Z, Y> mean() const noexcept
	{
		return sum<U>() / N;
	}

	Self& reverse()
	{
		rep(w, W) rep(z, Z) rep(y, Y) {
			std::reverse(std::begin(data) + w*Z*Y*X + z*Y*X + y*X,
						 std::begin(data) + w*Z*Y*X + z*Y*X + y*X + X);
		}
		return *this;
	}

	Self& sort()
	{
		rep(w, W) rep(z, Z) rep(y, Y) {
			std::sort(std::begin(data) + w*Z*Y*X + z*Y*X + y*X,
					  std::begin(data) + w*Z*Y*X + z*Y*X + y*X + X);
		}
		return *this;
	}

	Vec<size_t, W, Z, Y, X> argsort() const noexcept
	{
		auto indices = Vec<size_t, W, Z, Y, X>::seq(1);
		rep(w, W) rep(z, Z) rep(y, Y) {
			std::sort(indices.begin() + w*Z*Y*X + z*Y*X + y*X,
					  indices.begin() + w*Z*Y*X + z*Y*X + y*X + X,
					  [this, w, z, y](T left, T right) -> bool {
					  		return data[left + w*Z*Y*X + z*Y*X + y*X] < data[right + w*Z*Y*X + z*Y*X + y*X];
						}
					);
		}
		return indices;
	}

};
