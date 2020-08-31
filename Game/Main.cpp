#include "pch.h"
#include "TileMap.h"
#include "Core/Json.h"
#include "Objects/Scene.h"
#include "Graphics/Texture.h"
#include "Objects/GameObject.h"
#include "Components/PlayerComponent.h"

nc::Engine engine;
nc::Scene scene;

int main(int, char**){
	engine.Startup();

	nc::ObjectFactory::Instance().Initialize();
	nc::ObjectFactory::Instance().Register("PlayerComponent", new nc::Creator<nc::PlayerComponent, nc::Object>);

	rapidjson::Document document;
	nc::json::Load("scene.txt", document);

	scene.Create(&engine);
	scene.Read(document);

	nc::TileMap tileMap;
	nc::json::Load("tileMap.txt", document);
	tileMap.Read(document);
	tileMap.Create(&scene);

	SDL_Event event;
	bool quit = false;
	while (!quit) {
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}

		//update
		engine.Update();
		scene.Update();

		quit = (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == nc::InputSystem::eButtonState::PRESSED);

		//draw
		engine.GetSystem<nc::Renderer>()->BeginFrame();

		scene.Draw();

		engine.GetSystem<nc::Renderer>()->EndFrame();
	}

	engine.Shutdown();

	return 0;
}

/*std::string str;
	nc::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	nc::json::Get(document, "bool", b);
	std::cout << b << std::endl;

	int i1;
	nc::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	nc::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	nc::json::Get(document, "float", f);
	std::cout << f << std::endl;

	nc::Vector2 v2;
	nc::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	nc::Color color;
	nc::json::Get(document, "color", color);
	std::cout << color << std::endl;*/