#include "GameEngineSerializer.h"

GameEngineSerializer::GameEngineSerializer() 
{
}

GameEngineSerializer::~GameEngineSerializer() 
{
}

void GameEngineSerializer::Write(const void* _Ptr, size_t _Size)
{
	// �߰��� �������� ũ�Ⱑ 
	// vector �� �� ũ�⸦ �Ѿ�� �ȴٸ� ����� �ø���.
	// ���� �ƹ��͵� �����ϱ� 0 <= 0 + 4 �� �Ǳ� ������ resize �� ���� �ʾƵ� �ǰ�.
	if (Datas.size() <= Offset + _Size)
	{
		Datas.resize(Datas.size() + 1024);
	}

	// ���������� �߰��� �����ϴٸ� memcpy
	// vector�� [Offset] ��° ��ġ (������ ����) , ������ ������ ũ�� , ������ , ������ ����
	// ������ [0] ��° ��ġ����, 0  , ������ = 2 , ������ ũ��4 
	// ���� 2 �� ���Դٴ� ġ��, ������ ������ ������ �޸𸮸� ���ڷ� ����
	// �޸��� ���� �����ϰ� �����Ѵٴ� �ǹ�. 
	memcpy_s(&Datas[Offset], Datas.size() - Offset, _Ptr, _Size);

	// 4����Ʈ ��ŭ ä���� ������ �������� ������Ų��. 
	// �׷� ���� 4��� ġ�� 
	Offset += _Size;
}

// ���� ���� 2 �� ���Դٸ�?
void GameEngineSerializer::Write(const int& _Value)
{
	// 2 , 4 �� �Ѱ��ش�. 
	Write(&_Value, sizeof(int));
}

void GameEngineSerializer::Write(const std::string_view& _Value)
{
	// const char*

	// Write(_Value, sizeof(std::string_view));
}