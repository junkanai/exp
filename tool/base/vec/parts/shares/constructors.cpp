#define VEC_ASSERTION static_assert(W*Z*Y*X, "Template parameters of vec must be more than 0.")

Vec() : data(N)
{
	VEC_ASSERTION;
}

Vec(const T t) : data(t, N)
{
	VEC_ASSERTION;
}

Vec(const Self& s) : data(N)
{
	VEC_ASSERTION;
	rep(i, N) data[i] = s.data[i];
}

Vec(std::initializer_list<T> init) : data(N)
{
	VEC_ASSERTION;

	auto in_beg = init.begin();
	if ( N >= init.size() ) {
		rep(i, init.size() ) data[i] = in_beg[i];
		reps(i, init.size(), N) data[i] = {};
	} else {
		rep(i, N) data[i] = in_beg[i];
	}
}

#undef VEC_ASSERTION
