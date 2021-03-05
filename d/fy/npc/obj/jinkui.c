// hat.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create() {
	set_name(HIY"金盔"NOR, ({ "golden hat", "hat" }) );
	set_weight(3000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "一顶金色的头盔。\n");
		set("value", 1000);
		set("material", "iron");
		set("armor_prop/armor", 5);
	}
	::init_head();
}
