#include <ansi.h>

inherit ROOM;
string *names=({
  __DIR__"emaze2",
  __DIR__"emaze1",
  __DIR__"emaze4",
  __DIR__"emaze7",
} );
void create()
{
    set("short", HIC"石山"NOR);
    set("long", @LONG
四处的石山恰似“堆秀”，山势险峻，磴道陡峭，甚为新颖。山石，采用了不
同的堆垒技巧，既有单树的奇石，又有成群的山峦，崖谷峻峭，洞壑幽邃，同周围
的建筑物相配合，给人以华美、精巧的印象。但此间的假山真假错落，蜿蜒杂乱，
一不小心，便迷失了方向。
LONG
    );
    set("outdoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-70);
    set("coor/z",10);
    setup();
}
void reset()
{
    int i,j;
    string temp;
    ::reset();
    for (i=0;i<=3;i++)
    {
	j=random(4);
	temp=names[j];
	names[j]=names[i];
	names[i]=names[j];
	names[i]=temp;
    }
    set("exits", ([
	"north" : names[0],
	"south" : names[1],
	"east" : names[2],
	"west" : names[3],
      ]));
}
