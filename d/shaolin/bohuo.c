// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object con, ob;
        set("short", "拨火寮");
        set("long", @LONG
这是生火，烧菜的地方，几个胖僧人正在大锅中烧菜，边上另有小锅若干，那
里的菜是烧给方丈和大和尚吃的，作为寻常僧人，想品尝的话只有贿赂一下，据说
那些菜中都有名贵药材，对身体大有裨益。更能促进武学修为。
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"qianzao",  
]));
        set("objects", ([
                __DIR__"npc/monk5_sentry" : 2,
       ]) );

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",10);
	setup();
	con = new(__DIR__"obj/xiaoguo");
	ob  = new("obj/medicine/pill_bupin");
	if(ob && con) {ob->move(con); con->move(this_object());}
        con = new(__DIR__"obj/xiaoguo");
        ob  = new("obj/medicine/pill_bupin");
        if(ob && con) {ob->move(con); con->move(this_object());}
        con = new(__DIR__"obj/xiaoguo");
        ob  = new("obj/medicine/pill_bupin");
        if(ob && con) {ob->move(con); con->move(this_object());}

}
