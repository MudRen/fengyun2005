// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "椎捣狱");
        set("long", @LONG
迎面就是几个巨人，手持大椎，几个巨大的类似捣药碗似的东西里面似乎有惨
叫之声传来，定睛细看，原来是囚犯被放进去，由巨人捣为肉泥，看了这许多惨状，
你镇定了许多。“善恶到头终须报”，早知今日，何必当初啊。定了定神，你毅然
地走向车崩狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"moai",
		"down" : __DIR__"chebeng",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-80);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
