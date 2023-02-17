#pragma once
#include "weapon/CAmmoInfo.hpp"

struct SpecialAmmo
{
	char name[32];
	eAmmoSpecialType type;
};

constexpr std::array<SpecialAmmo, 7> SPECIAL_AMMOS = {{
	{ "关闭特殊子弹",		eAmmoSpecialType::None },
	{ "穿甲弹",	eAmmoSpecialType::ArmorPiercing },
	{ "爆炸子弹",		eAmmoSpecialType::Explosive },
	{ "全金属外壳子弹",eAmmoSpecialType::FMJ },
	{ "空心弹",		eAmmoSpecialType::HollowPoint },
	{ "燃烧弹",		eAmmoSpecialType::Incendiary },
	{ "曳光弹",			eAmmoSpecialType::Tracer },
}};