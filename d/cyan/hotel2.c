// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "四海客栈");
    set("long", @LONG
走进客栈，却不见小二迎上来，仅是厅中悬着一幅财神像，两旁的挂着的
对联上题道：“[1;35m三年不开张，开张吃三年[2;37;0m”。你哭笑不得地望着对联，看看趴
在大厅一隅的桌面上呼呼大睡的唯一一个客人，又摸了摸咕咕抗议的肚子，一
时间是去是留，倒真是踌躇难决。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/statue2":1,
	__DIR__"obj/scroll":1,
	__DIR__"obj/desk2":1,
	__DIR__"npc/man":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"out" : __DIR__"hotel",
  		"up" : __DIR__"hotel3",
	]) );


	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",95);
	setup();
}


void init() {
	add_action("do_get","get");
}



int do_get(string arg) {
	
	string arg1,arg2;
	int num,gao;
	object ye;
	
	if (!ye=present("fang shisan",this_object())) return 0;
	if (!arg)
		return 0;
	
	if (sscanf(arg,"%s from %s",arg1,arg2)==2)
	{
		if (arg2 == "桌面" || arg2 == "桌" || arg2 == "table")
			gao=2;
	
		if (arg1 == "tasty food" && gao == 2) gao=1;
		if (arg1 == "food" && gao == 2) gao=1;
		if (arg1 == "all" && gao == 2) gao=1;
		if (sscanf(arg1,"%s %d",arg2,num)==2)
			if (arg2 == "food" && gao == 2) gao=1;
		if (sscanf(arg1,"%s %d",arg2,num)==2)
			if (arg2 == "tasty food" && gao == 2) gao=1;
		

	}
	
	if (gao == 1) {
		message_vision("$N在睡梦中翻了个身，正好截住了你伸出的手腕。\n",ye);
		return 1;
	}
	

	return 0;
	
	
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("桌面", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/food");
		if(stone)
			stone->move(river);
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


