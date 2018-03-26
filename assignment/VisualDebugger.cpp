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
		HELP = 1,
		PAUSE = 2
	};

	//function declarations
	void KeyHold();
	void KeyRelease(unsigned char key, int x, int y);
	void KeyPress(unsigned char key, int x, int y);

	void exitCallback(void);

	void RenderScene();
	void HUDInit();

	///simulation objects
	Camera* camera;
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
		//initialise HUD
		//add an empty screen
		hud.AddLine(EMPTY, "");
		//add a help screen
		hud.AddLine(HELP, " Simulation");
		hud.AddLine(HELP, "    F10 - pause");
		hud.AddLine(HELP, "    F12 - reset");
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
		KeyHold();

		Renderer::Start(camera->getEye(), camera->getDir());

		std::vector<PxActor*> actors = scene->GetAllActors();
		if (actors.size())
			Renderer::Render(&actors[0], (PxU32)actors.size());

		if (hud_show) {
			if (scene->Pause()) hud.ActiveScreen(PAUSE);
			else hud.ActiveScreen(HELP);
			// TODO add victory hud
		} 
			
		hud.Render();
		Renderer::Finish();
		scene->Update(delta_time);
	}

	void HandleKeyPress(int key) {
		if (toupper(key) == 'R') {
			scene->ExampleKeyPressHandler();
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

		if (toupper(key) == 'I') {
			scene->GetSelectedActor()->addForce(PxVec3(0, 0, -1) * 150.f);
		}
		if (toupper(key) == 'K') {
			scene->GetSelectedActor()->addForce(PxVec3(0, 0, 1)*150.f);
		}
		if (toupper(key) == 'J') {
			scene->GetSelectedActor()->addForce(PxVec3(-1, 0, 0)*150.f);
		}
		if (toupper(key) == 'L') {
			scene->GetSelectedActor()->addForce(PxVec3(1, 0, 0)*150.f);
		}
	}
	void HandleKeyHold(int key) {
		// TODO: remove for release
		if (toupper(key) == 'W') {
			camera->MoveForward(delta_time);
		}
		if (toupper(key) == 'A') {
			camera->MoveLeft(delta_time);
		}
		if (toupper(key) == 'S') {
			camera->MoveBackward(delta_time);
		}
		if (toupper(key) == 'D') {
			camera->MoveRight(delta_time);
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

