// gloves.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create() {
    	set_name(YEL"金丝手套"NOR, ({ "golden gloves","gloves"}));
    	set_weight(5);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "双");
        	set("long", "一双金丝镶成的手套，质地优良，自然价格也不菲。。\n");
        	set("value", 90000);
		set("material", "cloth");
	}
    	::init_hands();
}

