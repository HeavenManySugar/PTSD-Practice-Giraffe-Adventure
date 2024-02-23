#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"


class AnimatedCharacter : public Util::GameObject {

public:
    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetLooping(bool looping) {
        auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        animation->SetLooping(looping);
    }
    
    void Play() {
        auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        animation->Play();
    }

    void Pause() {
        auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        animation->Pause();
    }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    [[nodiscard]] bool IfAnimationEnds() const;

};

#endif //ANIMATED_CHARACTER_HPP
