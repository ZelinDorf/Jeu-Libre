#pragma once

//	inlcude
////////////
#pragma push_macro("new")
#undef new
#pragma pop_macro("new")

//	macro
//////////
//template <class T>
//#define CPU_TEST_RUN						cpu::Run<cpu_engine, T>//a faire
#define TO_COLOR							cpu::ToColor
#define CAMERA								cpuEngine.GetCamera()

//	namespace
//////////////

//	std using
//////////////
template <class T>
using Vector = std::vector<T>;

template <class Key, class Value>
using UnorderedMap = std::unordered_map<Key, Value>;

template <class Key, class Value>
using Map = std::map<Key, Value>;

template <class T>
using Function = std::function<T>;

using String = std::string;
using WString = std::wstring;

using WStringView = std::wstring;
using StringView = std::string_view;

//	define + using
///////////////////


//	Lib
#include "InputSystem.h"

#include "EnemiesRegistery.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "StatsEnum.h"
#include "AALentity.h"

#include "SceneManager.h"
#include "Scene.h"

#include "ParserJSON.h"




