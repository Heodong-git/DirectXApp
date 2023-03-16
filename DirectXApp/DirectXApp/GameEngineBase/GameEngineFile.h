#pragma once
#include "GameEnginePath.h"
#include "GameEngineSerializer.h"

class GameEngineFile
{
public:
	// constrcuter destructer
	GameEngineFile();
	~GameEngineFile();
	GameEngineFile(std::filesystem::path _Path);

	// delete Function
	//GameEngineFile(const GameEngineFile& _Other) = delete;
	// GameEngineFile(GameEngineFile&& _Other) noexcept = delete;
	//GameEngineFile& operator=(const GameEngineFile& _Other) = delete;
	//GameEngineFile& operator=(GameEngineFile&& _Other) noexcept = delete;

	// 파일의 경로를 받아온다. 
	std::string GetFullPath() 
	{
		return Path.Path.string();
	}

	// 저장
	void Save(const GameEngineSerializer& _Data);

protected:

private:
	// 파일의 경로저장
	GameEnginePath Path;
};

