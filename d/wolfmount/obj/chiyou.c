// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
    set_name("巨像", ({ "巨像","蚩尤","chiyou","juxiang","大神蚩尤"}));
	set_weight(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "座");
		set("long",
            "\n                   蚩           尤           像           \n\n蚩尤乃大地万邪万兽之首，统率九大部族：蛮、夷、戎、狄、黑、蛰、邪、兽、鬼\n——每族各驱使百个小族，势力广阔达万族之多。。蚩尤被斩杀后，各部族大都臣\n服于黄帝，唯神狼一族愤然遁入深山，更建起这宏伟的蚩尤秘窟以祭大神。。\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
	}
    ::init_item();
}
