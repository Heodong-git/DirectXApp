#include "GameEngineFile.h"
#include "GameEngineDebug.h"

GameEngineFile::GameEngineFile() 
{
}

GameEngineFile::~GameEngineFile() 
{
}


GameEngineFile::GameEngineFile(std::filesystem::path _Path) 
	: Path(_Path)
{

}

// C의 파일입출력을 사용
void GameEngineFile::Save(const GameEngineSerializer& _Data)
{
	// 파일포인터를 초기화
	FILE* FilePtr = nullptr;

	// 파일의 경로를 받아온다. 
	// 여기서부터 내일다시 진행이고.. 음.. 
	std::string PathString = Path.GetPathToString();

	// "w" // 파일을 쓰고 만약에 경로에 파일이 존재하지 않는다면
	// 만들겠다.
	fopen_s(&FilePtr, PathString.c_str(), "wb");

	if (nullptr == FilePtr)
	{
		MsgAssert("파일 오픈에 실패했습니다." + PathString);
	}

	fwrite(_Data);

	// 파일을 fopen_s 를 사용하여 열어주었다면
	// 사용 후에 반드시 닫아주어야한다. 닫지 않으면 무슨일이 발생할지 모름. 큰일남. 
	if (nullptr != FilePtr)
	{
		fclose(FilePtr);
	}
}