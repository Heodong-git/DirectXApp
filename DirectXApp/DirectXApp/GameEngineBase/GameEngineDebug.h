#pragma once
#include <windows.h>
#include <assert.h>
#include <string>

// 이 프로젝트에서 사용할 디버깅 기능을 모아두고 편리하게 사용하기 위해서 제작

class GameEngineDebug
{
public:
	// constrcuter destructer
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

	static void LeakCheck();
	static void LeakPointBreak(int _Point);

protected:

private:

};

// 입력한 문자열을 창에 띄워주고 assert(false) 
#define MsgAssert(MsgText) std::string ErrorText = MsgText; MessageBoxA(nullptr, ErrorText.c_str(), "Error", MB_OK); assert(false);