//All Rights Reserved 1998 Apstone, Inc.

inherit ROOM;

void create()
{
 set("short", "灌木林");
 set("long",@LONG
拨开挡路的乱树枝，走进灌木林中。林子非常的阴暗潮湿，可能是离水边太近
的缘故，隐隐还有海腥味。你对这里有这么大一片灌木林感到非常吃惊。四周似乎
根本没有路，长满了半人高的杂草。
LONG);
	 set("exits", ([
	  	"north" : __DIR__"seaside2",
	 ]));
	 set("item_desc", ([
	    "bush" : "这片灌木林太深了,要想过去恐怕只有硬往前闯（dash）了。\n",
	    "灌木林" : "这片灌木林太深了,要想过去恐怕只有硬往前闯（dash）了。\n",
	    "灌木" : "这片灌木林太深了,要想过去恐怕只有硬往前闯（dash）了。\n",
	 ]));
	 set("outdoors", "bat");
	set("coor/x",1000);
	set("coor/y",-50);
	set("coor/z",0);
		setup();
}
void init()
{
    add_action("do_dash", "dash");
}

int do_dash( string arg )
{
	 object me,room;
	 me = this_player();
	 if(!arg || arg != "bush")
	  	return notify_fail("你要往哪儿闯？\n");
	 if(me->query_str()<20 || me->query("force") < 300) {
		return notify_fail("你累得气喘吁吁，也没有闯出条路来！
（需20点有效力量和300点内力）\n");
	 }
	 room = load_object(__DIR__"lin2");
	 if(!objectp(room)) 
		return notify_fail("你累得气喘吁吁，也没有闯出条路来！\n");
	 message_vision("$N使劲往灌木林中一闯，结果一个跟头翻了进去！\n",me);
	 me->move(room); 
	 me->delete("force");
	 return 1;
}
