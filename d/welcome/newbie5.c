// Silencer@fy4 workgroup

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"风云道"NOR);
	set("long", @LONG
前面就要进入风云世界了，往下看去，白云缭绕，一座雄伟的巨城里人来人往，
好不热闹，你不禁有些心慌。好在风云里有的是热情友善的朋友，而天神们也尽心
创造了一个友善的天地。用命令[1;31mｉ[0;32m看一下你的装备，发现你行囊里多了些东西，用
[1;31mｌｏｏｋ[0;32m命令可以看一下它们的用途。前途漫长，不做好准备可不行哦。进入风云
城有两条路，[1;32mｎｅｗｂｉｅ[0;32m是给新手的，有个有趣的ｑｕｅｓｔ还能加点儿经验评
价，顺便拿点儿小盘缠过日子，新版风云有许多变化，建议你从这条路开始．
[1;32mｖｅｔｅｒａｎ[0;32m是给轻车熟路已经来过这儿的，可以跳过新手的这一阶段，但是一
切都得白手起家，到时候可不要抱怨两手空空哦。
LONG
	);
	set("exits", ([
  		"newbie" :  AREA_FY"fqkhotel",
  		"veteran" :  AREA_FY"fqkhotel",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}

int init(){
	object food, drink, drug, intro, me;
	me = this_player();
	if (me->query_temp("first_time_login"))
	{
		food = new("/obj/food_item/newbie_food");
		drink = new("/obj/food_item/newbie_drink");
		drug = new("/obj/medicine/newbie_drug"); 
		intro = new("/obj/item/newbie_letter");
		if (food)	food->move(me);
		if (drink)	drink->move(me);
		if (drug)	drug->move(me);
		if (intro)	intro->move(me);
	}
}


int valid_leave(object me, string dir) {

	if (dir == "newbie") 
		REWARD_D->riddle_set(me,"新手入门",1);
		
	return ::valid_leave(me, dir);
}