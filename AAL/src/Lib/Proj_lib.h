#pragma once

//	inlcude
////////////
#pragma push_macro("new")
#undef new
#include "json.hpp"
#pragma pop_macro("new")

//	namespace
//////////////
using json									= nlohmann::json;

//	std using
//////////////
template <class T>
using Vector								= std::vector<T>;

template <class Key, class Value>
using UnorderedMap							= std::unordered_map<Key, Value>;

template <class Key, class Value>
using Map									= std::map<Key, Value>;

template <class T>
using Function								= std::function<T>;

using String								= std::string;
using WString								= std::wstring;

using WStringView							= std::wstring;
using StringView							= std::string_view;

//	define
///////////


//	Lib
#include "InputSystem.h"
#include "JSONParser.h"