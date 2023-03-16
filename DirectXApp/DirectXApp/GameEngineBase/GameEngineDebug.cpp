#include "GameEngineDebug.h"
#include <crtdbg.h>

GameEngineDebug::GameEngineDebug()
{
}

GameEngineDebug::~GameEngineDebug()
{
}

// --------- 메모리 릭 체크 관련 ----------------

// 릭이 있다면 출력창에 출력해준다. 
void GameEngineDebug::LeakCheck()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

// 릭 발생 위치 확인가능. 정확하진 않고 발생한 부분의 근처로. 
void GameEngineDebug::LeakPointBreak(int _Point)
{
	_CrtSetBreakAlloc(_Point);
}