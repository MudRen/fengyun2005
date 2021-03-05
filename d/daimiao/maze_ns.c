#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","镜中世界");
  set("long",@LONG
这是个镜子的世界。游目四望，不论是东南西北，抑或是天顶脚下，无处不覆
盖着明亮光洁的盈盈镜面。层层叠叠无数个的映像正在镜中满脸仓皇的与你对视，
看着环绕在周围的再熟悉不过的人影，一丝恐惧爬上了你的心头。
LONG
  );
	set("coor/x",99);
	set("coor/y",99);
	set("coor/z",0);
	set("no_fly",1);
		set("item_desc", ([
		"west":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"north":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"east":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"south":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
	]) );
	setup();
}

void init()
{
	if(userp(this_player()))
	{
//	remove_call_out("attack");
	call_out("attack",1,this_player());
	}
}

int attack(object ob)
{
	int i;
	int damage;
	object room;
	if( environment(ob) == this_object())
	{
		if (!room = find_object(__DIR__"dongci"))
			room = load_object(__DIR__"dongci");
		message_vision(HIW"$N脚下的镜面陡然一翻，$N整个人直直掉落下去！\n"NOR, ob);
		ob->set_temp("last_damage_from","在镜中世界里误踏陷阱而亡。\n");
		damage = ob->query("max_kee") -random(ob->query_kar())+5;
       	ob->receive_wound("kee",damage);
		ob->set("gin",0);
		ob->set("sen",0);
		if (ob->query("kee") > 0)
			ob->set("kee",0);
		ob->move(room);
		return 1;
	}
	else
		return 1;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

