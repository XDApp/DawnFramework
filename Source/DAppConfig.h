#pragma once
class DAppConfig
{
private:
	std::string __WorkPath;
public:
	DAppConfig();
	~DAppConfig();
	const std::string WorkPath();
	const std::string ResourcePath();
	const DColor BackgroundColor();
};

