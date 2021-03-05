/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "土路");
        set("long", @LONG
荒原上的一段蜿蜒曲折的土路，伴随一条默默的溪流（ＲＩＶＥＲ），清澈的
溪水，使人感到一股清新气息。周围群山起伏，碧水蜿蜒，风光秀丽。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"tulu2",
  "east" : __DIR__"sichou",
]));
        set("objects", ([
        __DIR__"npc/crazy_dog" : 2,
                        ]) );
        set("item_desc", ([
                "river": "好清澈的溪流，里面还有小鱼（ｃａｔｃｈ）耶！！\n",
                "溪流": "好清澈的溪流，里面还有小鱼（ｃａｔｃｈ）耶！！\n"

        ]) );
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","清澈的溪水");
        set("liquid/container", "溪流");
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_catch","catch");
}

int do_catch(string arg)
{
	object me;
	me=this_player();
	if(random(me->query("combat_exp")+1000)<50000)
	{
	if(me->max_food_capacity()>(int)me->query("food"))
	{
		me->add("food",15);
		return notify_fail("你一伸手，抓住一条小活鱼抛入口中．．．．
啊－－－味道不错，如果再有点瓦萨比就好喽．．．\n");
	}
	else
	return notify_fail("你伸出手试着抓了抓，结果什么也没抓到！\n");
	}
	else
	return notify_fail("你伸出手试着抓了抓，结果什么也没抓到！\n");
}
