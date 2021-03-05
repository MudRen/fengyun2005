//Created by justdoit at May 2001 
//All Rights Reserved ^_^

#include <ansi.h>;
inherit ROOM;
void create()
{
    set("short", "斩蟒台");
    set("long", @LONG
昔年佛门高僧苦瓜大师应白云城主之邀，云游至此，行至此台不由大惊，言道此
处实乃白云岛的风水命脉所在，一旦此处有所不测，则白云城危在旦夕，白云城主沉
思数日，历时三年在此兴建了高达百丈的斩蟒台，巍峨入天。而苦瓜再游此台时，脸
色阴郁变幻，缄口不言。
LONG
    );
    set("exits", 
      ([ 
	"east" : __DIR__"skystreet",
      ]));
    set("item_desc", ([
		"斩蟒台": "这是一处百丈的危台，遥遥望去，高不可攀。\n",
      ]) );
    set("objects", 
      ([ 
	//       __DIR__"npc/kugua" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-130);
    set("coor/z",30);
    setup();
}

void init()
{
    add_action("do_climb", "climb");
}


int do_climb(string arg)
{
    object me;
    me = this_player();
    if(arg != "斩蟒台" && arg != "up")
		return notify_fail("你要爬什么？\n");
    if (me->is_fighting() || me->is_busy())
		return notify_fail("你现在正忙。\n");
    if (me->query_skill("move",1) < 150)
		return notify_fail("你轻功不行，不可强爬。\n");
    message_vision("$N抓住斩蟒台外凸的石壁向上爬去。\n",me);
    
    if (random(2) || !REWARD_D->check_m_success(me,"王图一梦"))
    {
		message_vision(HIR"一阵海风吹过，$N手脚发软，从台上跌了下去。\n"NOR,me);
		me->unconcious();
		return 1;
    }
    me->move(load_object(__DIR__"zmttop"));
    me->perform_busy(1);
    message("vision",me->name()+"从台下慢慢的爬了上来。\n",environment(me),me);
    return 1;
}


/*

	       (\~~~/)            
	       ( ．．)        

	       (_____)~．      

　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
