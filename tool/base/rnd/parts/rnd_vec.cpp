template<class T, size_t W = 1, size_t Z = 1, size_t Y = 1, size_t X = 1>
class Rnd : public RndBase {
	T begin, div;
public:
	Rnd() : begin(0), div(2) { init(); }
	Rnd(T range) : begin(0), div(range + 1) { init(); }
	Rnd(T range_begin, T range_end) : begin(range_begin), div(range_end - range_begin + 1) { init(); }

	Vec<T, W, Z, Y, X> operator()()
	{
		Vec<T, W, Z, Y, X> rtn;
		rep(i, X*Y*Z*W) {
			rtn(i) = (T)(get_u32() % div + begin);
		}
		return rtn;
	}
};

template<size_t W, size_t Z, size_t Y, size_t X>
class Rnd<float, W, Z, Y, X> : public RndBase {
	float begin, scale;
public:
	Rnd() : begin(0), scale(1) { init(); }
	Rnd(float range) : begin(0), scale(range) { init(); }
	Rnd(float range_begin, float range_end) : begin(range_begin), scale(range_end - range_begin) { init(); }
	Vec<float, X, Y, Z, W> operator()()
	{
		Vec<float, W, Z, Y, X> rtn;
		rep(i, X*Y*Z*W) {
			rtn(i) = (float)(get_u32()) * scale / UINT32_MAX + begin;
		}
		return rtn;
	}
};

template<size_t W, size_t Z, size_t Y, size_t X>
class Rnd<double, W, Z, Y, X> : public RndBase {
	double begin, scale;
public:
	Rnd() : begin(0), scale(1) { init(); }
	Rnd(double range) : begin(0), scale(range) { init(); }
	Rnd(double range_begin, double range_end) : begin(range_begin), scale(range_end - range_begin) { init(); }
	Vec<double, W, Z, Y, X> operator()()
	{
		Vec<double, W, Z, Y, X> rtn;
		rep(i, X*Y*Z*W) {
			rtn(i) = (double)(get_u32()) * scale / UINT32_MAX + begin;
		}
		return rtn;
	}
};
