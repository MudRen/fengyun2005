/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "冰川");
        set("long", @LONG
第一次到这里的人一定不敢相信这是真的，巨大无比的冰川三面环山，分为两
支，形为冰斗，周围的山雪映入[37m冰川[32m，透着说不出的怪异。远远看去，简直就象一
个初涉人世的少女一样，绽放出迷人而又年轻的光彩！
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"baiyang",
]));
        set("item_desc", ([
                "冰川": "你围着冰川看了又看，发现冰川里似乎有着古怪！击（ｂｒｅａｋ）开它！\n",
                "ice": "你围着冰川看了又看，发现冰川里似乎有着古怪！击（ｂｒｅａｋ）开它！\n",
        ]) );
        set("frozen",10);
        //set("no_pk",1);
                
        set("outdoors", "xinjiang");
		set("coor/x",10);
		set("coor/y",-70);
		set("coor/z",0);
		setup();
}

void init()
{
        add_action("do_pour", "pour");
		add_action("do_break", "break");
}

int do_pour(string arg)
{
        object me;
        object con;
        me = this_player();
        if(!arg) return 0;
        if(!objectp(con=present(arg, me)))
        return 0;
        if(!con->query("liquid"))
        return 0;
        if(!con->query("liquid/remaining"))
        	return notify_fail( con->name() + "是空的。\n");
        con->add("liquid/remaining", -1);
        message_vision("$N拿起" + con->name() + "倒了一些" +
        	con->query("liquid/name")  + "在寒冰上。\n",me);
        if(con->query("liquid/name") == "热水")
        	tell_object(me,"寒冰刚刚化开了一点儿就又冻上了！！\n");
        if(con->query("liquid/name") == "盐水")
        {
        	tell_object(me,"奇怪得很，寒冰一遇盐水就开始解冻了！！\n");
        	add("frozen",-1);
        }
        if( query("frozen") <= 0 )
        {
        	tell_object(me,"寒冰终于化开了一个小洞．．．\n");
        	if(!query("exits/southwest"))
                set("exits/southwest",__DIR__"gela");
        	call_out("close_path",10);
        }
        return 1;
}

void close_path()
{
        if( !query("exits/southwest") ) return;
        message("vision",
"飘过来的水气眨眼间冻成冰珠，渐渐地封住了洞口．．\n",
                this_object() );
        delete("exits/southwest");
        set("frozen",30+random(5));
}

int do_break()
{
		object me;
		me = this_player();
		if(me->query("force") < 50)
			return notify_fail("你的内力不够了！\n");
		me->add("force",-50);
			return notify_fail("你飞起一掌，重重地击在冰川上！刹那间冰屑横飞，冰川上的裂痕更深了！\n");
}



