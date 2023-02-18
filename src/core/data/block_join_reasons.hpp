#pragma once

namespace big
{
    inline std::unordered_map<int, const char*> block_join_reasons =
	{
		{ 1, "无" },
		{ 5, "被投票踢出" }, // You have already been voted out of this game session.
		{ 7, "资产不兼容" }, // Failed to join session due to incompatible assets.
		{ 8, "战局已满" }, // The session you're trying to join is currently full.
		{ 9, "槽位已满" }, // The session you're trying to join is currently full of players.
		{ 10, "标题未更新" }, // Please make sure all players have the latest Title Update.
		{ 12, "邀请被停用" }, // Invites are currently disabled in the session.
		{ 13, "瞄准方式不匹配" }, // The session you are trying to join is using a different targeting preference. You can change your preference in the Settings tab of the Pause Menu in Grand Theft Auto V. Joining a new GTA Online Session.
		{ 14, "被识别为作弊者" }, // You are classed as a cheat and can only play with other cheats until you are forgiven.
		{ 16, "DLC不兼容" }, // Incompatible downloadable content. All players must have the latest compatibility pack.
		{ 17, "仅限帮会" }, // You are trying to enter a Crew Members only session.
		{ 21, "战局不存在" }, // The session you are trying to join no longer exists.
		{ 22, "仅限邀请" }, // The session you are trying to join is private. You will need to be invited to join this session.
		{ 26, "仅限好友" }, // The session you are trying to join is friends only.
		{ 23, "构建类型不同" }, // The session you are trying to join is a different build type.
		{ 25, "内容不同" }, // The session you are trying to join is not using the same content.
		{ 18, "被识别为恶意玩家" }, // The session you are trying to join is for people who are not Bad Sports or cheaters - you are a Bad Sport.
		{ 19, "仅限恶意玩家" }, // The session you are trying to join is for Bad Sports only.
		{ 20, "仅限作弊者" }, // The session you are trying to join is for cheaters only.
		{ 27, "用户声誉差" }, // Unable to join this session, your account has a bad reputation.
		{ 28, "战局可能不存在" }, // Unable to connect to session. The session may no longer exist.
		{ 29, "高级竞赛" }, // Unable to Join. The session you are trying to join is a Premium Race. Joining and accepting invites is disabled for this mode.
	};
}