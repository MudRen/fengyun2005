// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "奇石疏影");
	set("long", @LONG
沿着道路又行了片刻，你忽然惊觉附近的景色竟与记忆中大不相同。凝目
看去，身前的道路曲曲折折，高下不平，四周是或立或卧，似龟似虎，形态奇
趣而各自相异的石海，柔绚的光线透过石峰间的窄缝斜映在地面，交织成一片
相离相错的稀疏影像。
LONG
	);
	set("objects", ([
		__DIR__"obj/rock" : 1,
	]));
	set("exits",([
  		"south" : __DIR__"lvzhu",
		"north" : "/d/eastcoast/palace_path2",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",-10);
	setup();
}

void init()
{	
	object ob;

	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object here = this_object();
	object * inv,robber;
	int i,value=0;
	if( !ob || environment(ob) != here ) return;
	inv = all_inventory(ob);
	for (i=0;i<sizeof(inv) ;i++ )
		value += inv[i]->query("value");
	if (value >= 20000 && value < 100000)		// 穷土匪	20K Exp
		robber=new(__DIR__"npc/bandit");
	else if (value >= 100000 && value < 250000)	// 风颜		1M Exp
		robber=new(__DIR__"npc/fonyan");
	else if (value >= 250000)					// 风满楼	7M Exp
		robber=new(__DIR__"npc/fonmanlou");

	if (robber)
	{
		message_vision(CYN"\n一块大山石后突然转出一个人影，拦住你的去路。\n\n"NOR,ob);

		robber->move(here);
		robber->rob(ob);
	}

}

