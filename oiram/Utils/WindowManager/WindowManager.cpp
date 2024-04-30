﻿#include "WindowManager.h"

#include "../TemplateUtils.h"
#include "../Utils.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../../Physics/Rigidbody/Rigidbody.h"
#include "../InputManager/InputManager.h"
#include "../ObjectManager/ObjectManager.h"

std::list<GameObject> objectToDraw;

void WindowManager::WindowDraw()
{

    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;
    Player* player = ObjectManager::Get()->CastCreateObject<Player>(Player::ClassName());
    player->InitializeEntity();
    player->InitCharacterComponents();
    Cast<Renderer>(player->components.at("rend"))->SetTexture(player);
    AddNewObject(Cast<Renderer>(player->components.at("rend")));
    sf::RenderWindow window(sf::VideoMode(horizontal, vertical), "My window");
    inputManagerGame->SetWindowRef(&window);
    inputManagerGame->player = player;
    Rigidbody* rb = Cast<Rigidbody>(player->components.at("rigidbody"));
    Renderer* rend = Cast<Renderer>(player->components.at("rend"));

    rend->sprite.move(500, 500);
    
    rb->AddForce(Vector2(0.f, 60.f), Impulse);

    rb->useGravity = true;
    
    while (window.isOpen())
    {
        inputManagerGame->ListenEvent();
        window.clear(sf::Color::Black);

        deltaTime = clock.restart().asSeconds();
        Utils::GetEngine()->deltaTime = deltaTime;
        std::cout << deltaTime << std::endl;

        
        rb->Gravity(deltaTime,1.f);
        rend->sprite.move(rb->velocity.x * deltaTime, rb->velocity.y * deltaTime);
        

        for (auto obj : objectToDraw)
        {
            window.draw(obj->sprite);
        }

        window.display();
    }
    
    clock.restart();
}

std::string WindowManager::GetClass()
{
    return "WindowManager";
}

void WindowManager::AddNewObject(Renderer* object)
{
    objectToDraw.push_back(object);
    
}

std::string WindowManager::ClassName()
{
    return "WindowManager";
}
