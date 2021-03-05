//Sinny@fengyun
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "白云观");
    set("long", @LONG
这里乃是叶孤城所居住的地方。叶孤城魈图皇位已久。是以白云城处处以皇宫为
图本造筑。唯有此处甚为淡雅。小小的道观内，一桌，一椅，一蒲团而已。墙上中间
为白云前代门主，白云仙的肖像，仙风道骨，须发飘飘，两旁为一副字联，上书：
                     
                      一剑西来，天外飞仙！
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"changlang3",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/master" : 1,

      ]));
    set("item_desc", ([
	"hassock": "一个有些年头的蒲团，绣着几个小字：叩首（kneel）千次，金石为开！\n",
	"蒲团": "一个有些年头的蒲团，绣着几个小字：叩首（kneel）千次，金石为开！。\n"
      ]) );


    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-280);
    set("coor/z",30);
    setup();
}
void init()
{
    add_action("do_kneel","kneel");
}       


int do_kneel(string arg)
{
    object me,book;
    int i, max_sen, max_kee,max_gin;
    me = this_player();
    max_kee = me->query("max_kee");
    max_sen = me->query("max_sen");
    max_gin = me->query("max_gin");
    if(me->is_busy()) 
	return notify_fail("你的动作还没有完成，不能叩首。\n");
    if (me->query("sen") <= max_sen /10 || me->query("gin") <= max_gin /10|| me->query("kee")<=max_kee/10)
    {
	return notify_fail("你已经精疲力尽了，无法再磕头了。\n");
    }

    message_vision(HIC"$N跪在蒲团上，面向石壁的白云仙的肖像，一下一下的磕起头来。。。。\n"NOR,me);
    me->add("gin",-(max_gin/50));
    me->add("sen",-(max_sen/50));
    me->add("kee",-(max_kee/50));
    if(random(200)||(int)me->query_temp("by_kneel")>=1)   
	tell_object(this_object(),"你觉得腰酸背痛，头颈渐渐僵硬，四肢开始发麻，脑子嗡嗡做响，似乎随时会一头载倒。。\n");
    else {
	message_vision(HIY"蒲团终于碎出一道口子，一本绢册掉在地上，你赶忙拾在$N怀中！\n"NOR, me);
	book = new(BOOKS"skill/calligraphy_60");
	book->move(me);
	me->add_temp("by_kneel",1);
    }
    me->start_busy(3);
    return 1;
}

