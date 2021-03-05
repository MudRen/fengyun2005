// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "桃花屋");
	set("long", @LONG
这是一间很小很小的木屋，四周种满了桃花，粉红色的花瓣飘洒在空中，地上 
也铺着一层厚厚有如地毯般的桃花瓣，空气中充满着浓重的花香，但隐隐之中，一 
缕更沁人心魄的淡淡的幽香弥漫在花丛中，空气中，你的心中。。。屋中只有一枝 
桃花枝斜插在木墙缝中，便空荡荡的别无他物。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"taoyuan-exit",

	]));
        set("item_desc", ([
        	"桃花枝":	"
一支桃花枝，枝叶盈翠欲滴，桃花芳香五彩，一颗晶莹的露珠在花瓣边上似落未落。 
你可以从墙上把它拔（pull）下来。\n",
        	"branch":	"
一支桃花枝，枝叶盈翠欲滴，桃花芳香五彩，一颗晶莹的露珠在花瓣边上似落未落。 
你可以从墙上把它拔（pull）下来。\n",
	]) );
	set("coor/x",-80);
	set("coor/y",-120);
	set("coor/z",-10);
	setup();
//	create_door("north", "door","木门", "south", DOOR_CLOSED);
}


void 	init(){
	add_action("do_pull","pull");
}


int	do_pull(string arg){
	
	object me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙着。\n");
	if (!arg)	return notify_fail("你想拔什么?\n");
	if (arg == "桃花枝" || arg == "peach branch" || arg=="branch") {
		if (!REWARD_D->riddle_check(me, "桃花林探幽") || present("meihuadao",this_object()))
			return notify_fail(YEL"你摇了摇桃花枝，没有发现什么异常的地方。\n"NOR);
		if (this_object()->query("pull_time")+300> time())	// 5分钟出来一次。
			return notify_fail(YEL"你摇了摇桃花枝，什么动静也没有。\n"NOR);
		message_vision(GRN"\n$N走到墙边，轻轻摘下墙上的桃花枝。 \n
静寂如常，唯有屋顶缓缓落下红红白白的梅花瓣，春雨一般落在$N发上，肩上。。。\n\n"NOR,me);
		me->start_busy(3);
		this_object()->set("pull_time",time());
		call_out("meihua_out",4, me);
		return 1;
	}
	tell_object(me, "这儿没有这样东西。\n");
	return 1;
}


int	meihua_out(object me){
	
	object meihuadao;
	if (!objectp(me) || environment(me)!=this_object())	return 1;
	message_vision( GRN"\n梅花雨中，一阵幽香袭来。 \n
     			飘香梅雨花似昨，君之魂兮今日归 \n"+MAG"\n
幽幽的叹气声中，屋中多了一个蒙纱之人，只有一双眸子露了出来，尽是讥诮之意。\n 
梅花盗轻叹一声，也不多言，身形飘转中，朵朵血色的梅花洒向$N。\n\n"NOR,me); 
	meihuadao = new(__DIR__"npc/ty-meihuadao");
	meihuadao ->move(this_object());
	return 1;
}
	
	
	