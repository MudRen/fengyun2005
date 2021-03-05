inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "塔顶");
        set("long", @LONG
塔不高，密檐以上就是塔刹，塔刹上罕有人至，青苔横生，一不小心就容易滑
下去。站在上面，周围情景尽收眼底，近处是嵩岳寺内的塔林，远处是青铜峡和和
阗河的滚滚流水。仔细看去，东北角还有几缕似雾似烟的白气袅袅升起。
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"songyue",
	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"白气": "仔细辨认，这似乎是用牛马粪燃起的炊烟，这里怎么还会有人家呢？\n",
		]));
	set("outdoors", "zangbei");
        set("coor/x",-550);
        set("coor/y",650);
        set("coor/z",10);
	set("map","zbeast");
	setup();

}

void init(){
//	int i;
	object me;
	me = this_player();
	if (query("bird_out") && !me->query_temp("parrot/再见血奴")) call_out("do_bird", 1, me);
}

int do_bird(object ob) {

	if(interactive(ob) && environment(ob) != this_object()){
		return 1;
	}	
	message_vision(HIR"忽然间，一样东西从塔刹上飞了起来——是一只鸟，一只脖子上挂着铃的鸟。铃
声怪异而奇特，就仿佛要摄人的魂魄。转瞬间，鸟飞远了，铃声也远了。\n"NOR,ob);
	ob->set_temp("parrot/再见血奴",1);
	set("bird_out",0);
}


void reset()
{
//	object item,coffin;
//	object *inv,*players;
	
	::reset();
	set("bird_out",1);
	return;
} 