#pragma once
// c++이 실행되는 곳에서 사용할수 있는 모든 문자열 관련 처리방식을 지원해준다.
#include <filesystem>

// 설명 : 경로에 관련된 기능을 대표하는 클래스
//class GameEngineFile;
//class GameEngineDirectory;
class GameEnginePath
{
	// 전방선언을 그냥 필요
	friend class GameEngineFile;
	friend class GameEngineDirectory;

public:
	// constrcuter destructer
	GameEnginePath();
	GameEnginePath(std::filesystem::path _Path);
	GameEnginePath(const std::string& _Path);
	~GameEnginePath();

	// delete Function
	GameEnginePath(const GameEnginePath& _Other);
	GameEnginePath(GameEnginePath&& _Other);
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	// 저장된 파일명을 반환
	std::string GetFileName() const;
	std::string GetPathToString() const;

	// 나를 소유한 디렉터리로 이동
	void MoveParent();
	// 인자로 넣어준 경로를 가진 상위폴더가 있다면 이동한다.
	void MoveParentToChildPath(const std::string_view& _String);


	bool IsExists();
	bool IsExistsToPlusString(const std::string_view& _String);

	// bool MoveParentToChildPath(const std::string_view& _IOName );

	// 더이상의 상위폴더가 없는지 체크
	bool IsRoot();
	// 인자로 들어온 경로로 이동, 파일명을 이어붙여준다. 
	bool Move(const std::string_view& _Path);

	// 인자로 들어온 경로로 패스에 저장된 문자열을 변경한다.
	void SetPath(const std::string_view& _Path);

protected:

private:
	// std::string Path;
	std::filesystem::path Path;

};

