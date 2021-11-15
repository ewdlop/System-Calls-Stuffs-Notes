 #define _USE_MATH_DEFINES
#include <cmath>
#include <iostream> 
#include "Quaternion.h"

namespace MyMathFuncs {
	
	Quaternion::Quaternion() : a(0), b(0), c(0), d(0) {}
	Quaternion::Quaternion(double q_a, double q_b, double q_c, double q_d) : a(q_a), b(q_b), c(q_c), d(q_d) {}

	double Quaternion::real() { return a;}
	double Quaternion::i() { return b;}
	double Quaternion::j(){ return c;}
	double Quaternion::k(){ return d;}

	Quaternion Quaternion::imaginary() 
	{
		return Quaternion(0, b, c, d);
	}

	Quaternion Quaternion::imaginary() const
	{
		return Quaternion(0, b, c, d);
	}
	const Quaternion& Quaternion::turn_imaginary() 
	{
		a = 0;
		return *this;
	}

	Quaternion Quaternion::conjugation() 
	{
		return Quaternion(a, -1 * b, -1 * c, -1 * d);
	}
	Quaternion Quaternion::conjugation() const 
	{
		return Quaternion(a, -1 * b, -1 * c, -1 * d);
	}
	const Quaternion& Quaternion::turn_conjugate() 
	{
		b *= -1;
		c *= -1;
		d *= -1;
		return *this;
	}

	Quaternion Quaternion::plus() 
	{
		return Quaternion(a + d, (b - c), 0, 0) * Quaternion(1 / 2.0, 0, 0, 1 / 2.0);
	}
	Quaternion Quaternion::plus() const 
	{
		return Quaternion(a + d, (b - c), 0, 0) * Quaternion(1 / 2.0, 0, 0, 1 / 2.0);
	}

	Quaternion Quaternion::minus() {
		return Quaternion(a - d, (b + c), 0, 0) * Quaternion(1 / 2.0, 0, 0, -1 / 2.0);
	}
	Quaternion Quaternion::minus() const
	{
		return Quaternion(a - d, (b + c), 0, 0) * Quaternion(1 / 2.0, 0, 0, -1 / 2.0);
	}
	
	double Quaternion::norm() 
	{
		return std::sqrt(std::pow(a, 2) + std::pow(b, 2) + std::pow(c, 2) + std::pow(d, 2));
	}
	double Quaternion::norm() const
	{
		return std::sqrt(std::pow(a, 2) + std::pow(b, 2) + std::pow(c, 2) + std::pow(d, 2));
	}

	Quaternion Quaternion::inverse() 
	{
		double normSquareinverse = 1.0 / std::pow(this->norm(), 2);
		return normSquareinverse * this->conjugation();
	}
	Quaternion Quaternion::inverse() const
	{
		double normSquareinverse = 1.0 / std::pow(this->norm(), 2);
		return normSquareinverse * this->conjugation();
	}
	const Quaternion& Quaternion::turn_inverse()
	{
		double normSquareinverse = 1.0 / std::pow(this->norm(), 2);
		this->turn_conjugate();
		*this *= normSquareinverse;
		return *this;
	}

	bool Quaternion::operator==(const Quaternion& rhs)
	{
		return a == rhs.a && b == rhs.b && c == rhs.c && d ==rhs.d;
	}
	bool Quaternion::operator!=(const Quaternion& rhs)
	{
		return !(*this == rhs);
	}
	Quaternion& Quaternion::operator=(const Quaternion& rhs)
	{
		a = rhs.a;
		b = rhs.b;
		c = rhs.c;
		d = rhs.d;;
		return *this;
	}
	//Quaternion& Quaternion::operator=(Quaternion&& rhs)
	//{
	//	this->a = std::move(rhs.a);
	//	this->b = std::move(rhs.b);
	//	this->c = std::move(rhs.c);
	//	this->d = std::move(rhs.d);
	//	return *this;
	//}

	Quaternion& Quaternion::operator+=(const double& rhs)
	{
		a += rhs;
		return *this;
	}
	Quaternion& Quaternion::operator+=(const Quaternion& rhs)
	{
		a += rhs.a;
		b += rhs.b;
		c += rhs.c;
		d += rhs.d;;
		return *this;
	}
	Quaternion operator+(const double& lhs, const Quaternion& p)
	{
		return Quaternion(lhs + p.a, p.b, p.c, p.d);
	}
	Quaternion operator+(const Quaternion& p, const Quaternion& q)
	{
		return Quaternion(p.a + q.a, p.b + q.b, p.c + q.c, p.d + q.d);
	}

	Quaternion& Quaternion::operator-=(const double& rhs)
	{
		a -= rhs;
		return *this;
	}
	Quaternion& Quaternion::operator-=(const Quaternion& rhs) 
	{
		a -= rhs.a;
		b -= rhs.b;
		c -= rhs.c;
		d -= rhs.d;
		return *this;
	}
	Quaternion operator-(const double& lhs, const Quaternion& p) 
	{
		return Quaternion(lhs - p.a, -1 * p.b, -1 * p.c, -1 * p.d);
	}
	Quaternion operator-(const Quaternion& p, const Quaternion& q) 
	{
		return Quaternion(p.a - q.a, p.b - q.b, p.c - q.c, p.d - q.d);
	}

	Quaternion& Quaternion::operator*=(const double& rhs) 
	{
		a *= rhs;
		b *= rhs;
		c *= rhs;
		d *= rhs;
		return *this;
	}
	Quaternion& Quaternion::operator*=(const Quaternion& rhs) 
	{
		double real = a * rhs.a - b * rhs.b - c * rhs.c - d * rhs.d;
		double i = a * rhs.b + b * rhs.a + c * rhs.d - d * rhs.c;
		double j = a * rhs.c - b * rhs.d + c * rhs.a + d * rhs.b;
		double k = a * rhs.d + b * rhs.c - c * rhs.b + d * rhs.a;
		a = real;
		b = i;
		c = j;
		d = k;
		return *this;
	}
	Quaternion operator*(const double& lhs, const Quaternion& p)
	{
		return Quaternion(p.a * lhs, p.b * lhs, p.c * lhs, p.d * lhs);
	}
	Quaternion operator*(const Quaternion& p, const Quaternion& q)
	{
		double real = p.a * q.a - p.b * q.b - p.c * q.c - p.d * q.d;
		double i = p.a * q.b + p.b * q.a + p.c * q.d - p.d * q.c;
		double j = p.a * q.c - p.b * q.d + p.c * q.a + p.d * q.b;
		double k = p.a * q.d + p.b * q.c - p.c * q.b + p.d * q.a;
		return Quaternion(real,i,j,k);
	}

	double Quaternion::distance(const Quaternion& p, const Quaternion& q) {
		return Quaternion(p.a - q.a, p.b - q.b, p.c - q.c, p.d - q.d).norm();
	}

	double Quaternion::dot(const Quaternion& p, const Quaternion& q) {
		double n = 1 / 2.0;
		return n * (p * (q.conjugation()) + q * p.conjugation()).real();
	}

	void Quaternion::cross(const Quaternion& q) {
		double a = 0;
		double b = this->c * q.d - q.c * this->d;
		double c = q.b * this->d - this->b * q.d;
		double d = this->b * q.c - q.b * this->c;
		this->a = 0;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	Quaternion& Quaternion::cross2(const Quaternion& q) {
		double a = 0;
		double b = this->c * q.d - q.c * this->d;
		double c = q.b * this->d - this->b * q.d;
		double d = this->b * q.c - q.b * this->c;
		this->a = 0;
		this->b = b;
		this->c = c;
		this->d = d;
		return *this;
	}

	Quaternion Quaternion::cross(const Quaternion& p, const Quaternion& q) {
		return Quaternion(0, p.c * q.d - q.c * p.d, q.b * p.d - p.b * q.d, p.b * q.c - q.b * p.c);
	}

	//Quaternion* Quaternion::cross_ptr(const Quaternion& p, const Quaternion& q) {
	//	return new Quaternion(0, p.c * q.d - q.c * p.d, q.b * p.d - p.b * q.d, p.b * q.c - q.b * p.c);
	//}

	bool Quaternion::try_cross(const Quaternion& p, const Quaternion& q, Quaternion* result)
	{
		result->a = 0;
		result->b = p.c * q.d - q.c * p.d;
		result->c = q.b * p.d - p.b * q.d;
		result->d = p.b * q.c - q.b * p.c;
		return true;
	}

	double Quaternion::mixed(const Quaternion& p, const Quaternion& q, const Quaternion& r) {
		return dot(p, cross(q, r));
	}

	Quaternion Quaternion::polar_to_Quaternion(const double& norm, const double& angle, const double& vx, const double& vy,const double& vz) 
	{
		return norm * (std::cos(angle * M_PI / 180.0)
			+ (1.0 / Quaternion(0, vx, vy, vz).norm())
			* std::sin(angle * M_PI / 180.0)) * Quaternion(0, vx, vy, vz);
	}
	Quaternion Quaternion::rotation_about_axis(const double& angle, const double& vx,const double& vy,const double& vz,const Quaternion& p)
	{
		Quaternion p2Q = polar_to_Quaternion(1.0, angle / 2.0, vx, vy, vz);
		return p2Q * p * p2Q.inverse();
	}

	//notice this sgn is not just a scalar
	Quaternion Quaternion::sgn(const Quaternion& p) {
		if (p.norm() == 0) {
			return Quaternion(0, 0, 0, 0);
		}
		return (1.0 / p.norm()) * p;
	}

	double Quaternion::Arg(const Quaternion& p) {
		if (p.a < 0) {
			return std::atan(p.imaginary().norm() / p.a) + M_PI;
		}
		return std::atan(p.imaginary().norm() / p.a);
	}
	double Quaternion::arg(const Quaternion& p,const int& n) {
		return Arg(p) + 2 * M_PI * n;
	}

	Quaternion Quaternion::exp(const Quaternion& p) {
		return std::exp(p.a)
			* (std::cos(p.imaginary().norm())
			+ std::sin(p.imaginary().norm()) * sgn(p.imaginary()));
	}
	Quaternion Quaternion::Log(const Quaternion& p) {
		//Similar to the branch cut (-00, 0] case for complex number, using principal value
		if (p.imaginary().norm() == 0)
			return Quaternion(std::log(p.norm()), 0, 0, 0);
		return Quaternion(std::log(p.norm()), 0, 0, 0) + Arg(p) * sgn(p.imaginary());
	}
	Quaternion Quaternion::log(const Quaternion& p, const int& n) {
		if (p.imaginary().norm() == 0)
			return Quaternion(std::log(p.norm()), 0, 0, 0);
		return Quaternion(std::log(p.norm()), 0, 0, 0)
			+ arg(p, n) * sgn(p.imaginary());
	}
	Quaternion Quaternion::Pow(const Quaternion& p, const Quaternion& power) {
		//principal value
		return exp(Log(p) * power);
	}
	Quaternion Quaternion::pow(const Quaternion& p, const int& power) {
		if (power <= 0)
			return Quaternion(1, 0, 0, 0);
		return p * pow(p, power - 1);
	}
	Quaternion Quaternion::pow(const Quaternion& p, const int& numerataor, const int& denominator, const int& n) {
		double power = numerataor / (double)denominator;
		return power * exp(log(p, n));
	}
	Quaternion Quaternion::pow(const Quaternion& p, const Quaternion& power, const int& n) {
		return exp(log(p, n) * power);
	}
	Quaternion Quaternion::cos(const Quaternion& p) {
		if (p.imaginary().norm() == 0)
			return Quaternion(std::cos(p.a), 0, 0, 0);
		double factor = 1.0f / p.imaginary().norm() * std::sin(p.a) * std::sinh(p.imaginary().norm());
		return Quaternion(std::cos(p.a) * std::cosh(p.imaginary().norm()),
			-p.b * factor,
			-p.c * factor,
			-p.d * factor);
	}
	Quaternion Quaternion::sin(const Quaternion& p) {
		if (p.imaginary().norm() == 0)
			return Quaternion(std::sin(p.a), 0, 0, 0);
		double factor = 1.0f / p.imaginary().norm() * std::cos(p.a) * std::sinh(p.imaginary().norm());
		return Quaternion(std::sin(p.a) * std::cosh(p.imaginary().norm()),
			p.b * factor,
			p.c * factor,
			p.d * factor);
	}
	Quaternion Quaternion::tan(const Quaternion& p) {
		return sin(p) * cos(p).inverse();
	}
	Quaternion Quaternion::sec(const Quaternion& p) {
		return cos(p).inverse();
	}
	Quaternion Quaternion::csc(const Quaternion& p) {
		return sin(p).inverse();
	}
	Quaternion Quaternion::cot(const Quaternion& p) {
		return tan(p).inverse();
	}
	Quaternion Quaternion::cosh(const Quaternion& p) {
		return 0.5f * (exp(p) + exp(-1 * p));
	}
	Quaternion Quaternion::sinh(const Quaternion& p) {
		return 0.5f * (exp(p) - exp(-1 * p));
	}
	Quaternion Quaternion::tanh(const Quaternion& p) {
		return sinh(p) * cosh(p).inverse();
	}
	Quaternion Quaternion::sech(const Quaternion& p) {
		return 2 * exp(-1 * p) * (1 + exp(-2 * p)).inverse();
	}
	Quaternion Quaternion::csch(const Quaternion& p) {
		return 2 * exp(-1 * p) * (1 - exp(-2 * p)).inverse();
	}
	Quaternion Quaternion::coth(const Quaternion& p) {
		return tanh(p).inverse();
	}
	Quaternion Quaternion::acosh(const Quaternion& p) {
		return Log(p + pow(-1 + pow(p, 2) , 1, 2, 0));
	}
	Quaternion Quaternion::asinh(const Quaternion& p) {
		return Log(p + pow(1 + pow(p, 2), 1, 2, 0));
	}
	Quaternion Quaternion::atanh(const Quaternion& p) {
		return 0.5f * Log(1 + p) - 0.5f * Log(1 - p);
	}
	Quaternion Quaternion::asech(const Quaternion& p) {
		return Log((1 + pow(1 - pow(p, 2), 1, 2, 0)) * p.inverse());
	}
	Quaternion Quaternion::acsch(const Quaternion& p) {
		return Log(p.inverse() + pow(1 + pow(p, 2).inverse(), 1, 2, 0));
	}
	Quaternion Quaternion::acoth(const Quaternion& p) {
		return 0.5f * Log(1 + p) - 0.5f * Log(-1 + p);
	}
	Quaternion Quaternion::acos(const Quaternion& p) {
		return -1 * sgn(p.imaginary()) * acosh(p);
	}
	Quaternion Quaternion::asin(const Quaternion& p) {
		return sgn(-1 * p.imaginary()) * asinh(-1 * p * sgn(-1 * p.imaginary()));
	}
	Quaternion Quaternion::atan(const Quaternion& p) {
		return sgn(-1 * p.imaginary()) * atanh(-1 * p * sgn(-1 * p.imaginary()));;
	}
	Quaternion Quaternion::asec(const Quaternion& p) {
		return acos(p.inverse());
	}
	Quaternion Quaternion::acsc(const Quaternion& p) {
		return asin(p.inverse());
	}
	Quaternion Quaternion::acot(const Quaternion& p) {
		return atan(p.inverse());
	}

	std::ostream& operator<<(std::ostream& os, const Quaternion& p) {
		os << p.a << "+" << p.b << "i+" << p.c << "j+" << p.d << "k";
		return os;
	}

	Quaternion::~Quaternion()
	{
		#ifdef _DEBUG
			std::cout << "destructor" << std::endl;
		#endif // _DEBUG
	}
}