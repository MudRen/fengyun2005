// searoad.c
#include <ansi.h>
#define MINAGE 20
#define MAXAGE 80
#define FATEMARK "宿命B/常春_海潮"

inherit ROOM;
void create()
{
	set("short", "礁石");
	set("long", @LONG
海边山岩，下面急流澎湃，海浪汹涌，重列着千百块怪兽般的礁石，海边山岩
亦是怪石嵯峨，峥嵘险恶。礁石间恶浪汹涌澎湃，雪白的浪花，飞激四溅。
LONG
	);
	set("exits", ([
		"north" : __DIR__"island",
		"east" : __DIR__"rock1",
	]));
	set("outdoors", "tieflag");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init_scenery()
{
	remove_call_out("event_tide");
	call_out("event_tide",1,0);
}



string* msg= ({
	HIY"东海之滨， 礁石竦立。 海风微拂， 银浪拍岸。
极目远望， 但见长烟落日，晚霞满天。 \n\n"NOR,
	HIY"夕阳冉冉入海，余晖铺洒在海面上。有如万道金波，闪耀不已，瑰丽无比。 \n\n"NOR,
	WHT"沙岸上，鸥鹭泛波，沙禽掠岸。淡云孤雁远。
偶尔穿来啼声，飘飘杳杳，远及天外。 \n\n"NOR,
	RED"水天交际之处，暮霭沉沉似染，千里烟波如虹。 \n\n"NOR,
	HIW"碧海蓝天之中，忽而扁舟一叶，忽而白帆一缕。都仿似镶嵌在海天之上，
水云之间。 \n\n"NOR,
	HIR"红日将尽，但闻远潮轰轰，接连不断。由轻至响，
由远及近。稍时，竟声如闷雷，惊天动地。 \n\n"NOR,
	HIM"举目望去，海上波涛山立，巨浪汹涌。一条白浪向海岸疾驰而来， 势若
奔雷。瞬间即到，拍击海岸。但见乱石崩云，惊涛裂岸，激起重重白色的
水雾如堆雪般在轰鸣声中向岸上蔓延。 \n\n"NOR,
});


void add_fate_mark(object ob)
{
	int num = 1+random(10);
	if(!random(0)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void event_tide(int count)
{
	object *ppls,ob;
	function f=(:add_fate_mark:);
	ob=this_object();
	if(count==sizeof(msg))
	{
		ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && $1->query("age")>=MINAGE && $1->query("age")<=MAXAGE && !$1->query(FATEMARK):));
		if(sizeof(ppls))
			map_array(ppls,f);
		return ;
	}
	message("vision",msg[count],ob);
	call_out("event_tide",5,++count);
	return ;
}

