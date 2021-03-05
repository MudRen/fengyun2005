// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	object river,stone,*inv;

	set("short", "雪中阁");
        set("long", @LONG
走进暖意薰然的雪中阁，山顶凛然的寒气一扫而空。半是昏暗的小室中
斜摆着一张云纹绣榻，榻上粉帐低垂，流苏坠地，双凤交颈的锦被半搭在浅
红色的绡纱之外。绣榻边上是小巧的黄梨木妆台，台上一灯如豆，明镜盈盈
，镜边立着景泰蓝的瓷瓶，瓶中几朵素洁小花正自娇媚绽放。一只黄铜小暖
炉里正爇着几缕淡蓝的水沉香，绵密的香气在屋中浅浅浮动。
LONG
        );
	set("objects", ([
		__DIR__"npc/suluo" : 1,
		__DIR__"obj/desk2" : 1,
	]));
	set("exits",([
  		"west" : __DIR__"hanquan",
	]) );

	set("item_desc", ([
		"绣榻":	"绣榻两头雕着数头飞龙，龙尾交缠，中间镶着一颗明珠。\n",
		"明珠":	"一颗用蓝山翠玉雕成的圆珠，晶莹透彻。\n",
		"锦被": "锦被半搭，看不清下面是什么。\n",
		"明镜": "一面蛋圆形的铜镜，镜框上似乎有个把柄。\n",
		"把柄":	"你仔细一看，原来只是个普普通通的玲珑。\n",		
		"瓷瓶": "景泰蓝的瓷瓶中几朵素洁小花正自娇媚绽放。\n",
	]));	
	
	set("indoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",20);
	setup();

	river = present("妆台", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/cat");
		if(stone)
			stone->move(river);
	}

}



void reset()
{
	object river,stone,*inv;
	
	::reset();

	add("ref",1);
	if (query("ref") < 9)
		return;
	set("ref",0);

	river = present("妆台", this_object());
	if (!river)
		return;

	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/cat");
		if(stone)
		{
			stone->move(river);
			river->set("cat",1);
		}
	}


	return;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


