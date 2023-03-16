#pragma once
#include <vector>
#include <string>
#include <string_view>

// 데이터를 바이트 단위 char 배열로 만들어주는 녀석
// 직렬화란 클래스를 만들면 c++로 예를 들면 가상함수포인터나 
// 포인터같은 저장해봐야 쓸모없는 데이터들을 다 제외하고 필요한 데이터만
// 바이트 단위로 변경하는것을 의미합니다.

class GameEngineSerializer
{
public:
	// constrcuter destructer
	GameEngineSerializer();
	~GameEngineSerializer();

	// delete Function
	GameEngineSerializer(const GameEngineSerializer& _Other) = delete;
	GameEngineSerializer(GameEngineSerializer&& _Other) noexcept = delete;
	GameEngineSerializer& operator=(const GameEngineSerializer& _Other) = delete;
	GameEngineSerializer& operator=(GameEngineSerializer&& _Other) noexcept = delete;



	// 템플릿은 추후에 일단 int , string 만
	void Write(const int& _Value);
	void Write(const std::string_view& _Value);
	void Write(const void* _Ptr, size_t _Size);

	// 데이터를 반환
	inline void* GetData() 
	{
		return &Datas[0];
	}

	// 현재 추가되어있는 총 데이터의 크기를 반환
	inline size_t GetDataSize()
	{
		return Offset;
	}

protected:

private:
	// 총 1024 바이트를 저장할 수 있는 vector 를 선언한 것
	// vector 자체의 크기가 1024인 것이 아니다. 
	std::vector<char> Datas = std::vector<char>(1024);
	size_t Offset = 0;
};

