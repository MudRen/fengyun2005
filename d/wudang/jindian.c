//mac's houqing.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "金殿");
        set("long", @LONG
一路分花拂柳，走着走着。眼前豁然开朗。一座壮观的武当金殿就呈现在眼前。
金殿建在天柱峰顶端，是武当山的象征. 铜铸鎏金的金殿虽为铜铸，但其结构殿身
的立柱、梁枋以及瓦鳞、檐牙、窗棂、门限等诸形毕备，且每块铸件之间严丝合缝，
毫无人工雕凿之痕，浑然天成。顶翼角飞举，上饰龙凤、天马、等灵禽瑞兽栩栩如
生。金殿内供奉的真武帝君像披发跣足，丰姿巍伟。两侧端宝奉册的金童玉女，闲
淑俊仪，温文尔雅；擎旗捧剑的武士勇猛威烈，气势夺人。
LONG
        );
        set("exits", ([
         "northdown" : __DIR__"fourgate",
        "southup" : __DIR__"tianzhufeng",
        ]));
        set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
}

void init()
{
add_action("do_mobai", "mobai");
}

int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N虔诚地跪在真武帝君像前磕了个头。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N身上的杀孽之气似乎轻了。 \n" , who);
	add("number",1);
	if((int) query("number") >	random(40) + 20 )
	{
    message_vision( HIY "\n\n$N觉得眼前一花，真武大帝似乎动了一下！！！！\n\n"NOR,who);
    if ( !objectp(who = present("master zhenwu", this_object())) )
		{
        who = new(__DIR__"npc/zhenwu");
		who->move(this_object());
		}
	}	
	return 1;
}

void reset()
{
object obj;
:: reset();
delete("number");
if(objectp(obj = present("master zhenwu", this_object())) )
destruct(obj);
}
