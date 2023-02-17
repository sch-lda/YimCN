#pragma once
#include "core/enums.hpp"

struct custom_weapon {
	big::CustomWeapon id;
	const char name[32];
};

const custom_weapon custom_weapons[] = {
	{ big::CustomWeapon::NONE, "默认" },
	{ big::CustomWeapon::CAGE_GUN, "笼枪" },
	{ big::CustomWeapon::DELETE_GUN, "删除枪" },
	{ big::CustomWeapon::GRAVITY_GUN, "重力枪" },
	{ big::CustomWeapon::STEAL_VEHICLE_GUN, "偷车枪" },
	{ big::CustomWeapon::REPAIR_GUN, "修理枪" },
	{ big::CustomWeapon::VEHICLE_GUN, "载具枪" }
};