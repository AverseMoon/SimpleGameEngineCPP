#define SDL_MAIN_HANDLED
#include "Vector.h"
#include <SDL.h>
#include <list>
#include <string>
#include <sstream>
#include <memory.h>
#pragma once
using namespace std;
using namespace SGE_UTIL;
#ifndef SIMPLE_GAME_ENGINE_TREE
#define SIMPLE_GAME_ENGINE_TREE
#endif



namespace SGE_NODES {
	class NODE2D;
	typedef shared_ptr<NODE2D> NODETYPE;
	class NODE2D {
	private:
		Vec2 pos;
		Vec2 scl;
	public:
		Vec2 campos = Vec2(1,1);
		Vec2 camscl;
		Vec2 position;
		Vec2 scale;
		list<NODETYPE> children;
		void addChild(NODETYPE child) { children.push_back(child); child->refreshPosition(campos); child->refreshSize(scale); }

		void setPos(Vec2 newPos) { pos = newPos; refreshPosition(campos); }
		void setScale(Vec2 newScale) { scl = newScale; refreshSize(camscl); }

		void parentRefreshPosition(Vec2 ParentPos) {
			campos = ParentPos;
			position = pos + ParentPos;
			for (NODETYPE obj : children) {
				obj->parentRefreshPosition(position);
			}
		}
		void refreshPosition(Vec2 CameraPos) {
			campos = CameraPos;
			position = pos - CameraPos;
			for (NODETYPE obj : children) {
				obj->parentRefreshPosition(position);
			}
		}
		void refreshSize(Vec2 newScale) {
			camscl = newScale;
			scale = scl * newScale;
			refs();
			for (NODETYPE obj : children) {
				obj->refreshSize(scale);
			}
		}
		virtual void refs() {}
		void RENDER(SDL_Renderer* renderer) {
			this->render(renderer);
			for (NODETYPE child : children) { child->RENDER(renderer); }
		}
		virtual void render(SDL_Renderer* renderer) { }

		NODE2D(Vec2 p = Vec2(), Vec2 s = Vec2(1,1)) {
			pos = p;
			scl = s;
		}
	};

	class RECTANGLE : public NODE2D {
	private:
		Vec2 WH;
	public:
		RGBA color;
		Vec2 wh;

		void setSize(Vec2 newSize) { WH = newSize; refreshSize(camscl); }

		RECTANGLE(Vec2 p = Vec2(50,50), Vec2 wh = Vec2(50, 50), Vec2 s = Vec2(1,1), RGBA color = RGBA(255u,255u,255u,255u)) : NODE2D(p,s) {
			this->color = color;
			this->WH = wh;
		}
		virtual void refs() {
			wh = WH * scale;
		}
		virtual void render(SDL_Renderer* renderer) {
			SDL_Rect rect = { position.x, position.y, wh.x, wh.y };
			color.SetRenderColor(renderer);
			SDL_RenderFillRect(renderer, &rect);
		}
	};
	shared_ptr<NODE2D> Node2d(Vec2 position = Vec2(), Vec2 scale = Vec2(1, 1)) {
		return make_shared<NODE2D>(position, scale);
	}
	shared_ptr<NODE2D> Rectangle(Vec2 position = Vec2(), Vec2 wh = Vec2(50,50), Vec2 scale = Vec2(1,1), RGBA color = RGBA(255u, 255u, 255u, 255u)) {
		return make_shared<RECTANGLE>(position, wh, scale, color);
	}
	
}