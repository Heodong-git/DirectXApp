#include "GameEngineDebug.h"
#include <crtdbg.h>

GameEngineDebug::GameEngineDebug()
{
}

GameEngineDebug::~GameEngineDebug()
{
}

// --------- �޸� �� üũ ���� ----------------

// ���� �ִٸ� ���â�� ������ش�. 
void GameEngineDebug::LeakCheck()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

// �� �߻� ��ġ Ȯ�ΰ���. ��Ȯ���� �ʰ� �߻��� �κ��� ��ó��. 
void GameEngineDebug::LeakPointBreak(int _Point)
{
	_CrtSetBreakAlloc(_Point);
}