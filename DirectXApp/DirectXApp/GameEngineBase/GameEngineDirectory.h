#pragma once
#include <string_view>
#include <vector>
#include "GameEnginePath.h"

class GameEngineFile;
class GameEngineDirectory
{
public:
	// constrcuter destructer
	GameEngineDirectory();
	~GameEngineDirectory();

	// delete Function
	GameEngineDirectory(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory(GameEngineDirectory&& _Other) noexcept = delete;
	GameEngineDirectory& operator=(const GameEngineDirectory& _Other) = delete;
	GameEngineDirectory& operator=(GameEngineDirectory&& _Other) noexcept = delete;

	// ���͸��� ������ �ִ��� Ȯ��
	bool IsFile(const std::string_view& _FileName);

	// ���� ������ �������� ���������� �̵�
	bool MoveParent();

	// ���� ������ ���ڷ� ���� ���͸��� �ִ��� Ȯ���Ѵ�. 
	void MoveParentToDirectory(const std::string_view& _String);

	// ���� �������� ���ڷ� ���� �̸��� ���͸��� �̵��Ѵ�. 
	bool Move(const std::string_view& _String);

	// ���ϸ��� ��ο� �̾�ٿ��ش�. 
	GameEnginePath GetPlusFileName(const std::string_view& _String);

protected:

private:
	// "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\";
	GameEnginePath Path;
};

