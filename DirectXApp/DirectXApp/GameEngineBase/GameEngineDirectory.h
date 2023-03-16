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

	// 디렉터리에 파일이 있는지 확인
	bool IsFile(const std::string_view& _FileName);

	// 현재 폴더를 기준으로 상위폴더로 이동
	bool MoveParent();

	// 상위 폴더에 인자로 들어온 디렉터리가 있는지 확인한다. 
	void MoveParentToDirectory(const std::string_view& _String);

	// 현재 폴더에서 인자로 들어온 이름의 디렉터리로 이동한다. 
	bool Move(const std::string_view& _String);

	// 파일명을 경로에 이어붙여준다. 
	GameEnginePath GetPlusFileName(const std::string_view& _String);

protected:

private:
	// "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\";
	GameEnginePath Path;
};

