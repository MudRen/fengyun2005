// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "温泉");
        set("long", @LONG
黄山温泉古称汤泉，古人云“紫云峰下藏太阳，不施炉灶自成汤”，更兼有医
药功能名闻天下。因为曾多次涌出红色泉水，误为朱砂，所以又称朱砂泉。因为
地暖气湿，有好事的人在这里种了一些热带作物。有香蕉树，榴莲树，看来长得
都很好。温泉西上便是慈光阁，北边远远可见观瀑亭。
LONG
        );
    set("exits", ([ 
  		"westup" : __DIR__"taohua", 
  		"northup" : __DIR__"guanpu",
  		"eastdown" : __DIR__"shanmen", 
	]) );
	
	set("objects", ([
    	__DIR__"obj/tangquan" : 1,
    ]) );
    
    set("item_desc", ([
    	"榴莲树" : "你从来没见过这么高大的榴莲树。往上看去，上面结的大榴莲少说
也有二十多斤！ 你也许可以试着摇一摇（SHAKE）榴莲树。\n",
    	"durian tree" : "你从来没见过这么高大的榴莲树。往上看去，上面结的大榴莲少说
也有二十多斤！ 你也许可以试着摇一摇（SHAKE）榴莲树。\n",
		"香蕉树" : "一丛长得异常茂密的香蕉树，树不高。上面一捧捧香蕉又黄亮又大，
比市场上的看来好得多。\n",
		"banana tree" : "一丛长得异常茂密的香蕉树，树不高。上面一捧捧香蕉又黄亮又大，
比市场上的看来好得多。\n",
    ]) );
    
    set("banana_amount", 3);
    set("durian_amount", 3);
    set("outdoors", "huangshan");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void init() 
{
	add_action("do_shake", "shake");
	add_action("do_pick", "pick");
}

int do_pick(string arg)
{
   	object me, banana;
	int i, luck;
	
	i = NATURE_D->get_season();	
   	me = this_player(); 
   	luck = me->query_kar();
   	if(!arg || arg != "banana" && arg != "香蕉") return 0;	
	if( i==1 || i == 2){  
   		if ((int)query ("banana_amount") >= 1)
   		{
   			if (random(luck) > 15) {
				banana = new(__DIR__"obj/gbanana");
      			banana->move(me);
      		} else {
      			banana = new(__DIR__"obj/banana");
      			banana->move(me);
      		}
      		add("banana_amount", -1);
      		message_vision("$N伸手摘了一个又黄亮又大的香蕉下来。\n", me);
   		}
   		else { 
      		write ("香蕉都被摘光啦！！！ \n");
   		}
   	} else {
   		message_vision("$N围着香蕉树转了一圈。\n", me);
   		write("你什么都没有找到。\n");
   	}	
   	return 1;
}

int do_shake(string arg)
{
	object me/*, durian*/;
	int i/*, j*/, season;
	
	me = this_player();
   	i = me->query_str();
	season = NATURE_D->get_season();	
   	if(!arg || arg != "榴莲树" && arg != "durian tree" && arg != "tree") return 0;	
	if(me->is_busy()) {
		write("你现在正忙！\n");
   	    return 1;
   	}
   	if( i > 20 ) {
		message_vision("$N用尽全身力气，终于把榴莲树摇得摆动起来。\n", me);
		me->start_busy(3);
		if(random(i) > 5 && (int)query("durian_amount") >= 1 && (season == 2 || season == 4)) {
			remove_call_out("durian_fall");
			call_out("durian_fall", 1, me); 
		} 
		return 1;
	} else {
		message_vision("榴莲树太大了，$N根本摇不动它。\n", me);
	}
	return 1;
}

void durian_fall(object me)
{
	object durian;
	int luck;
	
	luck = me->query_kar();
	if(random(luck) < 5 ) {
		message_vision(RED"$N累得一屁股坐在地上。忽然，一颗大榴莲呼啸着从树顶落下，\n"NOR, me);
		message_vision(RED"$N无力闪避，咚的一声，大榴莲砸在$N的头上！！！\n"NOR, me); 
		remove_call_out("see_star");
		call_out("see_star", 2, me);
	} else {
		message_vision(HIY"一颗大榴莲呼啸着从树顶落下，啪的一声掉在$N身旁。\n"NOR, me);
	}
	add("durian_amount", -1);
	if(random(luck) > 10) {
		durian = new(__DIR__"obj/gdurian");
		durian->move(this_object());	
	} else {
		durian = new(__DIR__"obj/durian");
		durian->move(this_object());
	}
}

void see_star(object me)
{
	int i;
	
	i = me->query_int();
	tell_object(me, HIC"你眼前突然出现好多星星。。。。\n"NOR);
	tell_object(me, HIW"朦胧中，似乎宇宙向你展示星系的演变... 你忽然感到顿悟！\n"NOR);
	message("vison", me->name() + "傻呵呵的流着口水 ~~\n", environment(me), me);
	me->apply_condition("idiot", 1, this_object()); 
}