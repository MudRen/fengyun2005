// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "褂搭寮");
        set("long", @LONG
这是为同源的禅寺行者准备的住所，少林是禅宗祖庭，所以历来各地拜山的行
者不绝，所以特地辟出此地，供游方和尚使用，屋内陈设简单，一张通铺极长，每
铺上面一张小经桌。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"neiyuan",
  "east" : __DIR__"yibo",
]));
        set("objects", ([
                __DIR__"npc/other_monk1" : 1,
                __DIR__"npc/other_monk2" : 1,
                __DIR__"npc/other_monk3" : 1,
                __DIR__"npc/other_monk4" : 1,
                __DIR__"npc/other_monk5" : 1,
                __DIR__"npc/other_monk6" : 1,
                __DIR__"npc/other_monk7" : 1,
                __DIR__"npc/other_monk8" : 1,
                
       ]) );
	set("coor/x",10);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

/*
void reset()
{
object *inv, ob;
string *sname = ({"山烟寺的和尚","兴国禅寺的和尚","塞外的和尚","印度的和尚","南山寺的和尚","无名寺的和尚","黄山的和尚","泰庙的和尚"});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","山烟寺的和尚");
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++){
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        inv[i]->set("name",sname[i]);
	}
}
}
*/                                           
