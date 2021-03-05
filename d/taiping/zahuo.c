#include <ansi.h>
inherit ROOM;

int blinding(object me);
int bbqthem(object me, object obj);

void create()
{
        set("short", "太平杂货铺");
        set("long", @LONG
太平杂货铺实在是个标标准准的杂物铺，刷墙的白粉，各色各样的桐油和漆，
冰糖，花生，大米，小米，鸡蛋，鸭蛋，花粉，针线，鞋子，布匹，旱烟，老酒。。
只要你能想得到的东西，这里都有，连你想不到的东西这里都有。一间好大好大的
屋子里，堆满了五花八门，各式各样的东西，甚至还有一大捆已生了锈的刀枪，和
一大堆线装的旧画。
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"mroad3",
	]));
        set("item_desc", ([
	
	 ]));
	 set("objects", ([
               	__DIR__"npc/oldworm" : 1,
    	]) );
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

	
int blinding(object ob) {
	object *enemy;
	enemy=ob->query_enemy();
	if (!enemy || sizeof(enemy)<1)	return 1;
	message_vision(HIW"\n$N忽然一挥手抖出一包石灰，白粉飞散，附近一带立时就像是陷入漫天迷雾之中。\n"NOR,ob);
	foreach (object x in enemy) {
		if (x->query_temp("block_msg/all")) continue;
		bbqthem(ob,x);
	}
	return 1;
}

int bbqthem(object me, object enemy) 
{
	if(enemy->query("combat_exp")>random(me->query("combat_exp")*5))
        {
        	message_vision(HIB"$N连忙转过头去，避开白粉。\n"NOR,enemy);
        	return 1;
        }
	tell_object(enemy,HIW"你只觉得眼前白茫茫的一片，什么都看不到了。。。\n"NOR);
	enemy->add_temp("block_msg/all",1);
	message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n"NOR,enemy);
	call_out ("recover",10, enemy);
	return 1;
}


int recover (object obj){
	if (!obj)	return 1;
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
	return 1;
}	
