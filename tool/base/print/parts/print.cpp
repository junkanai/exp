#include <iostream>


class Print {
private:
	std::string int_format = "%3d";
	std::string flt_format = "%f";
	std::string end_with = "\n";
	std::string sep_with = " ";

#include "prints.cpp"

public:
	Print() {}
	void operator()() const { std::printf("\n"); }

	template<class T, class... U>
	void operator()(const T& t, const U&... u) const
	{
		prints(t);
		std::cout << sep_with;
		operator()(u...);
	}

	template<class T>
	void operator()(const T& t) const
	{
		prints(t);
		std::cout << end_with;
	}

	Print set_int(const std::string& format) const
	{
		Print rtn = *this;
		rtn.int_format = format;
		return rtn;
	}

	Print set_flt(const std::string& format) const
	{
		Print rtn = *this;
		rtn.flt_format = format;
		return rtn;
	}
	
	Print set_end(const std::string& end) const
	{
		Print rtn = *this;
		rtn.end_with = end;
		return rtn;
	}

	Print set_sep(const std::string& sep) const
	{
		Print rtn = *this;
		rtn.sep_with = sep;
		return rtn;
	}
};

Print print;
