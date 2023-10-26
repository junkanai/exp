template<class T>
class Rnd<T, 1, 1, 1, 1> : public RndBase {
	T begin, div;
public:
	Rnd() : begin(0), div(2) { init(); }
	Rnd(T range) : begin(0), div(range + 1) { init(); }
	Rnd(T range_begin, T range_end) : begin(range_begin), div(range_end - range_begin + 1) { init(); }
	T operator()() { return (T)(get_u32() % div + begin); }
};

template<>
class Rnd<float, 1, 1, 1, 1> : public RndBase {
	float begin, scale;
public:
	Rnd() : begin(0), scale(1) { init(); }
	Rnd(float range) : begin(0), scale(range) { init(); }
	Rnd(float range_begin, float range_end) : begin(range_begin), scale(range_end - range_begin) { init(); }
	float operator()() { return (float)(get_u32()) * scale / UINT32_MAX + begin; }
};

template<>
class Rnd<double, 1, 1, 1, 1> : public RndBase {
	double begin, scale;
public:
	Rnd() : begin(0), scale(1) { init(); }
	Rnd(double range) : begin(0), scale(range) { init(); }
	Rnd(double range_begin, double range_end) : begin(range_begin), scale(range_end) { init(); }
	double operator()() { return (double)(get_u32()) * scale / UINT32_MAX + begin; }
};

