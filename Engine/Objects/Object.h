#pragma once
#include "Core/Json.h"

namespace nc {
	class Object {
	public:
		virtual void Create(void* data = nullptr) = 0;
		virtual void Destroy() = 0;
		virtual Object* Clone() { return nullptr; }

		virtual void Read(const rapidjson::Value& value) {}

		virtual void Update() {}
	
		template<typename T>
		static Object* Instantiate() {
			T* instance = new T;
			return instance;
		}
	};
}