#include "VisualDebugger.h"
#include <vector>
#include "Extras\Camera.h"
#include "Extras\Renderer.h"
#include "Extras\HUD.h"

namespace VisualDebugger
{
	using namespace physx;

	enum RenderMode
	{
		DEBUG,
		NORMAL,
		BOTH
	};

	enum HUDState
	{
		EMPTY = 0,
		GAME = 1,
		VICTORY = 2,
		PAUSE = 3
	};

	//function declarations
	void KeyHold();
	void KeyRelease(unsigned char key, int x, int y);
	void KeyPress(unsigned char key, int x, int y);

	void exitCallback(void);

	void CameraUpdate();
	void RenderScene();
	void HUDInit();

	/// Gameplay Variables
	PxI32 hitCounter = 0;

	///simulation objects
	Camera* camera;
	PxReal ballAngle = .0f, mouseSensitivity = 25.0f;
	PhysicsEngine::MyScene* scene;
	PxReal delta_time = 1.f / 60.f;
	PxReal gForceStrength = 20;
	RenderMode render_mode = NORMAL;
	const int MAX_KEYS = 256;
	bool key_state[MAX_KEYS];
	bool hud_show = true;
	HUD hud;


	//Init the debugger
	void Init(const char *window_name, int width, int height) {
		///Init PhysX
		PhysicsEngine::PxInit();
		scene = new PhysicsEngine::MyScene();
		scene->Init();

		///Init renderer
		Renderer::BackgroundColor(PxVec3(150.f / 255.f, 150.f / 255.f, 150.f / 255.f));
		Renderer::SetRenderDetail(40);
		Renderer::InitWindow(window_name, width, height);
		Renderer::Init();

		camera = new Camera(PxVec3(0.0f, 5.0f, 15.0f), PxVec3(0.f, -.1f, -1.f), 5.f);

		//initialise HUD
		HUDInit();

		///Assign callbacks
		//render
		glutDisplayFunc(RenderScene);

		//keyboard
		glutKeyboardFunc(KeyPress);
		glutKeyboardUpFunc(KeyRelease);

		//exit
		atexit(exitCallback);
	}

	void HUDInit() {
		hud.Clear();

		hud.AddLine(EMPTY, "");

		//add a help screen
		hud.AddLine(GAME, " Simulation");
		hud.AddLine(GAME, "    F10 - pause");
		hud.AddLine(GAME, "    F12 - reset");
		hud.AddLine(GAME, "");
		hud.AddLine(GAME, " Score");
		hud.AddLine(GAME, "    " + to_string(hitCounter));

		//add a pause screen
		hud.AddLine(PAUSE, "");
		hud.AddLine(PAUSE, "");
		hud.AddLine(PAUSE, "");
		hud.AddLine(PAUSE, "   Simulation paused. Press F10 to continue.");

		//set font size for all screens
		hud.FontSize(0.018f);
		//set font color for all screens
		hud.Color(PxVec3(0.f, 0.f, 0.f));
	}

	void Start() {
		glutMainLoop();
	}

	void RenderScene() {
		CameraUpdate();
		KeyHold();

		Renderer::Start(camera->getEye(), camera->getDir());

		std::vector<PxActor*> actors = scene->GetAllActors();
		if (actors.size())
			Renderer::Render(&actors[0], (PxU32)actors.size());

		if (hud_show) {
			if (scene->Pause()) hud.ActiveScreen(PAUSE);
			else hud.ActiveScreen(GAME);
			// TODO add victory hud
		} 
			
		hud.Render();
		Renderer::Finish();
		scene->Update(delta_time);
	}

	void CameraUpdate() {
		PxReal x = 15.0f * sin(ballAngle * (PxPi / 180));
		PxReal z = 15.0f * cos(ballAngle * (PxPi / 180));

		PxVec3 target = scene->GetSelectedActor()->getGlobalPose().p + PxVec3(x, 5.0f, z);
		PxVec3 diff = target - camera->getTransform().p;

		camera->SetPosition(diff.x, diff.y, diff.z);
		camera->setDir(PxVec3(-x, .0f, -z)); // TODO Change to look at

		cout << scene->GetSelectedActor()->getLinearVelocity().magnitude() << endl;
	}

	void HandleKeyPress(int key) {
		if (toupper(key) == 'R') {
			scene->ExampleKeyPressHandler();
		}

		if (key == 32) { // Space
			if (abs(scene->GetSelectedActor()->getLinearVelocity().magnitude()) < .1f) {
				scene->GetSelectedActor()->addForce(PxVec3(camera->getDir().x, 0, camera->getDir().z) * 20.f);
				hitCounter += 1;
				HUDInit();
			}
		}

		// Handle Application Events
		if (key == GLUT_KEY_F10) {
			scene->Pause(!scene->Pause());
		}
		if (key == GLUT_KEY_F12) {
			scene->Reset();
		}
		if (key == 27) { // Escape
			exit(0);
		}
	}
	void HandleKeyRelease(int key) {
		if (toupper(key) == 'R') {
			scene->ExampleKeyReleaseHandler();
		}
	}
	void HandleKeyHold(int key) {
		if (toupper(key) == 'A') {
			ballAngle += delta_time * mouseSensitivity;
		}
		if (toupper(key) == 'D') {
			ballAngle -= delta_time * mouseSensitivity;
		}
	}

	void KeyPress(unsigned char key, int x, int y)
	{
		if (key_state[key] == true) return;
		key_state[key] = true;
		HandleKeyPress(key);
	}

	void KeyRelease(unsigned char key, int x, int y) {
		key_state[key] = false;
		HandleKeyRelease(key);
	}
	void KeyHold() {
		for (int i = 0; i < MAX_KEYS; i++) {
			if (key_state[i]) HandleKeyHold(i);
		}
	}

	///exit callback
	void exitCallback(void)
	{
		delete camera;
		delete scene;
		PhysicsEngine::PxRelease();
	}
}

