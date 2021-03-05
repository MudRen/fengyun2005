// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "走廊");

	set("long", @LONG
麒麟阁外面的一条走廊。本来在这个破落的小镇上，客栈也没什么钱修葺这条
本已摇摇晃晃，嘎吱嘎吱做响的木头走廊，但因为世袭一等侯狄青麟的到来，一辈
子省吃俭用的老板狠狠心硬是几乎搭上了所有的家当在走廊上铺上了红地毯，两边
栏上也高高挂起了大红灯笼。
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
		"down":__DIR__"yuelai",
		"up":__DIR__"corridor2",
	]) );
	//}}

	set("objects", ([
        	__DIR__"npc/xiaoyezi": 1,
        ]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();	
}
