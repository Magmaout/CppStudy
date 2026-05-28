#include "Container.hpp"

Container::Container(size_t size) {
	this->ptr = std::make_unique<int[]>(size);
	this->len = size;
}

Container::Container(std::initializer_list<int> list) {
	this->ptr = std::make_unique<int[]>(list.size());
	this->len = list.size();
	std::copy(list.begin(), list.end(), this->ptr.get());
}

Container::Container(const Container& other) {
	this->ptr = std::make_unique<int[]>(other.size());
	this->len = other.size();
	const std::span<const int> src{other.ptr.get(), other.size()};
	std::copy(src.begin(), src.end(), this->ptr.get());
}

Container::Container(Container&& other) noexcept {
	this->len = std::exchange(other.len, 0);
	this->ptr = std::move(other.ptr);
}

Container& Container::operator = (const Container& other) {
	Container temp(other);
	if (this != &other) swap(*this, temp);
	return *this;
}

Container& Container::operator = (Container&& other) noexcept {
	if (this != &other) {
		this->len = std::exchange(other.len, 0);
		this->ptr = std::move(other.ptr);
	}
	return *this;
}

bool Container::operator == (const Container& other) const noexcept {
	const std::span<const int> a{ this->ptr.get(), this->size() }, b{ other.ptr.get(), other.size() };
	return std::equal(a.begin(), a.end(), b.begin(), b.end());
}

int& Container::operator [] (size_t index) {
	if (index >= this->len) throw std::out_of_range("Index out of range Container class");
	return this->ptr[index];
}

const int& Container::operator [] (size_t index) const {
	if (index >= this->len) throw std::out_of_range("Index out of range Container class");
	return this->ptr[index];
}

Container::operator bool () noexcept {
	return this->len != 0;
}

Container& Container::operator += (int value) {
	const std::span<int> items{ this->ptr.get(), this->size() };
	std::for_each(items.begin(), items.end(), [value](auto& item) { item += value; });
	return *this;
}

Container& Container::operator ++ () {
	const std::span<int> items{ this->ptr.get(), this->size() };
	std::for_each(items.begin(), items.end(), [](auto& item) { ++item; });
	return *this;
}

Container Container::operator ++ (int) {
	Container temp(*this);
	++(*this);
	return temp;
}

std::string Container::str() const {
	const std::span<const int> items{ this->ptr.get(), this->size() };
	std::ostringstream output;
	for (size_t i = 0; auto& item : items) {
		i++;
		output << item << (i < this->len ? ", " : "");
	}
	return output.str();
}

size_t Container::size() const noexcept {
	return this->len;
}

void Container::swap(Container& first, Container& second) noexcept {
	std::swap(first.len, second.len);
	std::swap(first.ptr, second.ptr);
}

std::istream& operator >> (std::istream& in, Container& obj) {
	std::span<int> items{ obj.ptr.get(), obj.size() };
	for (auto& item : items) in >> item;
	return in;
}

std::ostream& operator << (std::ostream& out, const Container& obj) {
	out << obj.str();
	return out;
}