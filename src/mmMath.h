#pragma once

#include "ofMain.h"

class mmVec2i {
	public:
		int x, y;

		mmVec2i() {
			x = 0;
			y = 0;
		}

		mmVec2i(int a, int b) {
			x = a;
			y = b;
		}

		mmVec2i(const mmVec2i & a) {
			x = a.x;
			y = a.y;
		}

		// vector arithmetic
		mmVec2i operator+(mmVec2i const & a) {
			return mmVec2i(x + a.x, y + a.y);
		}

		mmVec2i operator-(mmVec2i const & a) {
			return mmVec2i(x - a.x, y - a.y);
		}

		mmVec2i operator*(mmVec2i const & a) {
			return mmVec2i(x * a.x, y * a.y);
		}

		mmVec2i operator/(mmVec2i const & a) {
			return mmVec2i(x / a.x, y / a.y);
		}

		// scalar arithmetic
		template <typename T>
		mmVec2i operator+(T const & s) {
			return mmVec2i(x + s, y + s);
		}

		template <typename T>
		mmVec2i operator-(T const & s) {
			return mmVec2i(x - s, y - s);
		}


		template <typename T>
		mmVec2i operator*(T const & s) {
			return mmVec2i(x * s, y * s);
		}

		template <typename T>
		mmVec2i operator/(T const & s) {
			return mmVec2i(x / s, y / s);
		}

		// ostream output
		friend ostream & operator<<(ostream & os, const mmVec2i & a) {
			os << "(" << a.x << ", " << a.y << ")";
			return os;
		}
};

class mmVec2f {
	public:
		float x, y;

		mmVec2f() {
			x = 0.f;
			y = 0.f;
		}

		mmVec2f(float a, float b) {
			x = a;
			y = b;
		}

		mmVec2f(const mmVec2f & a) {
			x = a.x;
			y = a.y;
		}

		// vector arithmetic
		mmVec2f operator+(mmVec2f const & a) {
			return mmVec2f(x + a.x, y + a.y);
		}

		mmVec2f operator-(mmVec2f const & a) {
			return mmVec2f(x - a.x, y - a.y);
		}

		mmVec2f operator*(mmVec2f const & a) {
			return mmVec2f(x * a.x, y * a.y);
		}

		mmVec2f operator/(mmVec2f const & a) {
			return mmVec2f(x / a.x, y / a.y);
		}

		// scalar arithmetic
		template <typename T>
		mmVec2f operator+(T const & s) {
			return mmVec2f(x + s, y + s);
		}

		template <typename T>
		mmVec2f operator-(T const & s) {
			return mmVec2f(x - s, y - s);
		}

		template <typename T>
		mmVec2f operator*(T const & s) {
			return mmVec2f(x * s, y * s);
		}

		template <typename T>
		mmVec2f operator/(T const & s) {
			return mmVec2f(x / s, y / s);
		}

		// ostream output
		friend ostream & operator<<(ostream & os, const mmVec2f & a) {
			os << "(" << a.x << ", " << a.y << ")";
			return os;
		}
};

class mm2dVec2i {
	public:
		// top left / bottom right
		mmVec2i tl, br;

		mm2dVec2i() {
			tl = mmVec2i();
			br = mmVec2i();
		}

		mm2dVec2i(int a, int b, int c, int d) {
			tl = mmVec2i(a, b);
			br = mmVec2i(c, d);
		}
		
		mm2dVec2i(mmVec2i a, mmVec2i b) {
			tl = a;
			br = b;
		}

		mm2dVec2i(const mm2dVec2i & a) {
			tl = a.tl;
			br = a.br;
		}

		mm2dVec2i operator+(mmVec2i const & a) {
			if (a.x < tl.x) tl.x = a.x;
			if (a.y < tl.y) tl.y = a.y;
			if (a.x > br.x) br.x = a.x;
			if (a.y > br.y) br.y = a.y;

			return mm2dVec2i((*this));
		}

		// ostream output
		friend ostream & operator<<(ostream & os, const mm2dVec2i & a) {
			os << "[" << a.tl << "<->" << a.br << "]";
			return os;
		}
};

class mm2dVec2f {
	public:
		mmVec2f tl, br;

		mm2dVec2f() {
			tl = mmVec2f();
			br = mmVec2f();
		}

		mm2dVec2f(int a, int b, int c, int d) {
			tl = mmVec2f(a, b);
			br = mmVec2f(c, d);
		}
		
		mm2dVec2f(mmVec2f a, mmVec2f b) {
			tl = a;
			br = b;
		}

		mm2dVec2f(const mm2dVec2f & a) {
			tl = a.tl;
			br = a.br;
		}

		mm2dVec2f operator+(mmVec2f const & a) {
			if (a.x < tl.x) tl.x = a.x;
			if (a.y < tl.y) tl.y = a.y;
			if (a.x > br.x) br.x = a.x;
			if (a.y > br.y) br.y = a.y;

			return mm2dVec2f((*this));
		}

		// ostream output
		friend ostream & operator<<(ostream & os, const mm2dVec2f & a) {
			os << "[" << a.tl << "<->" << a.br << "]";
			return os;
		}
};

class mmVec {
	public:
		static mmVec2f to_f(mmVec2i const & a) {
			return mmVec2f(a.x, a.y);
		}

		static mmVec2i to_i(mmVec2f const & a) {
			return mmVec2i(a.x, a.y);
		}

		static mm2dVec2i boundaryFromSize(mmVec2i const & size) {
			return mm2dVec2i(-size.x, -size.y, size.x + 1, size.y + 1);
		}
};

