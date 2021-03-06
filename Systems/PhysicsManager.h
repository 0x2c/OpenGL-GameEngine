#ifndef __PHYSMGR_H__
#define __PHYSMGR_H__

#include <iostream>
#include <unordered_map>

#include "Physics/Simulation.h"
#include "Physics/BVH/NaiveCollision.h"

using namespace Fizzix;


class PhysicsManager {
public:
	PhysicsManager();
	~PhysicsManager();

	void StartUp();
	void Shutdown();

	unsigned int RegisterPBody(PBody *pbody);
	void DeregisterPBody(unsigned int key);
	PBody* GetPBody(unsigned int key);
	void Update(float t, float dt);

	struct {
		bool __player;
		bool __arrows;
		bool __enemies;
		bool __trees;
	} DebugDraw;

	NaiveCollision *refCS;
	static unsigned int player_cid;
private:
	static unsigned int pid_gen;
	static unsigned int player_pid; //The only pid PhysicsMgr will manage
	

	void UpdatePlayer(float t, float dt);
	std::unordered_map<unsigned int, PBody *> pobjects;
};

#endif