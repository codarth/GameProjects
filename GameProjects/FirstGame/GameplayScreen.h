#pragma once

#include <Cogine\IGameScreen.h>
#include <Cogine\Window.h>
#include <Cogine\Camera2D.h>

class GameplayScreen : public Cogine::IGameScreen {
public:
	GameplayScreen(Cogine::Window* window);
	~GameplayScreen();

	virtual int getNextScreenIndex() const override;
	virtual int getPreviousScreenIndex() const override;
	virtual void build() override;
	virtual void destroy() override;
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void update() override;
	virtual void draw() override;

private:
	void checkInput();

	Cogine::Window* m_window;
	Cogine::Camera2D m_camera;
};

