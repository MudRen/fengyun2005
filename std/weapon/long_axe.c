// axe.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//	"斩""砍""劈""刺""抽""点""戳"
//	"砸" post_action:  "bash_weapon"
//	"射" post_action : "throw_weapon,

#include <weapon.h>
inherit WIELD;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

varargs void init_axe(int damage, int flag) {
	if(!clonep()) {
		set("weapon_prop/damage", damage);
		set("flag", (int)flag | LONG | TWO_HANDED);
		set("weapon_wielded", W_LONG_AXE);
		set("skill_type", "axe");
		if(!query("verbs")) {
			set("verbs", ({ "劈", "砍", "斩", "砸" }) );
		}
	}
	::init_wield();
}

