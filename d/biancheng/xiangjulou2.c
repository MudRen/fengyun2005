inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "相聚楼二楼");
        set("long", @LONG
小楼四面都围着栏杆，建筑得就像是一个小小的亭阁。最上面的一格窗户开了
一线，从这里看过去，恰巧可以看见屋子中间的一张圆桌。桌上摆着酒菜。屋子里
布置得精致而舒服，每样东西都恰巧摆在你最容易拿到的地方。
LONG
        );
        set("exits", ([ 
	"down": __DIR__"xiangjulou",
	]));
        set("objects", ([
	]) );
        set("coor/x",-40);
        set("coor/y",10);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
