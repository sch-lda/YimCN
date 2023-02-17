#pragma once
#include "core/enums.hpp"

namespace big
{
	struct SessionType {
		eSessionType id;
		const char name[22];
	};

	const SessionType sessions[] = {
		{ eSessionType::JOIN_PUBLIC,	"寻找公开战局" },
		{ eSessionType::NEW_PUBLIC,		"新的公开战局" },
		{ eSessionType::CLOSED_CREW,	"非公开帮会战局" },
		{ eSessionType::CREW,			"帮会战局" },
		{ eSessionType::CLOSED_FRIENDS,	"非公开好友战局" },
		{ eSessionType::FIND_FRIEND,	"加入好友" },
		{ eSessionType::SOLO,			"单人战局" },
		{ eSessionType::INVITE_ONLY,	"仅邀请战局" },
		{ eSessionType::JOIN_CREW,		"加入帮会战局" },
		{ eSessionType::SC_TV,		    "观战" },
		{ eSessionType::LEAVE_ONLINE,	"故事模式" }
	};
}