#include "Base64.h"
#include <stdint.h> // TODO: Use <cstdint>
#include <stdexcept>

std::string Base64::ENCODING_MAP =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string Base64::encode(std::string in) {
	std::string out;
	out.resize((((in.size() - 1) / 3) + 1) * 4);
	for (size_t i = 0, j = 0; i < in.size();) {
		char ch1 = i < in.size() ? in[i++] : 0;
		char ch2 = i < in.size() ? in[i++] : 0;
		char ch3 = i < in.size() ? in[i++] : 0;

		// combine ch1, ch2, ch3 into a single block
		uint32_t triplet = (ch1 << 0x10) + (ch2 << 0x08) + ch3;

		// Extract in multiples of 6 bits..
		out[j++] = ENCODING_MAP[(triplet >> 3 * 6) & 63];
		out[j++] = ENCODING_MAP[(triplet >> 2 * 6) & 63];
		out[j++] = ENCODING_MAP[(triplet >> 1 * 6) & 63];
		out[j++] = ENCODING_MAP[(triplet >> 0 * 6) & 63];
	}

	// Determine if last few characters of output needs to be set to "="
	if (in.size() % 3 != 0) {
		out[out.size() - 1] = '=';
		if (in.size() % 3 == 1) {
			out[out.size() - 2] = '=';
		}
	}
	return out;
}

std::string Base64::decode(std::string in) {
	std::string out;

	if (in.size() % 4 != 0) {
		throw std::runtime_error("Invalid input");
	}

	if (in[in.size() - 2] == '=' && in[in.size() - 1] != '=') {
		throw std::runtime_error("Invalid input");
	}

	size_t out_size = (in.size() / 4) * 3;

	// The last 1/2 characters can be "=", lets ignore them for a while
	size_t in_size = in.size();
	if (in[in_size - 1] == '=') {
		in_size--;
		out_size--;
		if (in[in_size - 1] == '=') {
			in_size--;
			out_size--;
		}
	}

	out.resize(out_size);
	for (size_t i = 0, j = 0; i < in.size();) {
		// TODO: find() can be costly... Use a reverse lookup table.

		// Get 1st 4 characters..
		size_t idx1 = ENCODING_MAP.find(in[i++]);
		size_t idx2 = ENCODING_MAP.find(in[i++]);
		size_t idx3 = (i == in.size() - 2) && in[i] == '=' ? 0 : ENCODING_MAP.find(in[i]);
		i++;
		size_t idx4 = (i == in.size() - 1) && in[i] == '=' ? 0 : ENCODING_MAP.find(in[i]);
		i++;

		if (idx1 == in.npos || idx2 == in.npos || idx3 == in.npos || idx4 == in.npos) {
			throw std::runtime_error("Invalid input");
		}
		uint32_t triplet = (idx1 << 3 * 6) + (idx2 << 2 * 6) + (idx3 << 1 * 6) + (idx4 << 0 * 6);
		if (j < out_size)
			out[j++] = (triplet >> 2 * 8) & 0xFF;
		if (j < out_size)
			out[j++] = (triplet >> 1 * 8) & 0xFF;
		if (j < out_size)
			out[j++] = (triplet >> 0 * 8) & 0xFF;
	}
	return out;
}
