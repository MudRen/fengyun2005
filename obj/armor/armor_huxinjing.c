// armor_hu_xin_jing.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit NECK;

void create() {
	set_name("护心镜", ({ "hxjing" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("material", "iron");
		set("armor_prop/armor", 5);
	}
	::init_neck();
}
