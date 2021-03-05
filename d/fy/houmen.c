// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "少林后山门");
        set("long", @LONG
少林的后门，几个壮年僧人把守此处，此门平时不开，只有当有弟
子闯过木人巷，闯出少林时才会大开后门，表示庆祝，从这里出去，你
便是江湖上一等一的高手了：

		放眼天下英雄，舍我其谁！

LONG
        );
        set("exits", ([ 
  "south" : __DIR__"muma",
  "west" : AREA_SONGSHAN"talin",
]));
        set("objects", ([
                __DIR__"npc/monk2" : 6,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-630);
	set("coor/y",1230);
	set("coor/z",70);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="south" && ob=present("shaolin monk", this_object()))
return notify_fail( 
"和尚说道：这位施主，请走正门！\n");
return 1;
}
void reset()
{
object *inv, ob;
string *sname=({"一幻","一尘","一茵","一寐",
"一空","一园","一少","一林","一寺","一第","一十"});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","一幻");
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        {
	if(i<=3)
        ob->add_team_member(inv[i]);
        inv[i]->set("name",sname[i]);
        }
}
}

