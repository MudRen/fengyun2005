#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "沙滩");
        set("long", @LONG
这是一个白色的沙滩，弯弯的沙滩象极了新月的形状，细腻的沙子散发着银白
色的光亮，海浪温柔的拍打着岸边，浪头退下后留在沙滩上是五彩缤纷的贝壳，象
是大海送给沙滩的礼物。背后的山崖象高耸的巨人，面前的海湾里布满了黑色的巨
石，象个天然的防护堤，巨浪打在上面溅起朵朵白色的浪花。
LONG
        );
       set("exits", ([
                "east" : AREA_TIEFLAG"rock0",
        ]));

    set("outdoors","shenshui");
    set("no_magic",1);
	set("coor/x",1780);
	set("coor/y",-12550);
	set("coor/z",20);
    setup();
}

void init()
{
	object me;

	if(interactive(me=this_player()))
	{
		remove_call_out("event_tide");
		call_out("event_tide",30,me,0);
	}
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



void event_tide(object me,int count)
{
	if(!me||!living(me)||!present(me,this_object()))
		return ;
	if(count==sizeof(msg))
	{
		me->set("宿命B/常春_海潮",1+random(10));
		return ;
	}
	message_vision(msg[count],me);
	call_out("event_tide",5,me,++count);
	return ;
}

/*
void do_flush(object me)
{
   object room;

    if(!me || environment(me) != this_object()) {
        return;
    }
    tell_object(me,"\n突然一个大浪把你卷了出去！\n\n");
    if(random(2) > 1) {
        room = find_object(__DIR__"ocean1");
        if(!objectp(room)) room= load_object(__DIR__"ocean1");
        me->move(room);
    } else {
        room = find_object(__DIR__"beach");
        if(!objectp(room)) room = load_object(__DIR__"beach");
        me->move(room);
    }
}
*/

