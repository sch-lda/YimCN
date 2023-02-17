#pragma once
#include "views/view.hpp"

namespace big
{
	enum class tabs {
		NONE,

		SELF,
		WEAPONS,
		TELEPORT,
		MOBILE,

		VEHICLE,
		HANDLING,
		HANDLING_SEARCH,
		HANDLING_SAVED_PROFILE,
		HANDLING_MY_PROFILES,
		HANDLING_CURRENT_PROFILE,
		LSC,
		SPAWN_VEHICLE,
		PV,
		PERSIST_CAR,
		FUN_VEHICLE,

		WORLD,
		SPAWN_PED,
		TIME_AND_WEATHER,
		CREATOR,
		TRAIN,
		WATER,
		BLACKHOLE,

		NETWORK,
		SESSION,
		MISSIONS,
		SPOOFING,
		PLAYER_DATABASE,
		SESSION_BROWSER,

		SETTINGS,
		STAT_EDITOR,
		CONTEXT_MENU_SETTINGS,
		ESP_SETTINGS,
		GUI_SETTINGS,
		HOTKEY_SETTINGS,
		REACTION_SETTINGS,
		PROTECTION_SETTINGS,
		TRANSLATION_SETTINGS,
		DEBUG,

		PLAYER
	};

	struct navigation_struct
	{
		const char name[32] = "";
		std::function<void()> func = nullptr;
		std::map<tabs, navigation_struct> sub_nav{};
	};

	class gui_service final
	{
		std::vector<tabs> current_tab{};
		bool switched_view = true;

		std::map<tabs, navigation_struct> nav = {
			{tabs::SELF, { "自身",view::self, {
				{ tabs::WEAPONS, { "武器", view::weapons }},
				{ tabs::MOBILE, {"手机", view::mobile}},
				{ tabs::TELEPORT, {"传送", view::teleport}},
			}}},
			{tabs::VEHICLE, { "载具", view::vehicle, {
				{ tabs::HANDLING, {"操控性", view::handling_current_profile, {
					{ tabs::HANDLING_CURRENT_PROFILE, {"当前配置", view::handling_current_profile } },
					{ tabs::HANDLING_SAVED_PROFILE, {"保存配置", view::handling_saved_profiles } },
				}}},
				{ tabs::LSC, { "洛圣都改车王", view::lsc }},
				{ tabs::SPAWN_VEHICLE, { "生成载具", view::spawn_vehicle }},
				{ tabs::PV, { "个人载具", view::pv }},
				{ tabs::PERSIST_CAR, { "保存载具", view::persist_car }},
				{ tabs::FUN_VEHICLE, { "有趣的功能", view::fun_vehicle }},
			}}},
			{ tabs::WORLD, { "世界", nullptr, {
				{ tabs::SPAWN_PED, { "生成生物模型", view::spawn_ped }},
				{ tabs::TIME_AND_WEATHER, { "时间天气", view::time_and_weather }},
				{ tabs::CREATOR, { "制作器", view::creator }},
				{ tabs::TRAIN, { "火车控制", view::train }},
				{ tabs::WATER, { "Water", view::water }},
				{ tabs::BLACKHOLE, { "黑洞", view::blackhole }},
		}}},
			{tabs::NETWORK, { "网络", nullptr, {
				{ tabs::SPOOFING, { "信息伪装", view::spoofing }},
				{ tabs::SESSION, { "战局", view::session }},
				{ tabs::MISSIONS, { "自由模式任务", view::missions }},
				{ tabs::PLAYER_DATABASE, { "玩家数据库", view::player_database }},
				{ tabs::SESSION_BROWSER, { "战局浏览器", view::session_browser }},
			}}},
			{tabs::NETWORK, { "Network", nullptr, {
				{ tabs::SPOOFING, { "Spoofing", view::spoofing }},
				{ tabs::SESSION, { "Session", view::session }},
				{ tabs::MISSIONS, { "Missions", view::missions }},
				{ tabs::PLAYER_DATABASE, { "Player Database", view::player_database }},
				{ tabs::SESSION_BROWSER, { "Session Browser", view::session_browser }},
			}}},
			{tabs::SETTINGS, { "设置", view::settings, {
				{ tabs::STAT_EDITOR, { "Stat 编辑器", view::stat_editor}},
				{ tabs::CONTEXT_MENU_SETTINGS, { "X键菜单", view::context_menu_settings}},
				{ tabs::ESP_SETTINGS, { "ESP透视", view::esp_settings}},
				{ tabs::GUI_SETTINGS, { "用户界面", view::gui_settings}},
				{ tabs::HOTKEY_SETTINGS, { "快捷键", view::hotkey_settings }},
				{ tabs::REACTION_SETTINGS, { "反应", view::reaction_settings}},
				{ tabs::PROTECTION_SETTINGS, { "防护", view::protection_settings}},
				{ tabs::TRANSLATION_SETTINGS, { "语言", view::translation_settings}},
				{ tabs::DEBUG, { "Debug", nullptr }},
			}}},
			{tabs::PLAYER, {"", view::view_player}}
		};
	public:
		gui_service();
		virtual ~gui_service();

		int nav_ctr = 0;

		navigation_struct* get_selected();
		std::vector<tabs>& get_selected_tab();
		bool has_switched_view();
		void set_selected(tabs);
		void set_nav_size(int);
		void increment_nav_size();
		void reset_nav_size();
		std::map<tabs, navigation_struct>& get_navigation();
	};

	inline gui_service* g_gui_service{};
}
