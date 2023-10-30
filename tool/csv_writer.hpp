#pragma once

#include <fstream>

#include "base.hpp"

class CsvWriter {
private:
	std::ofstream ofs;
public:
	CsvWriter(const std::string& filename)
	{
		ofs.open(filename);

		if ( !ofs ) {
        	throw std::runtime_error("Failed to open file");
		}
	}

	template<class T, size_t Y, size_t X>
	void operator()(const Vec<T, Y, X>& data)
	{
		rep( y, Y ) {
			rep( x, X ) {
				if ( x != 0 ) ofs << ", ";
				ofs << data[y, x];
			}
			ofs << std::endl;
		}
	}
	
	template<class T, size_t X>
	void operator()(const Vec<T, X>& data)
	{
		rep( x, X ) {
			ofs << data[x] << std::endl;
		}
	}
};
