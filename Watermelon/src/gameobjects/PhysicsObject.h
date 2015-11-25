#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "GameObject.h"
#include "ContactListener.h"
#include "Box2D/Box2D.h"


namespace GAME {
	class PhysicsObject : public GameObject, public ContactListener {
	public:
		PhysicsObject(int x = 0, int y = 0);
		virtual ~PhysicsObject();

		PhysicsObject(const PhysicsObject&) = delete;
		PhysicsObject(PhysicsObject &&) = delete;
		PhysicsObject& operator=(const PhysicsObject &) = delete;
		PhysicsObject& operator=(PhysicsObject &&) = delete;

		virtual void Update(const float deltaTime);
		virtual void Draw() const;


	public:
		b2Body* body;
	};
}


#endif