#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "大牢内");
	set("long", @LONG
石墙围成的院落很大，灰黑色的院墙是平常院墙的三四倍之高，上面站着几个
[33m狱卒[32m，正警惕地看守着犯人。院子里堆满了巨大的[33m石料[32m，有不少的犯人正在忙碌的
搬运。墙面一个[33m臭水坑[32m旁树了一块告示牌（[33mｓｉｇｎ[32m）。院子向西是出狱的大门。
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
       		"west" : __DIR__"dayu",
    	]));
    	set("objects", ([

    	]) );
	set("item_desc", ([
	    	"sign": "凡来此的犯人必须工作（ｗｏｒｋ）二十次方可出去。\n",
	    	"告示牌" : "凡来此的犯人必须工作（ｗｏｒｋ）二十次方可出去。\n",
	    	"臭水坑" : "臭水坑里几条蚊蝇的幼虫在蠕动，将就着喝几口吧（drink）\n",
	    	"pond" : "臭水坑里几条蚊蝇的幼虫在蠕动，将就着喝几口吧（drink）\n",	
	    	"狱卒":	  "狱卒说：东张西望，想越狱么？老子正愁没机会逮你呢！\n",
	    	"石料":	  "狱卒说：东张西望，想越狱么？老子正愁没机会逮你呢！\n",	
	]) );

//    	set("no_fight", 1);
    	set("no_fly",1);
    	set("outdoors", "jinan");
	set("valid_startroom",1);
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_work", "work");
	add_action("do_drink", "drink");
    	if( interactive(this_player())){
	    	this_player()->set("startroom", __FILE__);
    	}
}


int do_drink(){

	object me= this_player();
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	
	message_vision(CYN"$N趴在臭水坑边咕咕地喝了几口，咳，落难的英雄不如矢狗啊！\n"NOR, me);
	me->perform_busy(1);	
	if (me->query("food")<100) me->set("food",100);
        if (me->query("water")<100) me->set("water",100);	
        return 1;
}

int do_work(){
	object me;
	int i, gin, sen;
	me = this_player();
	i = me->query_temp("jail_work");
	gin = me->query("max_gin")*2/3;
	sen = me->query("max_sen")*2/3;
	if(me->is_busy()) 
		return notify_fail("你的动作还没有完成，不能工作。\n");
	message_vision(HIR"$N辛苦的加工石料，差点没累死过去。\n"NOR, me);
	me->receive_damage("gin",gin);
	me->receive_damage("sen",sen);
	me->set_temp("last_damage_from","在济南大牢强制劳动过度累死了。\n");
	me->perform_busy(2);
	me->set_temp("jail_work", i+1);
	return 1;	 
}

int valid_leave(object me, string dir){
	object obj;
	
	if(dir == "west" ) {
		if(me->query_temp("jail_work") < 20){
				return notify_fail("狱卒喝道：“站住，还没有做完工就想走？”\n");
			} 
			me->delete_temp("jail_work");
			me->set("vendetta/authority", 0);
			me->delete("marks/crime");
			me->set("startroom",AREA_FY"fqkhotel");	
			tell_object(me,HIR"\n狱卒说：出去规规矩矩做人，别再犯事儿了。\n"NOR);	
	}
	return 1;
}
