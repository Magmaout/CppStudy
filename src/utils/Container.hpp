#ifndef CONTAINER
#define CONTAINER

#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <utility>
#include <sstream>
#include <memory>
#include <span>

class Container  {
	public:
		explicit Container(std::initializer_list<int> list);
		explicit Container(size_t size);

		Container(const Container& other);
		Container(Container&& other) noexcept;

		Container& operator = (const Container& other);
		Container& operator = (Container&& other) noexcept;
		bool operator == (const Container& other) const noexcept;
		int& operator [] (size_t index);
		const int& operator [] (size_t index) const;
		explicit operator bool () noexcept;
		Container& operator += (int value);
		Container& operator ++ ();
		Container operator ++ (int);

		std::string str() const;
		size_t size() const noexcept;

	private:
		static void swap(Container& first, Container& second) noexcept;
		std::unique_ptr<int[]> ptr;
		size_t len{0};
		friend std::istream& operator >> (std::istream& in, Container& obj);
};

std::ostream& operator << (std::ostream& out, const Container& obj);

#endif //CONTAINER