// annie. 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "荒废的祠堂");
        set("long", @LONG
祠堂里积满了灰尘，一些牌位凌乱地堆在神台上，两只烛台孤零零的立在神台
上。神龛里空空的，上面结满了蛛网，神龛后面是厚厚的幔布。这里似乎新近有人
来过，地面上印有很多杂乱的脚印。 
LONG
        );
    set("exits", ([ 
		"west" : __DIR__"citang1",
	]));

	set("item_desc", ([
 		"幔布" : "长长厚厚的黑色幔布的更增添了这里神秘凄凉的气氛，你不由想掀开看看后面有什么。
（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",	
 		"curtain" : "长长厚厚的黑色幔布的更增添了这里神秘凄凉的气氛,你不由想掀开看看后面有什么。
（ｏｐｅｎ　ｃｕｒｔａｉｎ）。\n",
 	]) );  
	set("objects", ([
		__DIR__"obj/shentai" : 1, 
	]));
    set("indoors", "huashan");
	set("coor/x",-5);
	set("coor/y",15);
	set("coor/z",-10);
	setup();
}

void init(){
	add_action("do_open", "open");
	add_action("do_search", "search");
}

int do_open(string arg)
{
	object player,kumei;
	player = this_player();
	if(arg != "幔布" && arg != "curtain") {
		return 0;
	}
	if ( player->query("marks/忠诚") == 1 
			|| player->query("marks/忠诚") == -1)
	{
		message_vision("$N掀开幔布，积尘飞扬，隐隐一个黑色人影掠过，又好象只是幻觉。\n",player);
		if (query("gotone"))	// *cat
		{
			tell_object(player,"幔布的积尘下似乎有个什么东西在闪着微光。\n");
			if (!REWARD_D->riddle_check(player,"绝世芳华") 
				&& !REWARD_D->check_m_success(player,"绝世芳华"))
				REWARD_D->riddle_set(player,"绝世芳华",1);
			player->set_temp("annie/demon_suu",1);
		}
		return 1;
	}
	if (!REWARD_D->riddle_check(player,"听琴毛女洞") 
		&& !REWARD_D->check_m_success(player,"听琴毛女洞"))
		REWARD_D->riddle_set(player,"听琴毛女洞",1);
	kumei = new(__DIR__"npc/kumei.c");
	kumei->move(this_object());
	message_vision("$N试着掀开幔布。 \n\n\n",player);
	message_vision(HIB"忽然幔布动了一下，$N面前如鬼魅般出现一个$n。 \n\n\n"NOR,player,kumei);

	kumei->apprentice_me(player);
	return 1;
}


int do_search(string arg)
{
	object player,kumei;
	player = this_player();
	if(arg != "幔布" && arg != "curtain") {
		return notify_fail("你要找什么？\n");
	}
	if (player->is_busy())
	{
		return notify_fail("你现在正忙得很，没空乱摸。\n");
	}
	if ( REWARD_D->riddle_check(player,"绝世芳华") == 1 
		|| REWARD_D->riddle_check(player,"绝世芳华") == 2)
	{
		message_vision("$N掀开幔布，在幔布下的积尘中一阵乱摸。\n",player);
		if (query("gotone") && !random(5))	// *cat
		{
			kumei = new(__DIR__"obj/bottle2");
			if (kumei->move(player))
			{
				tell_object(player,"你在尘土中摸到了一个小小的玉瓶。\n");
				REWARD_D->riddle_set(player,"绝世芳华",2);
				delete("gotone");
			}
			else
				tell_object(player,"你在尘土中摸到了什么东西，但它一下就滑出了你的掌心。\n");
		}
		else
		{
			tell_object(player,"你什么也没有找到。\n");
		}
		player->start_busy(2);
		return 1;
	}
	return notify_fail("你什么也没有找到。");
}


void reset()
{
//	object shui;
    ::reset();
	if (!random(4))	
		set("gotone",1);	// *cat
}