#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "木匠居");
        set("long", @LONG
屋子外面排着几只刚做完还未上漆的柜子，扑面就是一阵桐木的香味，拉开门
帘，屋子里木屑飞舞，不习惯的人会呛得喘不过气来，吱吱嘎嘎的锯木声和乒乒乓
乓的钉锤声在李木匠听来，无疑比山上鸟儿的叫声更婉转，这气息，这声音，伴着
他走过了人生的一大半岁月。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"sroad3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("objects", ([
	        __DIR__"npc/carpenter": 1,
	]));
	set("coor/x",-40);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
