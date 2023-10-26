template<class T, size_t X>
class Vec<T, X, 1, 1, 1> {
private:
	static constexpr size_t D = 1;
	static constexpr size_t N = X;
	static constexpr size_t W = 1;
	static constexpr size_t Z = 1;
	static constexpr size_t Y = 1;

	using Self = Vec<T, X, 1, 1, 1>;
	std::valarray<T> data;

public:
#include "shares/constructors.cpp"
#include "shares/sizes.cpp"
#include "shares/operators.cpp"
#include "shares/funcs.cpp"

	T&       operator[](size_t x)
	{
		return data[x];
	}

	const T& operator[](size_t x) const
	{
		return data[x];
	}

	static constexpr size_t len() { return X; }

	T max() const noexcept
	{
		return data.max();
	}

	T min() const noexcept
	{
		return data.min();
	}

	size_t argmax() const
	{
		return std::distance(std::begin(data),
							 std::max_element(std::begin(data), std::end(data))
							 );
	}

	size_t argmin() const
	{
		return std::distance(std::begin(data),
							 std::min_element(std::begin(data), std::end(data))
							 );
	}

	template<class U = T>
	U sum() const noexcept {
		U rtn = 0;
		rep(i, N) rtn += data[i];
		return rtn;
	}

	template<class U = T>
	U mean() const noexcept
	{
		return sum<U>() / N;
	}

	Self& reverse()
	{
		std::reverse(std::begin(data), std::end(data));
		return *this;
	}

	Self& sort()
	{
		std::sort(std::begin(data), std::end(data));
		return *this;
	}

	Vec<size_t, X> argsort() const noexcept
	{
		auto indices = Vec<size_t, X>::seq(1);
		std::sort(indices.begin(), indices.end(),
				[this](T left, T right) -> bool { return data[left] < data[right]; }
				);
		return indices;
	}
};
