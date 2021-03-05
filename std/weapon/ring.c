// ring.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

#include <weapon.h>
inherit WIELD;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

varargs void init_ring(int damage, int flag) {
	if(!clonep()) {
		set("weapon_prop/damage", damage);
		set("nodrop_weapon",1);
		set("flag", flag | NO_HANDED);
		set("weapon_wielded", W_RING);
		set("skill_type", "unarmed");
	}
	::init_wield();
}

