// gloves.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>

#include <armor.h>
inherit HANDS;

void create() {
    set_name(HIC"摘星手"NOR, ({ "zhaixin-shou"}));

    set_weight(50);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "双");
        set("material", "蚕丝");
        set("wear_msg", "$N双手小心翼翼地把一双薄如蚕丝般的$n戴在手上。\n");
        set("unwield_msg", "$N小心翼翼地把$n从手上除了下来，轻轻收入怀中。\n");
        set("long", HIW
"一双银色的丝织手套，平平常常似无甚特别之处，但两只手套上分别绣着一句歪歪扭扭的诗，
右手为：天上星，天上星，自我手下摘。左手为：手中金，手中金，他人囊里送；旁边绣着
落款：天下第一偷  司空摘星。据传这手套本为华山派之物，但不巧切了司空之名讳，被司
空摘星九探华山莎箩坪而盗得。\n"NOR);
        set("value", 0);
        set("armor_prop/armor", 2);
		set("material", "cloth");
	}
	::init_hands();
}

