#ifndef QUATERNION_H
#define QUATERNION_H

namespace MyMathFuncs
{
	__declspec(align(32)) struct Quaternion
	{
		Quaternion();
		Quaternion(double q_a, double q_b, double q_c, double q_d);
		double real();
		double i();
		double j();
		double k();
		Quaternion imaginary();
		Quaternion imaginary() const;
		const Quaternion& turn_imaginary();
		Quaternion conjugation();
		Quaternion conjugation() const;
		const Quaternion& turn_conjugate();
		//const Quaternion& turn_conjugate() const;
		Quaternion plus();
		Quaternion plus() const;
		//const Quaternion& turn_plus();
		Quaternion minus();
		Quaternion minus() const;
		//const Quaternion& turn_minus();
		Quaternion inverse();
		Quaternion inverse() const;
		const Quaternion& turn_inverse();
		double norm();
		double norm() const;
		// <=, <, >, >= operator requires three value logic due to partial ordering
		bool operator==(const Quaternion& rhs);
		bool operator!=(const Quaternion& rhs);
		Quaternion& operator=(const Quaternion& rhs);
		Quaternion& operator+=(const double& rhs);
		Quaternion& operator+=(const Quaternion& rhs);
		friend Quaternion operator+(const double& lhs, const Quaternion& rhs);
		friend Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs);
		Quaternion& operator-=(const double& rhs);
		Quaternion& operator-=(const Quaternion& rhs);
		friend Quaternion operator-(const double& lhs, const Quaternion& rhs);
		friend Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs);
		Quaternion& operator*=(const double& rhs);
		Quaternion& operator*=(const Quaternion& rhs);
		friend Quaternion operator*(const double& lhs, const Quaternion& rhs);
		friend Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);
		static double distance(const Quaternion& p, const Quaternion& q);
		static double dot(const Quaternion& p, const Quaternion& q);
		static Quaternion cross(const Quaternion& p, const Quaternion& q);
		static double mixed(const Quaternion& p, const Quaternion& q, const Quaternion& r);
		static Quaternion polar_to_Quaternion(const double& norm, const double& angle, const double& vx, const double& vy, const double& vz);
		static Quaternion rotation_about_axis(const double& angle, const double& vx, const double& vy, const double& vz, const Quaternion& p);
		static Quaternion sgn(const Quaternion& p);
		static double Arg(const Quaternion& p);
		static double arg(const Quaternion& p, const int& n);
		static Quaternion exp(const Quaternion& p);
		static Quaternion Log(const Quaternion& p);
		static Quaternion log(const Quaternion& p, const int& n);
		static Quaternion Pow(const Quaternion& p, const Quaternion& power);
		static Quaternion pow(const Quaternion& p, const int& power);
		static Quaternion pow(const Quaternion& p, const int& numerataor, const int& denominator, const int& n);
		static Quaternion pow(const Quaternion& p, const Quaternion& power, const int& n);
		static Quaternion cos(const Quaternion& p);
		static Quaternion sin(const Quaternion& p);
		static Quaternion tan(const Quaternion& p);
		static Quaternion csc(const Quaternion& p);
		static Quaternion sec(const Quaternion& p);
		static Quaternion cot(const Quaternion& p);
		static Quaternion cosh(const Quaternion& p);
		static Quaternion sinh(const Quaternion& p);
		static Quaternion tanh(const Quaternion& p);
		static Quaternion sech(const Quaternion& p);
		static Quaternion csch(const Quaternion& p);
		static Quaternion coth(const Quaternion& p);
		static Quaternion acosh(const Quaternion& p);
		static Quaternion asinh(const Quaternion& p);
		static Quaternion atanh(const Quaternion& p);
		static Quaternion asech(const Quaternion& p);
		static Quaternion acsch(const Quaternion& p);
		static Quaternion acoth(const Quaternion& p);
		static Quaternion acos(const Quaternion& p);
		static Quaternion asin(const Quaternion& p);
		static Quaternion atan(const Quaternion& p);
		static Quaternion asec(const Quaternion& p);
		static Quaternion acsc(const Quaternion& p);
		static Quaternion acot(const Quaternion& p);
		~Quaternion();
		friend std::ostream& operator<<(std::ostream& os, const Quaternion& p);
		static void test()
		{

		};

		private:
			double a, b, c, d;
	};
}
#endif