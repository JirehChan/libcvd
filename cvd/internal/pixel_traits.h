#ifndef CVD_PIXEL_TRAITS_H_
#define CVD_PIXEL_TRAITS_H_

#include <limits>

namespace CVD {
namespace Pixel {
	
	template<class T> struct traits
	{
		static const bool integral=Error_trait_not_defined_for_this_class;
	};

	template<> struct traits<unsigned char> 
	{ 
		typedef int wider_type;
		static const bool integral = true;
		static const bool is_signed = false;
		static const int bits_used = 8;
		static const byte max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<char> 
	{ 
		typedef int wider_type;
		static const bool integral = true;
		static const bool is_signed = std::numeric_limits<char>::is_signed;
		static const int bits_used = std::numeric_limits<char>::digits;
		static const byte max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<signed char> 
	{ 
		typedef int wider_type;
		static const bool integral = true;
		static const bool is_signed = false;
		static const int bits_used = 7;
		static const byte max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<short> 
	{ 
		typedef int wider_type;
		static const bool integral = true;
		static const bool is_signed = true;
		static const int bits_used = 15;
		static const short max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<unsigned short> 
	{ 
		typedef int wider_type;
		static const bool integral = true;
		static const bool is_signed = false;
		static const int bits_used = 16;
		static const unsigned short max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<int> 
	{ 
		typedef int wider_type; 
		static const bool integral = true;
		static const bool is_signed = true;
		static const int bits_used = 16;
		static const int max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<unsigned int> 
	{ 
		typedef unsigned int wider_type; 
		static const bool integral = true;
		static const bool is_signed = false;
		static const int bits_used = 16;
		static const unsigned int max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<long> 
	{ 
		typedef int wider_type; 
		static const bool integral = true;
		static const bool is_signed = true;
		static const int bits_used = 16;
		static const long max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<unsigned long> 
	{ 
		typedef unsigned int wider_type; 
		static const bool integral = true;
		static const bool is_signed = false;
		static const int bits_used = 16;
		static const long max_intensity=(1 << bits_used) - 1; 
	};

	template<> struct traits<float> 
	{ 
		typedef float wider_type; 
		static const bool integral = false;
		static const bool is_signed = true;
		static const float max_intensity=1.0f; 
	};

	template<> struct traits<double> 
	{ 
		typedef double wider_type; 
		static const bool integral = false;
		static const bool is_signed = true;
		static const double max_intensity=1.0; 
	};

	template<> struct traits<long double> 
	{ 
		typedef long double wider_type; 
		static const bool integral = false;
		static const bool is_signed = true;
		static const long double max_intensity=1.0; 
	};

}
}

#endif