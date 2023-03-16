#pragma once
// c++�� ����Ǵ� ������ ����Ҽ� �ִ� ��� ���ڿ� ���� ó������� �������ش�.
#include <filesystem>

// ���� : ��ο� ���õ� ����� ��ǥ�ϴ� Ŭ����
//class GameEngineFile;
//class GameEngineDirectory;
class GameEnginePath
{
	// ���漱���� �׳� �ʿ�
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

	// ����� ���ϸ��� ��ȯ
	std::string GetFileName() const;
	std::string GetPathToString() const;

	// ���� ������ ���͸��� �̵�
	void MoveParent();
	// ���ڷ� �־��� ��θ� ���� ���������� �ִٸ� �̵��Ѵ�.
	void MoveParentToChildPath(const std::string_view& _String);


	bool IsExists();
	bool IsExistsToPlusString(const std::string_view& _String);

	// bool MoveParentToChildPath(const std::string_view& _IOName );

	// ���̻��� ���������� ������ üũ
	bool IsRoot();
	// ���ڷ� ���� ��η� �̵�, ���ϸ��� �̾�ٿ��ش�. 
	bool Move(const std::string_view& _Path);

	// ���ڷ� ���� ��η� �н��� ����� ���ڿ��� �����Ѵ�.
	void SetPath(const std::string_view& _Path);

protected:

private:
	// std::string Path;
	std::filesystem::path Path;

};

