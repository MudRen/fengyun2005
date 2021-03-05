// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "秤杆狱");
        set("long", @LONG
此狱乃是公平所在，大凡罪犯最怕正义，用公平和正义去惩罚他们，才是最让
他们胆寒的，所以地藏特地设此一狱，无刑无罚，但只教满腹正义之人讲书论课，
宣天下至理，直至感化为止。到此便再无刑狱。往下便是出口，直通平安大道。
LONG
        );
        set("exits", ([
		"up" : __DIR__"abi",
		"down" : __DIR__"pingan",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-180);
	set("no_fight",1);
	setup();
        
}
 
