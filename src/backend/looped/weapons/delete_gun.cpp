#include "backend/looped/looped.hpp"
#include "core/enums.hpp"
#include "gta/enums.hpp"
#include "util/entity.hpp"
#include "util/math.hpp"

namespace big
{
	void looped::weapons_delete_gun()
	{
		bool bCageGun = g.weapons.custom_weapon == CustomWeapon::DELETE_GUN;

		if (bCageGun)
		{
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)ControllerInputs::INPUT_AIM))
			{
				if (PAD::IS_DISABLED_CONTROL_JUST_RELEASED(0, (int)ControllerInputs::INPUT_ATTACK))
				{
					Entity entity;

					if (entity::raycast(&entity))
					{
						if (ENTITY::IS_ENTITY_A_PED(entity) && PED::IS_PED_A_PLAYER(entity))
						{
							g_notification_service->push_error("特殊武器", "不能删除玩家!");
						}
						else
						{
							Vector3 entLoc = ENTITY::GET_ENTITY_COORDS(entity, true);
							double dist = math::distance_between_vectors(self::pos, entLoc);

							if (dist > 500)
							{
								g_notification_service->push_error("特殊武器", "实体距离太远.");
							}
							else
							{
								if (entity::take_control_of(entity))
								{
									entity::delete_entity(entity);
								}
								else g_notification_service->push_error("特殊武器", "控制实体失败.");
							}
						}
					}
					else g_notification_service->push_error("特殊武器", "未选择实体.");
				}
			}
		}
	}
}
