// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "拔舌狱");
        set("long", @LONG
自古以来奸恶之徒，不孝之人多爱搬弄是非，佛口蛇心，故设拔舌狱，以七寸
长箝勾去舌头，使之口不能言，舌会复长，长而再拔，往复循环，直至犯人心胆皆
丧，来世为人，便不敢再犯此业。再往下便是剥皮狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"yandu",
		"down" : __DIR__"bopi",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-50);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
