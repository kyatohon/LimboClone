#ifndef PLAYER_H
#define PLAYER_H

#include "scenes/PlatformerScene.h"
#include "gameobjects/PhysicsObject.h"
#include "framework/Animation.h"



namespace GAME {
	class Player : public PhysicsObject {
	public:

		enum PlayerState {
			IDLE = 0,
			RUNNING = 1,
			JUMPING = 2,
			DEAD = 3,
			NUM_ANIMATIONS = 4
		};


		Player(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Player();

		Player(const Player&) = delete;
		Player(Player &&) = delete;
		Player& operator=(const Player &) = delete;
		Player& operator=(Player &&) = delete;

		bool IsDead() const;

		void HandleInput(const bool keyDownW, const bool keyDownA,
			const bool keyDownS, const bool keyDownD,
			const bool keyDownSPACE);

		void BeginContact(const b2Contact* contact, const PhysicsObject& physObjRef);
		void EndContact(const b2Contact* contact, const PhysicsObject& physObjRef);

		void Update(const float deltaTime);
		void Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

	private:
		void Move(const float32 force);
		void Jump();
		void Stop();

	private:
		SDL_RendererFlip flipTex = SDL_FLIP_NONE;
		std::vector<Animation*>* animations;
		PlayerState currentState;
		int32 numContacts = 0;
	};
}

#endif