#pragma once
#include <math.h>

template<class type>
class Vector2 {
	public:
		type x, y;

		Vector2()
			:x(0), y(0)
		{}

		Vector2(const type x,const type y)
			: x(x), y(y)
		{ }

		Vector2(const Vector2& vector2)
			: x(vector2.x), y(vector2.y)
		{ }

		void Normalize(){
			auto length = sqrt(static_cast<double>(x * x + y * y));
			if (length != 0) {
				x = x / length;
				y = y / length;
			}
		}

		Vector2 operator+(const Vector2& other) const {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator*(const type other) const {
			return Vector2(x * other, y * other);
		}

	private:
		
};