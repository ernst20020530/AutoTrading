#pragma once


#include <memory>

template<typename T>
class Singleton
{
public:
	Singleton() = delete;
	Singleton(const Singleton &c) = delete;
	Singleton(Singleton &&c) = delete;
	~Singleton() = delete;

	typedef T Type;

	static std::unique_ptr<T> &GetSingleton()
	{
		if (m_instance.get() == nullptr)
			m_instance.reset(new T);
		return m_instance;
	}

private:

	static std::unique_ptr<T> m_instance;

};

template<typename T>
std::unique_ptr<T> Singleton<T>::m_instance;