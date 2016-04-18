# TypeTraits
类型萃取实现顺序表
#pragma once

struct TrueType
{
	bool Get()
	{
		return true;
	}
};

struct FalseType
{
	bool Get()
	{
		return false;
	}
};

template<typename T>
struct TypeTraits
{
	typedef FalseType IsPoodType;//内嵌型别
};

//特化
template<>
struct TypeTraits<int>
{
	typedef TrueType IsPoodType;
};

template<>
struct TypeTraits<unsigned int>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<unsigned char>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<double>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<bool>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<float>
{
	typedef TrueType IsPoodType;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType IsPoodType;
};

template<>
struct TypeTraits<unsigned short>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<long long>
{
	typedef TrueType IsPoodType;
};
template<>
struct TypeTraits<long double>
{
	typedef TrueType IsPoodType;
};
