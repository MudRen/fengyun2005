inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "鹰舟");
        set("long", @LONG
这艘船大半都是用竹子建成，船舱是竹编的，甲板也是，是以船身特别轻。船
底装着两条细长的板，看来就像是雪橇，却是用极坚韧、极光滑的巨竹削成的。许
多只矫健有力的鹰，蜷伏在甲板上。两个红衣童子，正用一大条一大条新鲜的肉，
在喂它们。
LONG
        );
        set("exits", ([ 
	]));
	set("no_fly",1);
	set("no_fight",1);
        set("objects", ([

	]) );
	set("coor/x",-360);
        set("coor/y",100);
        set("coor/z",10);
	set("map","zbeast");
	setup();
}

int depart(object me){
	
	if (!me || environment(me)!=this_object())
		return 0;
		
	tell_object(me,CYN"
红衣童子从腰畔解下条长鞭，“叭”的凌空一抖。

鹰群立刻冲天飞起，无数银光闪闪的绳子也被带起，绳子带动船身，这艘船立

刻像雪橇般在平滑的沙地上滑行起来，开始时很慢，到後来却是滑行如飞，直

如御风而行一般。。。。\n\n"NOR);

	me->start_busy(4);
	call_out("arrive",4,me);
	return 1;
}

int arrive(object me) {
	if (!me || environment(me)!=this_object())
		return 0;
	tell_object(me,YEL"也不知行走了多久，船身一震，停了下来。\n"NOR);
	set("exits/down",AREA_GUANYIN"entrance");
	return 1;
}

int valid_leave(object who, string dir){
	if (userp(who))
	if (query("exits"))
		delete("exits");
	return 1;
}





