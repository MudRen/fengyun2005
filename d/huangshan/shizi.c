// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "狮子峰");
        set("long", @LONG
此处远看像是一头卧狮，头西尾东横卧于前。上面胜景无数，狮子林，麒麟，
宝塔等奇松，蒲团，凤凰等古柏都是罕见的美景，所以向有“没到狮子峰，不见黄
山踪”的盛誉。尤以清凉台更为出名，向来是游人必去之所。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qingliang",
  "east" : __DIR__"sanhua",
]));
        set("objects", ([
        __DIR__"npc/su" : 1,
	__DIR__"npc/su2" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",30);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="west" && (ob=present("bai hong", this_object())
|| ob=present("bai huan", this_object())) && me->query("bellicosity")>50)
return notify_fail(
ob->name()+"说道：请留步！\n");
return 1;
}
void reset()
{
object me,me2;
:: reset();
me2=present("bai huan",this_object());
me=present("bai hong",this_object());
if(me) me->dismiss_team();
if(me2) me2->dismiss_team();
if(me && me2) me->add_team_member(me2);
}
