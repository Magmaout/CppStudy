#include <windows.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Fraction {
public:
    explicit Fraction() : n(0), d(1) {}
    explicit Fraction(double numerator, double denominator) {
        if (denominator == 0) throw std::invalid_argument("Знаменатель не может быть равен нулю!");
        n = numerator;
        d = denominator;
        normalize();
    }
    explicit Fraction(double value) {
        if (value == 0) {
            n = 0;
            d = 1;
            return;
        }
        int decimalPlaces = 0;
        double temp = std::abs(value);
        temp -= std::floor(temp);

        while (temp > 0 && decimalPlaces < 10) {
            temp *= 10;
            temp -= std::floor(temp);
            decimalPlaces++;
        }
        double m = std::pow(10, decimalPlaces);
        n = value * m;
        d = m;
        normalize();
    }
    Fraction(const Fraction& other) {
        this->n = other.n;
        this->d = other.d;
    }

    Fraction add(const Fraction& other) const {
        double common_d = d * other.d;
        double new_n = n * other.d + other.n * d;
        return Fraction(new_n, common_d);
    }
    Fraction sub(const Fraction& other) const {
        double common_d = d * other.d;
        double new_n = n * other.d - other.n * d;
        return Fraction(new_n, common_d);
    }
    Fraction mul(const Fraction& other) const {
        return Fraction(n * other.n, d * other.d);
    }
    Fraction div(const Fraction& other) const {
        if (other.n == 0.0) throw std::domain_error("Знаменатель не может быть равен нулю!");
        return Fraction(n * other.d, d * other.n);
    }

    Fraction& operator = (const Fraction& other) {
        if (this != &other) {
            this->n = other.n;
            this->d = other.d;
        }
        return *this;
    }
    Fraction operator + (const Fraction& other) const {
        return add(other);
    }
    Fraction operator - (const Fraction& other) const {
        return sub(other);
    }
    Fraction operator * (const Fraction& other) const {
        return mul(other);
    }
    Fraction operator / (const Fraction& other) const {
        return div(other);
    }

    Fraction& operator += (const Fraction& other) {
        *this = *this + other; return *this;
    }
    Fraction& operator -= (const Fraction& other) {
        *this = *this - other; return *this;
    }
    Fraction& operator *= (const Fraction& other) {
        *this = *this * other; return *this;
    }
    Fraction& operator /= (const Fraction& other) {
        *this = *this / other; return *this;
    }

    bool operator == (const Fraction& other) const {
        return n * other.d == other.n * d;
    }
    bool operator != (const Fraction& other) const {
        return !(*this == other);
    }
    bool operator < (const Fraction& other) const {
        return (n * other.d < other.n * d);
    }
    bool operator > (const Fraction& other) const {
        return other < *this;
    }
    bool operator <= (const Fraction& other) const {
        return !(*this > other);
    }
    bool operator >= (const Fraction& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator << (std::ostream& output, const Fraction& fraction) {
        if (fraction.d == 1) output << fraction.n;
        else output << fraction.n << "/" << fraction.d;
        return output;
    }

    friend std::istream& operator >> (std::istream& input, Fraction& fraction) {
        std::string str; input >> str;

        if (str.empty()) {
            input.setstate(std::ios::failbit);
            return input;
        }
        for (char& c : str) if (c == ',') c = '.';
        size_t slash = str.find('/');

        try {
            if (slash != std::string::npos) fraction = Fraction(std::stod(str.substr(0, slash)), std::stod(str.substr(slash + 1)));
            else fraction = Fraction(std::stod(str));
        } catch (...) {
            input.setstate(std::ios::failbit);
        }
        return input;
    }

    void setNumerator(double numerator) {
        n = numerator;
    }
    void setDenominator(double denominator) {
        d = denominator;
    }

    double getNumerator() const {
        return n;
    }
    double getDenominator() const {
        return d;
    }

private:
    double n, d;

    void normalize() {
        if (n == 0) {
            n = 0;
            d = 1;
        } else {
            if (d == 0) throw std::invalid_argument("Знаменатель не может быть равен нулю!");
            if (d < 0) {
                n = -n;
                d = -d;
            }
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try {
        Fraction
            f1(1.0, 2.0),   // 1/2
            f2(1.0, 4.0),   // 1/4
            f3(1.5),        // 3/2 (конвертация из double)
            f4(0.25);       // 1/4 (конвертация из double)

        std::cout << "Тест вывода\n";
        std::cout << "- f1: " << f1 << '\n';
        std::cout << "- f2: " << f2 << '\n';
        std::cout << "- f3 (1.5): " << f3 << '\n';
        std::cout << "- f4 (0.25): " << f4 << '\n';
        std::cout << "- f1 + f2 = " << (f1 + f2) << '\n';
        std::cout << "- f1 * f2 = " << (f1 * f2) << '\n';

        std::cout << "\nТест ввода\n";
        std::cout << "- Введите дробь для f5 через / (слэш): ";
        Fraction f5;
        if (std::cin >> f5) {
            std::cout << "\tВаша дробь: " << f5 << '\n';
        } else {
            std::cout << "Неверный ввод данных!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "\n- Введите вещественное число через . (точку) для превращения в дробь f6: ";
        Fraction f6;
        if (std::cin >> f6) {
            std::cout << "\tВаша дробь: " << f6 << '\n';
        } else {
            std::cout << "Неверный ввод данных!'\n'";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "\n- Введите вещественное число через , (запятую) для превращения в дробь f7: ";
        Fraction f7;
        if (std::cin >> f7) {
            std::cout << "\tВаша дробь: " << f7 << '\n';
        } else {
            std::cout << "Неверный ввод данных!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "\n- Введите целое число для дроби f8: ";
        Fraction f8;
        if (std::cin >> f8) {
            std::cout << "\tВаша дробь: " << f8 << '\n';
        } else {
            std::cout << "Неверный ввод данных!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "\nОперации над вашими дробями\n";
        std::cout << "- f1 + f5 = " << (f1 + f5) << '\n';
        std::cout << "- f1 * f6 = " << (f1 * f6) << '\n';
        std::cout << "- f7 + f8 = " << (f7 + f8) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}