// annie 07.2003
// dancing_faery@hotmail.com

// love me? give me rebirthflower :>...

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "参商亭");
        set("long", @LONG
人生不相见，动如参与商。参商亭斜挂在石牌峰外的一角悬崖上，亭子不
大，亭柱也已经有些腐朽，却是占尽了一山上下看海观天的地势。站在亭中极
目眺去，东南山脉的青葱笼郁尽在眼底，更远处是一片直连远天的茫茫波涛。
据传在风清云爽的日子里，有时还能看见海那面远隔碧涛的一座小岛。
LONG
        );
	set("objects", ([
		__DIR__"obj/corner" : 1,
		__DIR__"npc/seablue" : 1,
	]));

	set("item_desc", ([
		"悬崖": "你目落悬崖，发现崖壁上竟长着几片青叶，一朵蓝花。\n",
		"cliff": "你目落悬崖，发现崖壁上竟长着几片青叶，一朵蓝花。\n",
		"flower": "一朵妖艳的蓝色小花，花瓣边沿泛着淡淡血光（pick）\n",
		"花": "一朵妖艳的蓝色小花，花瓣边沿泛着淡淡血光（pick）\n",
		"蓝花": "一朵妖艳的蓝色小花，花瓣边沿泛着淡淡血光（pick）\n",
	]) );

	set("exits",([
  		"west" : __DIR__"haoyue",
	]) );

	set("outdoors", "xiangsi");

	set("flower",1);

	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

void init()
{
	add_action("do_pick", "pick");
}


int do_pick(string arg)
{
   
   	object me, tea;
	int i;

   	me = this_player();
	i = me->query_skill("move",1);
      
	if(!arg || (arg != "flower" && arg != "花" && arg!= "蓝花" && arg!= "小花" && arg!="两生花"))
	{
		write("你要摘什么？\n");
		return 1;
	}
	if (!query("flower"))
	{
		write("你定神一看，崖上只有绿叶空摇，哪里还有花在？\n");
		return 1;
	}

	if (me->query("agi") < 36) {
		message_vision(CYN"$N痴痴的看着风中摇曳的花朵，神色惶然。\n"NOR,me);
		write("以你的身法，去摘下那朵花只会摔个尸骨无存，还是算了吧。\n");
		write("（至少需要36点实际速度才有可能成功）\n");	// 170 move + 2 ability if you don't distribute and w/o master
		return 1;	
	}
	
	if (i<201 && !me->query_temp("annie/pick_soulflower"))	// 只要不research，这永远是一个危险的任务．．．
	{
		me->set_temp("annie/pick_soulflower",1);
		message_vision(CYN"$N痴痴的看着风中摇曳的花朵，神色怔忡。\n"NOR,me);
		write("依你的轻身功夫，去摘崖壁上的花仍然有些危险。\n");
		write("你是否决定不顾一切，去摘下那朵花？\n");
		return 1;
	}
	if (i>200)
	{
		add("flower",-1);
		tea = new(__DIR__"obj/rebirthflower");
		tea->move(me);
		message_vision(CYN"\n$N深吸一口长气，跃出参商亭外，向崖外的小花落去。
刹那间$N已坠到花边，右手双指一剪，将花朵夹在手中。

$N略一提气，竟在空中倒翻而起，一鹤冲天般掠向亭柱。
一怔神间，$N已经姿势优雅的从亭外纵进，稳稳当当的落在地上，指间犹夹着娇艳的"HIB"两生花"NOR CYN"。\n\n"NOR,me);
		return 1;
	}
	me->set_temp("annie/pick_soulflower",0);
	if (i <= 120)
	{
		message_vision(CYN"\n$N叹了一声，深吸一口长气，跃出参商亭外，向崖外的小花落去。
刹那间$N已坠到花边，右手双指一剪，却没有夹到花茎。

$N心下一怔，已经整个人落了下去，只听一声悠长的惨叫传来．．．\n\n"NOR,me);
		me->add_temp("block_msg/all",1);
		me->move("/obj/void");	// 死得连尸体都没有了...
		me->set_temp("last_damage_from","为摘"HIB"两生花"HIY"从悬崖上坠落下去，尸骨无存。");
		// 嗯，通告一下....
		me->add_temp("block_msg/all",-1);
		me->die();
		return 1;
	}
	message_vision(CYN"\n$N叹了一声，深吸一口长气，跃出参商亭外，向崖外的小花落去。
刹那间$N已坠到花边，右手双指一剪，将花朵夹在手中。\n\n"NOR,me);

	add("flower",-1);	// 不管是否成功，花已经没有了。

	if ( random(i-120) > 8 )	// 200lv有90%机会,170lv有84%,150lv有73%机会，打倒dummies
	{
		message_vision(CYN"$N身法连展，笔直上冲，终于在一口真气将尽之时抓住亭栏。\n"NOR,me);
		tea = new(__DIR__"obj/rebirthflower");
		tea->move(me);
		message_vision(CYN"$N狼狈不堪的从亭外爬了进来，小心的收好"HIB"两生花"NOR CYN"，抹了一把冷汗。\n"NOR,me);
		return 1;
	}
	else
	{
		message_vision(CYN"正要松一口气，却发觉$N真气再提不起来，\n"NOR,me);
		message_vision(CYN"只听一声惨叫，$N已向崖下直直坠去．．．\n\n"NOR,me);
		me->add_temp("block_msg/all",1);
		me->move("/obj/void");
		me->set_temp("last_damage_from","为摘"HIB"两生花"HIY"从悬崖上坠落下去，尸骨无存。");
		me->add_temp("block_msg/all",-1);
		me->die();
		return 1;
	}
    return 1;
}

void reset()
{
	::reset();
	if (NATURE_D->get_season() < 3)	// 春夏二季
		set("flower",1);
}


