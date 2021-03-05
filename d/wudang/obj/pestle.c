
#include <ansi.h>

inherit ITEM;


void create() 
{
	set_name("铁杵", ({ "iron pestle","pestle" }) );	
	set_weight(80000);
	
set("long", " 一根巨大的铁杵,因为年代久远,历尽风雨,早已锈迹斑斑,相传真武帝君少年本为净乐国 
太子，后受紫气元君化为老妪点化＂铁杵磨成针，功到自然成＂的真谛，得悟大道．后 
世人铸成这根铁杵，但千百年来，再无第二人能将这铁杵磨（ｇｒｉｎｄ）成针． \n");
	
set("unit", "根" );
	
set("value", 100);
	
set("no_get",1);
   
 if( clonep() )
       
set_default_object(__FILE__);

}


void init()
{
	add_action("do_grind","grind");
}




int do_grind(string arg)
{
	
object player,needle;

int i, max_sen, max_gin;
	
player = this_player();
	
max_sen = player->query("max_sen");
	
max_gin = player->query("max_gin");
	
if (arg != "铁杵" && arg != "pestle" && arg != "iron pestle")
	
{
		return 0;
	}

	
//tell_object(player,"既然已经说是再无第二人了，你又何必再做这无用之功呢？\n");

//return 1;

	
if (player->query("marks/武当_执着"))
	{
		message_vision(" $N拿起铁杵掂了掂，叹了口气， 喃喃到“铁杵磨成针，功到自然成，可是这世上又有多少人能做到呢。。。”  \n",player);
		return 1;
	}
	
if(player->is_busy()) return notify_fail("你的动作还没有完成，不能磨针。\n");
	
	
if (player->query("sen") <= max_sen /10 || player->query("gin") <= max_gin /10)
	{
		return notify_fail("你现在太累了，不能磨针。\n");
	}
	i = player->query_temp("totalgrindtimes") + 1;
	player->set_temp("totalgrindtimes",i);
	player->add("gin",-(max_gin/20));
	player->add("sen",-(max_sen/20));
	message_vision("$N耐心地把铁杵在剑泉溪石上一下一下磨着，磨着．．． \n",player);
	tell_object(player,"铁杵看上去似乎渐渐细了点．．． \n");
	player->start_busy(2);
	if (i <= 500)
	{
		return 1;
	}
	if (random(500))
	{
		return 1;
	}else
	{
		message_vision("$N磨啊磨啊，铁杵终于被$N磨成了铁针！！ \n",player);
		player->set("marks/武当_执着",1);       	
		needle = new(__DIR__"needle");
		needle->move(player);
		player->delete_temp("totalgrindtimes");
		destruct(this_object());
		return 1;
	}
}
