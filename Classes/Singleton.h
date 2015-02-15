#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <list>
#include <algorithm>

class SingletonBase
{
	class InstanceTable : public std::list < SingletonBase * >
	{
	public:
		InstanceTable()
			: _bIsCleared(false)
		{

		};

		~InstanceTable()
		{
			_bIsCleared = true;
			for_each(begin(), end(), destroyInstance);
		}

	public:
		static void destroyInstance(SingletonBase *pInstance)
		{
			delete pInstance;
		}

	public:
		bool _bIsCleared;
	};

protected:
	SingletonBase()
	{
		_sInstanceTable.push_back(this);
	}

	virtual ~SingletonBase()
	{
		if (!_sInstanceTable._bIsCleared)
		{
			_sInstanceTable.remove(this);
		}
	}

private:
	static InstanceTable _sInstanceTable;
};

template <typename T>
class Singleton : public SingletonBase
{
public:
	static T* getInstance()
	{
		if (_sSingleton == nullptr)
		{
			_sSingleton = new (std::nothrow) T();
		}
		return _sSingleton;
	}

protected:
	Singleton()
	{

	};

	virtual ~Singleton()
	{
		_sSingleton = nullptr;
	};

private:
	static T* _sSingleton;
};

template<typename T> T* Singleton<T>::_sSingleton = nullptr;

#endif