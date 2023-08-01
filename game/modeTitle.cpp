/*****************************************************************//**
 * \file   modeTitle.cpp
 * \brief  �^�C�g����ʂ̃N���X�̒�`
 *
 * \author �R�{介v
 * \date   March 2023
 *********************************************************************/
#include"allMode.h"
#include <fstream>
#include <sstream>

bool modeT::save(const char* dir, valData* _val)
{
	std::vector<std::string> _data;
	fileIO::loadCSV(&_data, dir, false);

	for (int i = 0; i < _data.size(); i++)
	{
		if (_data[i].find("//") != std::string::npos) { continue; }

		if (_data[i] == "�ő�X�R�A") { i++; _data[i] = std::to_string(_val->maxScore); }
	}
	std::string insStr = "";
	for (auto insData : _data) { insStr += insData + "\n"; }
	std::ofstream ofs(dir);
	ofs << insStr;
	ofs.close();

	return true;
}

bool modeT::loadData(const char* dir, valData* _val)
{
	std::vector<std::string> _data;
	fileIO::loadCSV(&_data, dir, false);

	for (int i = 0; i < _data.size(); i++)
	{
		if (_data[i].find("//") != std::string::npos)
		{
			continue;
		}
		if (_data[i] == "�ő�X�R�A")
		{
			i++;
			_val->maxScore = std::atoi(_data[i].c_str());
		}

		//��
		//if (_data[i] == "���j�ς�Boss") { i++, _val->deadBoss.clear(); while (_data[i] != "�����܂�") { _val->deadBoss.emplace_back(_data[i]); i++; } }
		//if (_data[i] == "�����|�C���g") { i++; _val->points = std::atoi(_data[i].c_str()); }
		//if (_data[i] == "�J���҃��[�h") { _val->isDebug = true; }
		//if (_data[i] == "�{�X1�˗����")
		//{
		//	_val->boss1Inf = ""; i++;
		//	while (_data[i] != "�����܂�")
		//	{
		//		if (_data[i] == "���e") { _val->boss1Inf += "\n"; }
		//		if (_data[i] == "�T�v") { _val->boss1Inf += "\n"; }
		//		if (_data[i] == "��V") { _val->boss1Inf += "\n"; }
		//		_val->boss1Inf += _data[i] + "\n";
		//		i++;
		//	}
		//}
	}

	return true;
}

bool	modeT::Initialize()
{
	_cg = _modeServer->RS.loadGraphR("res/title.png");
	modeT::loadData("data.csv", &_modeServer->_valData);

	return true;
}

bool	modeT::Process()
{
	if ((_imputInf._gTrgb[KEY_INPUT_RETURN]))
	{
		_modeServer->Add(std::make_unique<modeG>(_modeServer), 1, MODE_GAME);
		return false;
	}
	return true;
}

bool	modeT::Render()
{
	DrawGraph(0, 0, _cg, false);

	return true;
}

bool	modeT::Terminate()
{
	StopMusic();
	return true;
}