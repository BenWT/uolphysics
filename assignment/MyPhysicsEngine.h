#pragma once

#include "BasicActors.h"
#include "CustomObjects.h"
#include <iostream>
#include <iomanip>

namespace PhysicsEngine
{
	using namespace std;

	//a list of colours: Circus Palette
	static const PxVec3 color_palette[] = {PxVec3(46.f/255.f,9.f/255.f,39.f/255.f),PxVec3(217.f/255.f,0.f/255.f,0.f/255.f),
		PxVec3(255.f/255.f,45.f/255.f,0.f/255.f),PxVec3(255.f/255.f,140.f/255.f,54.f/255.f),PxVec3(4.f/255.f,117.f/255.f,111.f/255.f)};


	// Positive X is to the right
	// Positive Z is towards the camera
	const std::vector<PxVec3> firstSectionVerts = {
		// Lower
		PxVec3(0, 0, 0),
		PxVec3(-3, 0, 0),
		PxVec3(-3, 0, -3),
		PxVec3(-5, 0, -3),
		PxVec3(-5, 0, -10),
		PxVec3(-2.5f, 0, -10),
		PxVec3(-2.5f, 0, -7),
		PxVec3(-.5f, 0, -7),
		PxVec3(-.5f, 0, -10),
		PxVec3(2, 0, -10),
		PxVec3(2, 0, -3),
		PxVec3(0, 0, -3),

		// Upper
		PxVec3(0, 1, 0),
		PxVec3(-3, 1, 0),
		PxVec3(-3, 1, -3),
		PxVec3(-5, 1, -3),
		PxVec3(-5, 1, -10),
		PxVec3(-2.5f, 1, -10),
		PxVec3(-2.5f, 0, -7),
		PxVec3(-.5f, 0, -7),
		PxVec3(-.5f, 1, -10),
		PxVec3(2, 1, -10),
		PxVec3(2, 1, -3),
		PxVec3(0, 1, -3),
	};
	const std::vector<PxU32> firstSectionTrigs = {
		13, 12, 0,
		0, 1, 13,
		14, 13, 1,
		1, 2, 14,
		15, 14, 2,
		2, 3, 15,
		16, 15, 3,
		3, 4, 16,
		17, 16, 4,
		4, 5, 17,
		18, 17, 5,
		5, 6, 18,
		19, 18, 6,
		6, 7, 19,
		20, 19, 7,
		7, 8, 20,
		21, 20, 8,
		8, 9, 21,
		22, 21, 9,
		9, 10, 22,
		23, 22, 10,
		10, 11, 23,
		12, 23, 11,
		11, 0, 12,
		20, 17, 18,
		18, 19, 20
	};


	const std::vector<PxVec3> secondSectionVerts = {
		// Lower
		PxVec3(0, 0, 0), // 0
		PxVec3(-11, 0, 0),
		PxVec3(-11, 0, -7),
		PxVec3(-9, 0, -7),
		PxVec3(-9, 0, -9),
		PxVec3(-11, 0, -9), // 5
		PxVec3(-11, 0, -10),
		PxVec3(-14, 0, -10),
		PxVec3(-14, 0, -8),
		PxVec3(-33, 0, -8),
		PxVec3(-33, 0, -15), // 10
		PxVec3(-31, 0, -15),
		PxVec3(-31, 0, -17),
		PxVec3(-33, 0, -17),
		PxVec3(-33, 0, -23),
		PxVec3(-29, 0, -23), // 15
		PxVec3(-29, 0, -27), 
		PxVec3(-26, 0, -27),
		PxVec3(-26, 0, -23),
		PxVec3(-22, 0, -23),
		PxVec3(-22, 0, -17), // 20
		PxVec3(-24, 0, -17),
		PxVec3(-24, 0, -15),
		PxVec3(-14, 0, -15),
		PxVec3(-14, 0, -13),
		PxVec3(-11, 0, -13), // 25
		PxVec3(-11, 0, -14),
		PxVec3(0, 0, -14),
		PxVec3(0, 0, -9),
		PxVec3(-2, 0, -9),
		PxVec3(-2, 0, -7), // 30
		PxVec3(0, 0, -7),

		// Upper
		PxVec3(0, 1, 0), // 0
		PxVec3(-11, 1, 0),
		PxVec3(-11, 1, -7),
		PxVec3(-9, 1, -7),
		PxVec3(-9, 1, -9),
		PxVec3(-11, 1, -9), // 5
		PxVec3(-11, 1, -10),
		PxVec3(-14, 1, -10),
		PxVec3(-14, 1, -8),
		PxVec3(-33, 1, -8),
		PxVec3(-33, 1, -15), // 10
		PxVec3(-31, 1, -15),
		PxVec3(-31, 1, -17),
		PxVec3(-33, 1, -17),
		PxVec3(-33, 1, -23),
		PxVec3(-29, 1, -23), // 15
		PxVec3(-29, 1, -27),
		PxVec3(-26, 1, -27),
		PxVec3(-26, 1, -23),
		PxVec3(-22, 1, -23),
		PxVec3(-22, 1, -17), // 20
		PxVec3(-24, 1, -17),
		PxVec3(-24, 1, -15),
		PxVec3(-14, 1, -15),
		PxVec3(-14, 1, -13),
		PxVec3(-11, 1, -13), // 25
		PxVec3(-11, 1, -14),
		PxVec3(0, 1, -14),
		PxVec3(0, 1, -9),
		PxVec3(-2, 1, -9),
		PxVec3(-2, 1, -7), // 30
		PxVec3(0, 1, -7)
	};
	const std::vector<PxU32> secondSectionTrigs = {
		33, 32, 0,
		0, 1, 33,
		34, 33, 1,
		1, 2, 34,
		35, 34, 2,
		2, 3, 35,
		36, 35, 3,
		3, 4, 36,
		37, 36, 4,
		4, 5, 37,
		38, 37, 5,
		5, 6, 38,
		39, 38, 6,
		6, 7, 39,
		40, 39, 7,
		7, 8, 40,
		41, 40, 8,
		8, 9, 41,
		42, 41, 9,
		9, 10, 42,
		43, 42, 10,
		10, 11, 43,
		44, 43, 11,
		11, 12, 44,
		45, 44, 12,
		12, 13, 45,
		46, 45, 13,
		13, 14, 46,
		47, 46, 14,
		14, 15, 47,
		48, 47, 15,
		15, 16, 48,
		49, 48, 16,
		16, 17, 49,
		50, 49, 17,
		17, 18, 50,
		51, 50, 18,
		18, 19, 51,
		52, 51, 19,
		19, 20, 52,
		53, 52, 20,
		20, 21, 53,
		54, 53, 21,
		21, 22, 54,
		55, 54, 22,
		22, 23, 55,
		56, 55, 23,
		23, 24, 56,
		57, 56, 24,
		24, 25, 57,
		58, 57, 25,
		25, 26, 58,
		59, 58, 26,
		26, 27, 59,
		60, 59, 27,
		27, 28, 60,
		61, 60, 28,
		28, 29, 61,
		62, 61, 29,
		29, 30, 62,
		63, 62, 30,
		30, 31, 63,
		32, 63, 31,
		31, 0, 32
	};

	struct FilterGroup
	{
		enum Enum
		{
			ACTOR0		= (1 << 0),
			ACTOR1		= (1 << 1),
			ACTOR2		= (1 << 2)
			//add more if you need
		};
	};

	///A customised collision class, implemneting various callbacks
	class MySimulationEventCallback : public PxSimulationEventCallback
	{
	public:
		//an example variable that will be checked in the main simulation loop
		bool trigger;

		MySimulationEventCallback() : trigger(false) {}

		///Method called when the contact with the trigger object is detected.
		virtual void onTrigger(PxTriggerPair* pairs, PxU32 count) 
		{
			//you can read the trigger information here
			for (PxU32 i = 0; i < count; i++)
			{
				//filter out contact with the planes
				if (pairs[i].otherShape->getGeometryType() != PxGeometryType::ePLANE)
				{
					//check if eNOTIFY_TOUCH_FOUND trigger
					if (pairs[i].status & PxPairFlag::eNOTIFY_TOUCH_FOUND)
					{
						cerr << "onTrigger::eNOTIFY_TOUCH_FOUND" << endl;
						trigger = true;
					}
					//check if eNOTIFY_TOUCH_LOST trigger
					if (pairs[i].status & PxPairFlag::eNOTIFY_TOUCH_LOST)
					{
						cerr << "onTrigger::eNOTIFY_TOUCH_LOST" << endl;
						trigger = false;
					}
				}
			}
		}

		///Method called when the contact by the filter shader is detected.
		virtual void onContact(const PxContactPairHeader &pairHeader, const PxContactPair *pairs, PxU32 nbPairs) 
		{
			cerr << "Contact found between " << pairHeader.actors[0]->getName() << " " << pairHeader.actors[1]->getName() << endl;

			//check all pairs
			for (PxU32 i = 0; i < nbPairs; i++)
			{
				//check eNOTIFY_TOUCH_FOUND
				if (pairs[i].events & PxPairFlag::eNOTIFY_TOUCH_FOUND)
				{
					cerr << "onContact::eNOTIFY_TOUCH_FOUND" << endl;
				}
				//check eNOTIFY_TOUCH_LOST
				if (pairs[i].events & PxPairFlag::eNOTIFY_TOUCH_LOST)
				{
					cerr << "onContact::eNOTIFY_TOUCH_LOST" << endl;
				}
			}
		}

		virtual void onConstraintBreak(PxConstraintInfo *constraints, PxU32 count) {}
		virtual void onWake(PxActor **actors, PxU32 count) {}
		virtual void onSleep(PxActor **actors, PxU32 count) {}
	};

	//A simple filter shader based on PxDefaultSimulationFilterShader - without group filtering
	static PxFilterFlags CustomFilterShader( PxFilterObjectAttributes attributes0,	PxFilterData filterData0,
		PxFilterObjectAttributes attributes1,	PxFilterData filterData1,
		PxPairFlags& pairFlags,	const void* constantBlock,	PxU32 constantBlockSize)
	{
		// let triggers through
		if(PxFilterObjectIsTrigger(attributes0) || PxFilterObjectIsTrigger(attributes1))
		{
			pairFlags = PxPairFlag::eTRIGGER_DEFAULT;
			return PxFilterFlags();
		}

		pairFlags = PxPairFlag::eCONTACT_DEFAULT;
		//enable continous collision detection
//		pairFlags |= PxPairFlag::eCCD_LINEAR;
		
		
		//customise collision filtering here
		//e.g.

		// trigger the contact callback for pairs (A,B) where 
		// the filtermask of A contains the ID of B and vice versa.
		if((filterData0.word0 & filterData1.word1) && (filterData1.word0 & filterData0.word1))
		{
			//trigger onContact callback for this pair of objects
			pairFlags |= PxPairFlag::eNOTIFY_TOUCH_FOUND;
			pairFlags |= PxPairFlag::eNOTIFY_TOUCH_LOST;
//			pairFlags |= PxPairFlag::eNOTIFY_CONTACT_POINTS;
		}

		return PxFilterFlags();
	};

	///Custom scene class
	class MyScene : public Scene
	{
		Plane* plane;
		Sphere* ball;
		Box* box1, box2;
		TriangleMesh* courseMesh1;
		TriangleMesh* courseMesh2;

		Box* seesawTop;
		RevoluteJoint* seeSawJoint;
		
		Box* spinner1;
		RevoluteJoint* spinner1Joint;
		Box* spinner2;
		RevoluteJoint* spinner2Joint;

		Box* windmill;
		RevoluteJoint* windmillJoint;

		MySimulationEventCallback* my_callback;
		
	public:
		MyScene() : Scene() {};

		///A custom scene class
		void SetVisualisation()
		{
			px_scene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
			px_scene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);
		}

		//Custom scene initialisation
		virtual void CustomInit() 
		{
			SetVisualisation();			

			GetMaterial()->setDynamicFriction(.2f);

			my_callback = new MySimulationEventCallback();
			px_scene->setSimulationEventCallback(my_callback);

			courseMesh1 = new TriangleMesh(firstSectionVerts, firstSectionTrigs);
			Add(courseMesh1);
			courseMesh2 = new TriangleMesh(secondSectionVerts, secondSectionTrigs, PxTransform(PxVec3(4.0f, .0f, -12.0f)));
			Add(courseMesh2);

			plane = new Plane();
			plane->Color(PxVec3(210.f/255.f,210.f/255.f,210.f/255.f));
			Add(plane);

			ball = new Sphere(PxTransform(PxVec3(-1.5f, 1.0f, -23.5f)), .5f, 15.0f);
			ball->Color(PxVec3(1.f, 1.f, 1.f));
			ball->Name("Ball");
			Add(ball);
			
			seesawTop = new Box(PxTransform(PxVec3(.0f, .0f, .0f)), PxVec3(.75f, .1f, 5.f), 1.f);
			seesawTop->Color(PxVec3(1.0f, .0f, .0f));
			Add(seesawTop);
			seeSawJoint = new RevoluteJoint(NULL, PxTransform(PxVec3(-12.5f, .75f, -23.5f), PxQuat(PxPi / 2, PxVec3(.0f, 1.0f, .0f))), seesawTop, PxTransform(PxVec3(.0f, .0f, -.2f)));
			
			spinner1 = new Box(PxTransform(PxVec3(.0f, .0f, .0f)), PxVec3(.75f, 2.5f, .1f), 2.f);
			spinner1->Color(PxVec3(.0f, 1.0f, .0f));
			Add(spinner1);
			spinner1Joint = new RevoluteJoint(NULL, PxTransform(-1.5f, 1.f, -20.0f, PxQuat(PxPi / 2, PxVec3(.0f, .0f, 1.0f))), spinner1, PxTransform(PxVec3(.0f, .0f, .0f)));

			spinner2 = new Box(PxTransform(PxVec3(.0f, .0f, .0f)), PxVec3(.75f, 2.5f, .1f), 2.f);
			spinner2->Color(PxVec3(.0f, 1.0f, .0f));
			Add(spinner2);
			spinner2Joint = new RevoluteJoint(NULL, PxTransform(-23.5f, 1.f, -28.0f, PxQuat(PxPi / 2, PxVec3(.0f, .0f, 1.0f))), spinner2, PxTransform(PxVec3(.0f, .0f, .0f)));

			windmill = new Box(PxTransform(PxVec3(.0f, .0f, .0f)), PxVec3(.1f, 5.0f, 1.0f), 1500.0f);
			windmill->Color(PxVec3(.0f, 0.f, 1.0f));
			Add(windmill);
			windmillJoint = new RevoluteJoint(NULL, PxTransform(-23.5f, 5.5f, -34.0f, PxQuat(PxPi / 2, PxVec3(.0f, 1.0f, .0f))), windmill, PxTransform(PxVec3(.0f, .0f, .0f)));
		}

		//Custom udpate function
		virtual void CustomUpdate() 
		{
			// Rotate the Windmill
			PxVec3 p = windmill->GetShape()->getLocalPose().p;
			PxQuat q = windmill->GetShape()->getLocalPose().q;
			windmill->GetShape()->setLocalPose(PxTransform(p, q * PxQuat(-0.01f, PxVec3(1.0f, .0f, .0f))));

			// camera follows the ball here
		}

		/// An example use of key release handling
		void ExampleKeyReleaseHandler()
		{
			cerr << "I am realeased!" << endl;
		}

		/// An example use of key presse handling
		void ExampleKeyPressHandler()
		{
			cerr << "I am pressed!" << endl;
		}
	};
}
