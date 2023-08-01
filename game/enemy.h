#pragma once
#include"charBase.h"

class EN : public CB
{
public:
	EN() {};
	~EN() {};

	/**
	 * @brief ����������
	 * @return true
	 */
	virtual bool	Initialize();

	/**
	 * @brief �폜����
	 * @return true
	 */
	virtual bool	Terminate();

	/**
	 * @brief �X�V����
	 * @return true
	 */
	virtual bool	Process();

	/**
	 * @brief �`�揈��
	 * @param �Đ����x
	 * @return true
	 */
	virtual bool	Render(float timeSpeed);
	void setRS(Rserver* _RS) { RS = _RS; }
	bool hitCheck(VECTOR _pos, VECTOR _vec, float _damage, float r) override;

private:
	float charSize;
	unsigned int charColor;
};