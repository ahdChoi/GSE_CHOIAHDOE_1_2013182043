#include "stdafx.h"
#include "Object.h"



Object::Object()
{
	memset(&m_f3Position, 0, sizeof(m_f3Position));
	memset(&m_f4Color, 0, sizeof(m_f4Color));
	m_f3Direction.x = 0.0f;
	m_f3Direction.y = 0.0f;
	m_f3Direction.z = 0.0f;
	
	m_f4Color.r = 1.0f;
	m_f4Color.g = 1.0f;
	m_f4Color.b = 1.0f;
	m_f4Color.a = 1.0f;

	m_iLife = 15;

	m_fLifeTime = 0;

	m_iObjectType = -1;
}


Object::~Object()
{
}

void Object::Update(DWORD elapsedTime)
{
	

}

///////////////////


Player::Player()
{

}
Player::~Player()
{

}
void Player::DamageAnimate()
{

}
void Player::BulletShot()
{
	if (m_bShootState_Arrow == true)
	{
		Arrow *arrow = new Arrow;
		default_random_engine dre;
		uniform_real_distribution<> urMovingDirection(-4.0f, 4.0f);
		dre.seed(time(NULL)); //매번달라지게하기위해 seed값을줌

		FLOAT3 dirVector;
		dirVector.x = urMovingDirection(dre);
		dirVector.y = urMovingDirection(dre);
		dirVector.z = 0;

		dirVector = Vector3::Normalize(dirVector);


		arrow->SetColor(0, 1, 0, 1);
		arrow->SetDirection(dirVector.x, dirVector.y, 0);
		arrow->SetLife(ARROW_LIFE);
		arrow->SetPosition(this->GetPosition());

		m_listArrow.push_back(arrow);
	}
}

void Player::ArrowShot()
{

}

void Player::Update(DWORD elapsedTime)
{
	//m_f3Position.x += 1 * m_f3Direction.x;
	//m_f3Position.y += 1 * m_f3Direction.y;

	m_f3Position.x += elapsedTime * (m_f3Direction).x;
	m_f3Position.y += elapsedTime * (m_f3Direction).y;
	m_f3Position.z += elapsedTime * (m_f3Direction).z;

	//m_fLifeTime = clock() / 1000;

	//cout << m_fLifeTime << endl;

	m_fLifeTime += (float)elapsedTime / (float)1000;

	//cout << m_fLifeTime << endl;

	//총알 업데이트
	for (auto iter = m_listArrow.begin(); iter != m_listArrow.end(); ++iter)
	{
		(*iter)->m_f3Position.x += elapsedTime * (*iter)->m_f3Direction.x;
		(*iter)->m_f3Position.y += elapsedTime * (*iter)->m_f3Direction.y;
	}


	m_fShootTimer_Arrow += elapsedTime;


	if ((float)m_fShootTimer_Arrow / (float)1000 > 0.5f)
	{
		m_bShootState_Arrow = true;
		m_fShootTimer_Arrow = 0;
	}
	else
	{
		m_bShootState_Arrow= false;
	}

}









/////////////////
/////////////
Enemy::Enemy()
{

}
Enemy::~Enemy()
{

}
////////////////


Ally::Ally()
{

}
Ally::~Ally()
{

}
//////////////




Bullet::Bullet()
{

}
Bullet::~Bullet()
{

}
/////////////////
Arrow::Arrow()
{

}
Arrow::~Arrow()
{

}

Building::Building()
{
	m_fShootTimer_Bullet = 0;
	m_bShootState_Bullet = false;
}
Building::~Building()
{

}
void Building::DamageAnimate()
{


}
void Building::BulletShot()
{

	if (m_bShootState_Bullet == true)
	{
		Bullet *bullet = new Bullet;
		default_random_engine dre;
		uniform_real_distribution<> urMovingDirection(-1.0f, 1.0f);
		dre.seed(time(NULL)); //매번달라지게하기위해 seed값을줌

		FLOAT3 dirVector;
		dirVector.x = urMovingDirection(dre);
		dirVector.y = urMovingDirection(dre);
		dirVector.z = 0;

		dirVector = Vector3::Normalize(dirVector);


		bullet->SetColor(1, 0, 0, 1);
		bullet->SetDirection(dirVector.x, dirVector.y, 0);
		bullet->SetLife(BULLET_LIFE);
		bullet->SetPosition(this->GetPosition());

		m_listBullet.push_back(bullet);
	}
	
	//cout << this->GetLifeTime() << endl;

}

void Building::ArrowShot()
{
	
}

void Building::Update(DWORD elapsedTime)
{
	for (auto iter = m_listBullet.begin(); iter != m_listBullet.end(); ++iter)
	{
		(*iter)->m_f3Position.x += elapsedTime * (*iter)->m_f3Direction.x;
		(*iter)->m_f3Position.y += elapsedTime * (*iter)->m_f3Direction.y;
	}


	m_fShootTimer_Bullet += elapsedTime;


	if ((float)m_fShootTimer_Bullet / (float)1000 > 0.5f)
	{
		m_bShootState_Bullet = true;
		m_fShootTimer_Bullet = 0;
	}
	else
	{
		m_bShootState_Bullet = false;
	}

	//this->m_f3Position.x += elapsedTime * (m_f3Direction).x;
	//this->m_f3Position.y += elapsedTime * (m_f3Direction).y;
	//this->m_f3Position.z += elapsedTime * (m_f3Direction).z;

	
	
}
//////////////////////
