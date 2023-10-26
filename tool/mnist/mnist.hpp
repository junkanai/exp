#pragma once

#include <fstream>

#include "../base.hpp"

namespace mnist {

constexpr auto TRAIN_IMAGES_PATH = "tool/mnist/raw/train-images-idx3-ubyte";
constexpr auto TRAIN_LABELS_PATH = "tool/mnist/raw/train-labels-idx1-ubyte";
constexpr auto TEST_IMAGES_PATH  = "tool/mnist/raw/t10k-images-idx3-ubyte";
constexpr auto TEST_LABELS_PATH  = "tool/mnist/raw/t10k-labels-idx1-ubyte";

constexpr size_t IMAGE_HEIGHT = 28;
constexpr size_t IMAGE_WIDTH = 28;
constexpr size_t IMAGE_SIZE = IMAGE_HEIGHT * IMAGE_WIDTH;

constexpr size_t TRAIN_SIZE = 60000;
constexpr size_t TEST_SIZE = 10000;

constexpr size_t IMAGE_OFFSET = 16;  // 16 byte
constexpr size_t LABEL_OFFSET = 8;   //  8 byte

template<class T = uint8_t>
Vec<T, TRAIN_SIZE, IMAGE_HEIGHT, IMAGE_WIDTH> read_train_images()
{
	std::ifstream file(TRAIN_IMAGES_PATH, std::ios::in | std::ios::binary);

    if ( !file.is_open() ) {
        throw std::runtime_error("Failed to open file");
    }

	file.seekg(IMAGE_OFFSET, std::ios_base::beg);

	Vec<T, TRAIN_SIZE, IMAGE_HEIGHT, IMAGE_WIDTH> rtn;

	rep(i, rtn.size()) {
		unsigned char tmp;
		file.read((char*)&tmp, sizeof(tmp));
		rtn(i) = (T)tmp;
	}

	return rtn;
}

template<class T = uint8_t>
Vec<T, TRAIN_SIZE> read_train_labels()
{
	std::ifstream file(TRAIN_LABELS_PATH, std::ios::in | std::ios::binary);

    if ( !file.is_open() ) {
        throw std::runtime_error("Failed to open file");
    }

	file.seekg(LABEL_OFFSET, std::ios_base::beg);

	Vec<T, TRAIN_SIZE> rtn;

	rep(i, rtn.size()) {
		unsigned char tmp;
		file.read((char*)&tmp, sizeof(tmp));
		rtn(i) = (T)tmp;
	}
	
	return rtn;
}

template<class T = uint8_t>
Vec<T, TEST_SIZE, IMAGE_HEIGHT, IMAGE_WIDTH> read_test_images()
{
	std::ifstream file(TEST_IMAGES_PATH, std::ios::in | std::ios::binary);

    if ( !file.is_open() ) {
        throw std::runtime_error("Failed to open file");
    }

	file.seekg(IMAGE_OFFSET, std::ios_base::beg);

	Vec<T, TEST_SIZE, IMAGE_HEIGHT, IMAGE_WIDTH> rtn;

	rep(i, rtn.size()) {
		unsigned char tmp;
		file.read((char*)&tmp, sizeof(tmp));
		rtn(i) = (T)tmp;
	}

	return rtn;
}

template<class T = uint8_t>
Vec<T, TEST_SIZE> read_test_labels()
{
	std::ifstream file(TEST_LABELS_PATH, std::ios::in | std::ios::binary);

    if ( !file.is_open() ) {
        throw std::runtime_error("Failed to open file");
    }

	file.seekg(LABEL_OFFSET, std::ios_base::beg);

	Vec<T, TEST_SIZE> rtn;

	rep(i, rtn.size()) {
		unsigned char tmp;
		file.read((char*)&tmp, sizeof(tmp));
		rtn(i) = (T)tmp;
	}
	
	return rtn;
}

}
