#pragma once

#include <Cogine\IMainGame.h>
#include "GameplayScreen.h"
#include <memory>

class App : public Cogine::IMainGame {
public:
	App();
	~App();

	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;

private:
	std::unique_ptr<GameplayScreen> m_gameplayScreen = nullptr;
};

