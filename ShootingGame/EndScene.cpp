#include "DxLib.h"
#include "EndScene.h"

EndScene::EndScene()
{
	waitTime = 0;
}

EndScene::~EndScene()
{

}

AbstractScene* EndScene::Update()
{
	if (waitTime <= 300)
	{
		waitTime++;
		return this;
	}
	else
	{
		return nullptr;
	}
}

void EndScene::Draw() const
{
	SetFontSize(100);
	DrawFormatString(350, 150, 0xffffff, "Shooting Game");

	DrawFormatString(150, 300, 0x00ffff, "Thank For Playing!!!");
}
