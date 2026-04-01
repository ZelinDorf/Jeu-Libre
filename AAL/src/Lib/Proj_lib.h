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

//	macro
//////////
#define TO_COLOR							cpu::ToColor
#define CAMERA								cpuEngine.GetCamera()

//	namespace
//////////////

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

//	define + using
///////////////////


//	Lib
#include "InputSystem.h"
#include "RessourcesManager.h"
#include "JSONParser.hpp"

#include "EnemiesRegistery.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "StatsEnum.h"
#include "AALentity.h"

#include "SceneManager.h"
#include "Scene.h"
