decltype(std::end(data)) begin()
{
	return std::begin(data);
}

decltype(std::end(data)) end()
{
	return std::end(data);
}

static Self seq(T step = 1, T start = 0, T ladder = 0)
{
	Self rtn;
	T value;

	rep(w, W) rep(z, Z) rep(y, Y) {
		value = start;
		start += ladder;
		rep(x, X) {
			rtn.data[w*Z*Y*X + z*Y*X + y*X + x] = value;
			value += step;
		}
	}
	return rtn;
}

