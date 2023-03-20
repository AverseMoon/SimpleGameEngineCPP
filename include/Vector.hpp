#define SDL_MAIN_HANDLED
#include <string>
#include <sstream>
#include <SDL.h>
#pragma once
using namespace std;
#ifndef SIMPLE_GAME_ENGINE_UTIL
#define SIMPLE_GAME_ENGINE_UTIL
#endif

namespace SGE_UTIL {
	class Vec2 {
	public:
		float x = 0.0;
		float y = 0.0;
		Vec2(float X, float Y) {
			x = X;
			y = Y;
		}
		Vec2(int X, int Y) {
			x = (float)X;
			y = (float)Y;
		}
		Vec2() {}
		Vec2 operator+(Vec2 const& obj) {
			return Vec2(x+obj.x, y + obj.y);
		}
		Vec2 operator-(Vec2 const& obj) {
			return Vec2(x - obj.x, y - obj.y);
		}
		Vec2 operator*(Vec2 const& obj) {
			return Vec2(x * obj.x, y * obj.y);
		}
		Vec2 operator/(Vec2 const& obj) {
			return Vec2(x / obj.x, y / obj.y);
		}
		string to_string() {
			stringstream output;

			output << "Vector2 object: {\n\tX: " << x << "\n\tY: " << y << "\n}";

			return output.str();
		}
	};
	class Vec2i {
	public:
		int x = 0.0;
		int y = 0.0;
		Vec2i(float X, float Y) {
			x = (int)X;
			y = (int)Y;
		}
		Vec2i(int X, int Y) {
			x = X;
			y = Y;
		}
		Vec2i(Vec2 conv) {
			x = (int)conv.x;
			y = (int)conv.y;
		}
		Vec2i() {}
		Vec2i operator+(Vec2i const& obj) {
			return Vec2(x + obj.x, y + obj.y);
		}
		Vec2i operator-(Vec2i const& obj) {
			return Vec2(x - obj.x, y - obj.y);
		}
		Vec2i operator*(Vec2i const& obj) {
			return Vec2i(x * obj.x, y * obj.y);
		}
		Vec2i operator/(Vec2i const& obj) {
			return Vec2i(x / obj.x, y / obj.y);
		}
		string to_string() {
			stringstream output;

			output << "Vector2i object: {\n\tX: " << x << "\n\tY: " << y << "\n}";

			return output.str();
		}
	};
	class Vec3 {
	public:
		float x = 0.0;
		float y = 0.0;
		float z = 0.0;
		Vec3(float X, float Y, float Z) {
			x = X;
			y = Y;
			z = Z;
		}
		Vec3(int X, int Y, int Z) {
			x = (float)X;
			y = (float)Y;
			z = (float)Z;
		}
		Vec3() {}
		Vec3 operator+(Vec3 const& obj) {
			return Vec3(x + obj.x, y + obj.y, z + obj.z);
		}
		Vec3 operator-(Vec3 const& obj) {
			return Vec3(x - obj.x, y - obj.y, z - obj.z);
		}
		Vec3 operator*(Vec3 const& obj) {
			return Vec3(x * obj.x, y * obj.y, z * obj.z);
		}
		Vec3 operator/(Vec3 const& obj) {
			return Vec3(x / obj.x, y / obj.y, z / obj.z);
		}
		string to_string() {
			stringstream output;

			output << "Vector3 object: {\n\tX: " << x << "\n\tY: " << y << "\n\tZ: " << z << "\n}";

			return output.str();
		}
	};
	class Vec3i {
	public:
		int x = 0;
		int y = 0;
		int z = 0;
		Vec3i(float X, float Y, float Z) {
			x = X;
			y = Y;
			z = Z;
		}
		Vec3i(int X, int Y, int Z) {
			x = X;
			y = Y;
			z = Z;
		}
		Vec3i(Vec3 conv) {
			x = (int)conv.x;
			y = (int)conv.y;
			z = (int)conv.z;
		}
		Vec3i() {}
		Vec3i operator+(Vec3i const& obj) {
			return Vec3i(x + obj.x, y + obj.y, z + obj.z);
		}
		Vec3i operator-(Vec3i const& obj) {
			return Vec3i(x - obj.x, y - obj.y, z - obj.z);
		}
		Vec3i operator*(Vec3i const& obj) {
			return Vec3i(x * obj.x, y * obj.y, z * obj.z);
		}
		Vec3i operator/(Vec3i const& obj) {
			return Vec3i(x / obj.x, y / obj.y, z / obj.z);
		}
		string to_string() {
			stringstream output;

			output << "Vector3i object: {\n\tX: " << x << "\n\tY: " << y << "\n\tZ: " << z << "\n}";

			return output.str();
		}
	};
	class Vec4 {
	public:
		float x = 0.0;
		float y = 0.0;
		float z = 0.0;
		float h = 0.0;
		Vec4(float X, float Y, float Z, float H) {
			x = X;
			y = Y;
			z = Z;
			h = H;
		}
		Vec4(int X, int Y, int Z, int H) {
			x = X;
			y = Y;
			z = Z;
			h = H;
		}
		Vec4() {}
		Vec4 operator+(Vec4 const& obj) {
			return Vec4(x + obj.x, y + obj.y, z + obj.z, h + obj.h);
		}
		Vec4 operator-(Vec4 const& obj) {
			return Vec4(x - obj.x, y - obj.y, z - obj.z, h - obj.h);
		}
		Vec4 operator*(Vec4 const& obj) {
			return Vec4(x * obj.x, y * obj.y, z * obj.z, h * obj.h);
		}
		Vec4 operator/(Vec4 const& obj) {
			return Vec4(x / obj.x, y / obj.y, z / obj.z, h / obj.h);
		}
		string to_string() {
			stringstream output;

			output << "Vector4 object: {\n\tX: " << x << "\n\tY: " << y << "\n\tZ: " << z << "\n\tH: " << h << "}";

			return output.str();
		}
	};
	class Vec4i {
	public:
		int x = 0.0;
		int y = 0.0;
		int z = 0.0;
		int h = 0.0;
		Vec4i(float X, float Y, float Z, float H) {
			x = X;
			y = Y;
			z = Z;
			h = H;
		}
		Vec4i(int X, int Y, int Z, int H) {
			x = X;
			y = Y;
			z = Z;
			h = H;
		}
		Vec4i(Vec4 conv) {
			x = (int)conv.x;
			y = (int)conv.y;
			z = (int)conv.z;
			h = (int)conv.h;
		}
		Vec4i() {}
		Uint32 Map_RGBA(const SDL_PixelFormat* format) {
			return SDL_MapRGBA(format, (Uint8)x, (Uint8)y, (Uint8)z, (Uint8)h);
		}
		Vec4i operator+(Vec4i const& obj) {
			return Vec4i(x + obj.x, y + obj.y, z + obj.z, h + obj.h);
		}
		Vec4i operator-(Vec4i const& obj) {
			return Vec4i(x - obj.x, y - obj.y, z - obj.z, h - obj.h);
		}
		Vec4i operator*(Vec4i const& obj) {
			return Vec4i(x * obj.x, y * obj.y, z * obj.z, h * obj.h);
		}
		Vec4i operator/(Vec4i const& obj) {
			return Vec4i(x / obj.x, y / obj.y, z / obj.z, h / obj.h);
		}
		string to_string() {
			stringstream output;

			output << "Vector4 object: {\n\tX: " << x << "\n\tY: " << y << "\n\tZ: " << z << "\n\tH: " << h << "}";

			return output.str();
		}
	};
	class RGBA {
	public:
		Uint8 r = 0xFF;
		Uint8 g = 0xFF;
		Uint8 b = 0xFF;
		Uint8 a = 0xFF;

		RGBA(Uint8 R = 0xFF, Uint8 G = 0xFF, Uint8 B = 0xFF, Uint8 A = 0xFF) {
			r = R;
			g = G;
			b = B;
			a = A;
		}
		RGBA(Vec4 conv) {
			r = conv.x;
			g = conv.y;
			b = conv.z;
			a = conv.h;
		}
		RGBA operator+(RGBA const& obj) {
			return RGBA(r + obj.r, g + obj.g, b + obj.b, a + obj.a);
		}
		RGBA operator-(RGBA const& obj) {
			return RGBA(r - obj.r, g - obj.g, b - obj.b, a - obj.a);
		}
		RGBA operator*(RGBA const& obj) {
			return RGBA(r * obj.r, g * obj.g, b * obj.b, a * obj.a);
		}
		RGBA operator/(RGBA const& obj) {
			return RGBA(r / obj.r, g / obj.g, b / obj.b, a / obj.a);
		}
		Uint32 toUint32(SDL_PixelFormat* format) {
			return SDL_MapRGBA(format, r, g, b, a);
		}
		SDL_Surface* CreateSurface(int width, int height, Uint32 flags = 0) {
			return SDL_CreateRGBSurface(flags, width, height, 32, r, g, b, a);
		}
		int SetRenderColor(SDL_Renderer* renderer) { return SDL_SetRenderDrawColor(renderer, r, g, b, a); }
		string to_string() {
			stringstream output;

			output << "RGBA object: {\n\tRed: " << r << "\n\tGreen: " << g << "\n\tBlue: " << b << "\n\tAlpha: " << a << "}";

			return output.str();
		}
	};
}