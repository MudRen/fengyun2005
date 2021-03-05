inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大厅尽头");
        set("long", @LONG
厅堂里既没有精致的摆设，也没有华丽的装饰，但却显得说不出的庄严、肃穆、
高贵、博大。无论谁走到这里，心情都会不由自主的觉得严肃沉重起来。长桌的尽
头处，一张宽大的交椅上，坐着一个白衣人。究竟是怎么样一个人，谁也看不太清
楚，只看见他端端正正地坐在那里。
LONG
        );
        set("exits", ([ 
	"south": __DIR__"hall3",
	"west": __DIR__"pianting2",
	]));
        set("objects", ([
        	__DIR__"npc/makongqun":	1,
	]) );
        set("coor/x",-10);
        set("coor/y",130);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
