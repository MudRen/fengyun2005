// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "忘机密藏");
        set("long", @LONG
从支路步下飞廊，只见一个偌大山洞，洞口青萝漫掩下隐隐可见＂忘机＂
二字，原来此处就是皓月宫的书馆＂忘机秘藏＂。走进洞中，只见几粒龙眼大
的明珠镶在壁上，淡白色的泠光映照着排排整齐的书橱，一个身著笔挺青衫的
中年男子正站在一粒明珠之下，翻动着手中的书籍。
LONG
        );
	set("objects", ([
		__DIR__"npc/wuge" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"nanzoulang",
	]) );

	set("item_desc", ([
		"书橱": (: look_stone :),
	]) );

	set("indoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",20);
	setup();
}

int init()
{
//	add_action("do_patch","patch");		disabled upon further investigation.
	add_action("do_patch","repair");
}

void reset()
{
	::reset();
	if (!random(20))
		present("xue wuge")->set("bladebook",1);
	if (!random(20))
		present("xue wuge")->set("spellsbook",1);
	present("xue wuge")->set("starrain",1);
}

string look_stone()
{
	object me = this_player();
	if (random(me->query_temp("annie/xiangsi_bookcase"))<30 || query("no_book"))
	{
		tell_object(me,"一排排书橱整齐地立在这里，有的橱中书页也已经泛起黄边。\n");
		me->add_temp("annie/xiangsi_bookcase",1);
		me->set_temp("annie/xiangsi_bookcase2",0);
		return " ";
	}
	tell_object(me,"一排排书橱整齐地立在这里，有的橱中书页也已经泛起黄边。\n"BLK"在一处明珠照射不到的漆黑角落，有个小小的书橱孤独的立着，看起来历久经年，无人修补，已经摇摇欲坠。\n"NOR);
	me->set_temp("annie/xiangsi_bookcase",0);
	me->set_temp("annie/xiangsi_bookcase2",1);
	return " ";
}

int do_patch(string arg)
{
	object me = this_player(),patch;
	if (!me->query_temp("annie/xiangsi_bookcase2"))
		return 0;
	patch=present(arg,me);
	if (!patch)
		return 0;
	if (query("no_book"))
		return 0;
	if (crypt(""+patch->query_weight(),"VUL0P7ezMvL7o") != "VUL0P7ezMvL7o")
		return 0;
	tell_object(me,"你蹲下身子，用"+patch->name(1)+"修起书橱。\n");
	set("no_book",1);
	destruct(patch);
	if (random(3) > 0)
	{
		tell_object(me,"半晌之后，你拍掉手上的尘土直起身子，满意的看着自己的成品。\n");
		return 1;
	}
	tell_object(me,"不经意间，一本发黄的小册从柜子里落下，掉进你的怀中。\n");
	patch=new(__DIR__"obj/paper");
	patch->move(me);
	return 1;
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


