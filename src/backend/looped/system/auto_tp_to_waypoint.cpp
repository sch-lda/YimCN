#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "util/teleport.hpp"

namespace big
{
    class auto_tp_to_waypoint : looped_command
    {
        using looped_command::looped_command;

        virtual void on_tick() override
        {
            //this is a hack to prevent the warning notify..
            if (!teleport::to_blip((int)BlipIcons::Waypoint))
                return;

            teleport::to_waypoint();
        }
    };

    auto_tp_to_waypoint g_auto_tp_to_waypoint("autotptowp", "自动传送到导航点", "设置导航点后立即传送.", g.self.auto_tp);
}
