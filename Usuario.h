#pragma once
#include<string>
class Usuario
{
public:
	Usuario() {}
	~Usuario() {}

	std::string nome = "", senha = "";
	int pontos = 0;
};