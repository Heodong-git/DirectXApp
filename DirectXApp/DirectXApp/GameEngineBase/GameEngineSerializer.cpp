#include "GameEngineSerializer.h"

GameEngineSerializer::GameEngineSerializer() 
{
}

GameEngineSerializer::~GameEngineSerializer() 
{
}

void GameEngineSerializer::Write(const void* _Ptr, size_t _Size)
{
	// 추가될 데이터의 크기가 
	// vector 의 총 크기를 넘어서게 된다면 사이즈를 늘린다.
	// 지금 아무것도 없으니까 0 <= 0 + 4 가 되기 때문에 resize 는 하지 않아도 되고.
	if (Datas.size() <= Offset + _Size)
	{
		Datas.resize(Datas.size() + 1024);
	}

	// 정상적으로 추가가 가능하다면 memcpy
	// vector의 [Offset] 번째 위치 (복사할 공간) , 복사할 공간의 크기 , 복사대상 , 복사할 개수
	// 벡터의 [0] 번째 위치부터, 0  , 복사대상 = 2 , 복사할 크기4 
	// 정수 2 가 들어왔다는 치면, 일정한 벡터의 일정한 메모리를 인자로 들어온
	// 메모리의 값과 동일하게 복사한다는 의미. 
	memcpy_s(&Datas[Offset], Datas.size() - Offset, _Ptr, _Size);

	// 4바이트 만큼 채웠기 때문에 오프셋을 증가시킨다. 
	// 그럼 현재 4라고 치고 
	Offset += _Size;
}

// 만약 정수 2 가 들어왔다면?
void GameEngineSerializer::Write(const int& _Value)
{
	// 2 , 4 를 넘겨준다. 
	Write(&_Value, sizeof(int));
}

void GameEngineSerializer::Write(const std::string_view& _Value)
{
	// const char*

	// Write(_Value, sizeof(std::string_view));
}