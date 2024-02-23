#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x, m_Giraffe->GetPosition().y + 10});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x - 10, m_Giraffe->GetPosition().y});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x, m_Giraffe->GetPosition().y - 10});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_Giraffe->SetPosition({m_Giraffe->GetPosition().x + 10, m_Giraffe->GetPosition().y});
    }

    if (m_Phase == Phase::COLLIDE_DETECTION) {
        if (m_Giraffe->IfCollides(m_Chest)) {
            m_Chest->SetVisible(false);
        }
    }

    if (m_Phase == Phase::BEE_ANIMATION) {
        m_Bee->SetLooping(true);
        m_Bee->Play();
    } else {
        m_Bee->SetLooping(false);
    }

    if (m_Phase == Phase::OPEN_THE_DOORS) {
        for (auto& door : m_Doors) {
            if (m_Giraffe->IfCollides(door)) {
                door->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
            }
        }
    }

    if (m_Phase == Phase::COUNTDOWN) {
        m_Ball->SetVisible(true);
        if (firstTime < 2) {
            m_Ball->Play();
            firstTime++;
        }
    }

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
