// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name( "石门", ({ "door"  }) );
	set("unit", "扇");
	set("no_get",1);
	set("value",20);
	set("long","
这是一扇沉重的石门，门上有一个星状的缺口(Hole)。
\n");
	set_weight(5000);
	::init_item();
}
