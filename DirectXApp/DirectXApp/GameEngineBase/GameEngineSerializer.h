#pragma once
#include <vector>
#include <string>
#include <string_view>

// �����͸� ����Ʈ ���� char �迭�� ������ִ� �༮
// ����ȭ�� Ŭ������ ����� c++�� ���� ��� �����Լ������ͳ� 
// �����Ͱ��� �����غ��� ������� �����͵��� �� �����ϰ� �ʿ��� �����͸�
// ����Ʈ ������ �����ϴ°��� �ǹ��մϴ�.

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



	// ���ø��� ���Ŀ� �ϴ� int , string ��
	void Write(const int& _Value);
	void Write(const std::string_view& _Value);
	void Write(const void* _Ptr, size_t _Size);

	// �����͸� ��ȯ
	inline void* GetData() 
	{
		return &Datas[0];
	}

	// ���� �߰��Ǿ��ִ� �� �������� ũ�⸦ ��ȯ
	inline size_t GetDataSize()
	{
		return Offset;
	}

protected:

private:
	// �� 1024 ����Ʈ�� ������ �� �ִ� vector �� ������ ��
	// vector ��ü�� ũ�Ⱑ 1024�� ���� �ƴϴ�. 
	std::vector<char> Datas = std::vector<char>(1024);
	size_t Offset = 0;
};

