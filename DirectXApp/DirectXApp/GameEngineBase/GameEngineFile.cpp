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

// C�� ����������� ���
void GameEngineFile::Save(const GameEngineSerializer& _Data)
{
	// ���������͸� �ʱ�ȭ
	FILE* FilePtr = nullptr;

	// ������ ��θ� �޾ƿ´�. 
	// ���⼭���� ���ϴٽ� �����̰�.. ��.. 
	std::string PathString = Path.GetPathToString();

	// "w" // ������ ���� ���࿡ ��ο� ������ �������� �ʴ´ٸ�
	// ����ڴ�.
	fopen_s(&FilePtr, PathString.c_str(), "wb");

	if (nullptr == FilePtr)
	{
		MsgAssert("���� ���¿� �����߽��ϴ�." + PathString);
	}

	fwrite(_Data);

	// ������ fopen_s �� ����Ͽ� �����־��ٸ�
	// ��� �Ŀ� �ݵ�� �ݾ��־���Ѵ�. ���� ������ �������� �߻����� ��. ū�ϳ�. 
	if (nullptr != FilePtr)
	{
		fclose(FilePtr);
	}
}