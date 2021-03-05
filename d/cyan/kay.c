// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "弑马台");
    set("long", @LONG
走到这里，一片毫无蔽掩的岩地突兀地自黄树林中显现。岩地尽处一条染
着斑斑褐迹的石槽，石槽边满是风蚀的残碑，让你幼年的一段记忆骤而清晰：
这里就是弑马台。传说中前朝东将军邀无数武林人士抵死肃清海疆、抗击倭人
贼寇之际，便是在此处弑去御赐名马，歃血而盟。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock3":1,
	__DIR__"npc/oldman":1,

	]));
	set("item_desc", ([
		"残碑":"碑上的文字已在历久经年的风吹雨打下侵蚀不清，你隐隐可\n以辨认出「．．歃．．盟．．破．．」几个残缺的字样。\n",
		"碑":"碑上的文字已在历久经年的风吹雨打下侵蚀不清，你隐隐可\n以辨认出「．．歃．．盟．．破．．」几个残缺的字样。\n",
		"bei":"碑上的文字已在历久经年的风吹雨打下侵蚀不清，你隐隐可\n以辨认出「．．歃．．盟．．破．．」几个残缺的字样。\n",
		"stone":"碑上的文字已在历久经年的风吹雨打下侵蚀不清，你隐隐可\n以辨认出「．．歃．．盟．．破．．」几个残缺的字样。\n",
	]) );
	set("exits",([
  		"west" : __DIR__"forest1",
	]) );

	set("outdoors", "cyan");

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",20);
	setup();
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


