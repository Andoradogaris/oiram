#include "WindowManager.h"

#include "../TemplateUtils.h"
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
    InputManager* eventManager = ObjectManager::Get()->CastCreateObject<InputManager>(InputManager::ClassName());
    eventManager->SetWindowRef(&window);

    Rigidbody* rb = Cast<Rigidbody>(player->components.at("rigidbody"));
    Renderer* rend = Cast<Renderer>(player->components.at("rend"));

    rb->useGravity = true;
    
    while (window.isOpen())
    {
        eventManager->ListenEvent();
        window.clear(sf::Color::Black);

        rb->Gravity(.1f);
        rb->AddForce(Vector2(0.f, -.0001f), Constant);
        rend->sprite.move(rb->velocity.x, rb->velocity.y);
        std::cout << rb->velocity.x << " | " << rb->velocity.y << std::endl;

        
        for (auto obj : objectToDraw)
        {
            window.draw(obj->sprite);
        }

        window.display();
    }

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
