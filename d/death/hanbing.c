// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "寒冰狱");
        set("long", @LONG
冰是昆仑山的千年寒冰，无数的犯人正赤身裸体的走在冰上，这里关得都是“
垢面蓬头，愁眉皱眼，大斗小秤欺痴蠢，致使灾屯累自身”的奸商，用别人的损失
换来自己的金银，结果仍是一无所有的在冰上走，对人用刑，地狱之法果然不同凡
间。
LONG
        );
        set("exits", ([
		"up" : __DIR__"chebeng",
		"down" : __DIR__"tuoke",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-100);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
